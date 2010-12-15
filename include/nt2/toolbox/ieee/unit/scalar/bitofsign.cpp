//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#define NT2_UNIT_MODULE "nt2 ieee toolbox - bitofsign/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// Test behavior of ieee components in scalar mode
//////////////////////////////////////////////////////////////////////////////
#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>
#include <nt2/sdk/memory/buffer.hpp>
#include <nt2/sdk/constant/real.hpp>
#include <nt2/sdk/constant/infinites.hpp>
#include <nt2/toolbox/ieee/include/bitofsign.hpp>

NT2_TEST_CASE_TPL ( bitofsign_real__1,  NT2_REAL_TYPES)
{
  using nt2::bitofsign;
  using nt2::functors::bitofsign_;
  typedef typename nt2::meta::call<bitofsign_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 


  // specific values tests
  NT2_TEST_ULP_EQUAL(  bitofsign(-nt2::Zero<T>()), -nt2::Zero<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(  bitofsign(nt2::Inf<T>()), nt2::Zero<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(  bitofsign(nt2::Minf<T>()), -nt2::Zero<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(  bitofsign(nt2::One<T>()), nt2::Zero<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(  bitofsign(nt2::Zero<T>()), nt2::Zero<r_t>(), 0);
} // end of test for real_

NT2_TEST_CASE_TPL ( bitofsign_unsigned_int__1,  NT2_UNSIGNED_TYPES)
{
  using nt2::bitofsign;
  using nt2::functors::bitofsign_;
  typedef typename nt2::meta::call<bitofsign_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 


  // specific values tests
  NT2_TEST_ULP_EQUAL(  bitofsign(nt2::One<T>()), nt2::Zero<r_t>(), 0);
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( bitofsign_signed_int__1,  NT2_INTEGRAL_SIGNED_TYPES)
{
  using nt2::bitofsign;
  using nt2::functors::bitofsign_;
  typedef typename nt2::meta::call<bitofsign_(T)>::type r_t;
  typedef typename nt2::meta::upgrade<T>::type u_t;
  typedef T wished_r_t;

  // return type conformity test 
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl; 


  // specific values tests
  NT2_TEST_ULP_EQUAL(  bitofsign(nt2::Mone<T>()), T(1ull << sizeof(T)*8-1), 0);
  NT2_TEST_ULP_EQUAL(  bitofsign(nt2::One<T>()), nt2::Zero<r_t>(), 0);
  NT2_TEST_ULP_EQUAL(  bitofsign(nt2::Zero<T>()), nt2::Zero<r_t>(), 0);
} // end of test for signed_int_