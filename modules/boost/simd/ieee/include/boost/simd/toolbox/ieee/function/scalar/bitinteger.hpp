//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_IEEE_FUNCTION_SCALAR_BITINTEGER_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_IEEE_FUNCTION_SCALAR_BITINTEGER_HPP_INCLUDED
#include <boost/dispatch/meta/adapted_traits.hpp>
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/include/constants/properties.hpp>
#include <boost/simd/include/functions/is_positive.hpp>


/////////////////////////////////////////////////////////////////////////////
// Implementation when type  is fundamental_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::bitinteger_, tag::cpu_
                            , (A0)
                            , (scalar_< fundamental_<A0> >)
                            )
  {

    typedef typename dispatch::meta::as_integer<A0, signed>::type result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      using namespace boost::simd;
      return is_positive(a0) ?
	bitwise_cast<result_type, A0>(a0) :
	Signmask<result_type>()-bitwise_cast<result_type, A0>(a0); 
    }
  };
} } }


#endif
