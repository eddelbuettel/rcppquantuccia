\name{NEWS}
\title{News for Package \pkg{RcppQuantuccia}}
\newcommand{\ghpr}{\href{https://github.com/eddelbuettel/rcppquantuccia/pull/#1}{##1}}
\newcommand{\ghit}{\href{https://github.com/eddelbuettel/rcppquantuccia/issues/#1}{##1}}

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
