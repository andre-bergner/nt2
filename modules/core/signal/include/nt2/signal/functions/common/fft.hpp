//==============================================================================
//         Copyright 2015 NumScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef NT2_SIGNAL_FUNCTIONS_COMMON_FFT_HPP_INCLUDED
#define NT2_SIGNAL_FUNCTIONS_COMMON_FFT_HPP_INCLUDED

#include <nt2/signal/functions/fft.hpp>
#include <nt2/include/functions/numel.hpp>
#include <nt2/core/container/table/table.hpp>
#include <nt2/core/container/dsl/as_terminal.hpp>
#include <nt2/core/utility/assign_swap.hpp>
#include <nt2/sdk/meta/type_id.hpp>
#include <boost/dispatch/meta/as_floating.hpp>
#include <fftw3.h>
#include <iostream>

namespace nt2 { namespace ext
{
  BOOST_DISPATCH_IMPLEMENT  ( fft_, tag::cpu_
                            , (A0)(S0)(A1)(S1)
                            , ((container_< nt2::tag::table_, single_<A0>, S0 >))
                              ((container_< nt2::tag::table_, complex_<single_<A1>>, S1 >))
                            )
  {
    typedef void result_type;
    typedef typename A0::value_type s_type;

    BOOST_FORCEINLINE result_type operator()(A0 const& in, A1& out) const
    {
      out.resize(nt2::extent(in));

      auto p  = fftwf_plan_dft_r2c_1d
                ( nt2::numel(in)
                , reinterpret_cast<s_type*>(const_cast<s_type*>( in.data()) )
                , reinterpret_cast<fftwf_complex*>( out.data() )
                , FFTW_ESTIMATE
                );

      fftwf_execute(p);
      fftwf_destroy_plan(p);
    }
  };

  BOOST_DISPATCH_IMPLEMENT  ( fft_, tag::cpu_
                            , (A0)(S0)(A1)(S1)
                            , ((container_< nt2::tag::table_, complex_<single_<A0>>, S0 >))
                              ((container_< nt2::tag::table_, complex_<single_<A1>>, S1 >))
                            )
  {
    typedef void result_type;
    typedef typename A0::value_type s_type;

    BOOST_FORCEINLINE result_type operator()(A0 const& in, A1& out) const
    {
      out.resize(nt2::extent(in));

      auto p = fftwf_plan_dft_1d (  nt2::numel(in)
                           , reinterpret_cast<fftwf_complex*>(const_cast<s_type* >( in.data())  )
                           , reinterpret_cast<fftwf_complex*>( out.data() )
                           , FFTW_FORWARD
                           , FFTW_ESTIMATE
                           );
      fftwf_execute(p);
      fftwf_destroy_plan(p);
    }
  };

  BOOST_DISPATCH_IMPLEMENT  ( fft_, tag::cpu_
                            , (A0)(S0)(A1)(S1)
                            , ((container_< nt2::tag::table_, double_<A0>, S0 >))
                              ((container_< nt2::tag::table_, complex_<double_<A1>>, S1 >))
                            )
  {
    typedef void result_type;
    typedef typename A0::value_type s_type;

    BOOST_FORCEINLINE result_type operator()(A0 const& in, A1& out) const
    {
      out.resize(nt2::extent(in));

      auto p  = fftw_plan_dft_r2c_1d
                ( nt2::numel(in)
                , reinterpret_cast<s_type*>(const_cast<s_type* >( in.data()) )
                , reinterpret_cast<fftw_complex*>( out.data() )
                , FFTW_ESTIMATE
                );

      fftw_execute(p);
      fftw_destroy_plan(p);
    }
  };

  BOOST_DISPATCH_IMPLEMENT  ( fft_, tag::cpu_
                            , (A0)(S0)(A1)(S1)
                            , ((container_< nt2::tag::table_, complex_<double_<A0>>, S0 >))
                              ((container_< nt2::tag::table_, complex_<double_<A1>>, S1 >))
                            )
  {
    typedef void result_type;
    typedef typename A0::value_type s_type;

    BOOST_FORCEINLINE result_type operator()(A0 const& in, A1& out) const
    {
      out.resize(nt2::extent(in));

      auto p = fftw_plan_dft_1d (  nt2::numel(in)
                           , reinterpret_cast<fftw_complex*>(const_cast<s_type* >( in.data())  )
                           , reinterpret_cast<fftw_complex*>( out.data() )
                           , FFTW_FORWARD
                           , FFTW_ESTIMATE
                           );
      fftw_execute(p);
      fftw_destroy_plan(p);
    }
  };

  BOOST_DISPATCH_IMPLEMENT  ( run_assign_, tag::cpu_
                            , (A0)(A1)(N)
                            , ((ast_<A0, nt2::container::domain>))
                              ((node_ < A1, nt2::tag::fft_
                                      , N , nt2::container::domain
                                      >
                              ))
                            )

  {
    typedef A0& result_type;
    typedef typename A0::value_type s0_type;
    typedef typename A1::value_type s1_type;
    typedef nt2::memory::container<tag::table_, s1_type, nt2::_1D>   isemantic;
    typedef nt2::memory::container<tag::table_, s0_type, nt2::_1D>   osemantic;

    result_type operator()(A0& o, const A1& i) const
    {
      NT2_AS_TERMINAL_IN (isemantic, in , boost::proto::child_c<0>(i));
      NT2_AS_TERMINAL_OUT(osemantic, out, o);

      nt2::fft( boost::proto::value(in), boost::proto::value(o) );

      assign_swap(o, out);

      return o;
    }
  };
} }

#endif
