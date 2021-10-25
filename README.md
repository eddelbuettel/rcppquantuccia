## RcppQuantuccia: Rcpp bindings for QuantLib Calendering

[![CI](https://github.com/eddelbuettel/rcppquantuccia/workflows/ci/badge.svg)](https://github.com/eddelbuettel/rcppquantuccia/actions?query=workflow%3Aci)
[![License](https://eddelbuettel.github.io/badges/GPL2+.svg)](http://www.gnu.org/licenses/gpl-2.0.html)
[![CRAN](https://www.r-pkg.org/badges/version/RcppQuantuccia)](https://cran.r-project.org/package=RcppQuantuccia)
[![Dependencies](https://tinyverse.netlify.com/badge/RcppQuantuccia)](https://cran.r-project.org/package=RcppQuantuccia)
[![Downloads](https://cranlogs.r-pkg.org/badges/RcppQuantuccia?color=brightgreen)](https://www.r-pkg.org/pkg/RcppQuantuccia)
[![Last Commit](https://img.shields.io/github/last-commit/eddelbuettel/rcppquantuccia)](https://github.com/eddelbuettel/rcppquantuccia)

### Status

Access to current calendaring functions from QuantLib in an easy-to-build smaller package.

All code is current to the current QuantLib release 1.24 (modulo small patches). All of
the calendars are implemented.

### Brief History

This package started as an integration of the (somewhat experimental)
[Quantuccia](https://github.com/pcaspers/Quantuccia) package (see next section) to R by means of Rcpp.

But [Quantuccia](https://github.com/pcaspers/Quantuccia) did not continue beyond its initial proof
of concept. As of release 0.0.5, we have now refocused it on an _even smaller subset_ of
[QuantLib](https://github.com/lballabio/quantlib): just the calendaring.  So code for pricers, math,
models, schedules, ... that was in [Quantuccia](https://github.com/pcaspers/Quantuccia) has been
removed.

But the calendaring, along with all its support code, is now current with the current
[QuantLib](https://github.com/lballabio/quantlib) release which, as of this writing, is 1.24.

### So what is Quantuccia?

[Quantuccia](https://github.com/pcaspers/Quantuccia) is the _"little sister"_ of
[QuantLib](https://github.com/lballabio/quantlib): A header-only subset of which aims to provide the
essential parts of [QuantLib](https://github.com/lballabio/quantlib) while being easier to deploy
requiring only [Boost](https://www.boost.org) headers besides itself.  (Note that
[Quantuccia](https://github.com/pcaspers/Quantuccia) appears to no longer being developed in its
upstream repo.  However, the idea of only relying on Boost headers is brillian and carried on here.)

Being header-only makes providing [Quantuccia](https://github.com/pcaspers/Quantuccia) for
[R](https://www.r-project.org) a breeze as we can rely on the
[Rcpp](http://dirk.eddelbuettel.com/code/rcpp.html) and
[BH](http://dirk.eddelbuettel.com/code/bh.html) packages.  Nothing else is required, and as these
packages are available on all relevant platforms, deploying RcppQuantuccia is straightforward.

### Example

Here we examine holiday lists for given calendars, specified by country and possibly exchange:

```r
R> library(RcppQuantuccia)
R> fromD <- as.Date("2017-01-01")
R> toD <- as.Date("2017-12-31")
R> getHolidays(fromD, toD)        # default calender ie TARGET
[1] "2017-04-14" "2017-04-17" "2017-05-01" "2017-12-25" "2017-12-26"
R> setCalendar("UnitedStates")
R> getHolidays(fromD, toD)        # US aka US::Settlement
[1] "2017-01-02" "2017-01-16" "2017-02-20" "2017-05-29" "2017-07-04" "2017-09-04"
[7] "2017-10-09" "2017-11-10" "2017-11-23" "2017-12-25"
R> setCalendar("UnitedStates::NYSE")
R> getHolidays(fromD, toD)        # US New York Stock Exchange
[1] "2017-01-02" "2017-01-16" "2017-02-20" "2017-04-14" "2017-05-29" "2017-07-04"
[7] "2017-09-04" "2017-11-23" "2017-12-25"
R>
```

This shows the difference between the default US settlement calendar and the NYSE calendar
which we selected explicitly.

As all calendars are now supported (and are listed in a convenience vector `calendars`) we can now
for example quickly count number of holiday per calendar (by computing the length of the returned
vector of holidays):

```r
> library(RcppQuantuccia)
> calendars
 [1] "TARGET"                         "UnitedStates"                   "UnitedStates/LiborImpact"
 [4] "UnitedStates/NYSE"              "UnitedStates/GovernmentBond"    "UnitedStates/NERC"
 [7] "UnitedStates/FederalReserve"    "Argentina"                      "Australia"
[10] "Austria"                        "Austria/Exchange"               "Bespoke"
[13] "Botswana"                       "Brazil"                         "Brazil/Exchange"
[16] "Canada"                         "Canada/TSX"                     "Chile"
[19] "China"                          "China/IB"                       "CzechRepublic"
[22] "Denmark"                        "Finland"                        "France"
[25] "France/Exchange"                "Germany"                        "Germany/FrankfurtStockExchange"
[28] "Germany/Xetra"                  "Germany/Eurex"                  "Germany/Euwax"
[31] "HongKong"                       "Hungary"                        "Iceland"
[34] "India"                          "Indonesia"                      "Israel"
[37] "Italy"                          "Italy/Exchange"                 "Japan"
[40] "Mexico"                         "NewZealand"                     "Norway"
[43] "Null"                           "Poland"                         "Romania"
[46] "Russia"                         "SaudiArabia"                    "Singapore"
[49] "Slovakia"                       "SouthAfrica"                    "SouthKorea"
[52] "SouthKorea/KRX"                 "Sweden"                         "Switzerland"
[55] "Taiwan"                         "Thailand"                       "Turkey"
[58] "Ukraine"                        "UnitedKingdom"                  "UnitedKingdom/Exchange"
[61] "UnitedKingdom/Metals"           "WeekendsOnly"
> nHol <- function(cal) { setCalendar(cal); length(getHolidays(as.Date("2022-01-01"), as.Date("2022-12-31"))) }
> nh <- data.frame(nh=sapply(calendars, nHol))	# sweep nHol function over calendars
> head(nh)
                            nh
TARGET                       3
UnitedStates                10
UnitedStates/LiborImpact    10
UnitedStates/NYSE            9
UnitedStates/GovernmentBond 11
UnitedStates/NERC            5
> tail(nh)
                       nh
Turkey                  8
Ukraine                10
UnitedKingdom           9
UnitedKingdom/Exchange  9
UnitedKingdom/Metals    9
WeekendsOnly            0
>
```

Here we set the year to 2022 as it includes the added US holiday of Juneteenth.

### A Smaller Subset

As of version 0.0.3, we exclude the 7.6 mb header file `sobolrsg.hpp`, and well as references to it
including the model subdirectory using the Sobol-based Brownian Market Models.  This shrinks the
resulting shared library from around 26 mb (!!) to 0.64 mb, and the (compressed) source tarball from
1.6 mb to 0.24 mb.

As of version 0.0.5, the focus is _strictly_ on calendaring.

### Installation

The package can be installed from [CRAN](https://cran.r-project.org) via

```r
install.packages("RcppQuantuccia")
```

or if you prefer non-release development version these can be installed from GitHub via e.g.

```r
remotes::install_github("eddelbuettel/rcppquantuccia")
```

or maybe just checkout the repository locally.

It only requires `Rcpp` and `BH` both of which are available whereever `R` itself runs.

### Authors

Dirk Eddelbuettel

### License

GPL (>= 2)
