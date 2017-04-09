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

namespace ql = QuantLib;

ql::BusinessDayConvention getBusinessDayConvention(const double n){
    if (n==0)
        return ql::Following;
    else if (n==1)
        return ql::ModifiedFollowing;
    else if (n==2)
        return ql::Preceding;
    else if (n==3)
        return ql::ModifiedPreceding;
    else if (n==4)
        return ql::Unadjusted;
    else if (n==5)
        return ql::HalfMonthModifiedFollowing;
    else if (n==6)
        return ql::Nearest;
    else
        return ql::Unadjusted;
}
