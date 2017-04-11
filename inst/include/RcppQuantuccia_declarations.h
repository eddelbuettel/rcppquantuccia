
#ifndef rcpp_quantuccia_declarations_h
#define rcpp_quantuccia_declarations_h

#include <ql/quantlib.hpp>

QuantLib::BusinessDayConvention getBusinessDayConvention(const int n);
QuantLib::Frequency getFrequency(const int n);
QuantLib::TimeUnit getTimeUnit(const int n);

#endif
