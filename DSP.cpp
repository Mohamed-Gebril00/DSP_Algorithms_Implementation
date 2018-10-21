/// DSP Algorithms Implementation.
/// Implemented By Mohamed Ahmed Gebril
/// Faculty of engineering Alexandria university
/// Communication Department
/// 16/10/2018

#include "./DSP_ToolBox/DSP.h"

const double PI = acos(-1.0);
SAMPLE j (0,-1);		//(0-j)

//******************************************************************************************************
//
// Fast Fourier transform Implementation
//
//******************************************************************************************************
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


//*****************************************************************************************************
//
// DCT Implementation
//
//*****************************************************************************************************
void DCT(SAMPLE samples[], uint32_t Input_Size)
{


    //int half_size=Input_Size/2;
    SAMPLE samples_even[Input_Size];
    SAMPLE samples_odd[Input_Size];
    SAMPLE Diagonal[Input_Size];

    for(int i=0,idx=1,idx_2=0 ; ((i< Input_Size) && (idx < Input_Size))  ;i+=2,idx+=2,idx_2++)
	{
        samples_even[idx_2] = samples[i];
		samples_odd[idx_2] = samples[idx];
	}

	 for(int i=(Input_Size-1),idx=(Input_Size-2),idx_2=(Input_Size/2) ; ((i>=0) && (idx >= 0))  ;i-=2,idx-=2,idx_2++)
	{
        samples_even[idx_2] = samples[i];
		samples_odd[idx_2] = samples[idx];
	}


	///************************************
	// Two-Point-DFT Operation
	///************************************
    FFT(samples_even,Input_Size);
    FFT(samples_odd,Input_Size);

    for(int i=0;i<Input_Size;i++)
        Diagonal[i] = exp(j * ((2.0*PI / (2*Input_Size)) * i));

    for(int i=0;i<Input_Size;i++)
        samples[i]=samples_even[i]+Diagonal[i]*samples_odd[i];

	double alpha = 0;

	///***************************************
	/// Shifting
	///***************************************
    for(int i=0;i<Input_Size;i++){
		i==0?(alpha=(1.0/(2.0*sqrt(Input_Size)))):(alpha=(1.0/(sqrt(2*Input_Size))));
        samples[i]=((exp(j * ((2.0*PI / (2*2*Input_Size)) * i))* alpha) * samples[i]);
        samples[i]=samples[i].real();

	}

    return;

}
