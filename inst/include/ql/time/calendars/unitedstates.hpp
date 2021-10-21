/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2004, 2005 Ferdinando Ametrano
 Copyright (C) 2000, 2001, 2002, 2003 RiskMap srl
 Copyright (C) 2003, 2004, 2005, 2006 StatPro Italia srl
 Copyright (C) 2017 Peter Caspers
 Copyright (C) 2017 Oleg Kulkov

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

/*! \file unitedstates.hpp
    \brief US calendars
*/

#ifndef quantlib_united_states_calendar_hpp
#define quantlib_united_states_calendar_hpp

#include <ql/time/calendar.hpp>

namespace QuantLib {

    //! United States calendars
    /*! Public holidays (see https://www.opm.gov/policy-data-oversight/pay-leave/federal-holidays):
        <ul>
        <li>Saturdays</li>
        <li>Sundays</li>
        <li>New Year's Day, January 1st (possibly moved to Monday if
            actually on Sunday, or to Friday if on Saturday)</li>
        <li>Martin Luther King's birthday, third Monday in January (since
            1983)</li>
        <li>Presidents' Day (a.k.a. Washington's birthday),
            third Monday in February</li>
        <li>Memorial Day, last Monday in May</li>
        <li>Juneteenth, June 19th (moved to Monday if Sunday or
            Friday if Saturday)</li>
        <li>Independence Day, July 4th (moved to Monday if Sunday or
            Friday if Saturday)</li>
        <li>Labor Day, first Monday in September</li>
        <li>Columbus Day, second Monday in October</li>
        <li>Veterans' Day, November 11th (moved to Monday if Sunday or
            Friday if Saturday)</li>
        <li>Thanksgiving Day, fourth Thursday in November</li>
        <li>Christmas, December 25th (moved to Monday if Sunday or Friday
            if Saturday)</li>
        </ul>

        Note that since 2015 Independence Day only impacts Libor if it
        falls on a  weekday (see <https://www.theice.com/iba/libor>,
        <https://www.theice.com/marketdata/reports/170> and
        <https://www.theice.com/publicdocs/LIBOR_Holiday_Calendar_2015.pdf>
        for the fixing and value date calendars).

        Holidays for the stock exchange (data from http://www.nyse.com):
        <ul>
        <li>Saturdays</li>
        <li>Sundays</li>
        <li>New Year's Day, January 1st (possibly moved to Monday if
            actually on Sunday)</li>
        <li>Martin Luther King's birthday, third Monday in January (since
            1998)</li>
        <li>Presidents' Day (a.k.a. Washington's birthday),
            third Monday in February</li>
        <li>Good Friday</li>
        <li>Memorial Day, last Monday in May</li>
        <li>Independence Day, July 4th (moved to Monday if Sunday or
            Friday if Saturday)</li>
        <li>Labor Day, first Monday in September</li>
        <li>Thanksgiving Day, fourth Thursday in November</li>
        <li>Presidential election day, first Tuesday in November of election
            years (until 1980)</li>
        <li>Christmas, December 25th (moved to Monday if Sunday or Friday
            if Saturday)</li>
        <li>Special historic closings (see
            http://www.nyse.com/pdfs/closings.pdf)</li>
        </ul>

        Holidays for the government bond market (data from
        http://www.bondmarkets.com):
        <ul>
        <li>Saturdays</li>
        <li>Sundays</li>
        <li>New Year's Day, January 1st (possibly moved to Monday if
            actually on Sunday)</li>
        <li>Martin Luther King's birthday, third Monday in January (since
            1983)</li>
        <li>Presidents' Day (a.k.a. Washington's birthday),
            third Monday in February</li>
        <li>Good Friday</li>
        <li>Memorial Day, last Monday in May</li>
        <li>Independence Day, July 4th (moved to Monday if Sunday or
            Friday if Saturday)</li>
        <li>Labor Day, first Monday in September</li>
        <li>Columbus Day, second Monday in October</li>
        <li>Veterans' Day, November 11th (moved to Monday if Sunday or
            Friday if Saturday)</li>
        <li>Thanksgiving Day, fourth Thursday in November</li>
        <li>Christmas, December 25th (moved to Monday if Sunday or Friday
            if Saturday)</li>
        </ul>

        Holidays for the North American Energy Reliability Council
        (data from http://www.nerc.com/~oc/offpeaks.html):
        <ul>
        <li>Saturdays</li>
        <li>Sundays</li>
        <li>New Year's Day, January 1st (possibly moved to Monday if
            actually on Sunday)</li>
        <li>Memorial Day, last Monday in May</li>
        <li>Independence Day, July 4th (moved to Monday if Sunday)</li>
        <li>Labor Day, first Monday in September</li>
        <li>Thanksgiving Day, fourth Thursday in November</li>
        <li>Christmas, December 25th (moved to Monday if Sunday)</li>
        </ul>

        \ingroup calendars

        \test the correctness of the returned results is tested
              against a list of known holidays.
    */
    class UnitedStates : public Calendar {
      private:
        class SettlementImpl : public Calendar::WesternImpl {
          public:
            std::string name() const override { return "US settlement"; }
            bool isBusinessDay(const Date&) const override;
        };
        class LiborImpactImpl : public SettlementImpl {
          public:
            std::string name() const override { return "US with Libor impact"; }
            bool isBusinessDay(const Date&) const override;
        };
        class NyseImpl : public Calendar::WesternImpl {
          public:
            std::string name() const override { return "New York stock exchange"; }
            bool isBusinessDay(const Date&) const override;
        };
        class GovernmentBondImpl : public Calendar::WesternImpl {
          public:
            std::string name() const override { return "US government bond market"; }
            bool isBusinessDay(const Date&) const override;
        };
        class NercImpl : public Calendar::WesternImpl {
          public:
            std::string name() const override {
                return "North American Energy Reliability Council";
            }
            bool isBusinessDay(const Date&) const override;
        };
        class FederalReserveImpl : public Calendar::WesternImpl {
          public:
            std::string name() const override { return "Federal Reserve Bankwire System"; }
            bool isBusinessDay(const Date&) const override;
        };
      public:
        //! US calendars
        enum Market { Settlement,     //!< generic settlement calendar
                      NYSE,           //!< New York stock exchange calendar
                      GovernmentBond, //!< government-bond calendar
                      NERC,           //!< off-peak days for NERC
                      LiborImpact,    //!< Libor impact calendar
                      FederalReserve  //!< Federal Reserve Bankwire System
        };
        UnitedStates(Market market = Settlement);
    };

