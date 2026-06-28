#include "../../include/filters/FreqDomainFilter.h"

Signal FrequencyDomainFilter::applyFilter(const Signal& signal) const
{
    double sampling_rate = signal.getSampleRate();
    auto freq_bin = FFT::ComputeFFT(signal);
    double n = freq_bin.size();
    double frequency;
    for(int k = 0; k < n; k++)
    {
        if(k<=n/2) frequency = k*sampling_rate/n;
        else frequency = (k-n)*sampling_rate/n;
        freq_bin[k] *= gain(frequency);
    }
    return IFFT::ComputeIFFT(freq_bin, sampling_rate);
}