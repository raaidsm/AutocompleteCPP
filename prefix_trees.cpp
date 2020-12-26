#include <iostream>
#include "support.cpp"

using namespace std;

class AutocompleterInterface {
public:
    virtual int getLength() = 0;
    virtual void insert(string, float, void*) = 0;
    virtual void remove(void*) = 0;
    virtual NodeReport* autocomplete(void*) = 0;
    virtual NodeReport* autocomplete(void*, int) = 0;
};

class SimplePrefixTree : public AutocompleterInterface {
protected:
    string _value;
    float _weight;
    SimplePrefixTree* _subtrees;
    float* _weights;
    WeightType _weightType;

    virtual void insertSum(string& value, float weight, void* prefix) {}
    virtual float insertAverage(string& value, float weight, void* prefix) {}
    virtual void removeSum(void*) {}
    virtual float* removeAverage(void*) {}

public:
    ~SimplePrefixTree() = default;
    explicit SimplePrefixTree(WeightType weightType) : _weightType(weightType) {
        _value = nullptr;
        _weight = 0;
        _subtrees = nullptr;
        _weights = nullptr;
        _weightType = static_cast<WeightType>(NULL);
    }
    SimplePrefixTree(string value, float weight, SimplePrefixTree* subtrees, float* weights, WeightType weightType) {
        _value = std::move(value);
        _weight = weight;
        _subtrees = subtrees;
        _weights = weights;
        _weightType = weightType;
    }

    bool isEmpty() {}
    bool isLeaf() {}
    string stringRep() {}
    void insert(string value, float weight, void* prefix) override {
        if (_weightType == eSum) {
            insertSum(value, weight, prefix);
        }
        else if (_weightType == eAverage) {
            insertAverage(value, weight, prefix);
        }
    }
    void remove(void* prefix) override {
        if (_weightType == eSum) {
            removeSum(prefix);
        }
        else if (_weightType == eAverage) {
            removeAverage(prefix);
        }
    }
    NodeReport* autocomplete(void* prefix) override {}
    NodeReport* autocomplete(void* prefix, int limit) override {}
};

class CompressedPrefixTree : public SimplePrefixTree {
protected:
    void insertSum(string& value, float weight, void* prefix) override {}
    float insertAverage(string& value, float weight, void* prefix) override {}
    void removeSum(void*) override {}
    float* removeAverage(void*) override {}

public:
    ~CompressedPrefixTree() = default;
    explicit CompressedPrefixTree(WeightType weightType) : SimplePrefixTree(weightType) {}
    //TODO:
    CompressedPrefixTree(string value, float weight, SimplePrefixTree* subtrees, float* weights,
                         WeightType weightType) : SimplePrefixTree(value, weight, subtrees, weights, weightType) {}

    NodeReport* autocomplete(void* prefix) override {}
    NodeReport* autocomplete(void* prefix, int limit) override {}
};