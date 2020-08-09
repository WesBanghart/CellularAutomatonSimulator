#include "ElementaryCA.h"

void ElementaryCA::simulate(int rule, int iterations)
{
    //Return if rule is out of bounds
    if(rule > 255 || rule < 0)
    {
        return;
    }

    //Convert rule to N bit binary representation of the 8 state transitions
    for(auto i = 0; i < 8; ++i)
    {
        rule_map[i] = rule % 2;
        rule = rule / 2;
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

void ElementaryCA::get_new_state() const
{
    int bin;
    copy_state();
    //We are having the edge cells wrap around
    for(auto i = 0; i < size; i++)
    {
        if(i == 0)
        {
            bin = (2 * 2 * prevState[size - 1]) + (2 * prevState[i]) + (prevState[i + 1]);

            for (const auto pair : rule_map)
            {

                if ((7 & bin) == pair.first)
                {
                    state[i] = pair.second;
                    break;
                }
            }
        }
        else if(i == size - 1)
        {
            bin = (2 * 2 * prevState[i - 1]) + (2 * prevState[i]) + (prevState[0]);

            for (const auto pair : rule_map)
            {
                if ((7 & bin) == pair.first)
                {
                    state[i] = pair.second;
                    break;
                }
            }
        }
        else
        {
            bin = (2 * 2 * prevState[i - 1]) + (2 * prevState[i]) + (prevState[i + 1]);

            for (const auto pair : rule_map)
            {
                if((7 & bin) == pair.first)
                {
                    state[i] = pair.second;
                    break;
                }
            }
        }
    }
}

void ElementaryCA::print_state() const
{
    for (auto i = 0; i < size; i++)
    {
        std::cout << state[i] << " ";
    }
    std::cout << std::endl;
}

void ElementaryCA::copy_state() const
{
    for (auto i = 0; i < size; i++)
    {
        prevState[i] = state[i];
    }
}
