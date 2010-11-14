//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_SELSUB_HPP_INCLUDED
#define NT2_TOOLBOX_BITWISE_FUNCTION_SCALAR_SELSUB_HPP_INCLUDED


namespace nt2 { namespace functors
{

  template<class Info>
  struct validate<selsub_,tag::scalar_(tag::arithmetic_),Info>
  {
    typedef boost::mpl::true_ result_type;
  };

  /////////////////////////////////////////////////////////////////////////////
  // Compute selsub(const A0& a0, const A1& a1, const A2& a2)
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  // Implementation when type  is fundamental_
  /////////////////////////////////////////////////////////////////////////////
  template<class Info>
  struct  call<selsub_,tag::scalar_(tag::arithmetic_),fundamental_,Info> : callable
  {
    template<class Sig> struct result;
    template<class This,class A0,class A1,class A2>
    struct result<This(A0,A1,A2)> : 
      boost::result_of<meta::arithmetic(A1,A2)>{};

    NT2_FUNCTOR_CALL(3)
    {
      typedef typename NT2_CALL_RETURN_TYPE(3)::type type;
      if (a0) return type(a1)-type(a2); else return type(a1); 
    }

  };
} }

#endif
/// Revised by jt the 13/11/2010
