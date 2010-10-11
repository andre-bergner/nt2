/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_META_AS_UNSIGNED_HPP_INCLUDED
#define NT2_SDK_META_AS_UNSIGNED_HPP_INCLUDED

#include <boost/mpl/eval_if.hpp>
#include <boost/mpl/identity.hpp>
#include <nt2/sdk/functor/category.hpp>
#include <nt2/sdk/meta/category_of.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/type_traits/make_unsigned.hpp>

namespace nt2 { namespace details
{
	template<class T, class Category>
	struct  as_unsigned;

  template<class T>
  struct  as_unsigned<T,tag::scalar_(tag::arithmetic_)>		
				: boost::mpl::eval_if < boost::mpl::bool_	<	boost::is_integral<T>::value
																							   && !boost::is_same<bool,T>::value
																									>
															, boost::make_unsigned<T>
                              , boost::mpl::identity<T>
                              > {};
} }

namespace nt2 { namespace meta
{
	template<class T>
  struct  as_unsigned
				: details::as_unsigned<T,typename category_of<T>::type::tag > {};
} }

#endif
