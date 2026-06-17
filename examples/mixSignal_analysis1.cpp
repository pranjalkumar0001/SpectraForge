#include <iostream>
#include "../include/Signal.h"
#include"../include/analysis/SpectrumAnalysis.h"
int main()
{
    Signal s1 = Signal::sin_signal_generator(100,2,10);
    Signal s2 = Signal::sin_signal_generator(100,2,25);
    Signal s3 = Signal::sin_signal_generator(100,2,40);

    Signal mixed = s1 + 0.5*s2 + 0.25*s3;
    auto spectrum = SpectrumAnalysis::Signal2Spectrum(mixed);
    auto peak = SpectrumAnalysis::dominantPeak(spectrum);
    std::cout<<"peak frequency is:: "<< peak.freq<< " and its magnitude is:: "<<peak.magnitude<<std::endl;
}