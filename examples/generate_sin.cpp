#include <iostream>
#include "../include/Signal.h"

int main(){
    Signal s = Signal::sin_signal_generator(5,2,1);
    std::cout<< s.getSampleRate()<<"\n"<<s.size()<<std::endl;
    for (int i = 0; i < s.size(); i++){
        std::cout<< s.getSamples()[i]<<",";
    }
}