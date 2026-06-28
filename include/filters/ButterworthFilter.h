#include "FreqDomainFilter.h"
enum class FilterType
{
    LowPass,
    HighPass,
    BandPass,
    BandStop
};

class ButterworthFilter : public FrequencyDomainFilter
{
    private:
    const FilterType type;
    const double cutoff1;
    const double cutoff2;
    const int order;

    protected:
    double gain(double frequency) const override;

    public:
    ButterworthFilter(FilterType type, int order, double cutoff1, double cutoff2 = 0.0);

};