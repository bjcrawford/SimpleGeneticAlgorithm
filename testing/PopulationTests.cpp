/**
 * @file PopulationTests.cpp
 * @author Brett Crawford
 * @brief
 * @detail
 * 
 */

#include "../src/Population/Population.hpp"
#include "../src/Individual/Individual.hpp"
#include "../src/SGAConstants.hpp"
#include "gtest/gtest.h"

/**
 * Fixture class for testing the default constuctor
 */
class PopulationDefaultConstructorFixtureTests : public testing::Test 
{
	protected:

		Population *pop;

		virtual void SetUp()
		{
			pop = new Population();
		}

		virtual void TearDown()
		{
			delete pop;
		}
};

// ==============================================================
// |              Default Constructor Tests                     |
// ==============================================================

TEST(PopulationDefaultConstructorTests, checkObjectCount)
{
	Population *pop = new Population();
	EXPECT_EQ(POP_SIZE, Individual::getCount());

	delete pop;
	EXPECT_EQ(0, Individual::getCount());
}

TEST_F(PopulationDefaultConstructorFixtureTests, checkRelFitnessBounds)
{
	ind_vec inds = pop->getPopulation();
	for(int i = 0; i < POP_SIZE; i++)
	{
		EXPECT_GE(inds[i]->getRelFitness(), 0.0) << "pop[" << i << "] is less than zero";
		EXPECT_LE(inds[i]->getRelFitness(), 1.0) << "pop[" << i << "] is greater than one";
	}
}