    // implementation

    namespace {

        // a few rules used by multiple calendars

        inline bool isWashingtonBirthday(Day d, Month m, Year y, Weekday w) {
            if (y >= 1971) {
                // third Monday in February
                return (d >= 15 && d <= 21) && w == Monday && m == February;
            } else {
                // February 22nd, possily adjusted
                return (d == 22 || (d == 23 && w == Monday)
                        || (d == 21 && w == Friday)) && m == February;
            }
        }

        inline bool isMemorialDay(Day d, Month m, Year y, Weekday w) {
            if (y >= 1971) {
                // last Monday in May
                return d >= 25 && w == Monday && m == May;
            } else {
                // May 30th, possibly adjusted
                return (d == 30 || (d == 31 && w == Monday)
                        || (d == 29 && w == Friday)) && m == May;
            }
        }

        inline bool isLaborDay(Day d, Month m, Year y, Weekday w) {
            // first Monday in September
            return d <= 7 && w == Monday && m == September;
        }

        inline bool isColumbusDay(Day d, Month m, Year y, Weekday w) {
            // second Monday in October
            return (d >= 8 && d <= 14) && w == Monday && m == October
                && y >= 1971;
        }

        inline bool isVeteransDay(Day d, Month m, Year y, Weekday w) {
            if (y <= 1970 || y >= 1978) {
                // November 11th, adjusted
                return (d == 11 || (d == 12 && w == Monday) ||
                        (d == 10 && w == Friday)) && m == November;
            } else {
                // fourth Monday in October
                return (d >= 22 && d <= 28) && w == Monday && m == October;
            }
        }

        inline bool isVeteransDayNoSaturday(Day d, Month m, Year y, Weekday w) {
            if (y <= 1970 || y >= 1978) {
                // November 11th, adjusted, but no Saturday to Friday
                return (d == 11 || (d == 12 && w == Monday)) && m == November;
            } else {
                // fourth Monday in October
                return (d >= 22 && d <= 28) && w == Monday && m == October;
            }
        }

