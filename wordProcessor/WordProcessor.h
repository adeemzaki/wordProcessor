#pragma once
#include "Paragraph.h"

class WordProcessor : private Paragraph
{
	Paragraph *Object;
public:
	WordProcessor();
	WordProcessor(const WordProcessor&);

	friend istream& operator>>(istream&, WordProcessor&);
	friend ostream& operator<<(ostream&, WordProcessor&);
	
	WordProcessor& operator=(WordProcessor&);
 	bool operator!=(const WordProcessor&); 
	bool operator==(const WordProcessor&);

	WordProcessor& operator+(const WordProcessor& obj);

	void SetNext(char, char);
	void clearMemory();
	void GetFrequency(ostream&);
	void operator-();
	void operator+();
	void operator^(int);
	void operator*(int x);
};

