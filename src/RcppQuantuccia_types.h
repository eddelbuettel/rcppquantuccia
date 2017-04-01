
#include <ql/quantlib.hpp>

//#include <boost/algorithm/string.hpp>
//#include <boost/lexical_cast.hpp>

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
    template <typename T> SEXP wrap(const T& d);

    template <> std::vector<QuantLib::Date> as(SEXP dtvecsexp);
    template <> SEXP wrap(const std::vector<QuantLib::Date> &dvec);
        
}


