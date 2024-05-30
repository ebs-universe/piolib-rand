

#ifndef RAND_CONFIG_H
#define RAND_CONFIG_H

#define RAND_VERSION       "0.1.0"

// If entropium is to be used, application must include ensure 
// cryptolib is pulled in on its own and the RAND_GENERATOR should be set.

#ifdef EBS_RAND_GENERATOR
    #define RAND_GENERATOR              EBS_RAND_GENERATOR
#else
    #define RAND_GENERATOR              RAND_GENERATOR_RAND
#endif

#ifdef __has_include
#  if __has_include (<cryptolib/config.h>)
#    include <cryptolib/config.h>
#    define HAVE_CRYPTOLIB
#  endif
#endif

#endif
