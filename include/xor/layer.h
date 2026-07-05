#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "xor/node.h"
#include "xor/random_number.h"

using namespace std;

class Layer {
    private:
        //Layer& previousLayer;
        vector<float> currentInputs;
        vector<Node> nodes;
        vector<float> currentOutputs;

        int numOfNodes;
        afs chosenActivationFunction;
        RandomNumber rng;

        void addNode(int num);
    public:
        Layer();
        Layer(int numOfNodes, afs activationFunction, int numOfInputs);
        Layer(int numOfNodes, Layer& newPreviousLayer);
        void loadInputs(vector<float>& newInput);
        void loadActivationFunction(afs newActivationFunction);
        afs getActivationFunction();
        int getNumOfNodes();
        vector<float> outputs();
        ~Layer();

};

#endif