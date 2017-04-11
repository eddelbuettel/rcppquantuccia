##' Advance a vector of dates by a given number of time units
##'
##' This function takes a vector of dates and returns another vector of dates
##' of the same length returning at each position the date advanced by the given
##' number of steps in the selected time unit, also respecting a business day
##' convention and and of month boolean switch. Currently supported values for
##' the time unit are \sQuote{Days}, \sQuote{Weeks}, \sQuote{Months} \sQuote{Years},
##' \sQuote{Hours}, \sQuote{Seconds}, \sQuote{Milliseconds} and \sQuote{Microseconds};
##' all are specified as integers. Currently supported values for
##' the business day convention are (starting from zero):
##' \sQuote{Following}, \sQuote{ModifiedFollowing}, \sQuote{Preceding},
##' \sQuote{ModifiedPreceding}, \sQuote{Unadjusted}, \sQuote{HalfModifiedFollowing}
##' \sQuote{Nearest} and a fallback of \sQuote{Unadjusted} for all other value.
##'
##' @title Compute adjusted dates
##' @param dates A Date vector with dates
##' @param n An integer variable with the number of units to advance
##' @param unit A character variable describing one of several supported values;
##' the C++ version implements expects a corresponding integer value
##' @param bdc A character variable describing one of several supported values,
##' the C++ version implements expects a corresponding integer value
##' @param emr A boolean variable select end-of-month, default is \sQuote{FALSE}
##' @return A Date vector with dates advanced according to the selected inputs
##' @examples
##' advanceUnits(Sys.Date()+0:6, 5, "Days", "Following")
advanceUnits <- function(dates, n,
                         unit=c("Days", "Weeks", "Months", "Years",
                                "Hours", "Minutes", "Seconds",
                                "Milliseconds", "Microseconds"),
                         bdc=c("Following", "ModifiedFollowing",
                               "Preceding", "ModifiedPreceding",
                               "Unadjusted", "HalfMonthModifiedFollowing",
                               "Nearest", "Unadjusted"),
                         emr=FALSE) {
    unit <- match.arg(unit)
    bdc <- match.arg(bdc)

    advanceUnits_cpp(dates, n, .matchUnit(unit), .matchBDC(bdc), emr)
}

.matchUnit <- function(arg) {
    switch(arg,
           Days = 0,
           Weeks = 1,
           Months = 2,
           Years = 3,
           Hours = 4,
           Minutes = 5,
           Seconds = 6,
           Milliseconds = 7,
           Microseconds = 8)
}

.matchBDC <- function(arg) {
    switch(arg,
           Following = 0,
           ModifiedFollowing = 1,
           Preceding = 2,
           ModifiedPreceding = 3,
           Unadjusted = 4,
           HalfMonthModifiedFollowing = 5,
           Nearest = 6,
           Unadjusted = 7)
}
