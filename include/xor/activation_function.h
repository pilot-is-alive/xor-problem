#ifndef ACTIVATION_FUNCTION_H
#define ACTIVATION_FUNCTION_H

using namespace std;

class ActivationFunction {
    public:
        static float sigmoid(float input);
        static float relu(float input);
};

#endif