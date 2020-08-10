#pragma once
#include <iostream>
#include <algorithm>
#include <unordered_map>

class TwoDimensionCA
{
public:
    TwoDimensionCA(int stateSizeX, int stateSizeY) : sizeX(stateSizeX), sizeY(stateSizeY)
    {        
        state = new int* [stateSizeY];
        for (auto i = 0; i < stateSizeY; i++)
        {
            state[i] = new int[stateSizeX];
        }

        prevState = new int*[stateSizeY];
        for (auto i = 0; i < stateSizeY; i++)
        {
            prevState[i] = new int[stateSizeX];
        }
    }
    void simulate(unsigned long long int rule[8], int iterations = 250);
private:
    int** state;
    int** prevState;
    std::unordered_map<int, int> rule_map;
    int sizeX;
    int sizeY;
    void get_new_state() const;
    void print_state() const;
    void copy_state() const;
};

