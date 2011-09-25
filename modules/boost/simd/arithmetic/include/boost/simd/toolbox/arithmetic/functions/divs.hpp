//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_DIVS_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_DIVS_HPP_INCLUDED
#include <boost/simd/include/simd.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \internal functor \endinternal
 * \ingroup boost_simd_arithmetic
 * \defgroup divs divs function
 *
 * \par Description
 * return the saturated  division of the operandsin the input type
 * \par
 * This only differs from standard \c / in division by zero
 * cases, and also for the division of Valmin by -1 that
 * produces Valmax
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/divs.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::divs_(A0,A0)>::type
 *     divs(const A0 & a0,const A0 & a1);
 * }
 * \endcode
 *
 * \param a0 is the first parameter of divs
 * \param a1 is the second parameter of divs
 * 
 * \return a value of the common type of the parameters
 *  
 * \internal end_functor \endinternal
**/

namespace boost { namespace simd {
  namespace tag
  {
    /*!
     * \internal tag \endinternal
     * \file
     * \brief Define the tag divs_ of functor divs 
     *        in namespace boost::simd::tag
     * \internal end_tag \endinternal
    **/
    struct divs_ {};
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::divs_, divs, 2)
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::divs_, saturated_div, 2) 
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::divs_, rdivide, 2)
  
  template<class A0, class A1>
  BOOST_DISPATCH_FORCE_INLINE
  typename dispatch::meta::call<tag::divs_(A0, A1)>::type
  ldivide(A0 const& a0, A1 const& a1)
  {
    return dispatch::make_functor<tag::divs_, A0>::type()(a1, a0);
  }
  
  template<class A0, class A1>
  BOOST_DISPATCH_FORCE_INLINE
  typename dispatch::meta::call<tag::divs_(A0, A1)>::type
  ldiv(A0 const& a0, A1 const& a1)
  {
    return dispatch::make_functor<tag::divs_, A0>::type()(a1, a0);
  }
  
} }

#endif
