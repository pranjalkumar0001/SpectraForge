#pragma once
#include "../Signal.h"
#include "IDFT.h"
#include <vector>
#include <complex>
#include <cmath>

class IFFT
{
    private:
    static bool isPower_of2(int n);
    static std::vector<std::complex<double>> recursiveIFFT(std::vector<std::complex<double>>& x);
    public:
    static Signal ComputeIFFT(std::vector<std::complex<double>>& spectrum, double sample_rate);
};