#include "../../include/analysis/SpectrumAnalysis.h"

std::vector<freqBin> SpectrumAnalysis::Signal2Spectrum(const Signal& signal)
{
    int size = signal.size();
    double binWidth = signal.getSampleRate()/size;
    std::vector<freqBin> freqData;
    freqData.reserve(size);
    std::vector<std::complex<double>> transform = DFT::ComputeDFT(signal);
    double freq = 0;
    for(int i = 0; i<size; i++)
    {
        freqBin data;
        data.freq = freq;
        data.magnitude = std::abs(transform[i]);
        freqData.push_back(data);
        freq = freq + binWidth;
    }
    return freqData;
} 

freqBin SpectrumAnalysis::dominantPeak(const std::vector<freqBin>& DataVector)
{
    int Peak_idx = 0;
    int size = DataVector.size();
    for (int i = 1; i<size/2; i++)
    {
        if (DataVector[i].magnitude > DataVector[Peak_idx].magnitude) Peak_idx = i;
    }
    return DataVector[Peak_idx];
}
