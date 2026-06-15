#include "../include/Signal.h"

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
    if(sampling_rate>0 && total_interval>0)
    {
        int len_signal = total_interval*sampling_rate + 1;
        new_signal.reserve(len_signal);
        constexpr double pi = 3.14159265358979323846;
        for(int i = 0; i<len_signal; i++)
        {
            double theta = 2*pi*frequency*i/sampling_rate + phase_difference;
            new_signal.push_back(amplitude*(std::sin(theta)));
        } 
        return Signal(new_signal, sampling_rate);
    }
    else{
        new_signal.assign(1,0);
        return Signal(new_signal,0);
    }
}

int Signal::size()
{
    return samples.size();
}

double Signal::getSampleRate()
{
    return sample_rate;
}

std::vector<double> Signal::getSamples()
{
    return samples;
}

double Signal::duration()
{
    return (size()-1)/sample_rate;
}
