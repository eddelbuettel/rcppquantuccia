## RcppQuantuccia  [![Build Status](https://travis-ci.org/eddelbuettel/rcppquantuccia.svg)](https://travis-ci.org/eddelbuettel/rcppquantuccia) [![License](http://img.shields.io/badge/license-GPL%20%28%3E=%202%29-brightgreen.svg?style=flat)](http://www.gnu.org/licenses/gpl-2.0.html) [![CRAN](http://www.r-pkg.org/badges/version/RcppQuantuccia)](http://cran.r-project.org/package=RcppQuantuccia) [![Downloads](http://cranlogs.r-pkg.org/badges/RcppQuantuccia?color=brightgreen)](http://www.r-pkg.org/pkg/RcppQuantuccia)

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

### Status

Still fairly new.

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
