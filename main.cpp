// Mohamed Ahmed Gebril
// 19/10/2018
// Small Application using FFT


#include <iostream>
#include <iomanip>
#include "./DSP_ToolBox/DSP.h"
using namespace std;

int main()
{
    cout << setprecision(4);
    SAMPLE Input_Samples[MAX_INPUT_SIZE];
    uint32_t Input_Size=0,Loop_Idx=0;
    cout << "Please Enter Input Size Must Be Power Of 2: ";
    cin >> Input_Size;
    cout << "Enter Samples Real only e.g 4 ..equivalent to(4+0j)" << endl;
    cout << "Complex (4,5) ..equivalent to 4+5j." << endl;
    for(Loop_Idx=0 ; Loop_Idx < Input_Size;Loop_Idx++)
    {
        cin >> Input_Samples[Loop_Idx];
    }
    FFT(Input_Samples, Input_Size);
    for(Loop_Idx=0;Loop_Idx<Input_Size;Loop_Idx++)
    {
        cout << Input_Samples[Loop_Idx] << endl;
    }
    return 0;
}
