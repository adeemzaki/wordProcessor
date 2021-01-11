#include "Word.h"
Word::Word() {
	Object = nullptr;
	Next = nullptr;
	  TotalCharactersCount=0;
	  TotalSpacesCount = 0;
	  TotalPunctuationsCount = 0;
}
Word::Word(Word& obj) {
	Word* newobj = this;
	newobj->Object = new Character{ *obj.Object };
	if (obj.Next != nullptr)
	{
		newobj->Next = new Word{ *obj.Next };
	}
	newobj->TotalCharactersCount = obj.TotalCharactersCount;
	newobj->TotalPunctuationsCount = obj.TotalPunctuationsCount;
	newobj->TotalSpacesCount = obj.TotalSpacesCount;
}

int Word::GetTotalCharactersCount() { return TotalCharactersCount; }

void Word::SetTotalCharactersCount(int x) { TotalCharactersCount = x; }

void Word::SetNext(char x,char a)
{
	Word* obj = this;
	
	while (obj->Next != nullptr)
	{
		obj = obj->Next;
	}
	if (x == ' ')
	{
		obj->check = false;
		obj->Next = new Word;
	}
	if (obj->Object == nullptr){
		obj->Object = new Character;
	}
	obj->Object->SetNext(x);
	if (obj->check)
	{
		if (x == ' ')
		{
			obj->check = false;
			obj->Next = new Word;
			obj->TotalSpacesCount++;
		}
		obj->TotalCharactersCount++;
		if (obj->Object->Check_IfCharacter(x) == false)
		{
			obj->TotalPunctuationsCount++;
		}
	}
}

void Word::print(ostream& fout, Word* obj)
{
	Word* newobj = obj;
	while (newobj->Object != nullptr)
	{
		newobj->Object->print(fout, newobj->Object);
		newobj = newobj->Next; 
		if (newobj == nullptr)
		{
			goto END;
		}
	}
END:
	int i = 0;
}

void Word::clearMemory()
{
	if (this->Object!=nullptr)
	{
		this->Object->clearMemory();
		if (this->Next != nullptr)
		{
			this->Next->Object->clearMemory();
		}
		if (this->Next != nullptr)
		{
			delete this->Next;
		}
	}
}

bool Word::operator==(const Word& obj)
{
	if (obj.Object == nullptr && this->Object == nullptr)
	{
		return true;
	}
	else
	{
		if (countCheck(obj))
		{
			if (*this->Object == *obj.Object)
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
	}
	return false;
}
bool Word::countCheck(const Word& obj) {

	if (this->TotalCharactersCount == obj.TotalCharactersCount)
	{
		 
		return true;
				 
	}
	return false;
}

void Word::GetFrequency(ostream& fout,int w,int s) {
	if (TotalSpacesCount!=1)
	{
		fout << "\nCharacters in word no " << w << " of sentence no " << s << " : "
			<< TotalCharactersCount - TotalPunctuationsCount;
		if (this->Next != nullptr)
		{
			this->Next->GetFrequency(fout, w + 1, s);
		}
	}
	
}

void Word::operator-() {
	Word* temp = this;
	if (temp->Next != nullptr)
		-(*temp->Next); 
	-(*this->Object);
}

void Word::operator+() {
	Word* temp = this;
	if (temp->Next != nullptr)
		+ (*temp->Next);
	+(*this->Object);
}

void Word::operator^(int x) {
	Word* temp = this;
	if (temp->Next != nullptr)
		(*temp->Next)^ x;
	(*this->Object) ^ x;
}
void Word::operator*(int x) {
	Word* temp = this;
	if (temp->Next != nullptr)
		(*temp->Next)* x;
	(*this->Object)* x;
}