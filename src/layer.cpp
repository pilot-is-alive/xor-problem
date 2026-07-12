#include "xor/layer.h"


Layer::Layer(int numOfNodes, afs activationFunction, int numOfInputs, vector<float> initInputs)
    : currentInputs(initInputs) {
    chosenActivationFunction  = activationFunction;
    currentInputs.assign(numOfInputs, 0);
}

Layer::Layer(int numOfNodes, Layer& newPreviousLayer)
    : currentInputs(newPreviousLayer.outputs()) {
    previousLayer = &newPreviousLayer;
    chosenActivationFunction  = newPreviousLayer.getActivationFunction();
    currentInputs.clear();
    currentInputs = newPreviousLayer.outputs();

    addNode(numOfNodes);
}

void Layer::loadNextLayer(Layer* newNextLayer) {
    nextLayer = newNextLayer;
}

void Layer::loadPreviousLayerNextLayer() {
    previousLayer->loadNextLayer(this);
}

void Layer::addNode(int num) {
    for (size_t i = 1; i <= num; i++) {
        Node newNode;

        newNode.loadBias(rng.get());

        for (size_t i = 1; i <= num; i++) {
            float newWeight = rng.get();
            newNode.addWeight(newWeight);
        }

        newNode.loadInputs(currentInputs);

        newNode.loadActivationFunction(chosenActivationFunction);
    }
}

void Layer::loadInputs(vector<float>& newInput) {
    currentInputs.clear();
    currentInputs = newInput;
}

void Layer::loadActivationFunction(afs newActivationFunction) {
    chosenActivationFunction = newActivationFunction;
}

afs Layer::getActivationFunction() {
    return chosenActivationFunction;
}

vector<float>& Layer::outputs() {
    currentOutputs.clear();

    for (Node& node: nodes) {
        currentOutputs.push_back(node.output());
    }

    return currentOutputs;
}