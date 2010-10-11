/*******************************************************************************
 *         Copyright 2003-2010 LASMEA UMR 6602 CNRS/U.B.P
 *         Copyright 2009-2010 LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_IMPL_EXPO_D_EXPO_REDUCTION_HPP_INCLUDED
#define NT2_TOOLBOX_EXPONENTIAL_FUNCTION_SCALAR_IMPL_EXPO_D_EXPO_REDUCTION_HPP_INCLUDED
#include <nt2/include/functions/oneplus.hpp>
#include <nt2/include/functions/round2even.hpp>
#include <nt2/include/functions/sqr.hpp>
#include <nt2/sdk/constant/digits.hpp>

namespace nt2
{
  namespace details
  {
    namespace internal
    {
      template < class A0> struct exp_reduction < A0, natural_tag, double>
      {
        static inline A0 isgemaxlog(const A0 & a0)
        {
          return is_ge(a0,integral_constant<A0,0x4086232bdd7abcd2ll>());
        }

        static inline A0 isleminlog(const A0 & a0)
        {
          return is_le(a0,integral_constant<A0,0xc086232bdd7abcd2ll>());
        }

        static inline A0 reduce(const A0& a0, A0& hi, A0& lo, A0& x)
        {
          A0 k  = round2even(Invlog_2<A0>()*a0);
          hi    = a0 - k * integral_constant<A0,0x3fe62e42fee00000ll>();
          lo    =      k * integral_constant<A0,0x3dea39ef35793c76ll>();
          x     = hi-lo;
          return k;
        }

        static inline A0 approx(const A0& x)
        {
	  typedef typename meta::scalar_of<A0>::type sA0;
          A0 const t = sqr(x);
          return x - t*horner<NT2_HORNER_COEFF_T(sA0, 5,
                                  ( 0x3e66376972bea4d0ll, 0xbebbbd41c5d26bf1ll
                                  , 0x3f11566aaf25de2cll, 0xbf66c16c16bebd93ll
                                  , 0x3fc555555555553ell
                                  )
                            )> (t);
        }
      };

      template < class A0 > struct exp_reduction < A0, two_tag, double>
      {
        static inline A0 isgemaxlog(const A0 & a0)
        {
          return is_ge(a0,integral_constant<A0,0x408ff80000000000ll>());
        }

        static inline A0 isleminlog(const A0 & a0)
        {
          return is_le(a0,integral_constant<A0,0xc08ff00000000000ll>());
        }

        static inline A0 reduce(const A0& a0, A0 , A0 , A0& x)
        {
          A0 k = round2even(a0);
          x = (a0 - k)*Log_2<A0>();
          return k;
        }

        static inline A0 approx(const A0& x)
        {
	  typedef typename meta::scalar_of<A0>::type sA0;
          const A0 t =  sqr(x);
          return x - t*horner<NT2_HORNER_COEFF_T(sA0, 5,
                                ( 0x3e66376972bea4d0ll
                                , 0xbebbbd41c5d26bf1ll
                                , 0x3f11566aaf25de2cll
                                , 0xbf66c16c16bebd93ll
                                , 0x3fc555555555553ell
                                )
                       )> (t);
        }
      };

      template < class A0 > struct exp_reduction < A0, ten_tag, double>
      {
        static inline A0 isgemaxlog(const A0 & a0)
        {
          return is_ge(a0,integral_constant<A0,0x40734413509f79fell>());
        }

        static inline A0 isleminlog(const A0 & a0)
        {
          return is_le(a0,integral_constant<A0,0xc0734413509f79fell>());
        }

        static inline A0 reduce(const A0& a0, A0&, A0&, A0& x)
        {
          A0 k  = round2even(integral_constant<A0,0x400a934f0979a372ll>()*a0);
          x     = a0-k*integral_constant<A0,0x3fd3440000000000ll>();
          x    -=  k*integral_constant<A0,0x3ed3509f79fef312ll>();
          return k;
        }

        static inline A0 approx(A0 x)
        {
	  typedef typename meta::scalar_of<A0>::type sA0;
          A0 xx =  sqr(x);
          A0 px = x*horner<NT2_HORNER_COEFF_T(sA0, 4,
                  (0x3fa4fd75f3062dd4ll,
                   0x40277d9474c55934ll,
                   0x40796b7a050349e4ll,
                   0x40a2b4798e134a01ll)
                  )> (xx);
          x =  px/( horner<NT2_HORNER_COEFF_T(sA0, 4,
                  (0x3ff0000000000000ll,
                   0x405545fdce51ca08ll,
                   0x4093e05eefd67782ll,
                   0x40a03f37650df6e2ll)
                  )> (xx)-px);
                return oneplus(x+x);
        }
      };
    }
  }
}


#endif

// /////////////////////////////////////////////////////////////////////////////
// End of d_expo_reduction.hpp
// /////////////////////////////////////////////////////////////////////////////
