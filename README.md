# RabbitFoxPopulationSim

Ecological Simulation.
An ecological life simulation, that will keep track of changing populations of rabbit and foxes, as they fight for food.

starting program will ask for a initial state to use to calculate the delta of both rabbit and fox population.

populations updated using these variables
    rabbitGrowth(g): the rate of increase of rabbits
    predationRate(p): fraction of prey eaten per predator
    foxPreConverstion(C): fraction of eaten prey turned into new predators
    foxMortalityRate(m): a per capita mortality rate for foxes
    carryCapacity(K) How many rabbits can be supported by the environment

    deltaRabbit = gR(1-R/K)-pRF
    deltaFoxes = cpRF-mF
