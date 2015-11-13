##############################################################################
###   Copyright 2003 and onward LASMEA UMR 6602 CNRS/U.B.P Clermont-Ferrand
###   Copyright 2009 and onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
###
###          Distributed under the Boost Software License, Version 1.0
###                 See accompanying file LICENSE.txt or copy at
###                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################

if(APPLE)
  nt2_module_use_link_flags(-framework Accelerate)
endif()

find_package(FFTW)

if(FFTW_FOUND)

  set ( SOURCES
        fft.cpp
        static_fft.cpp
        zero_crossing_rate.cpp
        globalzero_crossing_rate.cpp
      )

include_directories(${FFTW_INCLUDES})
link_libraries(${FFTW_LIBRARIES})

add_definitions("-DNT2_USE_FFTW")

else()

set ( SOURCES
      static_fft.cpp
      zero_crossing_rate.cpp
      globalzero_crossing_rate.cpp
    )

endif()


nt2_module_add_tests(core.signal.general.unit ${SOURCES})

