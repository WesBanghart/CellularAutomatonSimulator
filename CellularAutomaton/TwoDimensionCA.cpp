#include "TwoDimensionCA.h"

void TwoDimensionCA::simulate(unsigned long long int rule[8], int iterations)
{
    //TODO: determine if rule is out of bounds

    //Convert rule to N bit binary representation of the 8 state transitions
    int k = 0;
    for(auto i = 0; i < 8; i++)
    {
       for (auto j = 0; j < 64; ++j)
        {
            rule_map[k] = rule[i] % 2;
            rule[i] = rule[i] / 2;
            k++;
        } 
    }


    std::fill_n(state, size, 0);
    std::fill_n(prevState, size, 0);

    //Initialize middle element of the state
    state[size / 2] = 1;

    //CA iterations
    for (auto i = 0; i < iterations; ++i)
    {
        //Print Current State
        print_state();
        //Calculate New State
        get_new_state();
    }
}

void TwoDimensionCA::get_new_state() const
{
}

void TwoDimensionCA::print_state() const
{
}

void TwoDimensionCA::copy_state() const
{
}
