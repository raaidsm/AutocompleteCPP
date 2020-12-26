#include <iostream>

using namespace std;

enum WeightType {
    eSum,
    eAverage
};

struct NodeReport {
    string value;
    float weight;
};