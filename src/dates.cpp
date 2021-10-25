
//  RcppQuantuccia -- R interface to QuantLib via Quantuccia
//
//  Copyright (C) 2002 - 2021  Dirk Eddelbuettel <edd@debian.org>
//
//  This file is part of RcppQuantuccia
//
//  RcppQuantuccia is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 2 of the License, or
//  (at your option) any later version.
//
//  RcppQuantuccia is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with RcppQuantuccia.  If not, see <http://www.gnu.org/licenses/>.


// Taken from RQuantLib and adapted

// [[Rcpp::interfaces(r, cpp)]]

#include "RcppQuantuccia_types.h"
#include "RcppQuantuccia_declarations.h"
#include "RcppQuantuccia_as_wrap.h"

#include <boost/date_time/posix_time/conversion.hpp>


namespace ql = QuantLib;

RcppQuantuccia::CalendarContainer gblcal;

//' Set a calendar
//'
//' This function sets a calendar to the given market or country convention.
//' Note that at present only the default \sQuote{TARGET} and \sQuote{UnitedStates}
//' are supported.
//'
//' @title Set a calendar
//' @param calstr A character variable containing the market for which a calendar
//' is to be set
//' @return Nothing is returned but the global state is changed
//' @examples
//' setCalendar("UnitedStates")
// [[Rcpp::export]]
void setCalendar(std::string calstr) {
    gblcal.setCalendar(calstr);
}

//' Get calendar name or id
//'
//' This function returns the corresponding (full) name (as in the underlying
//' implementationclass) or identification string (used to select it) of the
//' current calendar.
//'
//' @title Get calendar name, or id
//' @return A string with the calendar name
//' @examples
//' getName()
// [[Rcpp::export]]
std::string getName() {
    return gblcal.getName();
}

//' @rdname getName
// [[Rcpp::export]]
std::string getId() {
    return gblcal.getId();
}


//' Advance a date to the next business day plus an optional shift
//'
//' This function takes a given date and advances it to the next business day
//' under the current (global) calendar setting. If an optional offset value is
//' given it is applied as well.
//'
//' @title Advance a date
//' @param rd A Date object describing the date to be advanced to the
//' next business day.
//' @param days An optional integer offset applied to the date
//' @return The advanced date is returned
//' @examples
//' advanceDate(Sys.Date(), 2)  # today to the next biz day, plus 2 days
// [[Rcpp::export]]
Rcpp::Date advanceDate(Rcpp::Date rd, int days=0) {
    ql::Calendar cal = gblcal.getCalendar();
    ql::Date d = Rcpp::as<ql::Date>(rd);
    ql::Date newdate = cal.adjust(d) + days;
    return Rcpp::wrap(newdate);
}

//' Test a vector of dates for business day
//'
//' This function takes a vector of dates and returns a logical vector
//' of the same length indicating at each position whether the corresponding
//' date is a business day in the currently active (global) calendar.
//'
//' @title Test for business days
//' @param dates A Date vector with dates to be examined
//' @return A logical vector indicating which dates are business days
//' @examples
//' isBusinessDay(Sys.Date()+0:6)
// [[Rcpp::export]]
Rcpp::LogicalVector isBusinessDay(Rcpp::DateVector dates) {
    ql::Calendar cal = gblcal.getCalendar();
    int n = dates.size();
    Rcpp::LogicalVector bizdays(n);
    std::vector<ql::Date> dv = Rcpp::as< std::vector<ql::Date> >(dates);
    for (auto i=0; i<n; i++) {
        bizdays[i] = cal.isBusinessDay(dv[i]);
    }
    return bizdays;
}

