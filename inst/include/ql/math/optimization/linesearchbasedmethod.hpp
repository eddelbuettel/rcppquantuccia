/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2006 Ferdinando Ametrano
 Copyright (C) 2009 Frédéric Degraeve

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

/*! \file linesearchbasedmethod.hpp
    \brief Abstract optimization method class
*/

#ifndef quantlib_line_search_based_optimization_method_h
#define quantlib_line_search_based_optimization_method_h

#include <ql/math/optimization/method.hpp>
#include <ql/math/array.hpp>
#include <ql/math/optimization/problem.hpp>
#include <ql/math/optimization/linesearch.hpp>
#include <ql/math/optimization/armijo.hpp>

#include <boost/shared_ptr.hpp>

namespace QuantLib {

    class LineSearch;

    class LineSearchBasedMethod : public OptimizationMethod {
      public:
        LineSearchBasedMethod(const boost::shared_ptr<LineSearch>& lSearch =
                                            boost::shared_ptr<LineSearch>());
        virtual ~LineSearchBasedMethod() {}

        virtual EndCriteria::Type minimize(Problem& P,
                                           const EndCriteria& endCriteria);
      protected:
        //! computes the new search direction
        virtual Disposable<Array>
        getUpdatedDirection(const Problem &P,
                            Real gold2,
                            const Array& gradient) = 0;
        //! line search
        boost::shared_ptr<LineSearch> lineSearch_;
    };

    // implementation

    inline LineSearchBasedMethod::LineSearchBasedMethod(
                           const boost::shared_ptr<LineSearch>& lineSearch)
    : lineSearch_(lineSearch) {
        if (!lineSearch_)
           lineSearch_ = boost::shared_ptr<LineSearch>(new ArmijoLineSearch);
    }

    inline EndCriteria::Type
    LineSearchBasedMethod::minimize(Problem& P,
                                    const EndCriteria& endCriteria) {
        // Initializations
        Real ftol = endCriteria.functionEpsilon();
        Size maxStationaryStateIterations_
            = endCriteria.maxStationaryStateIterations();
        EndCriteria::Type ecType = EndCriteria::None;   // reset end criteria
        P.reset();                                      // reset problem
        Array x_ = P.currentValue();              // store the starting point
        Size iterationNumber_ = 0;
        // dimension line search
        lineSearch_->searchDirection() = Array(x_.size());
        bool done = false;

        // function and squared norm of gradient values;
        Real fnew, fold, gold2;
        Real fdiff;
        // classical initial value for line-search step
        Real t = 1.0;
        // Set gradient g at the size of the optimization problem
        // search direction
        Size sz = lineSearch_->searchDirection().size();
        Array prevGradient(sz), d(sz), sddiff(sz), direction(sz);
        // Initialize cost function, gradient prevGradient and search direction
        P.setFunctionValue(P.valueAndGradient(prevGradient, x_));
        P.setGradientNormValue(DotProduct(prevGradient, prevGradient));
        lineSearch_->searchDirection() = -prevGradient;

        bool first_time = true;
        // Loop over iterations
        do {
            // Linesearch
            if (!first_time)
                prevGradient = lineSearch_->lastGradient();
            t = (*lineSearch_)(P, ecType, endCriteria, t);
            // don't throw: it can fail just because maxIterations exceeded
            //QL_REQUIRE(lineSearch_->succeed(), "line-search failed!");
            if (lineSearch_->succeed())
            {
                // Updates

                // New point
                x_ = lineSearch_->lastX();
                // New function value
                fold = P.functionValue();
                P.setFunctionValue(lineSearch_->lastFunctionValue());
                // New gradient and search direction vectors

                // orthogonalization coef
                gold2 = P.gradientNormValue();
                P.setGradientNormValue(lineSearch_->lastGradientNorm2());

                // conjugate gradient search direction
                direction = getUpdatedDirection(P, gold2, prevGradient);

                sddiff = direction - lineSearch_->searchDirection();
                lineSearch_->searchDirection() = direction;
                // Now compute accuracy and check end criteria
                // Numerical Recipes exit strategy on fx (see NR in C++, p.423)
                fnew = P.functionValue();
                fdiff = 2.0*std::fabs(fnew-fold) /
                        (std::fabs(fnew) + std::fabs(fold) + QL_EPSILON);
                if (fdiff < ftol ||
                    endCriteria.checkMaxIterations(iterationNumber_, ecType)) {
                    endCriteria.checkStationaryFunctionValue(0.0, 0.0,
                        maxStationaryStateIterations_, ecType);
                    endCriteria.checkMaxIterations(iterationNumber_, ecType);
                    return ecType;
                }
                P.setCurrentValue(x_);      // update problem current value
                ++iterationNumber_;         // Increase iteration number
                first_time = false;
            } else {
                done = true;
            }
        } while (!done);
        P.setCurrentValue(x_);
        return ecType;
    }

}

#endif
