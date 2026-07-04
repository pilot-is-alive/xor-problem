#ifndef NODE_H
#define NODE_H

#include <vector>

using namespace std;

class Node {
    private:
        float bias = 0.0;
        vector<float> currentInputs;
        vector<float> currentWeights;
        int currentActivationFunction;
        float currentOutput;


        void summation();
        void activationFunction();

    public:
        void loadInputs(vector<float> newInputs);
        void loadBias(float newBias);
        void loadActivationFunction(int newActivationFunction);
        float output();
};

#endif