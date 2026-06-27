#pragma once
#include "../Signal.h"
#include <vector>
#include <complex>
#include <cmath>

class IDFT{
    public:
    static Signal computeIDFT(const std::vector<std::complex<double>>& spectrum,double sample_rate);
};