        inline bool isJuneteenth(Day d, Month m, Year y, Weekday w) {
            // declared in 2021, but only observed by exchanges since 2022
            return (d == 19 || (d == 20 && w == Monday) || (d == 18 && w == Friday))
                && m == June && y >= 2022;
        }

    }

    inline UnitedStates::UnitedStates(UnitedStates::Market market) {
        // all calendar instances on the same market share the same
        // implementation instance
        static ext::shared_ptr<Calendar::Impl> settlementImpl(
                                        new UnitedStates::SettlementImpl);
        static ext::shared_ptr<Calendar::Impl> liborImpactImpl(
                                        new UnitedStates::LiborImpactImpl);
        static ext::shared_ptr<Calendar::Impl> nyseImpl(
                                        new UnitedStates::NyseImpl);
        static ext::shared_ptr<Calendar::Impl> governmentImpl(
                                        new UnitedStates::GovernmentBondImpl);
        static ext::shared_ptr<Calendar::Impl> nercImpl(
                                        new UnitedStates::NercImpl);
        static ext::shared_ptr<Calendar::Impl> federalReserveImpl(
                                        new UnitedStates::FederalReserveImpl);
        switch (market) {
          case Settlement:
            impl_ = settlementImpl;
            break;
          case LiborImpact:
            impl_ = liborImpactImpl;
            break;
          case NYSE:
            impl_ = nyseImpl;
            break;
          case GovernmentBond:
            impl_ = governmentImpl;
            break;
          case NERC:
            impl_ = nercImpl;
            break;
          case FederalReserve:
            impl_ = federalReserveImpl;
            break;
          default:
            QL_FAIL("unknown market");
        }
    }


    inline bool UnitedStates::SettlementImpl::isBusinessDay(const Date& date) const {
        Weekday w = date.weekday();
        Day d = date.dayOfMonth();
        Month m = date.month();
        Year y = date.year();
        if (isWeekend(w)
            // New Year's Day (possibly moved to Monday if on Sunday)
            || ((d == 1 || (d == 2 && w == Monday)) && m == January)
            // (or to Friday if on Saturday)
            || (d == 31 && w == Friday && m == December)
            // Martin Luther King's birthday (third Monday in January)
            || ((d >= 15 && d <= 21) && w == Monday && m == January
                && y >= 1983)
            // Washington's birthday (third Monday in February)
            || isWashingtonBirthday(d, m, y, w)
            // Memorial Day (last Monday in May)
            || isMemorialDay(d, m, y, w)
            // Juneteenth (Monday if Sunday or Friday if Saturday)
            || isJuneteenth(d, m, y, w)
            // Independence Day (Monday if Sunday or Friday if Saturday)
            || ((d == 4 || (d == 5 && w == Monday) ||
                 (d == 3 && w == Friday)) && m == July)
            // Labor Day (first Monday in September)
            || isLaborDay(d, m, y, w)
            // Columbus Day (second Monday in October)
            || isColumbusDay(d, m, y, w)
            // Veteran's Day (Monday if Sunday or Friday if Saturday)
            || isVeteransDay(d, m, y, w)
            // Thanksgiving Day (fourth Thursday in November)
            || ((d >= 22 && d <= 28) && w == Thursday && m == November)
            // Christmas (Monday if Sunday or Friday if Saturday)
            || ((d == 25 || (d == 26 && w == Monday) ||
                 (d == 24 && w == Friday)) && m == December))
            return false;
        return true;
    }

    inline bool UnitedStates::LiborImpactImpl::isBusinessDay(const Date& date) const {
        // Since 2015 Independence Day only impacts Libor if it falls
        // on a weekday
        Weekday w = date.weekday();
        Day d = date.dayOfMonth();
        Month m = date.month();
        Year y = date.year();
        if (((d == 5 && w == Monday) ||
            (d == 3 && w == Friday)) && m == July && y >= 2015)
            return true;
        return SettlementImpl::isBusinessDay(date);
    }

