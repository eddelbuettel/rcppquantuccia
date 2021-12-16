## RcppQuantuccia: Rcpp bindings for QuantLib Calendering

[![CI](https://github.com/eddelbuettel/rcppquantuccia/workflows/ci/badge.svg)](https://github.com/eddelbuettel/rcppquantuccia/actions?query=workflow%3Aci)
[![License](https://eddelbuettel.github.io/badges/GPL2+.svg)](http://www.gnu.org/licenses/gpl-2.0.html)
[![CRAN](https://www.r-pkg.org/badges/version/RcppQuantuccia)](https://cran.r-project.org/package=RcppQuantuccia)
[![Dependencies](https://tinyverse.netlify.com/badge/RcppQuantuccia)](https://cran.r-project.org/package=RcppQuantuccia)
[![Downloads](https://cranlogs.r-pkg.org/badges/RcppQuantuccia?color=brightgreen)](https://www.r-pkg.org/pkg/RcppQuantuccia)
[![Last Commit](https://img.shields.io/github/last-commit/eddelbuettel/rcppquantuccia)](https://github.com/eddelbuettel/rcppquantuccia)

### Status

Access to current calendaring functions from QuantLib in an easy-to-build smaller package.

As of release 0.1.0, all code is current to the current QuantLib release 1.24 (modulo a [small patch set](https://github.com/eddelbuettel/rcppquantuccia/blob/master/local/changes_from_quantlib_1.24.diff)). All of
the upstream, _i.e._ QuantLib, calendars are implemented as are the key access functions.

However, as [Quantuccia](https://github.com/pcaspers/Quantuccia) upstream is stale, we now *continue all future work in the [qlcal](https://github.com/qlcal) organization on GitHub and its [qlcal-r](https://github.com/qlcal/qlcal-r) repo* with the [qlcal R package](https://cran.r-project.org/package=qlcal) now also on CRAN.  So this repository here will likely **not** see any future work.

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
upstream repo.  However, the idea of only relying on Boost headers is brilliant and carried on here.)

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

As all calendars are now supported (and are listed in a convenience vector `calendars`):

```r
> library(RcppQuantuccia)
> calendars
 [1] "TARGET"                         "UnitedStates"
 [3] "UnitedStates/LiborImpact"       "UnitedStates/NYSE"
 [5] "UnitedStates/GovernmentBond"    "UnitedStates/NERC"
 [7] "UnitedStates/FederalReserve"    "Argentina"
 [9] "Australia"                      "Austria"
[11] "Austria/Exchange"               "Bespoke"
[13] "Botswana"                       "Brazil"
[15] "Brazil/Exchange"                "Canada"
[17] "Canada/TSX"                     "Chile"
[19] "China"                          "China/IB"
[21] "CzechRepublic"                  "Denmark"
[23] "Finland"                        "France"
[25] "France/Exchange"                "Germany"
[27] "Germany/FrankfurtStockExchange" "Germany/Xetra"
[29] "Germany/Eurex"                  "Germany/Euwax"
[31] "HongKong"                       "Hungary"
[33] "Iceland"                        "India"
[35] "Indonesia"                      "Israel"
[37] "Italy"                          "Italy/Exchange"
[39] "Japan"                          "Mexico"
[41] "NewZealand"                     "Norway"
[43] "Null"                           "Poland"
[45] "Romania"                        "Russia"
[47] "SaudiArabia"                    "Singapore"
[49] "Slovakia"                       "SouthAfrica"
[51] "SouthKorea"                     "SouthKorea/KRX"
[53] "Sweden"                         "Switzerland"
[55] "Taiwan"                         "Thailand"
[57] "Turkey"                         "Ukraine"
[59] "UnitedKingdom"                  "UnitedKingdom/Exchange"
[61] "UnitedKingdom/Metals"           "WeekendsOnly"
>

 We can then for example quickly count number of holiday per calendar (by computing the length of the returned
vector of holidays) and show a shortened print, all in a handful of lines continuing from above

```r
> getHols <- function(cal) {    # simple helper function
+    setCalendar(cal)
+    getHolidays(as.Date("2022-01-01"), as.Date("2022-12-31"))
+ }
> D <- data.table(calendar=calendars)
> D[ , `:=`(n = length(getHols(calendar)),
+           holidays = paste(format(getHols(calendar),"%d %b"), collapse=",")),
+    by = calendar ]
> D
> D
                       calendar  n                                                                     holidays
 1:                      TARGET  3                                                         15 Apr,18 Apr,26 Dec
 2:                UnitedStates 10        17 Jan,21 Feb,30 May,20 Jun,04 Jul,05 Sep,10 Oct,11 Nov,24 Nov,26 Dec
 3:    UnitedStates/LiborImpact 10        17 Jan,21 Feb,30 May,20 Jun,04 Jul,05 Sep,10 Oct,11 Nov,24 Nov,26 Dec
 4:           UnitedStates/NYSE  9               17 Jan,21 Feb,15 Apr,30 May,20 Jun,04 Jul,05 Sep,24 Nov,26 Dec
 5: UnitedStates/GovernmentBond 11 17 Jan,21 Feb,15 Apr,30 May,20 Jun,04 Jul,05 Sep,10 Oct,11 Nov,24 Nov,26 Dec
---
58:                     Ukraine 10        03 Jan,07 Jan,08 Mar,25 Apr,02 May,09 May,13 Jun,28 Jun,24 Aug,14 Oct
59:               UnitedKingdom  9               03 Jan,15 Apr,18 Apr,02 May,02 Jun,03 Jun,29 Aug,26 Dec,27 Dec
60:      UnitedKingdom/Exchange  9               03 Jan,15 Apr,18 Apr,02 May,02 Jun,03 Jun,29 Aug,26 Dec,27 Dec
61:        UnitedKingdom/Metals  9               03 Jan,15 Apr,18 Apr,02 May,02 Jun,03 Jun,29 Aug,26 Dec,27 Dec
62:                WeekendsOnly  0
>
```

Here we set the year to 2022 as it includes the added US holiday of Juneteenth.

We can also access the calendar 'name' from the underlying (QuantLib Calendar) object:

```r
> D[, name := { setCalendar(calendar); getName() }, by=calendar][, .(calendar,name)]
                       calendar                      name
 1:                      TARGET                    TARGET
 2:                UnitedStates             US settlement
 3:    UnitedStates/LiborImpact      US with Libor impact
 4:           UnitedStates/NYSE   New York stock exchange
 5: UnitedStates/GovernmentBond US government bond market
---
58:                     Ukraine  Ukrainian stock exchange
59:               UnitedKingdom             UK settlement
60:      UnitedKingdom/Exchange     London stock exchange
61:        UnitedKingdom/Metals    London metals exchange
62:                WeekendsOnly             weekends only
>
```


### A Smaller Subset

As of version 0.0.3, we exclude the 7.6 mb header file `sobolrsg.hpp`, and well as references to it
including the model subdirectory using the Sobol-based Brownian Market Models.  This shrinks the
resulting shared library from around 26 mb (!!) to 0.64 mb, and the (compressed) source tarball from
1.6 mb to 0.24 mb.

As of version 0.0.5, the focus is _strictly_ on calendaring.

As of version 0.1.0, QuantLib files are included 'as is' (no longer converted to header-only as Quantuccia did)
with a small ([documented in a diff](https://github.com/eddelbuettel/rcppquantuccia/blob/master/local/changes_from_quantlib_1.24.diff)) set of changes essentially commenting
out headers we no longer need and removed from some of the utilities directories, and turning off pragma instructions
we are not allowed to use at CRAN.

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

Dirk Eddelbuettel for the package and integration

The authors and contributors of QuantLib for the underlying calendaring code

### License

GPL (>= 2)
