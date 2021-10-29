
library(RcppQuantuccia)
library(data.table)

calendars

getHols <- function(cal) {    # simple help function
    setCalendar(cal)
    getHolidays(as.Date("2022-01-01"), as.Date("2022-12-31"))
}
D <- data.table(calendar=calendars)
D[ , `:=`(n = length(getHols(calendar)),
          holidays = paste(format(getHols(calendar),"%d %b"), collapse=",")),
  by = calendar ]
D
print(D[order(-holidays)], nrow=length(calendars))

D[, name := { setCalendar(calendar); getName() }, by=calendar][, .(calendar,name)]
