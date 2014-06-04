// anagramMain.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include "AnagramLib.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	string word;
	// generate word index
	cout << "Generating word Index ......" << endl;
	string wordListPath = "../WordLookup.txt";
	map<unsigned long, vector<string>> wordIndex;  // would prob be better if file path and index were global
	anagramUtils::createWordIndex(wordListPath, wordIndex);

	// main loop body
	do 
	{
		cout << "Enter a word or (-1) to exit" << endl;
		getline(cin, word);
		
		// create the anagram object and display
		anagram newAnagram = anagram(word, wordIndex);
		vector<string> tempAnagrams = newAnagram.getAnagrams();
		for(vector<string>::iterator vecIt = tempAnagrams.begin(); vecIt != tempAnagrams.end(); vecIt++)
		{
			cout << *vecIt << endl;
		}
		
	} while (word != "-1");

	return 0;
}

