/// DSP Algorithms Implementation.
/// Implemented By Mohamed Ahmed Gebril
/// Faculty of engineering Alexandria university
/// Communication Department
/// 16/10/2018

#ifndef DSP_TOOLBOX_H
#define DSP_TOOLBOX_H

#include <complex>
#include <math.h>
#include <stdint.h>
#include <iostream>
#define MAX_INPUT_SIZE 110000
typedef std::complex<double> SAMPLE;

void FFT(SAMPLE samples[], uint32_t Input_Size);
void DCT(SAMPLE samples[], uint32_t Input_Size);

#endif
