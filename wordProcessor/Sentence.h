#pragma once
#include "Word.h"
class Sentence : private Word
{
	Word* Object;
	Sentence* Next;
	int TotalPunctuationsCount;
	int TotalWordsCount;
	int TotalSpacesCount;
	int TotalCharactersCount;
	int dotCount=0;
	bool check = true;
public: 
	Sentence();
	Sentence(Sentence&);
	void SetNext(char, char);
	void clearMemory();
	void GetFrequency(ostream& fout, int);
	bool operator==(const Sentence& obj);
	bool countCheck(const Sentence& obj);
	void operator-();
	void operator+();
	void operator^(int x);
	void operator*(int x);
	;
	void print(ostream&, Sentence*);
	bool Check_IfCharacter(char);
	int GetTotalWordsCount();
	int GetTotalCharactersCount();
	int GetTotalPunctuationsCount();
	int GetTotalSpaceCount();

	void SetTotalWordsCount(int);
	void SetTotalCharactersCount(int);
	void SetTotalPunctuationsCount(int);
	void SetTotalSpaceCount(int);
};

