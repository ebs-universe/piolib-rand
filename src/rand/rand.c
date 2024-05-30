

#include "rand.h"
#include <stdlib.h>
#include <prbs/prbs.h>
#include <hal/uc.h>


#ifdef HAVE_CRYPTOLIB
#include <cryptolib/entropium/entropium.h>
#endif

static inline void RAND_INIT(uint8_t * pool);
static inline uint8_t RAND_BYTE(void);
static inline int RAND_INT(void);



void rand_init(void){
    uint8_t i;
    uint8_t pool[RAND_POOL];
    for (i=0; i<RAND_POOL; i++){
        pool[i] = entropy_get_byte();
    }
    RAND_INIT((uint8_t *)&pool[0]);
}

int rand_int_frombyte(void);

int rand_int_frombyte(void){
    int i = 0; 
    int rval = 0;
    for (i=0; i<__SIZEOF_INT__; i++){
        rval = rval << 8;
        rval |= rand_byte();
    }
    return rval;
}

uint8_t rand_byte(void){
    return(RAND_BYTE());
}

int rand_int(void){
    return(RAND_INT());
}


#if RAND_GENERATOR == RAND_GENERATOR_RAND

static inline void rand_init_rand(uint8_t * pool){
    srand(* (unsigned int *)pool);
}

static inline uint8_t rand_byte_rand(void){
    return (uint8_t)rand();
}

static inline int rand_int_rand(void){
    return rand();
}

#elif RAND_GENERATOR == RAND_GENERATOR_LFSR16

static lfsr16_t rk_lfsr16;

static inline void rand_init_lfsr16(uint8_t * pool){
    lfsr16_vAddEntropy(&rk_lfsr16, (void *)pool);
}
    
static inline uint8_t rand_byte_lfsr16(void){
    return lfsr16_cGetNextByte(&rk_lfsr16);
}

#elif RAND_GENERATOR == RAND_GENERATOR_LFSR32

static lfsr32_t rk_lfsr32;

static inline void rand_init_lfsr32(uint8_t * pool){
    lfsr32_vAddEntropy(&rk_lfsr32, (void *)pool);
}
    
static inline uint8_t rand_byte_lfsr32(void){
    return lfsr32_cGetNextByte(&rk_lfsr32);
}

#elif RAND_GENERATOR == RAND_GENERATOR_LFSR64

static lfsr64_t rk_lfsr64;

static inline void rand_init_lfsr64(uint8_t * pool){
    lfsr64_vAddEntropy(&rk_lfsr64, (void *)pool);
}
    
static inline uint8_t rand_byte_lfsr64(void){
    return lfsr64_cGetNextByte(&rk_lfsr64);
}

#elif RAND_GENERATOR == RAND_GENERATOR_SG16

static sg_lfsr16_t rk_sg16;

static inline void rand_init_sg16(uint8_t * pool){
    sg_lfsr16_vAddEntropy(&rk_sg16, (void *)pool);
}
    
static inline uint8_t rand_byte_sg16(void){
    return sg_lfsr16_cGetNextByte(&rk_sg16);
}

#elif RAND_GENERATOR == RAND_GENERATOR_SG32

static sg_lfsr32_t rk_sg32;

static inline void rand_init_sg32(uint8_t * pool){
    sg_lfsr32_vAddEntropy(&rk_sg32, (void *)pool);
}
    
static inline uint8_t rand_byte_sg32(void){
    return sg_lfsr32_cGetNextByte(&rk_sg32);
}

#elif RAND_GENERATOR == RAND_GENERATOR_SG64

static sg_lfsr64_t rk_sg64;

static inline void rand_init_sg64(uint8_t * pool){
    sg_lfsr64_vAddEntropy(&rk_sg64, (void *)pool);
}
    
static inline uint8_t rand_byte_sg64(void){
    return sg_lfsr64_cGetNextByte(&rk_sg64);
}

#elif RAND_GENERATOR == RAND_GENERATOR_ASG16

static asg_lfsr16_t rk_asg16;

static inline void rand_init_asg16(uint8_t * pool){
    asg_lfsr16_vAddEntropy(&rk_asg16, (void *)pool);
}
    
static inline uint8_t rand_byte_asg16(void){
    return asg_lfsr16_cGetNextByte(&rk_asg16);
}

#elif RAND_GENERATOR == RAND_GENERATOR_ASG32

static asg_lfsr32_t rk_asg32;

static inline void rand_init_asg32(uint8_t * pool){
    asg_lfsr32_vAddEntropy(&rk_asg32, (void *)pool);
}
    
static inline uint8_t rand_byte_asg32(void){
    return asg_lfsr32_cGetNextByte(&rk_asg32);
}

#elif RAND_GENERATOR == RAND_GENERATOR_ASG64

static asg_lfsr64_t rk_asg64;

static inline void rand_init_asg64(uint8_t * pool){
    asg_lfsr64_vAddEntropy(&rk_asg64, (void *)pool);
}
    
static inline uint8_t rand_byte_asg64(void){
    return asg_lfsr64_cGetNextByte(&rk_asg64);
}

#elif RAND_GENERATOR == RAND_GENERATOR_ENTROPIUM && HAVE_CRYPTOLIB

static inline void rand_init_entropium(uint8_t * pool){
    entropium_addEntropy(RAND_ENTROPY_POOL_LENGTH * 8, (void *)pool);
}
    
static inline uint8_t rand_byte_entropium(void){
    return entropium_getRandomByte();
}

#endif
