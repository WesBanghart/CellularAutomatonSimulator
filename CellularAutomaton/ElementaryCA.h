#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map> 


class ElementaryCA
{
public:
    ElementaryCA(int stateSize): size(stateSize)
    {
        state = new int[stateSize];
        prevState = new int[stateSize];
       // ruleSet = new int[8];
    }
    void simulate(int rule, int iterations = 1000);
private:
    int* state;
    int* prevState;
    std::unordered_map<int, int> rule_map;
    int size;
    void get_new_state() const;
    void print_state() const;
    void copy_state() const;
};
