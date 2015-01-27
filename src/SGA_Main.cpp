/**
 * @file SGA.cpp
 * @author Brett Crawford
 * @brief
 * @details
 */

#include <iostream>
#include "SGAConstants.hpp"
#include "Individual/Individual.hpp"
#include "Population/Population.hpp"

typedef std::vector<Individual *> ind_vec;

int main(int argc, char **argv)
{
	Population *pop = new Population();
	ind_vec ind;
	int bestInd;
	float bestObj;

	for(int i = 0; i < MAX_GEN; i++)
	{
		pop->selection();
		pop->reproduce();

		ind = pop->getPopulation();
		bestInd = 0;
		bestObj = ind[0]->getObjValue();
		for(int j = 0; j < POP_SIZE; j++)
		{
			if(ind[j]->getObjValue() > bestObj)
			{
				bestInd = j;
				bestObj = ind[j]->getObjValue();
			}
		}

		std::cout << "Best individual of gen " << i << std::endl;
		std::cout << "  Individual " << bestInd << std::endl;
		std::cout << "  Real Value: " << ind[bestInd]->getRealValue() << std::endl;
		std::cout << "  Objective Value: " << ind[bestInd]->getObjValue() << std::endl;
		std::cout << "  Relative Fitness: " << ind[bestInd]->getRelFitness() << std::endl;
		std::cout << "  Genotype: " << ind[bestInd]->getGenotype() << std::endl;
		std::cout << std::endl;
	}

	

	delete pop;

	return 0;
}