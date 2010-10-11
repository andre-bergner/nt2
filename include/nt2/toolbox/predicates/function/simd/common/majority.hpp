//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_COMMON_MAJORITY_HPP_INCLUDED
#define NT2_TOOLBOX_PREDICATES_FUNCTION_SIMD_COMMON_MAJORITY_HPP_INCLUDED
#include <nt2/sdk/meta/strip.hpp>
#include <nt2/include/functions/is_nez.hpp>


namespace nt2 { namespace functors
{
  //  no special validate for majority

  /////////////////////////////////////////////////////////////////////////////
  // Compute majority(const A0& a0, const A0& a1, const A0& a2)
  /////////////////////////////////////////////////////////////////////////////
  template<class Extension,class Info>
  struct call<majority_,
              tag::simd_(tag::arithmetic_,Extension),Info>
  {
    template<class Sig> struct result;
    template<class This,class A0>
    struct result<This(A0,A0,A0)>
      : meta::strip<A0>{};//

    NT2_FUNCTOR_CALL(3)
    {
      A0 aa0 = is_nez(a0);
      A0 aa1 = is_nez(a1);
      A0 aa2 = is_nez(a2);
      return b_or(b_or(b_and(aa0, aa1),b_and(aa1, aa2)),b_and(aa2, aa0));
    }
  };
} }

      
#endif
