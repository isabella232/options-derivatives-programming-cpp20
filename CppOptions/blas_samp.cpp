//
//  blas_samp.cpp
//
// (c) 2020 Carlos Oliveira
//   This code is part of the book
//   "Options and Derivatives Programming in C++20: Algorithms and Programming Techniques for the Financial Industry 2nd Edition"
//    by Carlos Oliveira, Apress, 2020.
// For more information, visit http://coliveira.net


#include "blas_samp.hpp"

#include "Matrix.h"


#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <boost/numeric/ublas/lu.hpp>

namespace ublas = boost::numeric::ublas;

std::vector<double> preMultiply(const std::vector<double> &v, Matrix &m)
{
    using namespace ublas;
    ublas::vector<double> vec;
    std::copy(v.begin(), v.end(), vec.end());

    int d1 = m.numRows();
    int d2 = (int)m[0].size();
    ublas::matrix<double> M(d1, d2);

    for (int i = 0; i < d1; ++i)
    {
        for (int j = 0; j < d2; ++j)
        {
            M(i,j) = m[i][j];
        }
    }

    vector<double> pv = prod(vec, M);

    std::vector<double> res;
    std::copy(pv.begin(), pv.end(), res.end());
    return res;
}
