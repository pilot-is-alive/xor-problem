#include "xor/activation_function.h";

const float ActivationFunction::e = exp(1.0f);

float ActivationFunction::sigmoid(float input) {
    return (1/(1 + pow(e, (-input))));
}

float ActivationFunction::relu(float input) {
    return (input > 0.0f? input: 0.0f);
}

float ActivationFunction::leakyRelu(float input) {
    return (input > 0.0f? input: (0.01f)*input);
}