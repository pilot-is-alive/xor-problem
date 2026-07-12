#ifndef LAYER_H
#define LAYER_H

#include <vector>
#include "xor/node.h"
#include "xor/random_number.h"

using namespace std;

class Layer {
    private:
        Layer* previousLayer = nullptr;
        Layer* nextLayer = nullptr;

        vector<float>& currentInputs;
        vector<Node> nodes;
        vector<float> currentOutputs;

        int numOfNodes;
        afs chosenActivationFunction;
        RandomNumber rng;

        void loadPreviousLayerNextLayer();
        void addNode(int num);
    public:
        Layer() = delete;
        Layer(int numOfNodes, afs activationFunction, int numOfInputs, vector<float> initInputs);
        Layer(int numOfNodes, Layer& newPreviousLayer);

        void loadNextLayer(Layer* newNextLayer);

        void loadInputs(vector<float>& newInput);
        void loadActivationFunction(afs newActivationFunction);
        afs getActivationFunction();
        int getNumOfNodes();
        vector<float>& outputs();
        ~Layer();

};

#endif