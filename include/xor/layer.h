#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "xor/node.h"
#include "xor/random_number.h"

using namespace std;

class Layer {
    private:
        vector<float> currentInputs;
        vector<Node> nodes;
        vector<float> currentOuputs;

        afs chosenActivationFunction;
        RandomNumber rng;
    public:
        Layer(afs activationFunction, int numOfNodes);
        void loadInputs(vector<float>& newInput);
        void loadActivationFunction(afs newActivationFunction);
        vector<float> outputs();
        ~Layer();

};

#endif