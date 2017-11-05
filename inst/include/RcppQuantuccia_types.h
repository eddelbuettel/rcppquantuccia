
#ifndef rcpp_quantuccia_types_h
#define rcpp_quantuccia_types_h

#define QL_HIGH_RESOLUTION_DATE
#include <ql/quantlib.hpp>

//using namespace QuantLib;

// default with Rcpp 0.12.14, supported since Rcpp 0.12.8
#define RCPP_NEW_DATE_DATETIME_VECTORS 1

#include <RcppCommon.h>

namespace Rcpp {

    // non-intrusive extension via template specialisation
    template <> QuantLib::Date as(SEXP dtsexp);

    // non-intrusive extension via template specialisation
    template <> SEXP wrap(const QuantLib::Date &d);

    // non-intrusive extension via template specialisation
    template <> std::vector<QuantLib::Date> as(SEXP dtvecsexp);

    // non-intrusive extension via template specialisation
    template <> SEXP wrap(const std::vector<QuantLib::Date> &dvec);
}

#include <Rcpp.h>

// define template specialisations for as and wrap
namespace Rcpp {

    //template <> QuantLib::Date as(SEXP dtsexp);
    template <typename T> T as(SEXP dtsexp);
    template <typename T> T as(Rcpp::Date);
    template <typename T> T as(Rcpp::Datetime);
    template <typename T> SEXP wrap(const T& d);

    template <> std::vector<QuantLib::Date> as(SEXP dtvecsexp);
    template <> SEXP wrap(const std::vector<QuantLib::Date> &dvec);

}

namespace RcppQuantuccia {

    namespace ql = QuantLib;

    class CalendarContainer {
    private:
        std::unique_ptr<ql::Calendar> p_cal;
        std::string m_id;
    public:
        CalendarContainer() : p_cal(new ql::TARGET), m_id("TARGET") {}
        ~CalendarContainer() = default;
        ql::Calendar getCalendar() { return *p_cal; }
        void setCalendar(std::string txt = "TARGET") {
            if (txt != m_id) {
                m_id = txt;
                if (txt == "TARGET") {
                    p_cal.reset(new ql::TARGET);

                } else if (txt == "UnitedStates" ||
                           txt == "UnitedStates/Settlement" ||
                           txt == "UnitedStates::Settlement") {
                    p_cal.reset(new ql::UnitedStates(ql::UnitedStates::Settlement));
                } else if (txt == "UnitedStates/NYSE" ||
                           txt == "UnitedStates::NYSE") {
                    p_cal.reset(new ql::UnitedStates(QuantLib::UnitedStates::NYSE));
                } else if (txt == "UnitedStates/GovernmentBond" ||
                           txt == "UnitedStates::GovernmentBond") {
                    p_cal.reset(new ql::UnitedStates(ql::UnitedStates::GovernmentBond));
                } else if (txt == "UnitedStates/NERC" ||
                           txt == "UnitedStates::NERC") {
                    p_cal.reset(new ql::UnitedStates(ql::UnitedStates::NERC));

                } else if (txt == "UnitedKingdom" ||
                           txt == "UnitedKingdom/Settlement" ||
                           txt == "UnitedKingdom::Settlement") {
                    p_cal.reset(new ql::UnitedKingdom(ql::UnitedKingdom::Settlement));
                } else if (txt == "UnitedKingdom/Exchange" ||
                           txt == "UnitedKingdom::Exchange") {
                    p_cal.reset(new ql::UnitedKingdom(ql::UnitedKingdom::Exchange));
                } else if (txt == "UnitedKingdom/Metals" ||
                           txt == "UnitedKingdom::Metals") {
                    p_cal.reset(new ql::UnitedKingdom(ql::UnitedKingdom::Metals));

                } else if (txt == "Germany" ||
                           txt == "Germany/Settlement" ||
                           txt == "Germany::Settlement") {
                    p_cal.reset(new ql::Germany(ql::Germany::Settlement));
                } else if (txt == "Germany/FrankfurtStockExchange" ||
                           txt == "Germany::FrankfurtStockExchange") {
                    p_cal.reset(new ql::Germany(ql::Germany::FrankfurtStockExchange));
                } else if (txt == "Germany/Xetra" ||
                           txt == "Germany::Xetra") {
                    p_cal.reset(new ql::Germany(ql::Germany::Xetra));
                } else if (txt == "Germany/Eurex" ||
                           txt == "Germany::Eurex") {
                    p_cal.reset(new ql::Germany(ql::Germany::Eurex));
                } else if (txt == "Germany/Euwax" ||
                           txt == "Germany::Euwax") {
                    p_cal.reset(new ql::Germany(ql::Germany::Euwax));

                } else if (txt == "Japan") {
                    p_cal.reset(new ql::Japan());

                } else if (txt == "China" ||
                           txt == "China/SSE" ||
                           txt == "China::SSE") {
                    p_cal.reset(new ql::China(ql::China::SSE));
                } else if (txt == "China/IB" ||
                           txt == "China::IB") {
                    p_cal.reset(new ql::China(ql::China::IB));

                } else if (txt == "Canada" ||
                           txt == "Canada/Settlement" ||
                           txt == "Canada::Settlement") {
                    p_cal.reset(new ql::Canada(ql::Canada::Settlement));
                } else if (txt == "Canada/TSX" ||
                           txt == "Canada::TSX") {
                    p_cal.reset(new ql::Canada(ql::Canada::TSX));

                } else {        // fallback
                    Rcpp::warning("Unrecognised calendar '%s' using fallback 'TARGET'", txt);
                    p_cal.reset(new ql::TARGET);
                }
            }
        }
    };
}

#endif
