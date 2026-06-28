#include "../../include/filters/ButterworthFilter.h"
#include <stdexcept>
#include <cmath>

ButterworthFilter::ButterworthFilter(FilterType type, int order, double cutoff1, double cutoff2): type(type), order(order), cutoff1(cutoff1), cutoff2(cutoff2)
{
    if (order<1) throw std::invalid_argument("order must be greater than 0");
    if (cutoff1<=0) throw std::invalid_argument("cutoff1 must be greater than 0");
    switch (type)
    {
        case FilterType::LowPass:
        case FilterType::HighPass:
        break;
        case FilterType::BandPass:
        if (cutoff1>cutoff2) throw std::invalid_argument("cutoff1 must be less than cutoff2");
        break;
        case FilterType::BandStop:
        if (cutoff1>cutoff2) throw std::invalid_argument("cutoff1 must be less than cutoff2");
        break;
    }
};

double ButterworthFilter::gain(double frequency) const
{
    switch (type)
    {
        case FilterType::LowPass:
        {
            double fc = cutoff1;
            int n = order;
            double d_sq = 1 + std::pow((frequency/fc), 2*n);
            double out = 1/std::sqrt(d_sq);
            return out;
        }

        case FilterType::HighPass:
        {
            if(frequency == 0) return 0;
            double fc = cutoff1;
            int n = order;
            double d_sq = 1 + std::pow((fc/frequency), 2*n);
            double out = 1/std::sqrt(d_sq);
            return out;
        }

        case FilterType::BandPass:
        {
            int n = order;
            double fl = cutoff1;
            double fh = cutoff2;
            double f0 = std::sqrt(fl*fh);
            double B = fh - fl;
            if((frequency*B) == 0) return 0;
            double d_sq = 1 + std::pow(((frequency*frequency)- (f0*f0))/(frequency*B), 2*n);
            double out = 1/std::sqrt(d_sq);
            return out;
        }

        case FilterType::BandStop:
        {
            int n = order;
            double fl = cutoff1;
            double fh = cutoff2;
            double f0 = std::sqrt(fl*fh);
            double B = fh - fl;
            if(((frequency*frequency)- (f0*f0)) == 0) return 0;
            double d_sq = 1 + std::pow((frequency*B)/((frequency*frequency)- (f0*f0)), 2*n);
            double out = 1/std::sqrt(d_sq);
            return out;
        }

        default:
        throw std::invalid_argument("invalid filter type");
    }
}