################################################################################
#         Copyright 2015 NumScale SAS
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

if (FFTW_INCLUDES)
  set (FFTW_FIND_QUIETLY TRUE)
endif (FFTW_INCLUDES)

find_path (FFTW_INCLUDES fftw3.h)

find_library (FFTW_DOUBLE_LIBRARIES NAMES fftw3)
find_library (FFTW_SINGLE_LIBRARIES NAMES fftw3f)

set(FFTW_LIBRARIES "${FFTW_DOUBLE_LIBRARIES};${FFTW_SINGLE_LIBRARIES}")

include (FindPackageHandleStandardArgs)
find_package_handle_standard_args (FFTW DEFAULT_MSG FFTW_LIBRARIES FFTW_INCLUDES)

mark_as_advanced (FFTW_LIBRARIES FFTW_INCLUDES)
