#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;

class __declspec(dllexport) anagram 
{
private:
	// word to find anagrams of
	string initialWord;

	// prime factorization of the initial word
	unsigned long prime_factorization;

	// list of anagrams for the initial word
	vector<string> anagrams; 

public:
	// getter methods
	string getInitialWord();
	vector<string> getAnagrams();

	// ctor
	anagram(string word, map<unsigned long, vector<string>> &wordIndex);
};

/* utility class, private ctor, and static methods only */
class __declspec(dllexport) anagramUtils
{
private:
	// private ctor
	anagramUtils() { /* never implement this function */  };

public:
	// return a prime associated with the supplied character
	static int getPrime( char c );

	// returns a prime factorization of the supplied word
	static unsigned long getPrimeFactorization( string word );

	// populate the supplied wordIndex
	static void createWordIndex( string path, map<unsigned long, vector<string>> &wordIndex);
};