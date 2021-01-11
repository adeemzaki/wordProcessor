#pragma once
#include "Character.h"
class Word :  private Character
{
    Character* Object;
    Word* Next;
	int TotalCharactersCount;
	int TotalSpacesCount;
	int TotalPunctuationsCount;
	bool check= true;
public:
	Word();
	Word(Word&);
	void SetNext(char, char);
	void clearMemory();
	bool operator==(const Word& obj);
	bool countCheck(const Word& obj);
	void GetFrequency(ostream& fout,int, int);
	void operator-();
	void operator+();
	void operator^(int x);
	void operator*(int x);
	void print(ostream&, Word*);

	int GetTotalCharactersCount();
	void SetTotalCharactersCount(int);
};

