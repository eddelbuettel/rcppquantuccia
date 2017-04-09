// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
//  RcppQuantuccia -- R interface to QuantLib via Quantuccia
//
//  Copyright (C) 2002 - 2017  Dirk Eddelbuettel <edd@debian.org>
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

namespace ql = QuantLib;

RcppQuantuccia::CalendarContainer gblcal;

// / /  [ [Rcpp::export]]
// void advanceDemo(Rcpp::Date rd) {
//     ql::TARGET cal1;
//     ql::UnitedStates cal2;
//     ql::Date d(static_cast<int>(rd.getDate() + Rcpp::getQLtoJan1970offset()));
//     Rcpp::Rcout << d << " " << cal1.adjust(d) << " " << cal2.adjust(d) << std::endl;
// }

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
    for (auto i=0; i<n; i++) {
        ql::Date d = Rcpp::as<ql::Date>(dates[i]);
        bizdays[i] = cal.isBusinessDay(d);
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
    for (auto i=0; i<n; i++) {
        ql::Date d = Rcpp::as<ql::Date>(dates[i]);
        holdays[i] = cal.isBusinessDay(d);
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
    for (auto i=0; i<n; i++) {
        ql::Date d = Rcpp::as<ql::Date>(dates[i]);
        weekends[i] = cal.isWeekend(d.weekday());
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
    for (auto i=0; i<n; i++) {
        ql::Date d = Rcpp::as<ql::Date>(dates[i]);
        eom[i] = cal.isEndOfMonth(d);
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
    for (auto i=0; i<n; i++) {
        ql::Date d = Rcpp::as<ql::Date>(dates[i]);
        ndates[i] = Rcpp::qlDate2Rcpp(cal.endOfMonth(d));
    }
    return ndates;
}


//' Adjust a vector of following a business-day convention
//'
//' This function takes a vector of dates and returns another vector of dates
//' of the same length returning at each position the adjusted date according
//' to the selected business-day convention matching the existing QuantLib
//' enumeration type. Currently supported values are (starting from zero):
//' \sQuote{Following}, \sQuote{ModifiedFollowing}, \sQuote{Preceding},
//' \sQuote{ModifiedPreceding}, \sQuote{Unadjusted}, \sQuote{HalfModifiedFollowing}
//' \sQuote{Nearest} and a fallback of \sQuote{Unadjusted} for all other value.
//'
//' @title Compute adjusted dates
//' @param dates A Date vector with dates
//' @param bdc An integer corresponding to the business-day convetion
//' @return A Date vector with dates adjust according to business-day convention
//' @examples
//' getEndOfMonth(Sys.Date()+0:6)
// [[Rcpp::export]]
Rcpp::DateVector adjust(Rcpp::DateVector dates, int bdc=0) {
    ql::Calendar cal = gblcal.getCalendar();
    QuantLib::BusinessDayConvention bdcval = getBusinessDayConvention(bdc);
    int n = dates.size();
    Rcpp::DateVector adjusted(n);
    for (auto i=0; i<n; i++) {
        ql::Date d = Rcpp::as<ql::Date>(dates[i]);
        adjusted[i] = Rcpp::qlDate2Rcpp(cal.adjust(d, bdcval));
    }
    return adjusted;
}
