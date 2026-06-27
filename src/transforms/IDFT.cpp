#include "../../include/transforms/IDFT.h"
#include <stdexcept>

Signal IDFT::computeIDFT(const std::vector<std::complex<double>>& spectrum,double sample_rate)
{
    const double pi = std::acos(-1);
    int len = spectrum.size();
    if(len == 0) throw std::invalid_argument("spectrum is empty");
    std::vector<double> time_D(len);
    for(int i = 0; i<len; i++)
    {
        std::complex<double> sum(0,0);
        for(int j = 0; j<len; j++)
        {
            std::complex<double> theta(0, 2*i*pi*j/len);
            sum += spectrum[j] * std::exp(theta);
        }
        time_D[i] = std::real(sum)/len;
    }
    return Signal(time_D, sample_rate);
}