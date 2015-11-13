//==============================================================================
//         Copyright 2015          NumScale SAS
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#include <nt2/include/functions/fft.hpp>
#include <nt2/include/functions/linspace.hpp>
#include <nt2/include/functions/cons.hpp>
#include <nt2/table.hpp>

#include <nt2/sdk/unit/tests.hpp>
#include <nt2/sdk/unit/module.hpp>

#include <nt2/include/functions/zeros.hpp>
#include <nt2/include/functions/linspace.hpp>
#include <nt2/include/functions/multiplies.hpp>
#include <nt2/include/functions/plus.hpp>
#include <nt2/include/functions/sin.hpp>
#include <nt2/include/functions/real.hpp>

#include <boost/dispatch/meta/as.hpp>
#include <complex>

#include <vector>

NT2_TEST_CASE_TPL( fft_real_complex, (double)(float))
{
  T Fs = 1000;
  T Period = 1./Fs;
  int L = 1024;

  nt2::table<T, nt2::_1D> in = nt2::zeros(1,L,boost::dispatch::meta::as_<T>());

  nt2::table<T, nt2::_1D> t = nt2::linspace(T(0),T(L-1),L)*Period;

  in = T(0.7)*nt2::sin(T(100)*nt2::Pi<T>()*t) + nt2::sin(T(240)*nt2::Pi<T>()*t);

  nt2::table<std::complex<T>, nt2::_1D > out = nt2::fft(in);
  nt2::table<std::complex<T> > ref
      = nt2::cons<std::complex<T> > ( nt2::of_size(1,25)
                                    , std::complex<T>(1.8786205746582682607e+00,  0.0000000000000000000e+00 )
                                    , std::complex<T>(1.8792318704302970467e+00, -3.3997577604419459973e-02 )
                                    , std::complex<T>(1.8810684703501192594e+00, -6.8087130877002521867e-02 )
                                    , std::complex<T>(1.8841385431997588196e+00, -1.0236135821413316904e-01 )
                                    , std::complex<T>(1.8884558075153536905e+00, -1.3691441517537894512e-01 )
                                    , std::complex<T>(1.8940396897901123907e+00, -1.7184267264113017859e-01 )
                                    , std::complex<T>(1.9009155507379174033e+00, -2.0724551139623104135e-01 )
                                    , std::complex<T>(1.9091149846112613897e+00, -2.4322616685066189568e-01 )
                                    , std::complex<T>(1.9186761982808619997e+00, -2.7989263906738526266e-01 )
                                    , std::complex<T>(1.9296444787494047013e+00, -3.1735868517388021726e-01 )
                                    , std::complex<T>(1.9420727600735461227e+00, -3.5574491372185068627e-01 )
                                    , std::complex<T>(1.9560223033801231729e+00, -3.9518000372353323524e-01 )
                                    , std::complex<T>(1.9715635069215573516e+00, -4.3580207507843526926e-01 )
                                    , std::complex<T>(1.9887768670808894100e+00, -4.7776024213798073959e-01 )
                                    , std::complex<T>(2.0077541161050183049e+00, -5.2121638849184548370e-01 )
                                    , std::complex<T>(2.0285995683525452904e+00, -5.6634720900226787066e-01 )
                                    , std::complex<T>(2.0514317143701883417e+00, -6.1334657520696500566e-01 )
                                    , std::complex<T>(2.0763851115544813553e+00, -6.6242829297326011329e-01 )
                                    , std::complex<T>(2.1036126321497898850e+00, -7.1382933756481836696e-01 )
                                    , std::complex<T>(2.1332881446141924719e+00, -7.6781367215879825494e-01 )
                                    , std::complex<T>(2.1656097240899732093e+00, -8.2467678279314915457e-01 )
                                    , std::complex<T>(2.2008035132252299348e+00, -8.8475109771158777505e-01 )
                                    , std::complex<T>(2.2391283879797865275e+00, -9.4841250487950956582e-01 )
                                    , std::complex<T>(2.2808816270412055616e+00, -1.0160882419231542784e+00 )
                                    , std::complex<T>(2.3264058420328082022e+00, -1.0882665132069315739e+00 )
                                    );

  NT2_TEST_ULP_EQUAL(out(nt2::_(1,25)), ref, 29000 );
}
