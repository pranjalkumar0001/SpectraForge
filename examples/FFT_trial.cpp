#include <iostream>
#include "../include/Signal.h"
#include "../include/transforms//FFT.h"
int main()
{
    Signal signal = Signal::sin_signal_generator(1023,1,5);

    auto dft = DFT::ComputeDFT(signal);
    auto fft = FFT::ComputeFFT(signal);

    double max_error = 0;

    for(int i=0;i<dft.size();i++)
    {
        double err = std::abs(dft[i]-fft[i]);

        if(err > max_error)
            max_error = err;
    }

    std::cout<<"Max error = "<<max_error<<"\n";
    return 0;
}