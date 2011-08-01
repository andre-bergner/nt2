//==============================================================================
//         Copyright 2003 - 2011 LASMEA UMR 6602 CNRS/Univ. Clermont II         
//         Copyright 2009 - 2011 LRI    UMR 8623 CNRS/Univ Paris Sud XI         
//                                                                              
//          Distributed under the Boost Software License, Version 1.0.          
//                 See accompanying file LICENSE.txt or copy at                 
//                     http://www.boost.org/LICENSE_1_0.txt                     
//==============================================================================
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_SSE_SSE2_SQRT_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTION_SIMD_SSE_SSE2_SQRT_HPP_INCLUDED
#include <boost/dispatch/meta/as_integer.hpp>
#include <boost/simd/include/constants/digits.hpp>
#include <boost/dispatch/meta/strip.hpp>

#include <boost/simd/include/functions/tofloat.hpp>
#include <boost/simd/include/functions/toint.hpp>
#include <boost/simd/include/functions/is_gtz.hpp>
#include <boost/simd/include/functions/sqr.hpp>
#include <boost/simd/include/functions/shri.hpp>

/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is uint8_t
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::sqrt_, tag::cpu_
                            , (A0)
                            , ((simd_<uint8_<A0>,boost::simd::tag::sse_>))
                            )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      using namespace boost::simd;

      A0 const na  = is_nez(a0);
      A0 n   = add(shri(a0, 4), Four<A0>());
      A0 n1  = shri(n+a0/n, 1);

      A0 ok = lt(n1, n);
      n  = select(ok, n1, n);
      n1 = select(ok, shri(n+a0/n, 1), n1);

      ok = lt(n1, n);
      n  = select(ok, n1, n);
      n  = seladd( gt(n*n,a0), n, Mone<A0>());

      return seladd(na, Zero<A0>(), n);

//       A0 msk = b_and(is_less_equal(n1,n), na);

//       n   = select(msk,n1,n);
//       n1  = sqr(n);
//       msk = b_or(gt(n1,a0), b_and(is_eqz(n1), na));
//       n   = seladd( msk, n, Mone<A0>());

      return seladd(na, Zero<A0>(), n);
    }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is arithmetic_
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::sqrt_, tag::cpu_
                            , (A0)
                            , ((simd_<arithmetic_<A0>,boost::simd::tag::sse_>))
                            )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      typedef typename dispatch::meta::as_integer<A0,signed>::type     int_type;
      typedef typename dispatch::meta::as_integer<A0,unsigned>::type  uint_type;
      return b_and( is_gtz(a0)
                  , simd::
                    native_cast<int_type>(sqrt( simd::
                                                native_cast<uint_type>(a0)))
                  );
    }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is double
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::sqrt_, tag::cpu_
                            , (A0)
                            , ((simd_<double_<A0>,boost::simd::tag::sse_>))
                            )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      A0 that = { _mm_sqrt_pd(a0)}; return that;
    }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is float
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::sqrt_, tag::cpu_
                            , (A0)
                            , ((simd_<float_<A0>,boost::simd::tag::sse_>))
                            )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      A0 that = { _mm_sqrt_ps(a0)}; return that;
    }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is uint32_t
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::sqrt_, tag::cpu_
                            , (A0)
                            , ((simd_<uint32_<A0>,boost::simd::tag::sse_>))
                            )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      using namespace boost::simd;

      A0 const na = is_nez(a0);
      A0 const z1 = add(shri(a0, 6),    boost::simd::integral_constant<A0,16>());
      A0 const z2 = add(shri(a0,10),   boost::simd::integral_constant<A0,256>());
      A0 const z3 = add(shri(a0,13),  boost::simd::integral_constant<A0,2048>());
      A0 const z4 = add(shri(a0,16), boost::simd::integral_constant<A0,16384>());
      static A0 const one = One<A0>();

      A0 n  = select( gt(a0, boost::simd::integral_constant<A0,177155824>())
                  , z4
                  , select( gt(a0, boost::simd::integral_constant<A0,4084387>())
                        , z3
                        , select( gt(a0, boost::simd::integral_constant<A0,31679>())
                                , z2
                                , z1
                                )
                        )
                  );
      A0 ok =  is_gtz(n);
      n = select(ok, n, one);
      A0 n1 = select(ok, shri(n+a0/n, 1), one);

      ok = lt(n1, n);
      n  = select(ok, n1, n);
      n1 = select(ok, shri(n+a0/n, 1), n1);

      ok =  lt(n1, n);
      n  = select(ok, n1, n);
      n1 = select(ok, shri(n+a0/n, 1), n1);

      ok =  lt(n1, n);
      n  = select(ok, n1, n);

      A0 tmp = sub(n*sub(n, one), one);
      n  = seladd( is_greater_equal(tmp+n,a0), n, Mone<A0>());
      n =  seladd(na, Zero<A0>(), n);

      return n;
    }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is uint64_t
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::sqrt_, tag::cpu_
                            , (A0)
                            , ((simd_<uint64_<A0>,boost::simd::tag::sse_>))
                            )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      return simd::native_cast<A0>(toint(sqrt(tofloat(a0))));
    }
  };
} } }


/////////////////////////////////////////////////////////////////////////////
// Implementation when type A0 is uint16_t
/////////////////////////////////////////////////////////////////////////////
namespace boost { namespace simd { namespace ext
{
  BOOST_SIMD_FUNCTOR_IMPLEMENTATION( boost::simd::tag::sqrt_, tag::cpu_
                            , (A0)
                            , ((simd_<uint16_<A0>,boost::simd::tag::sse_>))
                            )
  {

    typedef A0 result_type;

    BOOST_SIMD_FUNCTOR_CALL(1)
    {
      using namespace boost::simd;

      A0 const  na = is_nez(a0);
      A0 const  z1 = add(shri(a0, 6), boost::simd::integral_constant<A0, 16>());
      A0 const  z2 = add(shri(a0,10), boost::simd::integral_constant<A0, 256>());
      A0 const  C1 = boost::simd::integral_constant<A0, 31679>();
      //////////////////////////////////////////////////////////////////////////
      // choose a proper starting point for approximation
      //////////////////////////////////////////////////////////////////////////
      A0 n  = select(lt(a0, C1), z1, z2);
      A0 ok =  is_gtz(n);
      static A0 const one = One<A0>();
      n  = select(ok, n, one);

      A0 n1 = select(ok, shri(n+a0/n, 1), one);

      ok = lt(n1, n);
      n  = select(ok, n1, n);
      n1 = select(ok, shri(n+a0/n, 1), n1);

      ok = lt(n1, n);
      n  = select(ok, n1, n);
      n1 = select(ok, shri(n+a0/n, 1), n1);

      ok =  lt(n1, n);
      n  = select(ok, n1, n);
      n  = seladd( gt(n*n,a0), n, Mone<A0>());

      return seladd(na, Zero<A0>(), n);
    }
  };
} } }


#endif
