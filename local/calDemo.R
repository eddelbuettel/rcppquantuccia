
library(RcppQuantuccia)
library(data.table)
nHol <- function(cal) { setCalendar(cal); length(getHolidays(as.Date("2022-01-01"), as.Date("2022-12-31"))) }
D <- data.table(calendar=calendars)
D[ , holidays := nHol(calendars), by=calendars ]
print(D[order(-holidays)], nrow=length(calendars))