    inline bool UnitedStates::NyseImpl::isBusinessDay(const Date& date) const {
        Weekday w = date.weekday();
        Day d = date.dayOfMonth(), dd = date.dayOfYear();
        Month m = date.month();
        Year y = date.year();
        Day em = easterMonday(y);
        if (isWeekend(w)
            // New Year's Day (possibly moved to Monday if on Sunday)
            || ((d == 1 || (d == 2 && w == Monday)) && m == January)
            // Washington's birthday (third Monday in February)
            || isWashingtonBirthday(d, m, y, w)
            // Good Friday
            || (dd == em-3)
            // Memorial Day (last Monday in May)
            || isMemorialDay(d, m, y, w)
            // Juneteenth (Monday if Sunday or Friday if Saturday)
            || isJuneteenth(d, m, y, w)
            // Independence Day (Monday if Sunday or Friday if Saturday)
            || ((d == 4 || (d == 5 && w == Monday) ||
                 (d == 3 && w == Friday)) && m == July)
            // Labor Day (first Monday in September)
            || isLaborDay(d, m, y, w)
            // Thanksgiving Day (fourth Thursday in November)
            || ((d >= 22 && d <= 28) && w == Thursday && m == November)
            // Christmas (Monday if Sunday or Friday if Saturday)
            || ((d == 25 || (d == 26 && w == Monday) ||
                 (d == 24 && w == Friday)) && m == December)
            ) return false;

        if (y >= 1998 && (d >= 15 && d <= 21) && w == Monday && m == January)
            // Martin Luther King's birthday (third Monday in January)
            return false;

        if ((y <= 1968 || (y <= 1980 && y % 4 == 0)) && m == November
            && d <= 7 && w == Tuesday)
            // Presidential election days
            return false;

        // Special closings
        if (// President Bush's Funeral
            (y == 2018 && m == December && d == 5)
            // Hurricane Sandy
            || (y == 2012 && m == October && (d == 29 || d == 30))
            // President Ford's funeral
            || (y == 2007 && m == January && d == 2)
            // President Reagan's funeral
            || (y == 2004 && m == June && d == 11)
            // September 11-14, 2001
            || (y == 2001 && m == September && (11 <= d && d <= 14))
            // President Nixon's funeral
            || (y == 1994 && m == April && d == 27)
            // Hurricane Gloria
            || (y == 1985 && m == September && d == 27)
            // 1977 Blackout
            || (y == 1977 && m == July && d == 14)
            // Funeral of former President Lyndon B. Johnson.
            || (y == 1973 && m == January && d == 25)
            // Funeral of former President Harry S. Truman
            || (y == 1972 && m == December && d == 28)
            // National Day of Participation for the lunar exploration.
            || (y == 1969 && m == July && d == 21)
            // Funeral of former President Eisenhower.
            || (y == 1969 && m == March && d == 31)
            // Closed all day - heavy snow.
            || (y == 1969 && m == February && d == 10)
            // Day after Independence Day.
            || (y == 1968 && m == July && d == 5)
            // June 12-Dec. 31, 1968
            // Four day week (closed on Wednesdays) - Paperwork Crisis
            || (y == 1968 && dd >= 163 && w == Wednesday)
            // Day of mourning for Martin Luther King Jr.
            || (y == 1968 && m == April && d == 9)
            // Funeral of President Kennedy
            || (y == 1963 && m == November && d == 25)
            // Day before Decoration Day
            || (y == 1961 && m == May && d == 29)
            // Day after Christmas
            || (y == 1958 && m == December && d == 26)
            // Christmas Eve
            || ((y == 1954 || y == 1956 || y == 1965)
                && m == December && d == 24)
            ) return false;

        return true;
    }


