//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_COMMON_BOOLEAN_HPP_INCLUDED
#define NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_COMMON_BOOLEAN_HPP_INCLUDED
#include <nt2/sdk/constant/digits.hpp>
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_nez.hpp>


namespace nt2 { namespace functors
{
  //  no special validate for boolean

  /////////////////////////////////////////////////////////////////////////////
  // Compute boolean(const A0& a0)
  /////////////////////////////////////////////////////////////////////////////
  template<class Extension,class Info>
  struct call<boolean_,
              tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0)>
      : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL_DISPATCH(
      1,
      typename nt2::meta::scalar_of<A0>::type,
      (2, (int64_t,arithmetic_))
    )

    NT2_FUNCTOR_CALL_EVAL_IF(1,     int64_t)
    {
      //scalaire a 4 cycles
      //       A0 r;
      //        map<boolean_>(a0, r);
      //        return r;                                         //8 cycles
      //      return A0(boolean(a0[0]),boolean(a0[1]));           //15 cycles
      //      return select(iseqz(a0),Zero<A0>(),One<A0>());      //17 cycles
      //     return seladd(isnez(a0),Zero<A0>(),One<A0>());         //3.8 cycles
      return isnez(a0)&One<A0>();
    }
    NT2_FUNCTOR_CALL_EVAL_IF(1, arithmetic_)
    {
      return isnez(a0)&One<A0>();
    }
  };
} }

      
#endif
