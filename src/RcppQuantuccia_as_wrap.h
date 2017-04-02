
#ifndef rcpp_quantuccia_date_wrappers_h
#define rcpp_quantuccia_date_wrappers_h

#include <ql/quantlib.hpp>

#include <Rcpp.h>

// define template specialisations for as and wrap
namespace Rcpp {

    static const unsigned int QLtoJan1970Offset = 25569;  	// Offset to R / Unix epoch 

    inline unsigned int getQLtoJan1970offset(void) { return QLtoJan1970Offset; }

    template <> QuantLib::Date as(SEXP dtsexp) {
        Rcpp::Date dt(dtsexp);
        return QuantLib::Date(static_cast<int>(dt.getDate()) + QLtoJan1970Offset);
    }

    template <> SEXP wrap(const QuantLib::Date &d) {
        double dt = static_cast<double>(d.serialNumber()); // QL::BigInteger can cast to double
        return Rcpp::wrap(Rcpp::Date(dt - QLtoJan1970Offset));
    }

    // non-intrusive extension via template specialisation
    template <> std::vector<QuantLib::Date> as(SEXP dtvecsexp) {
        Rcpp::DateVector dtvec(dtvecsexp);
        int n = dtvec.size();
        std::vector<QuantLib::Date> dates(n);
        for (int i = 0; i<n; i++){
#if RCPP_VERSION >= Rcpp_Version(0,12,8)
            //dates[i] = QuantLib::Date(static_cast<int>(dtvec[i]) + QLtoJan1970Offset);
            dates[i] = QuantLib::Date(static_cast<int>(Rcpp::Date(dtvec[i]).getDate()) + QLtoJan1970Offset);
#else            
            dates[i] = QuantLib::Date(static_cast<int>(dtvec[i].getDate()) + QLtoJan1970Offset);
#endif            
        }
        return dates;
    }

    // non-intrusive extension via template specialisation
    template <> SEXP wrap(const std::vector<QuantLib::Date> &dvec) {
        int n = dvec.size();
        Rcpp::DateVector dtvec(n);
        for (int i = 0; i<n; i++) {
            // QL::BigInteger can cast to double
            double dt = static_cast<double>(dvec[i].serialNumber()); 
            dtvec[i] = Rcpp::Date(dt - QLtoJan1970Offset);
        }
        return Rcpp::wrap(dtvec);
    }

}

#endif
