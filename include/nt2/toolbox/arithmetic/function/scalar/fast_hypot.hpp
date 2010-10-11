//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_FAST_HYPOT_HPP_INCLUDED
#define NT2_TOOLBOX_ARITHMETIC_FUNCTION_SCALAR_FAST_HYPOT_HPP_INCLUDED
#include <nt2/sdk/constant/eps_related.hpp>
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/constant/real.hpp>

#include <nt2/include/functions/sqrt.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/include/functions/is_nan.hpp>
#include <nt2/include/functions/is_inf.hpp>
#include <nt2/include/functions/ldexp.hpp>

namespace nt2 { namespace functors
{

  //  no special validate for fast_hypot

  /////////////////////////////////////////////////////////////////////////////
  // Compute fast_hypot(const A0& a0, const A1& a1)
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct call<fast_hypot_,tag::scalar_(tag::arithmetic_),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1>
    struct result<This(A0,A1)> : 
      boost::result_of<meta::floating(A0,A1)>{};

    NT2_FUNCTOR_CALL_DISPATCH(
      2,
      A0,
      (3, (float,double, arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(2,  float)
    {
	// flibc do that in ::fast_hypotf(a0, a1) in asm with no more speed!
	// internal is 30% slower
	return nt2::sqrt(nt2::sqr(double(a0))+nt2::sqr(double(a1)));
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2, double)
    {
	return internal(a0, a1);
    }
    NT2_FUNCTOR_CALL_EVAL_IF(2, arithmetic_)
    {
      typedef typename NT2_CALL_RETURN_TYPE(2)::type type; 
      return nt2::fast_hypot(type(a0), type(a1)); 
    }
  private:
    
    template < class A0>
    static inline A0 internal(const A0& a0, const  A0& a1)
    {
      typedef typename meta::as_integer<A0, signed>::type  int_type;
      A0 x =  abs(a0);
      A0 y =  abs(a1);
      if (nt2::is_inf(x+y)) return Inf<float>();
      if (nt2::is_nan(x+y)) return Nan<float>();
      if (y > x) std::swap(x, y); 
      if (x*Eps<A0>() >=  y) return x;
      return x*nt2::sqrt(One<A0>()+nt2::sqr(y/x)); 
    }
  };
} }


      
#endif
