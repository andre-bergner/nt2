//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_MEMORY_FUNCTIONS_SIMD_SSE_SSE_ALIGNED_STORE_HPP_INCLUDED
#define BOOST_SIMD_MEMORY_FUNCTIONS_SIMD_SSE_SSE_ALIGNED_STORE_HPP_INCLUDED
#ifdef BOOST_SIMD_HAS_SSE_SUPPORT

#include <boost/simd/memory/functions/aligned_store.hpp>
#include <boost/simd/memory/functions/details/check_ptr.hpp>
#include <boost/simd/memory/iterator_category.hpp>
#include <boost/dispatch/functor/preprocessor/call.hpp>
#include <boost/dispatch/attributes.hpp>
#include <boost/simd/meta/is_pointing_to.hpp>

namespace boost { namespace simd { namespace ext
{
  /// INTERNAL ONLY - SSE single SIMD store without offset
  BOOST_DISPATCH_IMPLEMENT          ( aligned_store_
                                    , boost::simd::tag::sse_
                                    , (A0)(A1)
                                    , ((simd_ < single_<A0>
                                              , boost::simd::tag::sse_
                                              >
                                      ))
                                      (iterator_< scalar_< single_<A1> > >)
                                    )
  {
    typedef void result_type;

    BOOST_FORCEINLINE result_type operator()(__m128 a0, A1 a1) const
    {
      BOOST_SIMD_DETAILS_CHECK_PTR(a1, sizeof(__m128));
      _mm_store_ps(a1,a0);
    }
  };

} } }

#endif
#endif
