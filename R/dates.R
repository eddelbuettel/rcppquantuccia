##' Adjust a vector of dates following a business-day convention
##'
##' This function takes a vector of dates and returns another vector of dates
##' of the same length returning at each position the adjusted date according
##' to the selected business-day convention. Currently supported values for
##' the business day convention are (starting from zero):
##' \sQuote{Following}, \sQuote{ModifiedFollowing}, \sQuote{Preceding},
##' \sQuote{ModifiedPreceding}, \sQuote{Unadjusted}, \sQuote{HalfModifiedFollowing}
##' and \sQuote{Nearest}.
##'
##' @title Compute adjusted dates
##' @param dates A Date vector with dates
##' @param bdc A character variable describing one of several supported values,
##' the C++ version implements expects a corresponding integer value
##' @return A Date vector with dates adjust according to business-day convention
##' @examples
##' adjust(Sys.Date()+0:6)
adjust <- function(dates, bdc=c("Following", "ModifiedFollowing",
                                "Preceding", "ModifiedPreceding",
                                "Unadjusted", "HalfMonthModifiedFollowing",
                                "Nearest")) {
    bdc <- match.arg(bdc)
    adjust_cpp(dates, .matchBDC(bdc))
}

##' Advance a vector of dates by a given number of time units
##'
##' This function takes a vector of dates and returns another vector of dates
##' of the same length returning at each position the date advanced by the given
##' number of steps in the selected time unit, also respecting a business day
##' convention and and of month boolean switch. Currently supported values for
##' the time unit are \sQuote{Days}, \sQuote{Weeks}, \sQuote{Months} \sQuote{Years},
##' \sQuote{Hours}, \sQuote{Seconds}, \sQuote{Milliseconds} and \sQuote{Microseconds};
##' all are specified as integers. Note that intra-daily units are not currently
##' supported for advancing \sQuote{Date} objects. Currently supported values for
##' the business day convention are (starting from zero):
##' \sQuote{Following}, \sQuote{ModifiedFollowing}, \sQuote{Preceding},
##' \sQuote{ModifiedPreceding}, \sQuote{Unadjusted}, \sQuote{HalfModifiedFollowing}
##' and \sQuote{Nearest}.
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
                               "Nearest"),
                         emr=FALSE) {
    unit <- match.arg(unit)
    bdc <- match.arg(bdc)
    advanceUnits_cpp(dates, n, .matchUnit(unit), .matchBDC(bdc), emr)
}

## Internal helper
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

## Internal helper
.matchBDC <- function(arg) {
    switch(arg,
           Following = 0,
           ModifiedFollowing = 1,
           Preceding = 2,
           ModifiedPreceding = 3,
           Unadjusted = 4,
           HalfMonthModifiedFollowing = 5,
           Nearest = 6)
}
