#include "../Signal.h"
#include "../transforms/FFT.h"
#include "../transforms/IFFT.h"


class SignalFilter{
    public:
        virtual Signal applyFilter(const Signal& input) const = 0;
        virtual ~SignalFilter() = default;
};