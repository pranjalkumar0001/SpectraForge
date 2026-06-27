#include <iostream>
#include "../include/Signal.h"
#include "../include/transforms/FFT.h"
#include "../include/transforms/IFFT.h"

int main(){
    Signal s =Signal::sin_signal_generator(1023, 1, 23);
    auto spectrum = FFT::ComputeFFT(s);
    Signal recovered =IFFT::ComputeIFFT(spectrum,s.getSampleRate());
    double max_error = 0;

auto original = s.getSamples();
auto reconstructed = recovered.getSamples();

for(int i = 0; i < original.size(); i++)
{
    double err = std::abs(original[i]-reconstructed[i]);

    if(err > max_error) max_error = err;}
    std::cout <<std::scientific << max_error << '\n';
}
