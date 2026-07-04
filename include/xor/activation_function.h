#ifndef ACTIVATION_FUNCTION_H
#define ACTIVATION_FUNCTION_H

#include <cmath>

using namespace std;

class ActivationFunction {
    private:
        static const float e;

    public:
        static float sigmoid(float input);
        static float relu(float input);
        static float leakyRelu(float input);
};

#endif