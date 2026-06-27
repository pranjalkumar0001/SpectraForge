#include <iostream>
#include "../include/Signal.h"
#include "../include/transforms/DFT.h"
#include "../include/transforms/IDFT.h"

int main(){
    Signal s =Signal::sin_signal_generator(140,1,10);
    auto spectrum = DFT::ComputeDFT(s);
    Signal recovered =IDFT::computeIDFT(spectrum,s.getSampleRate());
    double max_error = 0;

auto original = s.getSamples();
auto reconstructed = recovered.getSamples();

for(int i = 0; i < original.size(); i++)
{
    double err = std::abs(original[i]-reconstructed[i]);

    if(err > max_error) max_error = err;}
    std::cout << max_error << '\n';
}
