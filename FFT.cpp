/// FFT Implementation Using recursion
/// Implemented By Mohamed Ahmed Gebril
/// Faculty of engineering Alexandria university
/// Communication Department
/// 16/10/2018


#include <bits/stdc++.h>
using namespace std;

typedef complex<double> sample;

#define x real()
#define y imag()

const double PI= acos(-1.0);
const double EPS=1e-7;

sample j (0,-1); // (0-1j)

void FFT(sample samples[],int SIZE)
{
    if(SIZE == 2)
    {
        sample temp;
        temp=samples[0];
        samples[0]=temp+samples[1];
        samples[1]=temp-samples[1];
        return;
    }

    int half_size=SIZE/2;
    sample samples_half_even[half_size];
    sample samples_half_odd[half_size];
    sample Diagonal[half_size];

    /// even sequence
    for(int i=0,idx=0 ; i< SIZE ;i+=2,idx++)
        samples_half_even[idx] = samples[i];

    /// odd sequence
    for(int i=1,idx=0;i<SIZE;i+=2,idx++)
        samples_half_odd[idx] = samples[i];

    /// divide again
    FFT(samples_half_even,half_size);
    FFT(samples_half_odd,half_size);

    /// get the diagnol matrix
    for(int i=0;i<half_size;i++)
        Diagonal[i] = exp(j * ((2.0*PI / SIZE) * i));

    /// concatenate
    for(int i=0;i<half_size;i++)
        samples[i]=samples_half_even[i]+Diagonal[i]*samples_half_odd[i];


    for(int i=half_size,idx=0;i<SIZE;i++,idx++)
        samples[i]=samples_half_even[idx]-((Diagonal[idx])*samples_half_odd[idx]);

    return;

}


int main()
{
    cout << setprecision(4);
    cout << fixed;
    sample j (0,-1);
    sample user_input[110000];
    int n;
	cout <<"Please enter number of samples must be power of 2: ";
    cin >> n;
	cout << "Enter samples. in form of complex data (real,imag) e.g(5,3) = 5+3i," << endl;
	cout <<"or i form of real data only e.g. 5 = 5+0i" << endl;
    for(int i=0;i<n;i++)
    {
        cin >> user_input[i];
    }
    FFT(user_input,n);
    for(int i=0;i<n;i++)
    {
        cout << (user_input[i])<<endl;
    }
 }
