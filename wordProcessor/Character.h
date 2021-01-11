#pragma once
#include<iostream>
using namespace std;
class Character
{	
	bool caps; //true is caps
	bool Encripted;
 
	int CharactersCount;
	int SpaceCount;
	int PunctuationCount;
	Character* Next;
	char character;
public:
	Character();
	Character(Character&);
	int GetCharactersCount(); 
	void SetNext(char);
	void clearMemory();
	void Setcount();
	void print(ostream&, Character*);

	bool Check_IfCharacter(char);

	bool operator==(const Character& obj);

	bool countCheck(const Character& obj);

	void operator-();
	void operator+();

	bool Iscapital(char);
	void operator^(int x);
	void operator*(int x);
};

