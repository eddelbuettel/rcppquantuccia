// -*- mode: C++; c-indent-level: 4; c-basic-offset: 4; indent-tabs-mode: nil; -*-
//
//  RQuantLib -- R interface to the QuantLib libraries
//
//  Copyright (C) 2002 - 2014  Dirk Eddelbuettel <edd@debian.org>
//
//  This file is part of RQuantLib.
//
//  RQuantLib is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 2 of the License, or
//  (at your option) any later version.
//
//  RQuantLib is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with RQuantLib.  If not, see <http://www.gnu.org/licenses/>.

// #include <rquantlib.h>

// the actual implementation is now in this header which is also pulled into
// compilation units when using 'plugin' mode via Rcpp Attributes
// #include <rquantlib_impl.h>

// [[Rcpp::interfaces(r, cpp)]]

#include "RcppQuantuccia_types.h"

// using namespace QuantLib;
namespace ql = QuantLib;

static const unsigned int QLtoJan1970Offset = 25569;

// [[Rcpp::export]]
void advanceDemo(Rcpp::Date rd) {
    ql::TARGET cal1;
    ql::UnitedStates cal2;    
    ql::Date d(static_cast<int>(rd.getDate() + QLtoJan1970Offset));
    Rcpp::Rcout << d << " " << cal1.adjust(d) << " " << cal2.adjust(d) << std::endl;
}




