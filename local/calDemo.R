
suppressMessages( { library(RcppQuantuccia); library(data.table) } )
options(width=150)

str(calendars)   # show (some) known calendars

getHols <- function(cal) {    # simple helper function
    setCalendar(cal)
    getHolidays(as.Date("2022-01-01"), as.Date("2022-12-31"))
}
D <- data.table(calendar=calendars)
D[ , `:=`(n = length(getHols(calendar)),
          holidays = paste(format(getHols(calendar),"%d %b"), collapse=",")),
  by = calendar ]
D[n > 0, ][order(n, decreasing=TRUE)]

D[, name := { setCalendar(calendar); getName() }, by=calendar][, .(calendar,name)]
