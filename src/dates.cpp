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


// #include <rquantlib.h>

// the actual implementation is now in this header which is also pulled into
// compilation units when using 'plugin' mode via Rcpp Attributes
// #include <rquantlib_impl.h>

// [[Rcpp::interfaces(r, cpp)]]

#include "RcppQuantuccia_types.h"
#include "RcppQuantuccia_as_wrap.h"

namespace ql = QuantLib;

RcppQuantuccia::CalendarContainer gblcal;
//ql::Calendar getDefaultCalendar();
//ql::Calendar getCalendar(const std::string &txt);

// [[Rcpp::export]]
void advanceDemo(Rcpp::Date rd) {
    ql::TARGET cal1;
    ql::UnitedStates cal2;
    ql::Date d(static_cast<int>(rd.getDate() + Rcpp::getQLtoJan1970offset()));
    Rcpp::Rcout << d << " " << cal1.adjust(d) << " " << cal2.adjust(d) << std::endl;
}

// [[Rcpp::export]]
void setCalendar(std::string calstr) {
    gblcal.setCalendar(calstr);
}

// [[Rcpp::export]]
Rcpp::Date advanceDate(Rcpp::Date rd, int days=0) { //, std::string calstr="TARGET"
    ql::Calendar cal = gblcal.getCalendar();
    ql::Date d(static_cast<int>(rd.getDate() + Rcpp::getQLtoJan1970offset()));
    ql::Date newdate = cal.adjust(d) + days;
    return Rcpp::wrap(newdate);
}

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