    inline bool UnitedStates::GovernmentBondImpl::isBusinessDay(const Date& date)
                                                                      const {
        Weekday w = date.weekday();
        Day d = date.dayOfMonth(), dd = date.dayOfYear();
        Month m = date.month();
        Year y = date.year();
        Day em = easterMonday(y);
        if (isWeekend(w)
            // New Year's Day (possibly moved to Monday if on Sunday)
            || ((d == 1 || (d == 2 && w == Monday)) && m == January)
            // Martin Luther King's birthday (third Monday in January)
            || ((d >= 15 && d <= 21) && w == Monday && m == January
                && y >= 1983)
            // Washington's birthday (third Monday in February)
            || isWashingtonBirthday(d, m, y, w)
            // Good Friday (2015 was half day due to NFP report)
            || (dd == em-3 && y != 2015)
            // Memorial Day (last Monday in May)
            || isMemorialDay(d, m, y, w)
            // Juneteenth (Monday if Sunday or Friday if Saturday)
            || isJuneteenth(d, m, y, w)
            // Independence Day (Monday if Sunday or Friday if Saturday)
            || ((d == 4 || (d == 5 && w == Monday) ||
                 (d == 3 && w == Friday)) && m == July)
            // Labor Day (first Monday in September)
            || isLaborDay(d, m, y, w)
            // Columbus Day (second Monday in October)
            || isColumbusDay(d, m, y, w)
            // Veteran's Day (Monday if Sunday)
            || isVeteransDay(d, m, y, w)
            // Thanksgiving Day (fourth Thursday in November)
            || ((d >= 22 && d <= 28) && w == Thursday && m == November)
            // Christmas (Monday if Sunday or Friday if Saturday)
            || ((d == 25 || (d == 26 && w == Monday) ||
                 (d == 24 && w == Friday)) && m == December))
            return false;

        // Special closings
        if (// President Bush's Funeral
            (y == 2018 && m == December && d == 5)
            // Hurricane Sandy
            || (y == 2012 && m == October && (d == 30))
            // President Reagan's funeral
            || (y == 2004 && m == June && d == 11)
            ) return false;

        return true;
    }


    inline bool UnitedStates::NercImpl::isBusinessDay(const Date& date) const {
        Weekday w = date.weekday();
        Day d = date.dayOfMonth();
        Month m = date.month();
        Year y = date.year();
        if (isWeekend(w)
            // New Year's Day (possibly moved to Monday if on Sunday)
            || ((d == 1 || (d == 2 && w == Monday)) && m == January)
            // Memorial Day (last Monday in May)
            || isMemorialDay(d, m, y, w)
            // Independence Day (Monday if Sunday)
            || ((d == 4 || (d == 5 && w == Monday)) && m == July)
            // Labor Day (first Monday in September)
            || isLaborDay(d, m, y, w)
            // Thanksgiving Day (fourth Thursday in November)
            || ((d >= 22 && d <= 28) && w == Thursday && m == November)
            // Christmas (Monday if Sunday)
            || ((d == 25 || (d == 26 && w == Monday)) && m == December))
            return false;
        return true;
    }


    inline bool UnitedStates::FederalReserveImpl::isBusinessDay(const Date& date) const {
        // see https://www.frbservices.org/holidayschedules/ for details
        Weekday w = date.weekday();
        Day d = date.dayOfMonth();
        Month m = date.month();
        Year y = date.year();
        if (isWeekend(w)
            // New Year's Day (possibly moved to Monday if on Sunday)
            || ((d == 1 || (d == 2 && w == Monday)) && m == January)
            // Martin Luther King's birthday (third Monday in January)
            || ((d >= 15 && d <= 21) && w == Monday && m == January
                && y >= 1983)
            // Washington's birthday (third Monday in February)
            || isWashingtonBirthday(d, m, y, w)
            // Memorial Day (last Monday in May)
            || isMemorialDay(d, m, y, w)
            // Juneteenth (Monday if Sunday or Friday if Saturday)
            || isJuneteenth(d, m, y, w)
            // Independence Day (Monday if Sunday)
            || ((d == 4 || (d == 5 && w == Monday)) && m == July)
            // Labor Day (first Monday in September)
            || isLaborDay(d, m, y, w)
            // Columbus Day (second Monday in October)
            || isColumbusDay(d, m, y, w)
            // Veteran's Day (Monday if Sunday)
            || isVeteransDayNoSaturday(d, m, y, w)
            // Thanksgiving Day (fourth Thursday in November)
            || ((d >= 22 && d <= 28) && w == Thursday && m == November)
            // Christmas (Monday if Sunday)
            || ((d == 25 || (d == 26 && w == Monday)) && m == December))
            return false; // NOLINT(readability-simplify-boolean-expr)
        return true;
    }

}

#endif
