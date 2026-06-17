#include "../include/Signal.h"
#include <stdexcept>
#include <numbers>

Signal::Signal(std::vector<double> Samples, double sampleRate):samples(Samples), sample_rate(sampleRate)
{
}

Signal Signal::sin_signal_generator(
        double sampling_rate, 
        double total_interval,
        double frequency,
        double phase_difference,
        double amplitude)
{ 
    std::vector<double> new_signal;
    if (sampling_rate<=0) throw std::invalid_argument("sampling rate must be grater than 0");
    if (total_interval<=0) throw std::invalid_argument("time interval must be greater than 0");
    int len_signal = total_interval*sampling_rate + 1;
    new_signal.reserve(len_signal);
        constexpr double pi = std::numbers::pi;
        for(int i = 0; i<len_signal; i++)
        {
            double theta = 2*pi*frequency*i/sampling_rate + phase_difference;
            new_signal.push_back(amplitude*(std::sin(theta)));
        } 
        return Signal(new_signal, sampling_rate);
    
}

int Signal::size() const
{
    return samples.size();
}

double Signal::getSampleRate() const
{
    return sample_rate;
}

std::vector<double> Signal::getSamples() const
{
    return samples;
}

double Signal::duration() const
{
    return (size()-1)/sample_rate;
}

Signal Signal::operator+(const Signal& other) const
{
    if (sample_rate != other.getSampleRate()) throw std::invalid_argument("signal must have same sample rate");
    if (size() != other.size()) throw std::invalid_argument("signals must have same size");
    std::vector<double> SumSample;
    SumSample.reserve(size());
    std::vector<double> otherSample = other.getSamples();
    for(int i = 0; i<size(); i++)
    {
        SumSample.push_back(samples[i] + otherSample[i]);
    }
    return Signal(SumSample, getSampleRate());
}

Signal Signal::operator*(double scaler) const
{
    std::vector<double> mulSamples;
    mulSamples.reserve(size());
    for (double s: samples)
    {
        mulSamples.push_back(scaler*s);
    }
    return Signal(mulSamples, sample_rate);
}

Signal operator*(double scaler, const Signal& signal)
{
    return signal*scaler;
}

Signal Signal::operator-(const Signal& other) const
{
    return *this + (other * (-1));
}

Signal Signal::operator/(double scaler) const
{
    if(scaler == 0) throw std::runtime_error("Division by zero not possible");
    return *this * (1/scaler);
}