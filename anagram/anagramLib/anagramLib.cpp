// anagramLib.cpp : Defines the exported functions for the DLL application.
#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

#include "anagramLib.h"

using namespace std;

anagram::anagram(string word, map<unsigned long, vector<string>> &wordIndex)
{
	initialWord = word;
	prime_factorization = anagramUtils::getPrimeFactorization(initialWord);
	anagrams = wordIndex[prime_factorization];
}

string anagram::getInitialWord()
{
	return initialWord;
}

vector<string> anagram::getAnagrams()
{
	return anagrams;
}

////////////////////////////////////
// Utils
////////////////////////////////////

// given a number character, return its corresponding prime
int anagramUtils::getPrime( char c )
{
	c = toupper(c);
	switch (c)
	{
	 case 'A': return 2; break;  case 'B': return 3; break;  case 'C': return 5; break; 	
	 case 'D': return 7; break;  case 'E': return 11; break; case 'F': return 13; break;
	 case 'G': return 17; break; case 'H': return 19; break; case 'I': return 23; break; 	
	 case 'J': return 29; break; case 'K': return 31; break; case 'L': return 37; break;
	 case 'M': return 41; break; case 'N': return 43; break; case 'O': return 47; break; 	
	 case 'P': return 53; break; case 'Q': return 59; break; case 'R': return 61; break;
	 case 'S': return 67; break; case 'T': return 71; break; case 'U': return 73; break; 	
	 case 'V': return 79; break; case 'W': return 83; break; case 'X': return 89; break;
	 case 'Y': return 97; break; case 'Z': return 101; break;

	 default : return 0;
	}
}

// calculates the prime factorization for the supplied word
unsigned long anagramUtils::getPrimeFactorization(string word)
{
	unsigned long primeFact = 1;
	for(int i = 0; i < word.length(); i++)
	{
		primeFact = primeFact * getPrime(word[i]);
	}
	
	return primeFact;
}

// create an index of words and their prime factorizations
void anagramUtils::createWordIndex( string path, map<unsigned long, vector<string>> &wordIndex)
{
	string line;
	vector<string> wordList;
	ifstream dictFile(path);
	if (dictFile.is_open())
	{
		while ( dictFile.good() )
		{
			// read in each line and compute its prime factorization
			getline (dictFile, line);
			unsigned long pf = anagramUtils::getPrimeFactorization(line);
			// add the word to the index passed in
			wordIndex[pf].push_back(line);
		}
		dictFile.close();
	}
	else cout << "Unable to open file";     
}
