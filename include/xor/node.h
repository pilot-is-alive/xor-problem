#ifndef NODE_H
#define NODE_H

#include <vector>
#include "xor/activation_function.h"
#include "xor/afs.h"

using namespace std;

class Node {
    private:
        float bias = 0.0;
        vector<float> currentInputs;
        vector<float> currentWeights;
        ActivationFunction activationFunction;
        afs chosenActivationFunction;
        float currentOutput;

        float summation();

    public:
        void loadInputs(vector<float>& newInputs);
        void loadBias(float newBias);
        void loadActivationFunction(afs newActivationFunction);
        float output();
};

#endif