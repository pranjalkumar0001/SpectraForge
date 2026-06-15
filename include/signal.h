#include <vector>
#include <cmath>
class Signal{
public:
    std::vector<double> sin_signal_generator(
        double dt, 
        double total_interval,
        double frequency,
        double phase_difference = 0,
        double amplitude = 1){
            std::vector<double> new_signal;
            if(dt>0 && total_interval>0)
            {
                int len_signal = total_interval/dt + 1;
                new_signal.reserve(len_signal);
               constexpr double pi = 3.14159265358979323846;
                for(int i = 0; i<len_signal; i++)
                {
                    double theta = 2*pi*frequency*i*dt + phase_difference;
                    new_signal.push_back(amplitude*(std::sin(theta)));
                } 
            }
            return new_signal;
        }
    };