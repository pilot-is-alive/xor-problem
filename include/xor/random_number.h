#ifndef RANDOM_NUMBER_H
#define RANDOM_NUMBER_H

#include <random>

using namespace std;

class RandomNumber {
    private:
        random_device rd;
        mt19937 gen{rd()};
        uniform_real_distribution<float> distrib{-5.0f, 5.0f};
    
    public:
        float get() {
            return distrib(gen);
        }

};


#endif