#include "Character.h"

Character::Character() {
	CharactersCount = 0;
	SpaceCount = 0;
	PunctuationCount = 0;
	Next = nullptr;
	character = '\0'; 
	caps =false;
}
Character::Character(Character& obj) {
	Character* temp = this;
	if (temp->character== '\0')
	{
		temp->character = obj.character;
		temp->Setcount();  
		if (Check_IfCharacter(temp->character))
		{
			if (Iscapital(temp->character) && temp->character != ' ')
			{
				temp->caps = true;
			}
			else {
				temp->caps = false;
			}
		}
	}
	if (temp->Next == nullptr && obj.Next != nullptr)
	{
		temp->Next = new Character(*obj.Next);
	}
	
} 

void Character::Setcount() {
	CharactersCount++;
	if (character==' ')
	{
		SpaceCount = 1;
		PunctuationCount = 0;
	}
	else if(!Check_IfCharacter(character))
	{
		SpaceCount = 0;
		PunctuationCount = 1;
	}
}

void Character::SetNext(char x)
{
	Character* obj = this;
	if (character != '\0')
	{
		while (obj->Next!=nullptr)
		{
			obj = obj->Next;
		}
		obj->Next = new Character;
		obj = obj->Next;
	}

	obj->character = x;
	obj->CharactersCount++;
	if (Check_IfCharacter(x))
	{
		obj->SpaceCount=0;
		obj->PunctuationCount=0;
		if (Iscapital(obj->character) && obj->character!=' ')
		{
			obj->caps = true;
		}
		else {
			obj->caps = false;
		}
	}
	else { 
		if (x==' '||x=='\n')
		{
			obj->SpaceCount = 1;
			obj->PunctuationCount = 0;
		}
		else {
			obj->SpaceCount = 0;
			obj->PunctuationCount = 1;
		}
	}
	
}

void Character::clearMemory()
{
	if (this->Next != nullptr)
	{
		this->Next->clearMemory();
	}
	if (this->Next != nullptr)
	{
		delete this->Next;
	}
}

void Character::print(ostream& fout, Character* obj)
{
	Character* newobj = obj;
	while (newobj->character !='\0')
	{
		fout << newobj->character;
		newobj = newobj->Next;
		if (newobj==nullptr)
		{
			goto END;
		}
	}
END:
	int i = 0;
}

int Character::GetCharactersCount() {
	return CharactersCount;
}

bool Character::Check_IfCharacter(char a) {
	if (a == ' ')
	{
		return false;
	}
	if (a > 'z' || a < 'a') {
		if (a > 'Z' || a < 'A') {
			return false;
		}
	}
	return true;
}

bool Character::operator==(const Character& obj)
{
		if (countCheck(obj))
		{
			if (this->character == obj.character)
			{
				if (this->Next != nullptr && obj.Next != nullptr)
				{
					if (*this->Next == *obj.Next)
					{
						return true;
					}
				}
				if (this->Next == nullptr && obj.Next == nullptr)
				{
					return true;
				}
			}

		}

	return false;
}
bool Character::countCheck(const Character& obj) {

	if (this->CharactersCount == obj.CharactersCount)
	{
		if (this->SpaceCount == obj.SpaceCount)
		{
			if (this->PunctuationCount == obj.PunctuationCount)
			{
				return true;
			}
		}
	}
	return false;
}

void Character::operator-() {

	Character* temp = this;
	
	if (temp->Next != nullptr)
	{
		-(*temp->Next);
	} 
	if (Check_IfCharacter(character) && temp->character != ' ')
	{
		if (temp->caps)
		{
			temp->character = temp->character + 32;
			caps = false;
		}
	}
}

void Character::operator+() {

	Character* temp = this;

	if (temp->Next != nullptr)
	{
		+(*temp->Next);
	}
	if (Check_IfCharacter(temp->character) && temp->character!=' ')
	{
		if (!temp->caps)
		{
			temp->character = temp->character- 32;
			caps = false;
		}
	}
}

bool Character::Iscapital(char x)
{
	if (x<'a')
	{
		return true;
	}
	return false;
}

void Character::operator^(int x) {

		Character* temp = this;

		if (temp->Next != nullptr)
		{
			(*temp->Next)^x;
		}
		if (Check_IfCharacter(temp->character) && temp->character != ' ')
		{
			if (!temp->Encripted)
			{
				temp->character = temp->character +x;
				if (temp->character>'z')
				{
					int lessby = temp->character-'z';
					temp->character = 'a';
					temp->character = temp->character + lessby;
				}
				else if (temp->character > 'Z'&& temp->character < 'a')
				{
					int lessby = temp->character - 'Z';
					temp->character = 'A';
					temp->character = temp->character + lessby;
				}
				Encripted = true;
			}
		}
}
void Character::operator*(int x) {

	Character* temp = this;

	if (temp->Next != nullptr)
	{
		(*temp->Next) * x;
	}
	if (Check_IfCharacter(temp->character) && temp->character != ' ')
	{
		if (temp->Encripted)
		{
			temp->character = temp->character - x;
			if (temp->character < 'a' && temp->character > 'Z')
			{
				int lessby =  'a' - temp->character;
				temp->character = 'z';
				temp->character = temp->character - lessby;
			}
			else if (temp->character < 'A' )
			{
				int lessby = 'A'- temp->character;
				temp->character = 'Z';
				temp->character = temp->character - lessby;
			}
			Encripted = false;
		}
	}
}