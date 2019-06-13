

#ifndef RAND_H
#define RAND_H

#include <stdint.h>
#include "config.h"

#define RAND_GENERATOR_ENTROPY      0
#define RAND_GENERATOR_RAND         1
#define RAND_GENERATOR_LFSR16       2
#define RAND_GENERATOR_LFSR32       3
#define RAND_GENERATOR_LFSR64       4
#define RAND_GENERATOR_SG16         5
#define RAND_GENERATOR_SG32         6
#define RAND_GENERATOR_SG64         7
#define RAND_GENERATOR_ASG16        8
#define RAND_GENERATOR_ASG32        9
#define RAND_GENERATOR_ASG64        10
#define RAND_GENERATOR_ENTROPIUM    11

void rand_init(void);
uint8_t rand_byte(void);
int rand_int(void);


extern void entropy_init(void);
extern uint8_t entropy_get_byte(void);
extern void entropy_deinit(void);


#if RAND_GENERATOR == RAND_GENERATOR_ENTROPY
    #define RAND_INIT   rand_init_entropy
    #define RAND_BYTE   rand_byte_entropy
    #define RAND_INT    rand_int_frombyte
#elif RAND_GENERATOR == RAND_GENERATOR_RAND
    #define RAND_INIT   rand_init_rand
    #define RAND_BYTE   rand_byte_rand
    #define RAND_INT    rand_int_rand
#elif RAND_GENERATOR == RAND_GENERATOR_LFSR16
    #define RAND_INIT   rand_init_lfsr16
    #define RAND_BYTE   rand_byte_lfsr16
    #define RAND_INT    rand_int_frombyte
#elif RAND_GENERATOR == RAND_GENERATOR_LFSR32
    #define RAND_INIT   rand_init_lfsr32
    #define RAND_BYTE   rand_byte_lfsr32
    #define RAND_INT    rand_int_frombyte
#elif RAND_GENERATOR == RAND_GENERATOR_LFSR64
    #define RAND_INIT   rand_init_lfsr64
    #define RAND_BYTE   rand_byte_lfsr64
    #define RAND_INT    rand_int_frombyte
#elif RAND_GENERATOR == RAND_GENERATOR_SG16
    #define RAND_INIT   rand_init_sg16
    #define RAND_BYTE   rand_byte_sg16
    #define RAND_INT    rand_int_frombyte
#elif RAND_GENERATOR == RAND_GENERATOR_SG32
    #define RAND_INIT   rand_init_sg32
    #define RAND_BYTE   rand_byte_sg32
    #define RAND_INT    rand_int_frombyte
#elif RAND_GENERATOR == RAND_GENERATOR_SG64
    #define RAND_INIT   rand_init_sg64
    #define RAND_BYTE   rand_byte_sg64
    #define RAND_INT    rand_int_frombyte
#elif RAND_GENERATOR == RAND_GENERATOR_ASG16
    #define RAND_INIT   rand_init_asg16
    #define RAND_BYTE   rand_byte_asg16
    #define RAND_INT    rand_int_frombyte
#elif RAND_GENERATOR == RAND_GENERATOR_ASG32
    #define RAND_INIT   rand_init_asg16
    #define RAND_BYTE   rand_byte_asg16
    #define RAND_INT    rand_int_frombyte
#elif RAND_GENERATOR == RAND_GENERATOR_ASG64
    #define RAND_INIT   rand_init_asg16
    #define RAND_BYTE   rand_byte_asg16
    #define RAND_INT    rand_int_frombyte
#elif RAND_GENERATOR == RAND_GENERATOR_ENTROPIUM
    #define RAND_INIT   rand_init_entropium
    #define RAND_BYTE   rand_byte_entropium
    #define RAND_INT    rand_int_frombyte
#else
    #define RAND_INIT   rand_init_rand
    #define RAND_BYTE   rand_byte_rand
    #define RAND_INT    rand_int_rand
#endif

#endif
