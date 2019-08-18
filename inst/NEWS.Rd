\name{NEWS}
\title{News for Package \pkg{RcppQuantuccia}}
\newcommand{\ghpr}{\href{https://github.com/eddelbuettel/rcppquantuccia/pull/#1}{##1}}
\newcommand{\ghit}{\href{https://github.com/eddelbuettel/rcppquantuccia/issues/#1}{##1}}

\section{Changes in version 0.0.3 (2019-08-19)}{
  \itemize{
    \item Updated Travis CI test file (\ghpr{8})).
    \item Updated US holiday calendar data with G H Bush funeral date (ghpr{9}). 
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
