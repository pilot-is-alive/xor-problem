#include "xor/node.h"

float Node::summation() {
    float sum = 0.0f;
    for (size_t i = 0; i < currentInputs.size(); i++) {
        sum += ( currentWeights.at(i) * currentInputs.at(i)); 
    } 
}

float Node::output() {
    float output = -1.0f;
    switch(chosenActivationFunction) {
        case afs::RELU:
            output = activationFunction.relu(summation() + bias);
            break;
        case afs::SIGMOID:
            output = activationFunction.sigmoid(summation() + bias);
            break;
        case afs::LEAKYRELU:
            output = activationFunction.leakyRelu(summation() + bias);
            break;
    }

    currentOutput = output;
    return output;
}

void Node::loadInputs(vector<float>& newInputs) {
    currentInputs = newInputs;
}
void Node::loadBias(float newBias) {
    bias = newBias;
}
void Node::loadActivationFunction(afs newActivationFunction) {
    chosenActivationFunction = newActivationFunction;
}
