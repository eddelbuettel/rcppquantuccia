/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2000, 2001, 2002, 2003 RiskMap srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file thirty360.hpp
    \brief 30/360 day counters
*/

#ifndef quantlib_thirty360_day_counter_h
#define quantlib_thirty360_day_counter_h

#include <ql/time/daycounter.hpp>

namespace QuantLib {

    //! 30/360 day count convention
    /*! The 30/360 day count can be calculated according to a
        number of conventions.

        US convention: if the starting date is the 31st of a month or
        the last day of February, it becomes equal to the 30th of the
        same month.  If the ending date is the 31st of a month and the
        starting date is the 30th or 31th of a month, the ending date
        becomes equal to the 30th.  If the ending date is the last of
        February and the starting date is also the last of February,
        the ending date becomes equal to the 30th.
        Also known as "30/360" or "360/360".

        Bond Basis convention: if the starting date is the 31st of a
        month, it becomes equal to the 30th of the same month.
        If the ending date is the 31st of a month and the starting
        date is the 30th or 31th of a month, the ending date
        also becomes equal to the 30th of the month.
        Also known as "US (ISMA)".

        European convention: starting dates or ending dates that
        occur on the 31st of a month become equal to the 30th of the
        same month.
        Also known as "30E/360", or "Eurobond Basis".

        Italian convention: starting dates or ending dates that
        occur on February and are greater than 27 become equal to 30
        for computational sake.

        ISDA convention: starting or ending dates on the 31st of the
        month become equal to 30; starting dates or ending dates that
        occur on the last day of February also become equal to 30,
        except for the termination date.  Also known as "30E/360
        ISDA", "30/360 ISDA", or "30/360 German".

        NASD convention: if the starting date is the 31st of a
        month, it becomes equal to the 30th of the same month.
        If the ending date is the 31st of a month and the starting
        date is earlier than the 30th of a month, the ending date
        becomes equal to the 1st of the next month, otherwise the
        ending date becomes equal to the 30th of the same month.

        \ingroup daycounters
    */
    class Thirty360 : public DayCounter {
      public:
        enum Convention {
            USA,
            BondBasis,
            European,
            EurobondBasis,
            Italian,
            German,
            ISMA,
            ISDA,
            NASD
        };
      private:
        class Thirty360_Impl : public DayCounter::Impl {
          public:
            Time yearFraction(const Date& d1, const Date& d2,
                              const Date&, const Date&) const override {
                return dayCount(d1,d2)/360.0;
            }
        };
        class US_Impl : public Thirty360_Impl {
          public:
            std::string name() const override { return std::string("30/360 (US)"); }
            Date::serial_type dayCount(const Date& d1, const Date& d2) const override;
        };
        class ISMA_Impl : public Thirty360_Impl {
          public:
            std::string name() const override { return std::string("30/360 (Bond Basis)"); }
            Date::serial_type dayCount(const Date& d1, const Date& d2) const override;
        };
        class EU_Impl : public Thirty360_Impl {
          public:
            std::string name() const override { return std::string("30E/360 (Eurobond Basis)"); }
            Date::serial_type dayCount(const Date& d1, const Date& d2) const override;
        };
        class IT_Impl : public Thirty360_Impl {
          public:
            std::string name() const override { return std::string("30/360 (Italian)"); }
            Date::serial_type dayCount(const Date& d1, const Date& d2) const override;
        };
        class ISDA_Impl : public Thirty360_Impl {
          public:
            explicit ISDA_Impl(const Date& terminationDate, bool isLastPeriod)
            : terminationDate_(terminationDate), isLastPeriod_(isLastPeriod) {}
            std::string name() const override { return std::string("30E/360 (ISDA)"); }
            Date::serial_type dayCount(const Date& d1, const Date& d2) const override;
          private:
            Date terminationDate_;
            bool isLastPeriod_;
        };
        class NASD_Impl : public Thirty360_Impl {
          public:
            std::string name() const override { return std::string("30/360 (NASD)"); }
            Date::serial_type dayCount(const Date& d1, const Date& d2) const override;
        };
        static ext::shared_ptr<DayCounter::Impl>
        implementation(Convention c, const Date& terminationDate, bool isLastPeriod);
      public:
        /*! \deprecated Use the constructor taking a convention and possibly a termination date.
                        Deprecated in version 1.23.
        */
        QL_DEPRECATED
        Thirty360()
        : DayCounter(implementation(Thirty360::BondBasis, Date(), false)) {}

        /*! \deprecated Use the constructor taking a convention and possibly a termination date.
                        Deprecated in version 1.23.
        */
        QL_DEPRECATED
        Thirty360(Convention c, bool isLastPeriod)
        : DayCounter(implementation(c, Date(), isLastPeriod)) {}

        explicit Thirty360(Convention c, const Date& terminationDate = Date())
        : DayCounter(implementation(c, terminationDate, false)) {}
    };

    // implementation

    namespace {

        inline bool isLastOfFebruary(Day d, Month m, Year y) {
            return m == 2 && d == 28 + (Date::isLeap(y) ? 1 : 0);
        }

    }

