//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_PREDICATES_FUNCTIONS_SIMD_SSE_SSE_IS_UNORD_HPP_INCLUDED
#define BOOST_SIMD_PREDICATES_FUNCTIONS_SIMD_SSE_SSE_IS_UNORD_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_SSE_SUPPORT
#include <boost/simd/predicates/functions/is_unord.hpp>
#include <boost/simd/sdk/meta/as_logical.hpp>

namespace boost { namespace simd { namespace ext
{
  BOOST_DISPATCH_IMPLEMENT  ( is_unord_, boost::simd::tag::sse_, (A0)
                            , ((simd_<single_<A0>,boost::simd::tag::sse_>))
                              ((simd_<single_<A0>,boost::simd::tag::sse_>))
                            )
  {
    typedef typename meta::as_logical<A0>::type result_type;

    BOOST_SIMD_FUNCTOR_CALL_REPEAT(2)
    {
      return _mm_cmpunord_ps(a0,a1);
    }
  };

} } }

#endif
#endif