//' Test a vector of dates for holiday
//'
//' This function takes a vector of dates and returns a logical vector
//' of the same length indicating at each position whether the corresponding
//' date is a holiday in the currently active (global) calendar.
//'
//' @title Test for holidays
//' @param dates A Date vector with dates to be examined
//' @return A logical vector indicating which dates are holidays
//' @examples
//' isHoliday(Sys.Date()+0:6)
// [[Rcpp::export]]
Rcpp::LogicalVector isHoliday(Rcpp::DateVector dates) {
    ql::Calendar cal = gblcal.getCalendar();
    int n = dates.size();
    Rcpp::LogicalVector holdays(n);
    std::vector<ql::Date> dv = Rcpp::as< std::vector<ql::Date> >(dates);
    for (auto i=0; i<n; i++) {
        holdays[i] = cal.isBusinessDay(dv[i]);
    }
    return holdays;
}

//' Test a vector of dates for weekends
//'
//' This function takes a vector of dates and returns a logical vector
//' of the same length indicating at each position whether the corresponding
//' date is a weekend in the currently active (global) calendar.
//'
//' @title Test for weekends
//' @param dates A Date vector with dates to be examined
//' @return A logical vector indicating which dates are weekends
//' @examples
//' isWeekend(Sys.Date()+0:6)
// [[Rcpp::export]]
Rcpp::LogicalVector isWeekend(Rcpp::DateVector dates) {
    ql::Calendar cal = gblcal.getCalendar();
    int n = dates.size();
    Rcpp::LogicalVector weekends(n);
    std::vector<ql::Date> dv = Rcpp::as< std::vector<ql::Date> >(dates);
    for (auto i=0; i<n; i++) {
        weekends[i] = cal.isWeekend(dv[i].weekday());
    }
    return weekends;
}

//' Test a vector of dates for end-of-month
//'
//' This function takes a vector of dates and returns a logical vector
//' of the same length indicating at each position whether the corresponding
//' date is at the end of a month in the currently active (global) calendar.
//'
//' @title Test for end-of-month
//' @param dates A Date vector with dates to be examined
//' @return A logical vector indicating which dates are end-of-month
//' @examples
//' isEndOfMonth(Sys.Date()+0:6)
// [[Rcpp::export]]
Rcpp::LogicalVector isEndOfMonth(Rcpp::DateVector dates) {
    ql::Calendar cal = gblcal.getCalendar();
    int n = dates.size();
    Rcpp::LogicalVector eom(n);
    std::vector<ql::Date> dv = Rcpp::as< std::vector<ql::Date> >(dates);
    for (auto i=0; i<n; i++) {
        eom[i] = cal.isEndOfMonth(dv[i]);
    }
    return eom;
}


//' Compute a vector of dates with end-of-month
//'
//' This function takes a vector of dates and returns another vector of dates
//' of the same length returning at each position whether the corresponding
//' end-of-month date in the currently active (global) calendar.
//'
//' @title Compute end-of-month
//' @param dates A Date vector with dates
//' @return A Date vector with dates which are end-of-month
//' @examples
//' getEndOfMonth(Sys.Date()+0:6)
// [[Rcpp::export]]
Rcpp::DateVector getEndOfMonth(Rcpp::DateVector dates) {
    ql::Calendar cal = gblcal.getCalendar();
    int n = dates.size();
    Rcpp::DateVector ndates(n);
    std::vector<ql::Date> dv = Rcpp::as< std::vector<ql::Date> >(dates);
    for (auto i=0; i<n; i++) {
        ndates[i] = Rcpp::qlDate2Rcpp(cal.endOfMonth(dv[i]));
    }
    return ndates;
}

//' @rdname adjust
// [[Rcpp::export]]
Rcpp::DateVector adjust_cpp(Rcpp::DateVector dates, int bdc=0) {
    ql::Calendar cal = gblcal.getCalendar();
    ql::BusinessDayConvention bdcval = getBusinessDayConvention(bdc);
    int n = dates.size();
    Rcpp::DateVector adjusted(n);
    std::vector<ql::Date> dv = Rcpp::as< std::vector<ql::Date> >(dates);
    for (auto i=0; i<n; i++) {
        adjusted[i] = Rcpp::qlDate2Rcpp(cal.adjust(dv[i], bdcval));
    }
    return adjusted;
}

