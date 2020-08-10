// CellularAutomaton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ElementaryCA.h"
#include "TwoDimensionCA.h"

void one_dimen_driver();
void two_dimen_driver();

int main()
{
    std::cout << "Press 1 for Elementary Cellular Automota Simulation\nPress 2 for Two Dimensional Cellular Automata simulation.\n";
    int choice;
    std::cin >> choice;
    if(choice  == 1)
    {
        one_dimen_driver();
    }
    if(choice == 2)
    {
        two_dimen_driver();
    }
}

void two_dimen_driver()
{
    std::cout << "Cellular Automata visualizer. \n Enter a negative number to exit...\n";
    std::string input;
    while (true)
    {
        std::cout << "Enter a Rule: ";
        std::cin >> input;

        TwoDimensionCA ca(10, 10);

        ca.simulate(input);
        std::cout << std::endl << std::endl;
    }
}

void one_dimen_driver()
{
    std::cout << "Elementary Cellular Automata visualizer. \n Enter a negative number to exit...\n";

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