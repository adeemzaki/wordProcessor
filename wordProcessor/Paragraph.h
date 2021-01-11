#pragma once
#include "Sentence.h"
class Paragraph :
    private Sentence
{
    Sentence *Object;
    Paragraph* Next;
    Paragraph* Temp;
    int TotalPunctuationsCount;
    int TotalSentencesCount;
    int TotalWordsCount;
    int TotalSpacesCount;
    int TotalCharactersCount;
    bool check = true;
public:
    Paragraph();
    Paragraph(const Paragraph&); 
    void SetNext(char, char);
    void clearMemory();
    void print(ostream&,Paragraph*);
    bool operator==(const Paragraph& obj);
    bool countCheck(const Paragraph& obj);

    void GetFrequency(ostream&, int);

    Paragraph& operator+(const Paragraph& obj);

    void operator-();

    void operator+();

    void operator^(int x);

    void operator*(int x);

    int GetTotalSentencesCount();
    int GetTotalWordsCount();
    int GetTotalCharactersCount();
    int GetTotalPunctuationsCount();
    int GetTotalSpaceCount();

    void SetTotalSentencesCount(int);
    void SetTotalWordsCount(int);
    void SetTotalCharactersCount(int);
    void SetTotalPunctuationsCount(int);
    void SetTotalSpaceCount(int);
};

