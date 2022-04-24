/*
Name: Ryan Vreeke
Assignment: A1: An Ecological Simulation
An ecological life simulation, that will keep track of the changing popultaions of rabbits and foxes, as they fight for food;
*/
#include <iostream>
#include <cmath>

void plotPopulations(double rabbits, double foxes, double scale);
void incrementCounter(int *counter);

/*
    rabbitGrowth(g): the rate of increase of rabbits
    predationRate(p): fraction of prey eaten per predator
    foxPreConverstion(C): fraction of eaten prey turned into new predators
    foxMortalityRate(m): a per capita mortality rate for foxes
    carryCapacity(K) How many rabbits can be supported by the environment

    deltaRabbit = gR(1-R/K)-pRF
    deltaFoxes = cpRF-mF
*/
//uses all the variable to get the delta population in fox an rabbit populations
void updatePopulations(double g, double p, double c, double m, double k, double &numRabbits, double &numFoxes)
{
    double deltaRabbit = g * numRabbits * (1 - numRabbits / k) - p * numRabbits * numFoxes;
    double deltaFoxes = c * p * numRabbits * numFoxes - m * numFoxes;

    numRabbits += deltaRabbit;
    numFoxes += deltaFoxes;
}
//Method called to start the sim loop, with init rabbit and fox popultaions and the number of iteration that the sim should perform
void runSimulation(int iterations, double rabbits, double foxes)
{
    int i = 0;
    double scale = 0.1;

    plotPopulations(rabbits, foxes, scale);
    std::cout << std::endl;

    while (i < iterations)
    {
        if(rabbits <= 0 || foxes <= 0){//if the fox or rabbit population is below or equal to zero then break out of the loop and end the simulation
            break;
        }
        updatePopulations(0.2, 0.0022, 0.6, 0.2, 1000.0, rabbits, foxes);
        plotPopulations(rabbits, foxes, scale);
        std::cout << std::endl;//move the chart one line down before the loop starts over and the new pop is plotted
        incrementCounter(&i);
    }
}
/*
* helper method that plots the designated number of blank spaces then the character c
*/
void plotCharacter(int number, char c)
{
    if (number < 1)
    {
        std::cout << c;
        return;
    }
    for (int i = 0; i < number; i++)
    {
        std::cout << " ";
    }
    std::cout << c;
}
//plots that population of the rabit and foxes using the scale factor.
void plotPopulations(double rabbits, double foxes, double scale)
{
    int plotRabbits = floor(rabbits * scale);
    int plotFoxes = floor(foxes * scale);

    if (plotFoxes == plotRabbits)
    {
        plotCharacter(plotFoxes, '*');
    }
    else
    {
        if (plotFoxes > plotRabbits)
        {
            plotFoxes -= plotRabbits;
            plotCharacter(plotRabbits, 'r');
            plotCharacter(plotFoxes - 1, 'F');
        }
        else
        {
            plotRabbits -= plotFoxes;
            plotCharacter(plotFoxes, 'F');
            plotCharacter(plotRabbits-1, 'r');
        }
    }
}
//uses pointer to increment the counter by 1
void incrementCounter(int *counter)
{
    *counter = *counter + 1;
}
//main method that gets user inputs to and then starts the simulation with the init population and iternations to perform
int main()
{
    double rabbits;
    double foxes;
    int iterations;

    std::cout << "What is the initial rabbit population?: ";
    std::cin >> rabbits;

    if (std::cin.fail() || rabbits < 0)//if cin fails then print an error and return 1 to end the program
    {
        std::cerr << "please enter an integer" << std::endl;
        return 1;
    }

    std::cout << "What is the initial fox population?: ";
    std::cin >> foxes;

    if (std::cin.fail() || foxes < 0)
    {
        std::cerr << "please enter an integer" << std::endl;
        return 1;
    }

    runSimulation(500, rabbits, foxes);
    return 0;
}
