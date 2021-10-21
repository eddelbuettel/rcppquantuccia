/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2000, 2001, 2002, 2003 RiskMap srl
 Copyright (C) 2004 Ferdinando Ametrano
 Copyright (C) 2013 BGC Partners L.P.

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

/*! \file actual365fixed.hpp
    \brief Actual/365 (Fixed) day counter
*/

#ifndef quantlib_actual365fixed_day_counter_h
#define quantlib_actual365fixed_day_counter_h

#include <ql/time/daycounter.hpp>

namespace QuantLib {

    //! Actual/365 (Fixed) day count convention
    /*! "Actual/365 (Fixed)" day count convention, also know as
        "Act/365 (Fixed)", "A/365 (Fixed)", or "A/365F".

        \warning According to ISDA, "Actual/365" (without "Fixed") is
                 an alias for "Actual/Actual (ISDA)" (see
                 ActualActual.)  If Actual/365 is not explicitly
                 specified as fixed in an instrument specification,
                 you might want to double-check its meaning.

        \ingroup daycounters
    */
    class Actual365Fixed : public DayCounter {
      public:
        enum Convention { Standard, Canadian, NoLeap };
        explicit Actual365Fixed(Convention c = Actual365Fixed::Standard)
        : DayCounter(implementation(c)) {}

      private:
        class Impl : public DayCounter::Impl {
          public:
            std::string name() const override { return std::string("Actual/365 (Fixed)"); }
            Time
            yearFraction(const Date& d1, const Date& d2, const Date&, const Date&) const override {
                return daysBetween(d1,d2)/365.0;
            }
        };
        class CA_Impl : public DayCounter::Impl {
          public:
            std::string name() const override {
                return std::string("Actual/365 (Fixed) Canadian Bond");
            }
            Time yearFraction(const Date& d1,
                              const Date& d2,
                              const Date& refPeriodStart,
                              const Date& refPeriodEnd) const override;
        };
        class NL_Impl : public DayCounter::Impl {
          public:
            std::string name() const override { return std::string("Actual/365 (No Leap)"); }
            Date::serial_type dayCount(const Date& d1, const Date& d2) const override;
            Time yearFraction(const Date& d1,
                              const Date& d2,
                              const Date& refPeriodStart,
                              const Date& refPeriodEnd) const override;
        };
        static ext::shared_ptr<DayCounter::Impl> implementation(Convention);
    };

    // Implementation
    inline ext::shared_ptr<DayCounter::Impl>
    Actual365Fixed::implementation(Actual365Fixed::Convention c) {
        switch (c) {
          case Standard:
            return ext::shared_ptr<DayCounter::Impl>(new Impl);
          case Canadian:
            return ext::shared_ptr<DayCounter::Impl>(new CA_Impl);
          case NoLeap:
            return ext::shared_ptr<DayCounter::Impl>(new NL_Impl);
          default:
            QL_FAIL("unknown Actual/365 (Fixed) convention");
        }
    }

    inline
    Time Actual365Fixed::CA_Impl::yearFraction(const Date& d1,
                                               const Date& d2,
                                               const Date& refPeriodStart,
                                               const Date& refPeriodEnd) const {
        if (d1 == d2)
            return 0.0;

        // We need the period to calculate the frequency
        QL_REQUIRE(refPeriodStart != Date(), "invalid refPeriodStart");
        QL_REQUIRE(refPeriodEnd != Date(), "invalid refPeriodEnd");

        Time dcs = daysBetween(d1,d2);
        Time dcc = daysBetween(refPeriodStart,refPeriodEnd);
        auto months = Integer(std::lround(12 * dcc / 365));
        QL_REQUIRE(months != 0,
                   "invalid reference period for Act/365 Canadian; "
                   "must be longer than a month");
        auto frequency = Integer(12 / months);

        if (dcs < Integer(365/frequency))
            return dcs/365.0;

        return 1./frequency - (dcc-dcs)/365.0;

    }

    inline
    Date::serial_type Actual365Fixed::NL_Impl::dayCount(const Date& d1,
                                                        const Date& d2) const {

        static const Integer MonthOffset[] = {
            0,  31,  59,  90, 120, 151,  // Jan - Jun
            181, 212, 243, 273, 304, 334   // Jun - Dec
        };

        Date::serial_type s1 = d1.dayOfMonth()
                             + MonthOffset[d1.month()-1] + (d1.year() * 365);
        Date::serial_type s2 = d2.dayOfMonth()
                             + MonthOffset[d2.month()-1] + (d2.year() * 365);

        if (d1.month() == Feb && d1.dayOfMonth() == 29) {
            --s1;
        }

        if (d2.month() == Feb && d2.dayOfMonth() == 29) {
            --s2;
        }

        return s2 - s1;
    }

    inline
    Time Actual365Fixed::NL_Impl::yearFraction(const Date& d1,
                                               const Date& d2,
                                               const Date& d3,
                                               const Date& d4) const {
        return dayCount(d1, d2)/365.0;
    }

}

#endif
