
#ifndef rcpp_quantuccia_types_h
#define rcpp_quantuccia_types_h

#ifndef QL_HIGH_RESOLUTION_DATE
  #define QL_HIGH_RESOLUTION_DATE
#endif
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
    template <typename T> T as(Rcpp::Datetime);
    template <typename T> SEXP wrap(const T& d);

    template <> std::vector<QuantLib::Date> as(SEXP dtvecsexp);
    template <> SEXP wrap(const std::vector<QuantLib::Date> &dvec);

}

namespace RcppQuantuccia {

    namespace ql = QuantLib;

    class CalendarContainer {
    private:
        std::unique_ptr<ql::Calendar> p_cal = std::make_unique<ql::Calendar>(ql::TARGET());
        std::string m_id = "TARGET";
    public:
        CalendarContainer() = default;
        ~CalendarContainer() = default;
        ql::Calendar getCalendar() const { return *p_cal; }
        std::string getName() const { return p_cal->name(); }
        std::string getId() const { return m_id; }
        void setCalendar(const std::string txt);
    };
}

#endif
