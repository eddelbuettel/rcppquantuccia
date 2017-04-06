// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#ifndef RCPP_RcppQuantuccia_RCPPEXPORTS_H_GEN_
#define RCPP_RcppQuantuccia_RCPPEXPORTS_H_GEN_

#include "RcppQuantuccia_types.h"
#include <Rcpp.h>

namespace RcppQuantuccia {

    using namespace Rcpp;

    namespace {
        void validateSignature(const char* sig) {
            Rcpp::Function require = Rcpp::Environment::base_env()["require"];
            require("RcppQuantuccia", Rcpp::Named("quietly") = true);
            typedef int(*Ptr_validate)(const char*);
            static Ptr_validate p_validate = (Ptr_validate)
                R_GetCCallable("RcppQuantuccia", "RcppQuantuccia_RcppExport_validate");
            if (!p_validate(sig)) {
                throw Rcpp::function_not_exported(
                    "C++ function with signature '" + std::string(sig) + "' not found in RcppQuantuccia");
            }
        }
    }

    inline void setCalendar(std::string calstr) {
        typedef SEXP(*Ptr_setCalendar)(SEXP);
        static Ptr_setCalendar p_setCalendar = NULL;
        if (p_setCalendar == NULL) {
            validateSignature("void(*setCalendar)(std::string)");
            p_setCalendar = (Ptr_setCalendar)R_GetCCallable("RcppQuantuccia", "RcppQuantuccia_setCalendar");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_setCalendar(Rcpp::wrap(calstr));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
    }

    inline Rcpp::Date advanceDate(Rcpp::Date rd, int days = 0) {
        typedef SEXP(*Ptr_advanceDate)(SEXP,SEXP);
        static Ptr_advanceDate p_advanceDate = NULL;
        if (p_advanceDate == NULL) {
            validateSignature("Rcpp::Date(*advanceDate)(Rcpp::Date,int)");
            p_advanceDate = (Ptr_advanceDate)R_GetCCallable("RcppQuantuccia", "RcppQuantuccia_advanceDate");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_advanceDate(Rcpp::wrap(rd), Rcpp::wrap(days));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::Date >(rcpp_result_gen);
    }

    inline Rcpp::LogicalVector isBusinessDay(Rcpp::DateVector dates) {
        typedef SEXP(*Ptr_isBusinessDay)(SEXP);
        static Ptr_isBusinessDay p_isBusinessDay = NULL;
        if (p_isBusinessDay == NULL) {
            validateSignature("Rcpp::LogicalVector(*isBusinessDay)(Rcpp::DateVector)");
            p_isBusinessDay = (Ptr_isBusinessDay)R_GetCCallable("RcppQuantuccia", "RcppQuantuccia_isBusinessDay");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_isBusinessDay(Rcpp::wrap(dates));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::LogicalVector >(rcpp_result_gen);
    }

    inline Rcpp::LogicalVector isHoliday(Rcpp::DateVector dates) {
        typedef SEXP(*Ptr_isHoliday)(SEXP);
        static Ptr_isHoliday p_isHoliday = NULL;
        if (p_isHoliday == NULL) {
            validateSignature("Rcpp::LogicalVector(*isHoliday)(Rcpp::DateVector)");
            p_isHoliday = (Ptr_isHoliday)R_GetCCallable("RcppQuantuccia", "RcppQuantuccia_isHoliday");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_isHoliday(Rcpp::wrap(dates));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::LogicalVector >(rcpp_result_gen);
    }

    inline Rcpp::LogicalVector isWeekend(Rcpp::DateVector dates) {
        typedef SEXP(*Ptr_isWeekend)(SEXP);
        static Ptr_isWeekend p_isWeekend = NULL;
        if (p_isWeekend == NULL) {
            validateSignature("Rcpp::LogicalVector(*isWeekend)(Rcpp::DateVector)");
            p_isWeekend = (Ptr_isWeekend)R_GetCCallable("RcppQuantuccia", "RcppQuantuccia_isWeekend");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_isWeekend(Rcpp::wrap(dates));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::LogicalVector >(rcpp_result_gen);
    }

    inline Rcpp::LogicalVector isEndOfMonth(Rcpp::DateVector dates) {
        typedef SEXP(*Ptr_isEndOfMonth)(SEXP);
        static Ptr_isEndOfMonth p_isEndOfMonth = NULL;
        if (p_isEndOfMonth == NULL) {
            validateSignature("Rcpp::LogicalVector(*isEndOfMonth)(Rcpp::DateVector)");
            p_isEndOfMonth = (Ptr_isEndOfMonth)R_GetCCallable("RcppQuantuccia", "RcppQuantuccia_isEndOfMonth");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_isEndOfMonth(Rcpp::wrap(dates));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::LogicalVector >(rcpp_result_gen);
    }

    inline Rcpp::DateVector getEndOfMonth(Rcpp::DateVector dates) {
        typedef SEXP(*Ptr_getEndOfMonth)(SEXP);
        static Ptr_getEndOfMonth p_getEndOfMonth = NULL;
        if (p_getEndOfMonth == NULL) {
            validateSignature("Rcpp::DateVector(*getEndOfMonth)(Rcpp::DateVector)");
            p_getEndOfMonth = (Ptr_getEndOfMonth)R_GetCCallable("RcppQuantuccia", "RcppQuantuccia_getEndOfMonth");
        }
        RObject rcpp_result_gen;
        {
            RNGScope RCPP_rngScope_gen;
            rcpp_result_gen = p_getEndOfMonth(Rcpp::wrap(dates));
        }
        if (rcpp_result_gen.inherits("interrupted-error"))
            throw Rcpp::internal::InterruptedException();
        if (rcpp_result_gen.inherits("try-error"))
            throw Rcpp::exception(as<std::string>(rcpp_result_gen).c_str());
        return Rcpp::as<Rcpp::DateVector >(rcpp_result_gen);
    }

}

#endif // RCPP_RcppQuantuccia_RCPPEXPORTS_H_GEN_
