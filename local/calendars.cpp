
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


// Taken from RQuantLib and adapted / simplified

// [[Rcpp::interfaces(r, cpp)]]

#include "RcppQuantuccia_types.h"

namespace ql = QuantLib;

#if 0
static ql::Calendar* defaultCalendar = new ql::TARGET;

ql::Calendar getDefaultCalendar() { return *defaultCalendar; }

ql::Calendar setCalendar(const std::string & txt) {
    if (txt == "UnitedStates") {
        free(defaultCalendar);
        defaultCalendar = new ql::UnitedStates;
    }
    return *defaultCalendar;
}
#endif
