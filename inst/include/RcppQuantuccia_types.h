
#ifndef rcpp_quantuccia_types_h
#define rcpp_quantuccia_types_h

#include <ql/quantlib.hpp>

//using namespace QuantLib;

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
                if (txt == "UnitedStates") {
                    p_cal.reset(new ql::UnitedStates);
                } else {        // fallback
                    p_cal.reset(new ql::TARGET);
                }
            }
        }
    };
}

#endif
