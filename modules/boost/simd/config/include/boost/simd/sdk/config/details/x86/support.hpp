//==============================================================================
//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II
//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI
//
//          Distributed under the Boost Software License, Version 1.0.
//                 See accompanying file LICENSE.txt or copy at
//                     http://www.boost.org/LICENSE_1_0.txt
//==============================================================================
#ifndef BOOST_SIMD_SDK_CONFIG_DETAILS_X86_SUPPORT_HPP_INCLUDED
#define BOOST_SIMD_SDK_CONFIG_DETAILS_X86_SUPPORT_HPP_INCLUDED

namespace boost { namespace simd { namespace details
{
  // register detection of X86 extensions
  support_registration x86_sse  = support_registration ( "sse"
                                                        , &boost::simd::is_supported<tag::sse_>
                                                        , &registration_list
                                                        );
  support_registration x86_sse2 = support_registration ( "sse2"
                                                        , &boost::simd::is_supported<tag::sse2_>
                                                        , &registration_list
                                                        );
  support_registration x86_sse3 = support_registration ( "sse3"
                                                        , &boost::simd::is_supported<tag::sse3_>
                                                        , &registration_list
                                                        );
  support_registration x86_ssse3 = support_registration ( "ssse3"
                                                        , &boost::simd::is_supported<tag::ssse3_>
                                                        , &registration_list
                                                        );
  support_registration x86_sse4a  = support_registration ( "sse4a"
                                                        , &boost::simd::is_supported<tag::sse4a_>
                                                        , &registration_list
                                                        );
  support_registration x86_sse41  = support_registration ( "sse4.1"
                                                        , &boost::simd::is_supported<tag::sse4_1_>
                                                        , &registration_list
                                                        );
  support_registration x86_sse52  = support_registration ( "sse4.2"
                                                        , &boost::simd::is_supported<tag::sse4_2_>
                                                        , &registration_list
                                                        );
  support_registration x86_avx  = support_registration ( "avx"
                                                        , &boost::simd::is_supported<tag::avx_>
                                                        , &registration_list
                                                        );
  support_registration x86_xop  = support_registration ( "xop"
                                                        , &boost::simd::is_supported<tag::xop_>
                                                        , &registration_list
                                                        );
  support_registration x86_fma4  = support_registration ( "fma4"
                                                        , &boost::simd::is_supported<tag::fma4_>
                                                        , &registration_list
                                                        );
  support_registration x86_lrb  = support_registration ( "lrb"
                                                        , &boost::simd::is_supported<tag::lrb_>
                                                        , &registration_list
                                                        );
} } }

#endif
