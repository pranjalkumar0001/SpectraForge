#include <iostream>
#include "../include/Signal.h"
#include "../include/transforms/DFT.h"

int main(){
    Signal s = Signal::sin_signal_generator(100,1,20);
    auto spectrum = DFT::ComputeDFT(s);
    for(std::complex<double> i: spectrum)
    {
        std::cout<< std::abs(i)<< ",";
    }
}