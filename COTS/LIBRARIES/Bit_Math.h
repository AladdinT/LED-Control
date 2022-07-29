#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT( x ,bit_order) ( (x) |= (1 << (bit_order) ))
#define CLR_BIT( x ,bit_order) ( (x) &= (~(1 << (bit_order)) ) )
#define TOG_BIT( x ,bit_order) ( (x) ^= (1 << (bit_order) ) )
#define GET_BIT( x ,bit_order) ( (x) >> (bit_order) & 1 )


#endif
