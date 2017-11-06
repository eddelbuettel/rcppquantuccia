## RcppQuantuccia  [![Build Status](https://travis-ci.org/eddelbuettel/rcppquantuccia.svg)](https://travis-ci.org/eddelbuettel/rcppquantuccia) [![License](https://eddelbuettel.github.io/badges/GPL2+.svg)](http://www.gnu.org/licenses/gpl-2.0.html) [![CRAN](http://www.r-pkg.org/badges/version/RcppQuantuccia)](https://cran.r-project.org/package=RcppQuantuccia) [![Downloads](http://cranlogs.r-pkg.org/badges/RcppQuantuccia?color=brightgreen)](http://www.r-pkg.org/pkg/RcppQuantuccia)

### About

[Quantuccia](https://github.com/pcaspers/Quantuccia) is the _"little sister"_ of
[QuantLib](https://github.com/lballabio/quantlib): A header-only subset of which aims to provide the
essential parts of [QuantLib](https://github.com/lballabio/quantlib) while being easier to deploy
requiring only [Boost](http://www.boost.org) headers besides itself.

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

### Status

Still fairly new. Functional but _e.g._ several of the other QuantLib calendars still need to be ported.

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

### Authors

Dirk Eddelbuettel

### License

GPL (>= 2)
