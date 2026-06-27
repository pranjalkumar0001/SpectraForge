#include "../../include/transforms/IFFT.h"
#include <stdexcept>


const double pi = std::acos(-1);

bool IFFT::isPower_of2(int n)
{
    return (n & (n - 1)) == 0 && n > 0;
}
std::vector<std::complex<double>> IFFT::recursiveIFFT(std::vector<std::complex<double>>& x)
{
    int N = x.size();
    if (N<=1) return x;
    std::vector<std::complex<double>> even(N / 2);
    std::vector<std::complex<double>> odd(N / 2);
    for (size_t i = 0; i < N / 2; ++i) {
        even[i] = x[i * 2];
        odd[i]  = x[i * 2 + 1];
    }
    auto even_call = recursiveIFFT(even);
    auto odd_call = recursiveIFFT(odd);

    std::vector<std::complex<double>> result(N);
    for(int i = 0; i<N/2; i++)
    {
        std::complex<double> t = std::polar(1.0, 2.0 * pi * i / N) * odd_call[i];
        result[i] = even_call[i] + t;
        result[i + N/2] = even_call[i] - t;
    }

    return result;
}


Signal IFFT::ComputeIFFT(std::vector<std::complex<double>>& spectrum, double sample_rate)
{
    int len = spectrum.size();
    if(len == 0) throw std::invalid_argument("spectrum is empty");
    if(!isPower_of2(len)) return IDFT::computeIDFT(spectrum, sample_rate);
    auto time_d_comp = IFFT::recursiveIFFT(spectrum);
    std::vector<double> time_d(len);
    for(int i = 0; i<len; i++){
        auto c = time_d_comp[i];
        time_d[i] = std::real(c)/len;
    }
    return Signal(time_d, sample_rate);
}