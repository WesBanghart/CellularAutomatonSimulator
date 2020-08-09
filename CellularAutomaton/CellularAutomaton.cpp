// CellularAutomaton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ElementaryCA.h"

int main()
{
    std::cout << "Cellular Automata visualizer. \n Enter a negative number to exit...";
    ElementaryCA elementary(101);
    auto input = 0;

    while (true)
    {
        std::cout << "Enter a Rule: ";
        std::cin >> input;
        if (input < 0)
        {
            break;
        }

        elementary.simulate(input, 250);
        std::cout << std::endl << std::endl;
    }

}