//' @rdname advanceUnits
// [[Rcpp::export]]
Rcpp::DateVector advanceUnits_cpp(Rcpp::DateVector dates, int n, int unit,
                                  int bdc, bool emr) {
    ql::Calendar cal = gblcal.getCalendar();
    ql::BusinessDayConvention bdc_ = getBusinessDayConvention(bdc);
    ql::TimeUnit tu = getTimeUnit(unit);
    int ndays = dates.size();
    Rcpp::DateVector adv(ndays);
    std::vector<ql::Date> odv = Rcpp::as< std::vector<ql::Date> >(dates);
    for (auto i=0; i<ndays; i++) {
        ql::Date nd = cal.advance(odv[i], n, tu, bdc_, (emr == 1) ? true : false);
        adv[i] = Rcpp::qlDate2Rcpp(nd);
    }
    return adv;
}


//' Compute the number of business days between dates
//'
//' This function takes two vectors of start and end dates and returns another
//' vector of the number of business days between each corresponding date pair
//' according to the active calendar.
//'
//' @title Compute number of business dates between calendar dates
//' @param from A Date vector with interval start dates
//' @param to A Date vector with interval end dates
//' @param includeFirst A boolean indicating if the start date is included, default
//' is \sQuote{TRUE}
//' @param includeLast A boolean indicating if the end date is included, default
//' is \sQuote{FALSE}
//' @return A numeric vector with the number of business dates between the
//' corresponding date pair
//' @examples
//' businessDaysBetween(Sys.Date() + 0:6, Sys.Date() + 3 + 0:6)
// [[Rcpp::export]]
Rcpp::NumericVector businessDaysBetween(Rcpp::DateVector from, Rcpp::DateVector to,
                                        bool includeFirst=true, bool includeLast=false) {
    ql::Calendar cal = gblcal.getCalendar();
    int n = from.size();
    Rcpp::NumericVector between(n);
    std::vector<ql::Date> fdv = Rcpp::as< std::vector<ql::Date> >(from);
    std::vector<ql::Date> tdv = Rcpp::as< std::vector<ql::Date> >(to);
    for (auto i=0; i<n; i++) {
        between[i] = cal.businessDaysBetween(fdv[i], tdv[i], includeFirst, includeLast);
    }
    return between;
}

//' Compute the number of holidays (or business days) between two dates
//'
//' This function takes a start and end date and returns a vector of holidays
//' (or business days) between them according to the active calendar.
//'
//' @title Compute holidays or business days
//' @param from A Date object with the start date
//' @param to A Date object with the end date
//' @param includeWeekends A boolean indicating if weekends should be included, default
//' is \sQuote{FALSE}
//' @return A Date vector with holidays or business days between the given dates
//' @examples
//' getHolidays(Sys.Date(), Sys.Date() + 30)
// [[Rcpp::export]]
Rcpp::DateVector getHolidays(Rcpp::Date from, Rcpp::Date to, bool includeWeekends=false) {
    ql::Calendar cal = gblcal.getCalendar();
    std::vector<ql::Date> holidays = cal.holidayList(Rcpp::as<ql::Date>(from),
                                                     Rcpp::as<ql::Date>(to), includeWeekends);
    int n = holidays.size();
    Rcpp::DateVector dv(n);
    for (auto i=0; i<n; i++) {
        dv[i] = Rcpp::qlDate2Rcpp(holidays[i]);
    }
    return dv;
}

//' @rdname getHolidays
// [[Rcpp::export]]
Rcpp::DateVector getBusinessDays(Rcpp::Date from, Rcpp::Date to) {
    ql::Calendar cal = gblcal.getCalendar();
    std::vector<ql::Date> holidays = cal.businessDayList(Rcpp::as<ql::Date>(from),
                                                         Rcpp::as<ql::Date>(to));
    int n = holidays.size();
    Rcpp::DateVector dv(n);
    for (auto i=0; i<n; i++) {
        dv[i] = Rcpp::qlDate2Rcpp(holidays[i]);
    }
    return dv;
}
