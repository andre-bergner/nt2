//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_ARITHMETIC_FUNCTIONS_SCALAR_FLOOR_HPP_INCLUDED
#define BOOST_SIMD_ARITHMETIC_FUNCTIONS_SCALAR_FLOOR_HPP_INCLUDED

#include <boost/simd/arithmetic/functions/floor.hpp>
#include <boost/simd/sdk/math.hpp>
#include <boost/dispatch/attributes.hpp>
#include <cmath>

namespace boost { namespace simd { namespace ext
{
  BOOST_DISPATCH_IMPLEMENT          ( floor_, tag::cpu_
                                    , (A0)
                                    , (scalar_< single_<A0> >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE BOOST_SIMD_FUNCTOR_CALL(1)
    {
      #ifdef BOOST_SIMD_HAS_FLOORF
      return ::floorf(a0);
      #else
      return std::floor(a0);
      #endif
    }
  };


  BOOST_DISPATCH_IMPLEMENT          ( floor_, tag::cpu_
                                    , (A0)
                                    , (scalar_< double_<A0> >)
                                    )
  {
    typedef A0 result_type;

    BOOST_FORCEINLINE BOOST_SIMD_FUNCTOR_CALL(1)
    {
      return ::floor(a0);
    }
  };
} } }

#endif
