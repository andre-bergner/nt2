//////////////////////////////////////////////////////////////////////////////
///   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
///   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
///
///          Distributed under the Boost Software License, Version 1.0
///                 See accompanying file LICENSE.txt or copy at
///                     http://www.boost.org/LICENSE_1_0.txt
//////////////////////////////////////////////////////////////////////////////
#ifndef BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_DIST_HPP_INCLUDED
#define BOOST_SIMD_TOOLBOX_ARITHMETIC_FUNCTIONS_DIST_HPP_INCLUDED
#include <boost/simd/include/simd.hpp>
#include <boost/dispatch/include/functor.hpp>

/*!
 * \internal functor \endinternal
 * \ingroup boost_simd_arithmetic
 * \defgroup dist dist function
 *
 * \par Description
 * this is $\|a_0-a_1\|$, and is always properly computed
 *
 * \par Header file
 * 
 * \code
 * #include <nt2/include/functions/dist.hpp>
 * \endcode
 * 
 * 
 * \synopsis
 *
 * \code
 * namespace boost::simd
 * {
 *   template <class A0>
 *     meta::call<tag::dist_(A0,A0)>::type
 *     dist(const A0 & a0,const A0 & a1);
 * }
 * \endcode
 *
 * \param a0 is the first parameter of dist
 * \param a1 is the second parameter of dist
 * 
 * \return a value of the common type of the parameters
 *  
 * \internal end_functor \endinternal
**/

namespace boost { namespace simd { namespace tag
  {         
    /*!
     * \internal tag \endinternal
     * \file
     * \brief Define the tag dist_ of functor dist 
     *        in namespace boost::simd::tag
     * \internal end_tag \endinternal
    **/
    struct dist_ {};
  }
  BOOST_DISPATCH_FUNCTION_IMPLEMENTATION(tag::dist_, dist, 2)
} }

#endif

// modified by jt the 25/12/2010
