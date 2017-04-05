// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/RcppQuantuccia.h"
#include "../inst/include/RcppQuantuccia_types.h"
#include <Rcpp.h>
#include <string>
#include <set>

using namespace Rcpp;

// setCalendar
void setCalendar(std::string calstr);
static SEXP RcppQuantuccia_setCalendar_try(SEXP calstrSEXP) {
BEGIN_RCPP
    Rcpp::traits::input_parameter< std::string >::type calstr(calstrSEXP);
    setCalendar(calstr);
    return R_NilValue;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP RcppQuantuccia_setCalendar(SEXP calstrSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(RcppQuantuccia_setCalendar_try(calstrSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// advanceDate
Rcpp::Date advanceDate(Rcpp::Date rd, int days);
static SEXP RcppQuantuccia_advanceDate_try(SEXP rdSEXP, SEXP daysSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::Date >::type rd(rdSEXP);
    Rcpp::traits::input_parameter< int >::type days(daysSEXP);
    rcpp_result_gen = Rcpp::wrap(advanceDate(rd, days));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP RcppQuantuccia_advanceDate(SEXP rdSEXP, SEXP daysSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(RcppQuantuccia_advanceDate_try(rdSEXP, daysSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// isBusinessDay
Rcpp::LogicalVector isBusinessDay(Rcpp::DateVector dates);
static SEXP RcppQuantuccia_isBusinessDay_try(SEXP datesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::DateVector >::type dates(datesSEXP);
    rcpp_result_gen = Rcpp::wrap(isBusinessDay(dates));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP RcppQuantuccia_isBusinessDay(SEXP datesSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(RcppQuantuccia_isBusinessDay_try(datesSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}
// isHoliday
Rcpp::LogicalVector isHoliday(Rcpp::DateVector dates);
static SEXP RcppQuantuccia_isHoliday_try(SEXP datesSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::traits::input_parameter< Rcpp::DateVector >::type dates(datesSEXP);
    rcpp_result_gen = Rcpp::wrap(isHoliday(dates));
    return rcpp_result_gen;
END_RCPP_RETURN_ERROR
}
RcppExport SEXP RcppQuantuccia_isHoliday(SEXP datesSEXP) {
    SEXP rcpp_result_gen;
    {
        Rcpp::RNGScope rcpp_rngScope_gen;
        rcpp_result_gen = PROTECT(RcppQuantuccia_isHoliday_try(datesSEXP));
    }
    Rboolean rcpp_isInterrupt_gen = Rf_inherits(rcpp_result_gen, "interrupted-error");
    if (rcpp_isInterrupt_gen) {
        UNPROTECT(1);
        Rf_onintr();
    }
    Rboolean rcpp_isError_gen = Rf_inherits(rcpp_result_gen, "try-error");
    if (rcpp_isError_gen) {
        SEXP rcpp_msgSEXP_gen = Rf_asChar(rcpp_result_gen);
        UNPROTECT(1);
        Rf_error(CHAR(rcpp_msgSEXP_gen));
    }
    UNPROTECT(1);
    return rcpp_result_gen;
}

// validate (ensure exported C++ functions exist before calling them)
static int RcppQuantuccia_RcppExport_validate(const char* sig) { 
    static std::set<std::string> signatures;
    if (signatures.empty()) {
        signatures.insert("void(*setCalendar)(std::string)");
        signatures.insert("Rcpp::Date(*advanceDate)(Rcpp::Date,int)");
        signatures.insert("Rcpp::LogicalVector(*isBusinessDay)(Rcpp::DateVector)");
        signatures.insert("Rcpp::LogicalVector(*isHoliday)(Rcpp::DateVector)");
    }
    return signatures.find(sig) != signatures.end();
}

// registerCCallable (register entry points for exported C++ functions)
RcppExport SEXP RcppQuantuccia_RcppExport_registerCCallable() { 
    R_RegisterCCallable("RcppQuantuccia", "RcppQuantuccia_setCalendar", (DL_FUNC)RcppQuantuccia_setCalendar_try);
    R_RegisterCCallable("RcppQuantuccia", "RcppQuantuccia_advanceDate", (DL_FUNC)RcppQuantuccia_advanceDate_try);
    R_RegisterCCallable("RcppQuantuccia", "RcppQuantuccia_isBusinessDay", (DL_FUNC)RcppQuantuccia_isBusinessDay_try);
    R_RegisterCCallable("RcppQuantuccia", "RcppQuantuccia_isHoliday", (DL_FUNC)RcppQuantuccia_isHoliday_try);
    R_RegisterCCallable("RcppQuantuccia", "RcppQuantuccia_RcppExport_validate", (DL_FUNC)RcppQuantuccia_RcppExport_validate);
    return R_NilValue;
}
