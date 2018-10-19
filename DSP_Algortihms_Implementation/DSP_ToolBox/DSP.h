#ifndef DSP_TOOLBOX_H
#define DSP_TOOLBOX_H

#include <complex>
#include <math.h>
#include <stdint.h>
#define MAX_INPUT_SIZE 110000
typedef std::complex<double> SAMPLE;

void FFT(SAMPLE samples[], uint32_t Input_Size);

#endif
