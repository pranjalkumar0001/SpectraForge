#pragma once
#include <vector>
#include <cmath>

class Signal{
private:
    std::vector<double> samples;
    double sample_rate;
public:
    Signal(std::vector<double> Samples, double sampleRate);

    static Signal sin_signal_generator(
        double sampling_rate, 
        double total_interval,
        double frequency,
        double phase_difference = 0,
        double amplitude = 1);

    int size() const;

    double getSampleRate() const;

    std::vector<double> getSamples() const;

    double duration() const;

    Signal operator+(const Signal& other) const;

    Signal operator*(double scaler) const;

    Signal operator-(const Signal& other) const;

    Signal operator/(double scaler) const;
};

Signal operator*(double scaler, const Signal& signal);