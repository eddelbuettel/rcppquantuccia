/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2008 Klaus Spanderen

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file gausslobattointegral.hpp
    \brief integral of a one-dimensional function using the adaptive
    Gauss-Lobatto integral
*/

#ifndef quantlib_gauss_lobatto_integral_hpp
#define quantlib_gauss_lobatto_integral_hpp

#include <ql/errors.hpp>
#include <ql/utilities/null.hpp>
#include <ql/math/integrals/integral.hpp>

namespace QuantLib {

    //! Integral of a one-dimensional function
    /*! Given a target accuracy \f$ \epsilon \f$, the integral of
        a function \f$ f \f$ between \f$ a \f$ and \f$ b \f$ is
        calculated by means of the Gauss-Lobatto formula
    */

    /*! References:
       This algorithm is a C++ implementation of the algorithm outlined in

       W. Gander and W. Gautschi, Adaptive Quadrature - Revisited.
       BIT, 40(1):84-101, March 2000. CS technical report:
       ftp.inf.ethz.ch/pub/publications/tech-reports/3xx/306.ps.gz

       The original MATLAB version can be downloaded here
       http://www.inf.ethz.ch/personal/gander/adaptlob.m
    */

    class GaussLobattoIntegral : public Integrator {
      public:
        GaussLobattoIntegral(Size maxIterations,
                             Real absAccuracy,
                             Real relAccuracy = Null<Real>(),
                             bool useConvergenceEstimate = true);

      protected:
        Real integrate (const boost::function<Real (Real)>& f,
                        Real a, Real b) const;

        Real adaptivGaussLobattoStep(const boost::function<Real (Real)>& f,
                                     Real a, Real b, Real fa, Real fb,
                                     Real is) const;
        Real calculateAbsTolerance(const boost::function<Real (Real)>& f,
                                   Real a, Real b) const;

        Real relAccuracy_;
        const bool useConvergenceEstimate_;

        static Real alpha_() { return std::sqrt(2.0/3.0); }
        static Real beta_()  { return 1.0/std::sqrt(5.0); }
        static Real x1_()    { return 0.94288241569547971906; }
        static Real x2_()    { return 0.64185334234578130578; }
        static Real x3_()    { return 0.23638319966214988028; }
    };

    // implementation

    inline GaussLobattoIntegral::GaussLobattoIntegral(Size maxIterations,
                                               Real absAccuracy,
                                               Real relAccuracy,
                                               bool useConvergenceEstimate)
    : Integrator(absAccuracy, maxIterations),
      relAccuracy_(relAccuracy),
      useConvergenceEstimate_(useConvergenceEstimate) {
    }

    inline Real GaussLobattoIntegral::integrate(
                                     const boost::function<Real (Real)>& f,
                                     Real a, Real b) const {

        setNumberOfEvaluations(0);
        const Real calcAbsTolerance = calculateAbsTolerance(f, a, b);

        increaseNumberOfEvaluations(2);
        return adaptivGaussLobattoStep(f, a, b, f(a), f(b), calcAbsTolerance);
    }

    inline Real GaussLobattoIntegral::calculateAbsTolerance(
                                     const boost::function<Real (Real)>& f,
                                     Real a, Real b) const {


        Real relTol = std::max(relAccuracy_, QL_EPSILON);

        const Real m = (a+b)/2;
        const Real h = (b-a)/2;
        const Real y1 = f(a);
        const Real y3 = f(m-alpha_()*h);
        const Real y5 = f(m-beta_()*h);
        const Real y7 = f(m);
        const Real y9 = f(m+beta_()*h);
        const Real y11= f(m+alpha_()*h);
        const Real y13= f(b);

        const Real f1 = f(m-x1_()*h);
        const Real f2 = f(m+x1_()*h);
        const Real f3 = f(m-x2_()*h);
        const Real f4 = f(m+x2_()*h);
        const Real f5 = f(m-x3_()*h);
        const Real f6 = f(m+x3_()*h);

        Real acc=h*(0.0158271919734801831*(y1+y13)
                  +0.0942738402188500455*(f1+f2)
                  +0.1550719873365853963*(y3+y11)
                  +0.1888215739601824544*(f3+f4)
                  +0.1997734052268585268*(y5+y9)
                  +0.2249264653333395270*(f5+f6)
                  +0.2426110719014077338*y7);

        increaseNumberOfEvaluations(13);
        if (acc == 0.0 && (   f1 != 0.0 || f2 != 0.0 || f3 != 0.0
                           || f4 != 0.0 || f5 != 0.0 || f6 != 0.0)) {
            QL_FAIL("can not calculate absolute accuracy "
                    "from relative accuracy");
        }

        Real r = 1.0;
        if (useConvergenceEstimate_) {
            const Real integral2 = (h/6)*(y1+y13+5*(y5+y9));
            const Real integral1 = (h/1470)*(77*(y1+y13)+432*(y3+y11)+
                                             625*(y5+y9)+672*y7);

            if (std::fabs(integral2-acc) != 0.0)
                r = std::fabs(integral1-acc)/std::fabs(integral2-acc);
            if (r == 0.0 || r > 1.0)
                r = 1.0;
        }

        if (relAccuracy_ != Null<Real>())
            return std::min(absoluteAccuracy(), acc*relTol)/(r*QL_EPSILON);
        else {
            return absoluteAccuracy()/(r*QL_EPSILON);
        }
    }

    inline Real GaussLobattoIntegral::adaptivGaussLobattoStep(
                                     const boost::function<Real (Real)>& f,
                                     Real a, Real b, Real fa, Real fb,
                                     Real acc) const {
        QL_REQUIRE(numberOfEvaluations() < maxEvaluations(),
                   "max number of iterations reached");

        const Real h=(b-a)/2;
        const Real m=(a+b)/2;

        const Real mll=m-alpha_()*h;
        const Real ml =m-beta_()*h;
        const Real mr =m+beta_()*h;
        const Real mrr=m+alpha_()*h;

        const Real fmll= f(mll);
        const Real fml = f(ml);
        const Real fm  = f(m);
        const Real fmr = f(mr);
        const Real fmrr= f(mrr);
        increaseNumberOfEvaluations(5);

        const Real integral2=(h/6)*(fa+fb+5*(fml+fmr));
        const Real integral1=(h/1470)*(77*(fa+fb)
                                       +432*(fmll+fmrr)+625*(fml+fmr)+672*fm);

        // avoid 80 bit logic on x86 cpu
        volatile Real dist = acc + (integral1-integral2);
        if(Real(dist)==acc || mll<=a || b<=mrr) {
            QL_REQUIRE(m>a && b>m,"Interval contains no more machine number");
            return integral1;
        }
        else {
            return  adaptivGaussLobattoStep(f,a,mll,fa,fmll,acc)
                  + adaptivGaussLobattoStep(f,mll,ml,fmll,fml,acc)
                  + adaptivGaussLobattoStep(f,ml,m,fml,fm,acc)
                  + adaptivGaussLobattoStep(f,m,mr,fm,fmr,acc)
                  + adaptivGaussLobattoStep(f,mr,mrr,fmr,fmrr,acc)
                  + adaptivGaussLobattoStep(f,mrr,b,fmrr,fb,acc);
        }
    }

}
#endif
