#pragma once
#include <vector>
#include <complex>
#include "../Signal.h"

class DFT
{
    public:
        static std::vector<std::complex<double>> ComputeDFT(const Signal& signal);
};