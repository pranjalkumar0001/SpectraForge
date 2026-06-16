#pragma once
#include "../Signal.h"
#include "../transforms/DFT.h"

struct freqBin
{
    double freq;
    double magnitude;
};

class SpectrumAnalysis
{
    public:
    static std::vector<freqBin> Signal2Spectrum(const Signal& signal);

    static freqBin dominantPeak(const std::vector<freqBin>& DataVector);
};
