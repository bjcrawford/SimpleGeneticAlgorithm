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
	float relFitness = 0;
	float totalFitness = 0;

	for(int i = 0; i < POP_SIZE; i++)
	{
		totalFitness += population[i]->getObjValue();
	}

	for(int i = 0; i < POP_SIZE; i++)
	{
		relFitness = population[i]->getObjValue();
		population[i]->setRelFitness(relFitness / totalFitness);
	}
}