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

/**
 * Fixture class for testing the default constuctor
 */
class IndividualDefaultConstructorFixtureTests : public testing::Test 
{
	protected:

		Individual *ind;

		virtual void SetUp()
		{
			ind = new Individual();
		}

		virtual void TearDown()
		{
			delete ind;
		}
};

/**
 * Fixture class for testing the chromosome constructor
 */
class IndividualChromoConstructorFixtureTests : public testing::Test
{
	protected:

		std::vector<bool> chromo;
		Individual *ind;

		virtual void SetUp()
		{
			chromo = { true, true, false, true, false, true, 
			           true, false, false, true, false, true };
			ind = new Individual(chromo);
		}

		virtual void TearDown()
		{
			delete ind;
		}
};

/**
 * Fixture class for testing the real value constructor
 */
class IndividualRealConstructorFixtureTests : public testing::Test
{
	protected:

		float realValue;
		Individual *ind;

		virtual void SetUp()
		{
			realValue = 0.95336914f;
			ind = new Individual(realValue);
		}

		virtual void TearDown()
		{
			delete ind;
		}
};

// ==============================================================
// |              Default Constructor Tests                     |
// ==============================================================

TEST(IndividualDefaultConstructorTests, checkObjectCount)
{
	Individual *ind = new Individual();
	EXPECT_EQ(1, ind->getCount());

	delete ind;
	EXPECT_EQ(0, ind->getCount());
}

TEST_F(IndividualDefaultConstructorFixtureTests, checkRealValueBounds)
{
	EXPECT_TRUE(ind->getRealValue() >= -1.0f);
	EXPECT_TRUE(ind->getRealValue() <= 2.0f);
}

TEST_F(IndividualDefaultConstructorFixtureTests, checkObjValueBounds)
{
	EXPECT_TRUE(ind->getObjValue() >= 0.0f);
	EXPECT_TRUE(ind->getObjValue() <= 4.0f);
}

TEST_F(IndividualDefaultConstructorFixtureTests, checkRelFitnessBounds)
{
	EXPECT_TRUE(ind->getRelFitness() >= 0.0f);
	EXPECT_TRUE(ind->getRelFitness() <= 4.0f);
}

// ==============================================================
// |              Chromosome Constructor Tests                  |
// ==============================================================

TEST(IndividualChromoConstructorTests, checkObjectCount)
{
	std::vector<bool> chromo = { true, true, false, true, false, true, 
		                         true, false, false, true, false, true };

	Individual *ind = new Individual(chromo);
	EXPECT_EQ(1, ind->getCount());

	delete ind;
	EXPECT_EQ(0, ind->getCount());
}

TEST_F(IndividualChromoConstructorFixtureTests, checkRealValue)
{
	// Refactor to calculate the magic number here
	EXPECT_FLOAT_EQ(0.953369, ind->getRealValue());
}

TEST_F(IndividualChromoConstructorFixtureTests, checkObjValue)
{
	// Refactor to calculate the magic number here
	EXPECT_FLOAT_EQ(1.051966, ind->getObjValue());
}

TEST_F(IndividualChromoConstructorFixtureTests, checkGenotype)
{
	// Refactor to create string from chromo
	EXPECT_EQ("101001101011", ind->getGenotype());
}

TEST_F(IndividualChromoConstructorFixtureTests, checkRelFitnessBounds)
{
	EXPECT_TRUE(ind->getRelFitness() >= 0.0f);
	EXPECT_TRUE(ind->getRelFitness() <= 4.0f);
}

// ==============================================================
// |              Real Value Constructor Tests                  |
// ==============================================================

TEST(IndividualRealConstructorTests, checkObjectCount)
{
	float realValue = 0.95336914f;
	Individual *ind = new Individual(realValue);
	EXPECT_EQ(1, ind->getCount());

	delete ind;
	EXPECT_EQ(0, ind->getCount());
}

TEST_F(IndividualRealConstructorFixtureTests, checkRealValue)
{
	// Refactor to calculate the magic number here
	EXPECT_FLOAT_EQ(0.953369, ind->getRealValue());
}

TEST_F(IndividualRealConstructorFixtureTests, checkObjValue)
{
	// Refactor to calculate the magic number here
	EXPECT_FLOAT_EQ(1.051966, ind->getObjValue());
}

TEST_F(IndividualRealConstructorFixtureTests, checkGenotype)
{
	// Refactor to create string from chromo
	EXPECT_EQ("101001101011", ind->getGenotype());
}

TEST_F(IndividualRealConstructorFixtureTests, checkRelFitnessBounds)
{
	EXPECT_TRUE(ind->getRelFitness() >= 0.0f);
	EXPECT_TRUE(ind->getRelFitness() <= 4.0f);
}