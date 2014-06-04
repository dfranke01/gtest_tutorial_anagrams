// anagramTest.cpp : Defines the entry point for the console application.
//
#pragma once
#include "anagramLib.h"
#include <iostream>
#include <algorithm>
// keep last in include list
#include "gtest/gtest.h"

using namespace std;

TEST(anagramTestCase, getPrimeTest)
{
	int primeA = anagramUtils::getPrime('A');
	int primeE = anagramUtils::getPrime('e');
	int primeQ = anagramUtils::getPrime('Q');
	int primeS = anagramUtils::getPrime('s');
	EXPECT_EQ(primeA, 2);
	EXPECT_EQ(primeE, 11);
	EXPECT_EQ(primeQ, 59);
	EXPECT_EQ(primeS, 67);
}

TEST(anagramTestcase, getPrimeFactorization)
 {
 	string teststr1 = "one";
	string teststr2 = "two";
	string teststr3 = "parsec";
	EXPECT_EQ(22231, anagramUtils::getPrimeFactorization(teststr1));
	EXPECT_EQ(276971, anagramUtils::getPrimeFactorization(teststr2));
	EXPECT_EQ(23827210, anagramUtils::getPrimeFactorization(teststr3));
 }
 
TEST(anagramTestCase, createWordIndex)
{
	string wordListPath = "../WordLookup.txt";
	map<unsigned long, vector<string>> wordIndex;
	anagramUtils::createWordIndex(wordListPath, wordIndex);
	
	ASSERT_FALSE(wordIndex.empty());
	 
    // find a prime factorization
    map<unsigned long, vector<string>>::iterator it = wordIndex.find(9409346);
	if( it != wordIndex.end())
	{
		// find a word in the vector associated with that prime factorization
		EXPECT_NE(find(it->second.begin(), it->second.end(), "stain"), it->second.end());
		EXPECT_NE(find(it->second.begin(), it->second.end(), "saint"), it->second.end());
		EXPECT_NE(find(it->second.begin(), it->second.end(), "satin"), it->second.end());	
	}	
}

TEST(anagramTestCase, createClassInstance)
{
	// generate word index 
	string wordListPath = "../WordLookup.txt";
	map<unsigned long, vector<string>> wordIndex;
	anagramUtils::createWordIndex(wordListPath, wordIndex);
	
	anagram testAnagram = anagram::anagram("parsec", wordIndex);
	vector<string> testVector = testAnagram.getAnagrams();
	EXPECT_NE(find(testVector.begin(), testVector.end(), "parsec"), testVector.end());
	EXPECT_NE(find(testVector.begin(), testVector.end(), "capers"), testVector.end());
    EXPECT_NE(find(testVector.begin(), testVector.end(), "scrape"), testVector.end());
	EXPECT_NE(find(testVector.begin(), testVector.end(), "spacer"), testVector.end());
	EXPECT_NE(find(testVector.begin(), testVector.end(), "escarp"), testVector.end());
	EXPECT_NE(find(testVector.begin(), testVector.end(), "sparce"), testVector.end());

}

int main(int argc, char** argv) 
{ 
	testing::InitGoogleTest(&argc, argv); 
	RUN_ALL_TESTS(); 
	std::getchar(); // keep console window open until Return keystroke
	return 0;
}



