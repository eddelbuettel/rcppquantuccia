
## simple tests, to be replaced "eventually" by something better using RUnit

if (requireNamespace("RcppQuantuccia", quietly=TRUE)) {

    library(RcppQuantuccia)

    setCalendar("UnitedStates/NYSE")

    dates <- as.Date("2017-01-03") + 0:3  # four weekdays, so adjustments give same dates
    stopifnot(adjust(dates) == dates,
              adjust(dates, bdc="Following") == dates,
              adjust(dates, bdc="ModifiedFollowing") == dates,
              adjust(dates, bdc="Preceding") == dates,
              adjust(dates, bdc="ModifiedPreceding") == dates,
              adjust(dates, bdc="Unadjusted") == dates,
              adjust(dates, bdc="HalfMonthModifiedFollowing") == dates,
              adjust(dates, bdc="Nearest") == dates,
              adjust(dates, bdc="Unadjusted") == dates)

    date <- as.Date("2017-01-01")   	# New Year's -- now expect differences
    stopifnot(adjust(date) != date,
              adjust(date, bdc="Following") != date,
              adjust(date, bdc="ModifiedFollowing") != date,
              adjust(date, bdc="Preceding") != date,
              adjust(date, bdc="ModifiedPreceding") != date,
              adjust(date, bdc="Unadjusted") == date,  ## NB: unaltered by design
              adjust(date, bdc="HalfMonthModifiedFollowing") != date,
              adjust(date, bdc="Nearest") != date)

    date <- as.Date("2017-01-03")  		# workday
    stopifnot(advanceDate(date, 0) == date,
              advanceDate(date, 1) == date + 1)

    dates <- as.Date("2017-01-03") + 0:2  		# workday
    stopifnot(advanceUnits(dates, 0, "Days") == dates,
              advanceUnits(dates, 1, "Days") == dates + 1)

    date <- as.Date("2017-01-03")  		# workday
    stopifnot(businessDaysBetween(date, date + 7) == 5)

    stopifnot(getEndOfMonth(date) == as.Date("2017-01-31"))

    print(getHolidays(date, getEndOfMonth(date)))

}
