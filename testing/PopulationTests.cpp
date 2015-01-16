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