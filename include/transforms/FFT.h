#pragma once
#include <vector>
#include <complex>
#include "../Signal.h"
# include"./DFT.h"

class FFT
{
    private:
    static bool isPower_of2(int n);
    static std::vector<std::complex<double>> recursiveFFT(std::vector<std::complex<double>>& x);
    public:
    static std::vector<std::complex<double>> ComputeFFT(const Signal& signal);
};