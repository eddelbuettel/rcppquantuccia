
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
        ql::Calendar *m_cal;
        std::string m_id;
    public:
    	CalendarContainer() : m_cal(new ql::TARGET), m_id("TARGET") {}
        ~CalendarContainer() {
            free(m_cal);
        }
        ql::Calendar getCalendar() { return *m_cal; }
        void setCalendar(std::string txt = "TARGET") {
            if (txt != m_id) {
                m_id = txt;
                if (txt == "UnitedStates") {
                    free(m_cal);
                    m_cal = new ql::UnitedStates;
                } else {
                    free(m_cal);
                    m_cal = new ql::UnitedStates;
                }
            }
        }
    };
}

#endif
