#include <iostream>
#include <iomanip>
#include <complex>

#include "../include/Signal.h"
#include "../include/transforms/FFT.h"
#include "../include/filters/ButterworthFilter.h"

void testFilter(const ButterworthFilter& filter,
                const Signal& signal,
                const std::string& name)
{ 
    auto before = FFT::ComputeFFT(signal);
    auto filtered = filter.applyFilter(signal);
    auto after = FFT::ComputeFFT(filtered);

    const double Fs = signal.getSampleRate();
    int N = before.size();

    std::cout << "\n========================================================\n";
    std::cout << name << '\n';
    std::cout << "========================================================\n";

    std::cout << std::fixed << std::setprecision(4);

    std::cout << " Bin   Frequency    Before      After      Ratio\n";
    std::cout << "--------------------------------------------------------\n";

    for(int k = 0; k < N; k++)
    {
        double freq;

        if(k <= N/2)
            freq = k * Fs / N;
        else
            freq = (k - N) * Fs / N;

        double b = std::abs(before[k]);
        double a = std::abs(after[k]);

        std::cout
            << std::setw(3) << k << "   "
            << std::setw(8) << freq << "   "
            << std::setw(10) << b << "   "
            << std::setw(10) << a << "   ";

        if(b > 1e-12)
            std::cout << a/b;

        std::cout << '\n';
    }
}

int main()
{
    constexpr double Fs = 128;
    constexpr double duration = 1.0;

    // DC component
    Signal dc = Signal::DC_signal_generator(Fs, duration, 5);

    // Low frequency
    Signal s5 = Signal::sin_signal_generator(Fs, duration, 5, 0, 10);

    // Mid frequency
    Signal s20 = Signal::sin_signal_generator(Fs, duration, 20, 0, 10);

    // High frequency
    Signal s40 = Signal::sin_signal_generator(Fs, duration, 40, 0, 10);

    Signal mix = dc + s5 + s20 + s40;

    ButterworthFilter low(FilterType::LowPass,1,15);

    ButterworthFilter high(FilterType::HighPass,1,15);

    ButterworthFilter band(FilterType::BandPass,1,15,30);

    ButterworthFilter stop(FilterType::BandStop,1,15,30);

    testFilter(low,mix,"LOW PASS");

    testFilter(high,mix,"HIGH PASS");

    testFilter(band,mix,"BAND PASS");

    testFilter(stop,mix,"BAND STOP");
}