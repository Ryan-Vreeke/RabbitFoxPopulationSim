# RabbitFoxPopulationSim


Ecological Simulation that will chart the change in population of Foxes and Rabbits over time.

The change in rabbit population depends on the natural rabbit growth rate. the carrying-capacity of the environments food and how often the foxes eat the rabbits. 

The change in the fox population depends on their natural die-off rate an how much the population is boosted by having rabbits to eat

change rates above are calculated usin a modification of the Lotka-Volterra. it has number of parameters:

	rabbitGrowth(g): the rate of increase of rabbits
    predationRate(p): fraction of prey eaten per predator
    foxPreConverstion(C): fraction of eaten prey turned into new predators
    foxMortalityRate(m): a per capita mortality rate for foxes
    carryCapacity(K) How many rabbits can be supported by the environment


The change in populations (deltaRabbit and deltaFoxes) for a given population of rabbits and foxes numRabbits (R) and numFoxes (F) is then:

    deltaRabbit = gR(1-R/K)-pRF
    deltaFoxes = cpRF-mF

 
