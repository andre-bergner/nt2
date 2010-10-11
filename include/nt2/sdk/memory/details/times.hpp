/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_MEMORY_DETAILS_TIMES_HPP_INCLUDED
#define NT2_SDK_MEMORY_DETAILS_TIMES_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// CT/RT hybrid times functor
////////////////////////////////////////////////////////////////////////////////
#include <boost/mpl/times.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/tr1/functional.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <nt2/sdk/functor/preprocessor/call.hpp>

namespace nt2 { namespace details
{
  struct times
  {
    template<class Sig> struct result;

    template<class This, class A, class B>
    struct result<This(A const&,B const&)>
    {
      template<bool As, bool Bs, int Dummy = 0 >
      struct inner
	  {
        BOOST_TYPEOF_NESTED_TYPEDEF_TPL(nested, A() * B() );
        typedef typename nested::type type;
      };

      template<int Dummy>
      struct inner<false,false,Dummy>
      {
        typedef typename boost::mpl::times<A,B>::type type;
      };

      typedef typename inner< boost::is_arithmetic<A>::value
                                  , boost::is_arithmetic<B>::value
                                  >::type type;
    };

    template<bool A0, bool A1> struct status {};

    NT2_FUNCTOR_DISPATCH ( 2, (status < boost::is_arithmetic<A0>::value
                                      , boost::is_arithmetic<A1>::value>
                              )
                          , ( 4,( (status<true  , true> )
                                , (status<true  , false>)
                                , (status<false , true> )
                                , (status<false , false>)
                                )
                            )
                          , times
                          )

    NT2_FUNCTOR_EVAL_IF(2, (status<true,true>), times)
    {
      return a0*a1;
    }

    NT2_FUNCTOR_EVAL_IF(2, (status<false,false>), times)
    {
      return typename NT2_RETURN_TYPE(2,times)::type();
    }

    NT2_FUNCTOR_EVAL_IF(2, (status<false,true>) , times)
    {
      return A0::value * a1;
    }

    NT2_FUNCTOR_EVAL_IF(2, (status<true,false>) , times)
    {
      return a0 * A1::value;
    }
  };
} }

#endif
