#include "SignalFilter.h"

class FrequencyDomainFilter : public SignalFilter
{
protected:
    virtual double gain(double frequency) const = 0;

public:
    Signal applyFilter(const Signal& signal) const override;
};