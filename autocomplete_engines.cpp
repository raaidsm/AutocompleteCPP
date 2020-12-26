#include <iostream>
#include "prefix_trees.cpp"

using namespace std;

class AutocompleteEngine {
public:
    virtual void insert() = 0;
    virtual void remove() = 0;
    virtual NodeReport* autocomplete(string) = 0;
    virtual NodeReport* autocomplete(string, int) = 0;
};

class LetterAutocompleteEngine : public AutocompleteEngine {};

class SentenceAutocompleteEngine : public AutocompleteEngine {};