    inline
    ext::shared_ptr<DayCounter::Impl>
    Thirty360::implementation(Thirty360::Convention c, const Date& terminationDate, bool isLastPeriod) {
        switch (c) {
          case USA:
            return ext::shared_ptr<DayCounter::Impl>(new US_Impl);
          case European:
          case EurobondBasis:
            return ext::shared_ptr<DayCounter::Impl>(new EU_Impl);
          case Italian:
            return ext::shared_ptr<DayCounter::Impl>(new IT_Impl);
          case ISMA:
          case BondBasis:
            return ext::shared_ptr<DayCounter::Impl>(new ISMA_Impl);
          case ISDA:
          case German:
            return ext::shared_ptr<DayCounter::Impl>(new ISDA_Impl(terminationDate, isLastPeriod));
          case NASD:
            return ext::shared_ptr<DayCounter::Impl>(new NASD_Impl);
          default:
            QL_FAIL("unknown 30/360 convention");
        }
    }

    inline
    Date::serial_type Thirty360::US_Impl::dayCount(const Date& d1,
                                                   const Date& d2) const {
        Day dd1 = d1.dayOfMonth(), dd2 = d2.dayOfMonth();
        Month mm1 = d1.month(), mm2 = d2.month();
        Year yy1 = d1.year(), yy2 = d2.year();

        if (dd1 == 31) { dd1 = 30; }
        if (dd2 == 31 && dd1 >= 30) { dd2 = 30; }

        if (isLastOfFebruary(dd2, mm2, yy2) && isLastOfFebruary(dd1, mm1, yy1)) { dd2 = 30; }
        if (isLastOfFebruary(dd1, mm1, yy1)) { dd1 = 30; }

        return 360*(yy2-yy1) + 30*(mm2-mm1) + (dd2-dd1);
    }

    inline
    Date::serial_type Thirty360::ISMA_Impl::dayCount(const Date& d1,
                                                     const Date& d2) const {
        Day dd1 = d1.dayOfMonth(), dd2 = d2.dayOfMonth();
        Month mm1 = d1.month(), mm2 = d2.month();
        Year yy1 = d1.year(), yy2 = d2.year();

        if (dd1 == 31) { dd1 = 30; }
        if (dd2 == 31 && dd1 == 30) { dd2 = 30; }

        return 360*(yy2-yy1) + 30*(mm2-mm1) + (dd2-dd1);
    }

    inline
    Date::serial_type Thirty360::EU_Impl::dayCount(const Date& d1,
                                                   const Date& d2) const {
        Day dd1 = d1.dayOfMonth(), dd2 = d2.dayOfMonth();
        Month mm1 = d1.month(), mm2 = d2.month();
        Year yy1 = d1.year(), yy2 = d2.year();

        if (dd1 == 31) { dd1 = 30; }
        if (dd2 == 31) { dd2 = 30; }

        return 360*(yy2-yy1) + 30*(mm2-mm1) + (dd2-dd1);
    }

    inline
    Date::serial_type Thirty360::IT_Impl::dayCount(const Date& d1,
                                                   const Date& d2) const {
        Day dd1 = d1.dayOfMonth(), dd2 = d2.dayOfMonth();
        Month mm1 = d1.month(), mm2 = d2.month();
        Year yy1 = d1.year(), yy2 = d2.year();

        if (dd1 == 31) { dd1 = 30; }
        if (dd2 == 31) { dd2 = 30; }

        if (mm1 == 2 && dd1 > 27) { dd1 = 30; }
        if (mm2 == 2 && dd2 > 27) { dd2 = 30; }

        return 360*(yy2-yy1) + 30*(mm2-mm1) + (dd2-dd1);
    }

    inline
    Date::serial_type Thirty360::ISDA_Impl::dayCount(const Date& d1,
                                                     const Date& d2) const {
        Day dd1 = d1.dayOfMonth(), dd2 = d2.dayOfMonth();
        Month mm1 = d1.month(), mm2 = d2.month();
        Year yy1 = d1.year(), yy2 = d2.year();

        if (dd1 == 31) { dd1 = 30; }
        if (dd2 == 31) { dd2 = 30; }

        if (isLastOfFebruary(dd1, mm1, yy1)) { dd1 = 30; }

        bool isTerminationDate =
            terminationDate_ == Date() ? isLastPeriod_ : d2 == terminationDate_;
        if (!isTerminationDate && isLastOfFebruary(dd2, mm2, yy2)) { dd2 = 30; }

        return 360*(yy2-yy1) + 30*(mm2-mm1) + (dd2-dd1);
    }

    inline
    Date::serial_type Thirty360::NASD_Impl::dayCount(const Date& d1,
                                                     const Date& d2) const {
        Day dd1 = d1.dayOfMonth(), dd2 = d2.dayOfMonth();
        Integer mm1 = d1.month(), mm2 = d2.month();
        Year yy1 = d1.year(), yy2 = d2.year();

        if (dd1 == 31) { dd1 = 30; }
        if (dd2 == 31 && dd1 >= 30) { dd2 = 30; }
        if (dd2 == 31 && dd1 < 30) { dd2 = 1; mm2++; }

        return 360*(yy2-yy1) + 30*(mm2-mm1) + (dd2-dd1);
    }

}

#endif
