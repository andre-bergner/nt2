//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2012   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#define NT2_UNIT_MODULE "nt2 ieee toolbox - predecessor/scalar Mode"

//////////////////////////////////////////////////////////////////////////////
// unit test behavior of ieee components in scalar mode
//////////////////////////////////////////////////////////////////////////////
/// created by jt the 04/12/2010
///
#include <nt2/ieee/include/functions/predecessor.hpp>
#include <nt2/include/functions/prev.hpp>
#include <nt2/include/constants/eps_related.hpp>

#include <boost/type_traits/is_same.hpp>
#include <nt2/sdk/functor/meta/call.hpp>
#include <nt2/sdk/meta/as_integer.hpp>
#include <nt2/sdk/meta/as_floating.hpp>
#include <nt2/sdk/meta/as_signed.hpp>
#include <nt2/sdk/meta/upgrade.hpp>
#include <nt2/sdk/meta/downgrade.hpp>
#include <nt2/sdk/meta/scalar_of.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <boost/type_traits/common_type.hpp>
#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

#include <nt2/constant/constant.hpp>

#include <nt2/include/functions/next.hpp>



NT2_TEST_CASE_TPL ( predecessor_real__1_0,  NT2_REAL_TYPES)
{

  using nt2::predecessor;
  using nt2::tag::predecessor_;
  typedef typename nt2::meta::call<predecessor_(T)>::type r_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;



  // specific values tests
  NT2_TEST_EQUAL(predecessor(nt2::Inf<T>()), nt2::Valmax<r_t>());
  NT2_TEST_EQUAL(predecessor(nt2::Minf<T>()), nt2::Nan<r_t>());
  NT2_TEST_EQUAL(predecessor(nt2::Mone<T>()), nt2::Mone<r_t>()-nt2::Eps<r_t>());
  NT2_TEST_EQUAL(predecessor(nt2::Nan<T>()), nt2::Nan<r_t>());
  NT2_TEST_EQUAL(predecessor(nt2::One<T>()), nt2::One<r_t>()-nt2::Eps<r_t>()/2);
  NT2_TEST_EQUAL(predecessor(nt2::Valmin<T>()), nt2::Minf<r_t>());
  NT2_TEST_EQUAL(predecessor(nt2::Zero<T>()), -nt2::Bitincrement<T>());
} // end of test for floating_

NT2_TEST_CASE_TPL ( predecessor_unsigned_int__1_0,  NT2_UNSIGNED_TYPES)
{

  using nt2::predecessor;
  using nt2::tag::predecessor_;
  typedef typename nt2::meta::call<predecessor_(T)>::type r_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;



  // specific values tests
  NT2_TEST_EQUAL(predecessor(nt2::One<T>()), nt2::Zero<r_t>());
  NT2_TEST_EQUAL(predecessor(nt2::Valmin<T>()), nt2::Valmin<r_t>());
  NT2_TEST_EQUAL(predecessor(nt2::Zero<T>()), nt2::Zero<r_t>());
} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( predecessor_signed_int__1_0,  NT2_INTEGRAL_SIGNED_TYPES)
{

  using nt2::predecessor;
  using nt2::tag::predecessor_;
  typedef typename nt2::meta::call<predecessor_(T)>::type r_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;



  // specific values tests
  NT2_TEST_EQUAL(predecessor(nt2::Mone<T>()), -nt2::Two<r_t>());
  NT2_TEST_EQUAL(predecessor(nt2::One<T>()), nt2::Zero<r_t>());
  NT2_TEST_EQUAL(predecessor(nt2::Valmin<T>()), nt2::Valmin<r_t>());
  NT2_TEST_EQUAL(predecessor(nt2::Zero<T>()), nt2::Mone<r_t>());
} // end of test for signed_int_

NT2_TEST_CASE_TPL ( predecessor_real__2_1,  NT2_REAL_TYPES)
{

  using nt2::predecessor;
  using nt2::tag::predecessor_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<predecessor_(T,iT)>::type r_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;


} // end of test for floating_

NT2_TEST_CASE_TPL ( predecessor_unsigned_int__2_1,  NT2_UNSIGNED_TYPES)
{

  using nt2::predecessor;
  using nt2::tag::predecessor_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<predecessor_(T,iT)>::type r_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;


} // end of test for unsigned_int_

NT2_TEST_CASE_TPL ( predecessor_signed_int__2_1,  NT2_INTEGRAL_SIGNED_TYPES)
{

  using nt2::predecessor;
  using nt2::tag::predecessor_;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::as_integer<T>::type iT;
  typedef typename nt2::meta::call<predecessor_(T,iT)>::type r_t;
  typedef T wished_r_t;


  // return type conformity test
  NT2_TEST( (boost::is_same < r_t, wished_r_t >::value) );
  std::cout << std::endl;


} // end of test for signed_int_
