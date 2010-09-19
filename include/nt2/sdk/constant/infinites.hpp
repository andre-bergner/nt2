/*******************************************************************************
 *         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
 *         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
 *
 *          Distributed under the Boost Software License, Version 1.0.
 *                 See accompanying file LICENSE.txt or copy at
 *                     http://www.boost.org/LICENSE_1_0.txt
 ******************************************************************************/
#ifndef NT2_SDK_CONSTANT_INFINITES_HPP_INCLUDED
#define NT2_SDK_CONSTANT_INFINITES_HPP_INCLUDED

////////////////////////////////////////////////////////////////////////////////
// Base class for generating an integral constant
////////////////////////////////////////////////////////////////////////////////
namespace nt2 { namespace constants
{
    struct inf_ 	{};
    struct m_inf_	{}; 
} }

namespace nt2
{
  NT2_CONSTANT_IMPLEMENTATION(nt2::constants::inf_         , Inf         )
  NT2_CONSTANT_IMPLEMENTATION(nt2::constants::m_inf_       , Minf        )
}

#include <nt2/sdk/constant/details/infinites.hpp>

#endif
