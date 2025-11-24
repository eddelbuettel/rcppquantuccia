\name{NEWS}
\title{News for Package \pkg{RcppQuantuccia}}
\newcommand{\ghpr}{\href{https://github.com/eddelbuettel/rcppquantuccia/pull/#1}{##1}}
\newcommand{\ghit}{\href{https://github.com/eddelbuettel/rcppquantuccia/issues/#1}{##1}}

\section{Changes in version 0.1.3 (2025-11-24)}{
  \itemize{
    \item A badge URL and link have been updated in README.md
    \item The continuous integration sript switched first to r-ci-setup and
    then to the r-ci action with embedded setup
    \item The DESCRIPTION file now uses Authors@R
  }
}

\section{Changes in version 0.1.2 (2023-11-29)}{
  \itemize{
    \item \code{RcppExports.cpp} has been regenerated under an updated
    \pkg{Rcpp} to address a format string warning under R-devel
    \item The compilation standard is no longer set to C++14
  }
}

\section{Changes in version 0.1.1 (2022-10-19)}{
  \itemize{
    \item Minor code reorganization splitting off \code{calendars.cpp}
    \item Convert the Argentinian calendar sources files as utf-8 to
    appease \code{clang++-15}
    \item Advertise the \pkg{qlcal} package as an alternative
  }
}

\section{Changes in version 0.1.0 (2021-10-30)}{
  \itemize{
    \item Code reorganized to have minimal (documented) changes relative
    to upstream, essentially just removing unused headers, and pragma
    \item Added example for full calendaring to README.md
  }
}

\section{Changes in version 0.0.5 (2021-10-23)}{
  \itemize{
    \item Refocused on calendaring functionality only, removed
    daycounters/, math/, methods/, models/, plus other unused headers
    \item Fully updated to (current) QuantLib release 0.2.4
    \item Added getBusinessDays() to retrieve range of dates
    \item Added Brazil calendar
  }
}

\section{Changes in version 0.0.4 (2021-10-12)}{
  \itemize{
    \item Allow for 'Null' calendar without weekends or holidays
    \item Switch CI use to \href{https://eddelbuettel.github.io/r-ci/}{r-ci}
    \item Updated UnitedStates calendar to current QuantLib calendar
    \item Small updates to DESCRIPTION and README.md
  }
}

\section{Changes in version 0.0.3 (2019-08-19)}{
  \itemize{
    \item Updated Travis CI test file (\ghpr{8})).
    \item Updated US holiday calendar data with G H Bush funeral date (\ghpr{9}).
    \item Updated C++ use to not trigger warnings [CRAN request] (\ghpr{9}).
    \item Comment-out pragmas to suppress warnings [CRAN Policy] (\ghpr{9}).
    \item Change build to exclude Sobol sequence reducing file size for source
    and shared library, at the cost of excluding market models (\ghpr{10}).
  }
}

\section{Changes in version 0.0.2 (2017-11-06)}{
  \itemize{
    \item Added calendars for Canada, China, Germany, Japan and United Kingdom.
    \item Added bespoke and joint calendars.
    \item Using new date(time) vectors (\ghpr{6}).
  }
}

\section{Changes in version 0.0.1 (2017-04-16)}{
  \itemize{
    \item Initial release with a number of date and calendar functions
  }
}
