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

	matingPool.resize(POP_SIZE);
	for(int i = 0; i < POP_SIZE; i++)
		matingPool[i] = NULL;

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

ind_vec Population::getMatingPool()
{
	return matingPool;
}

void Population::selection()
{
	typedef std::chrono::system_clock sys_clock;
	sys_clock::time_point tp = sys_clock::now();
  	sys_clock::duration dtn = tp.time_since_epoch();
  	unsigned int seed = dtn.count();

	std::default_random_engine prng(seed);
	std::uniform_real_distribution<float> dist(0.0, 1.0);

	for(int i = 0; i < POP_SIZE; i++)
	{
		float selectValue = dist(prng);
		float accumValue = 0.0;
		for(int j = 0; j < POP_SIZE; j++)
		{
			if(selectValue >= accumValue &&
			   selectValue <= (accumValue + population[j]->getRelFitness()))
			{
				matingPool[i] = new Individual(population[j]);
				break;
			}
			accumValue += population[j]->getRelFitness();
		}
	}
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