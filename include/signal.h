#include <vector>
#include <cmath>

class Signal{
private:
    std::vector<double> samples;
    double sample_rate;
public:
    Signal(std::vector<double> Samples, double sampleRate)
    {
        samples = Samples;
        sample_rate = sampleRate;
    }
    static Signal sin_signal_generator(
        double sampling_rate, 
        double total_interval,
        double frequency,
        double phase_difference = 0,
        double amplitude = 1){
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
            
        }
    };