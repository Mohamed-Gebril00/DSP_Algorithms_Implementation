#include "./DSP_ToolBox/DSP.h"

const double PI = acos(-1.0);
SAMPLE j (0,-1);		//(0-j)

void FFT(SAMPLE samples[], uint32_t Input_Size)
{

	if(Input_Size == 2)
    {
        SAMPLE temp;
        temp=samples[0];
        samples[0]=temp+samples[1];
        samples[1]=temp-samples[1];
        return;
    }

    int half_size=Input_Size/2;
    SAMPLE samples_half_even[half_size];
    SAMPLE samples_half_odd[half_size];
    SAMPLE Diagonal[half_size];

    /// even sequence
    for(int i=0,idx=0 ; i< Input_Size ;i+=2,idx++)
        samples_half_even[idx] = samples[i];

    /// odd sequence
    for(int i=1,idx=0;i<Input_Size;i+=2,idx++)
        samples_half_odd[idx] = samples[i];

    /// divide again
    FFT(samples_half_even,half_size);
    FFT(samples_half_odd,half_size);

    /// get the diagnol matrix
    for(int i=0;i<half_size;i++)
        Diagonal[i] = exp(j * ((2.0*PI / Input_Size) * i));

    /// concatenate
    for(int i=0;i<half_size;i++)
        samples[i]=samples_half_even[i]+Diagonal[i]*samples_half_odd[i];


    for(int i=half_size,idx=0;i<Input_Size;i++,idx++)
        samples[i]=samples_half_even[idx]-((Diagonal[idx])*samples_half_odd[idx]);

    return;

}
