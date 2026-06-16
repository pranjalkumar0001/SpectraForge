#include <iostream>
#include "../include/analysis/SpectrumAnalysis.h"
#include "../include/Signal.h"

int main(){
    Signal s = Signal::sin_signal_generator(100,1,20);

    auto spectrum = SpectrumAnalysis::Signal2Spectrum(s);

    auto peak = SpectrumAnalysis::dominantPeak(spectrum);

    std::cout << peak.freq << '\n';
    std::cout<<peak.magnitude<<'\n';
}