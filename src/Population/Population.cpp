/**
 * @file Population.cpp
 * @author Brett Crawford
 * @brief
 * @detail
 * 
 */

#include "Population.hpp"

// ==============================================================
// |                  Constructors/Destructor                   |
// ==============================================================

Population::Population()
{
	population.resize(POP_SIZE);
	for(int i = 0; i < POP_SIZE; i++)
		population[i] = new Individual();
	calcRelFitness();
}

Population::~Population()
{
	for(int i = 0; i < POP_SIZE; i++)
		if(population[i] != NULL)
			delete population[i];
}

// ==============================================================
// |                     Public Methods                         |
// ==============================================================

ind_vec Population::getPopulation()
{
	return population;
}

void Population::reproduce()
{
}

// ==============================================================
// |                     Private Methods                        |
// ==============================================================

void Population::calcRelFitness()
{
}