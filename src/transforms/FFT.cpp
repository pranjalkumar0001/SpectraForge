#include "../../include/transforms/FFT.h"

const double pi = std::acos(-1);

bool FFT::isPower_of2(int n)
{
    return (n & (n - 1)) == 0 && n > 0;
}

std::vector<std::complex<double>> FFT::recursiveFFT(std::vector<std::complex<double>>& x)
{
    int N = x.size();
    if (N<=1) return x;
    std::vector<std::complex<double>> even(N / 2);
    std::vector<std::complex<double>> odd(N / 2);
    for (size_t i = 0; i < N / 2; ++i) {
        even[i] = x[i * 2];
        odd[i]  = x[i * 2 + 1];
    }
    auto even_call = recursiveFFT(even);
    auto odd_call = recursiveFFT(odd);

    std::vector<std::complex<double>> result(N);
    for(int i = 0; i<N/2; i++)
    {
        std::complex<double> t = std::polar(1.0, -2.0 * pi * i / N) * odd_call[i];
        result[i] = even_call[i] + t;
        result[i + N/2] = even_call[i] - t;
    }

    return result;
}

std::vector<std::complex<double>> FFT::ComputeFFT(const Signal& signal)
{
    if (signal.size() <= 0) throw std::invalid_argument("Signal is empty");
    if (!FFT::isPower_of2(signal.size())) return DFT::ComputeDFT(signal);
    std::vector<std::complex<double>> complex_samples;
    complex_samples.reserve(signal.getSamples().size());        
    for (double val : signal.getSamples()) {
        complex_samples.emplace_back(val, 0.0);
    }
    return FFT::recursiveFFT(complex_samples);
}