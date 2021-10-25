
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

namespace ql = QuantLib;

ql::BusinessDayConvention getBusinessDayConvention(const int n) {
    switch (n) {
    case 0:
        return ql::Following;
        break;
    case 1:
        return ql::ModifiedFollowing;
        break;
    case 2:
        return ql::Preceding;
        break;
    case 3:
        return ql::ModifiedPreceding;
        break;
    case 4:
        return ql::Unadjusted;
        break;
    case 5:
        return ql::HalfMonthModifiedFollowing;
        break;
    case 6:
        return ql::Nearest;
        break;
    default:
        return ql::Unadjusted;
    }
}

ql::Frequency getFrequency(const int n) {
    switch (n) {
    case -1:
        return ql::NoFrequency;
        break;
    case 0:
        return ql::Once;
        break;
    case 1:
        return ql::Annual;
        break;
    case 2:
        return ql::Semiannual;
        break;
    case 3:
        return ql::EveryFourthMonth;
        break;
    case 4:
        return ql::Quarterly;
        break;
    case 6:
        return ql::Bimonthly;
        break;
    case 12:
        return ql::Monthly;
        break;
    case 13:
        return ql::EveryFourthWeek;
        break;
    case 26:
        return ql::Biweekly;
        break;
    case 52:
        return ql::Weekly;
        break;
    case 365:
        return ql::Daily;
        break;
    default:
        return ql::OtherFrequency;
    }
}

ql::TimeUnit getTimeUnit(const int n) {
    switch (n) {
    case 0:
        return ql::Days;
        break;
    case 1:
        return ql::Weeks;
        break;
    case 2:
        return ql::Months;
        break;
    case 3:
        return ql::Years;
        break;
    case 4:
        return ql::Hours;
        break;
    case 5:
        return ql::Seconds;
        break;
    case 6:
        return ql::Minutes;
        break;
    case 7:
        return ql::Milliseconds;
        break;
    case 8:
        return ql::Microseconds;
        break;
    default:
        Rcpp::stop("Wrong TimeUnit value\n");
        break;
    }
}
