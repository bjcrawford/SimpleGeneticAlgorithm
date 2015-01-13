/**
 * @file IndividualTests.cpp
 * @author Brett Crawford
 * @brief
 * @detail
 * 
 */

#include "../src/Individual/Individual.hpp"
#include "../src/SGAConstants.hpp"
#include "gtest/gtest.h"

TEST(IndividualTests, defaultConstructorCreationDeletion)
{
	Individual *ind = new Individual();
	EXPECT_EQ(ind->getCount(), 1);

	delete ind;
	EXPECT_EQ(ind->getCount(), 0);
}



/*
bool testConstructorDefault();
bool testConstructorOneArg();

int main(int argc, char **argv)
{
	testConstructorDefault();
	testConstructorOneArg();

	return 0;
}

bool testConstructorDefault()
{
	std::cout << "Default Constructor Test" << std::endl;

	Individual *ind = new Individual();
	std::cout << "  Individual ind created" << std::endl;
	std::cout << "  Individual::count: " << ind->getCount() << std::endl;

	std::cout << "  Individual ind properties:" << std::endl;
	std::cout << "    ind->getRealValue(): " << ind->getRealValue() << std::endl;
	std::cout << "    ind->getObjValue(): " << ind->getObjValue() << std::endl;
	std::cout << "    ind->getGenotype(): " << ind->getGenotype() << std::endl;
	for(int i = 0; i < NUM_OF_GENES; i++)
	{
		std::cout << "    ind->getGene(" << i << "): " << ind->getGene(i) 
		          << std::endl;
	}

	delete ind;
	std::cout << "  Individual ind destroyed" << std::endl;
	std::cout << "  Individual::count: " << ind->getCount() << std::endl;

	return true;
}

bool testConstructorOneArg()
{
	std::cout << "One Argument Constructor Test" << std::endl;

	std::vector<bool> chromo = { true, true, false, true, false, true, 
		                         true, false, false, true, false, true };

	Individual *ind = new Individual(chromo);
	std::cout << "  Individual ind created" << std::endl;
	std::cout << "  Individual::count: " << ind->getCount() << std::endl;

	std::cout << "  Individual ind properties:" << std::endl;
	std::cout << "    ind->getRealValue(): " << ind->getRealValue() << std::endl;
	std::cout << "    ind->getObjValue(): " << ind->getObjValue() << std::endl;
	std::cout << "    ind->getGenotype(): " << ind->getGenotype() << std::endl;
	for(int i = 0; i < NUM_OF_GENES; i++)
	{
		std::cout << "    ind->getGene(" << i << "): " << ind->getGene(i) 
		          << std::endl;
	}

	delete ind;
	std::cout << "  Individual ind destroyed" << std::endl;
	std::cout << "  Individual::count: " << ind->getCount() << std::endl;

	return true;
}
*/