#include <R.h>
#include <Rinternals.h>
#include <stdlib.h> // for NULL
#include <R_ext/Rdynload.h>

/* FIXME: 
   Check these declarations against the C/Fortran source code.
*/

/* .Call calls */
extern SEXP RcppQuantuccia_adjust_cpp(SEXP, SEXP);
extern SEXP RcppQuantuccia_advanceDate(SEXP, SEXP);
extern SEXP RcppQuantuccia_advanceUnits_cpp(SEXP, SEXP, SEXP, SEXP, SEXP);
extern SEXP RcppQuantuccia_businessDaysBetween(SEXP, SEXP, SEXP, SEXP);
//extern SEXP RcppQuantuccia_dtConvert(SEXP);
extern SEXP RcppQuantuccia_getEndOfMonth(SEXP);
extern SEXP RcppQuantuccia_getHolidays(SEXP, SEXP, SEXP);
extern SEXP RcppQuantuccia_isBusinessDay(SEXP);
extern SEXP RcppQuantuccia_isEndOfMonth(SEXP);
extern SEXP RcppQuantuccia_isHoliday(SEXP);
extern SEXP RcppQuantuccia_isWeekend(SEXP);
extern SEXP RcppQuantuccia_RcppExport_registerCCallable();
extern SEXP RcppQuantuccia_setCalendar(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"RcppQuantuccia_adjust_cpp",                   (DL_FUNC) &RcppQuantuccia_adjust_cpp,                   2},
    {"RcppQuantuccia_advanceDate",                  (DL_FUNC) &RcppQuantuccia_advanceDate,                  2},
    {"RcppQuantuccia_advanceUnits_cpp",             (DL_FUNC) &RcppQuantuccia_advanceUnits_cpp,             5},
    {"RcppQuantuccia_businessDaysBetween",          (DL_FUNC) &RcppQuantuccia_businessDaysBetween,          4},
//    {"RcppQuantuccia_dtConvert",                    (DL_FUNC) &RcppQuantuccia_dtConvert,                    1},
    {"RcppQuantuccia_getEndOfMonth",                (DL_FUNC) &RcppQuantuccia_getEndOfMonth,                1},
    {"RcppQuantuccia_getHolidays",                  (DL_FUNC) &RcppQuantuccia_getHolidays,                  3},
    {"RcppQuantuccia_isBusinessDay",                (DL_FUNC) &RcppQuantuccia_isBusinessDay,                1},
    {"RcppQuantuccia_isEndOfMonth",                 (DL_FUNC) &RcppQuantuccia_isEndOfMonth,                 1},
    {"RcppQuantuccia_isHoliday",                    (DL_FUNC) &RcppQuantuccia_isHoliday,                    1},
    {"RcppQuantuccia_isWeekend",                    (DL_FUNC) &RcppQuantuccia_isWeekend,                    1},
    {"RcppQuantuccia_RcppExport_registerCCallable", (DL_FUNC) &RcppQuantuccia_RcppExport_registerCCallable, 0},
    {"RcppQuantuccia_setCalendar",                  (DL_FUNC) &RcppQuantuccia_setCalendar,                  1},
    {NULL, NULL, 0}
};

void R_init_RcppQuantuccia(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
