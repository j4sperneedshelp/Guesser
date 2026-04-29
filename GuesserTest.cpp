/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// Example "smoke test" (can be deleted)
TEST(GuesserTest, smoke_test)
{
  Guesser object("Secret");
  ASSERT_EQ( 1+1, 2 );
}

TEST(GuesserTest,three_tries) {
	Guesser object("Secret");
	object.match("wrong");
	object.match("wrong");
	object.match("wrong");
	ASSERT_FALSE(object.match("Secret"));
}

TEST(GuesserTest,zero_length_guess) {
	Guesser object("Secret");
	ASSERT_FALSE(object.match(""));
}

TEST(GuesserTest,long_guess) {
	Guesser object("Secret");
	ASSERT_EQ(object.distance("Secret1"),1);
}

TEST(GuesserTest,short_guess) {
	Guesser object("Secret");
	ASSERT_EQ(object.distance("Secre"),1);
}

TEST(GuesserTest,same_len_guess) {
	Guesser object("Secret");
	ASSERT_EQ(object.distance("Secrel"),1);
}

TEST(GuesserTest,long_input) {
	Guesser object("SecretSecretSecretSecretSecretSecret");
	ASSERT_TRUE(object.match(SecretSecretSecretSecretSecretSe));
}

TEST(GuesserTest,correct_guess) {
	Guesser object("Secret");
	ASSERT_TRUE(object.match("Secret"));
}

TEST(GuesserTest,zero_distance) {
	Guesser object("Secret");
	ASSERT_EQ(object.distance("Secret"),0);
}

