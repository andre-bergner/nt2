//==============================================================================
//         Copyright 2003 - 2012   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2014   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_LINALG_FUNCTIONS_CSNE_HPP_INCLUDED
#define NT2_LINALG_FUNCTIONS_CSNE_HPP_INCLUDED

/*!
  @file
  @brief Defines Semi-Normal Equations that solve R'(Rx) = A'b with a one-step
  iterative refinement
  (based on Qr factorization)
**/

#include <nt2/include/functor.hpp>

namespace nt2
{
  namespace tag
  {
    /// @brief Defines sne function tag
    struct csne_ : ext::abstract_<csne_>
    {
      /// INTERNAL ONLY
      typedef ext::abstract_<csne_> parent;
      template<class... Args>
      static BOOST_FORCEINLINE BOOST_AUTO_DECLTYPE dispatch(Args&&... args)
      BOOST_AUTO_DECLTYPE_BODY( dispatching_csne_( ext::adl_helper(), static_cast<Args&&>(args)... ) )
    };
  }
  namespace ext
  {
    template<class Site, class... Ts>
    BOOST_FORCEINLINE generic_dispatcher<tag::csne_, Site> dispatching_csne_(adl_helper, boost::dispatch::meta::unknown_<Site>, boost::dispatch::meta::unknown_<Ts>...)
    {
      return generic_dispatcher<tag::csne_, Site>();
    }
    template<class... Args>
    struct impl_csne_;
  }

  /*!
    @brief

    @param
    @param

    @return
  **/
  NT2_FUNCTION_IMPLEMENTATION_TPL (tag::csne_, csne
                                  , (A0 const&)(A1 const&)
                                  , 2
                                  );
}

#endif
