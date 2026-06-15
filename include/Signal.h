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

    int size();

    double getSampleRate();

    std::vector<double> getSamples();

    double duration();
};