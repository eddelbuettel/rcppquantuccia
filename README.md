## RcppQuantuccia  [![Build Status](https://travis-ci.org/eddelbuettel/rcppquantuccia.svg)](https://travis-ci.org/eddelbuettel/rcppquantuccia) [![License](http://img.shields.io/badge/license-GPL%20%28%3E=%202%29-brightgreen.svg?style=flat)](http://www.gnu.org/licenses/gpl-2.0.html) 

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

```
R> library(anytime)  # so that we can use anydate()
R> library(RcppQuantuccia)
R> getHolidays(anydate(20170101), anydate(20170630))
[1] "2017-04-14" "2017-04-17" "2017-05-01"
R> setCalendar("UnitedStates::NYSE")
R> getHolidays(anydate(20170101), anydate(20170630))
[1] "2017-01-02" "2017-01-16" "2017-02-20" "2017-04-14" "2017-05-29"
R> 
```

This shows the difference between the default US settlement calendar and the NYSE calendar 
which we selected explicitly.  

### Status

Still fairly new. Functional but _e.g._ several of the other QuantLib calendars still need to be ported.

### Installation

Currently from GitHub only, so do e.g.

```r
remotes::install_github("eddelbuettel/rcppquantuccia")
```

or maybe just checkout the repository locally.

### Authors

Dirk Eddelbuettel

### License

GPL (>= 2)
