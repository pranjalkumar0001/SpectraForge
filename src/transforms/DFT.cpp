#include "../../include/transforms/DFT.h"

std::vector<std::complex<double>> DFT::ComputeDFT(const Signal& signal)
{
    //double max_freq = (signal.getSampleRate())/2;
    int binSize = signal.size();
    std::vector<double> TimeDomainSamples = signal.getSamples();
    //double binWidth = max_freq/binSize;
    std::vector<std::complex<double>> dft_samples;
    dft_samples.reserve(binSize);
    for(int i = 0; i < binSize; i++)
    {
        std::complex<double> sum(0,0);
        for(int j = 0; j < binSize; j++)
        {
            std::complex<double> theta(0, -2*i*3.14159265358979323846*j/binSize);
            sum = sum + (TimeDomainSamples[j])*(std::exp(theta));
        }
        dft_samples.push_back(sum);
    }
    return dft_samples;
}