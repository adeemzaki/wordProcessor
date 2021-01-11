#include "Sentence.h"

Sentence::Sentence() {
	Object = nullptr;
	Next = nullptr;
	  TotalPunctuationsCount = 0;
	  TotalWordsCount = 0;
	  TotalSpacesCount = 0;
	  TotalCharactersCount = 0;
}
Sentence::Sentence(Sentence& obj) { 
	Sentence* newobj = this;
	newobj->Object = new Word{ *obj.Object };
	if (obj.Next != nullptr)
	{
		newobj->Next = new Sentence{ *obj.Next };
	}
	this->TotalPunctuationsCount= obj.TotalPunctuationsCount;
	this->TotalWordsCount = obj.TotalWordsCount;
	this->TotalSpacesCount = obj.TotalSpacesCount;
	this->TotalCharactersCount = obj.TotalCharactersCount;
}
 
int Sentence::GetTotalWordsCount() { return TotalWordsCount; }
int Sentence::GetTotalCharactersCount() { return TotalCharactersCount; }
int Sentence::GetTotalPunctuationsCount() { return TotalPunctuationsCount; }
int Sentence::GetTotalSpaceCount() { return TotalSpacesCount; }

void Sentence::SetTotalWordsCount(int x) { TotalWordsCount = x; }
void Sentence::SetTotalCharactersCount(int x) { TotalCharactersCount = x; }
void Sentence::SetTotalPunctuationsCount(int x) { TotalPunctuationsCount = x; }
void Sentence::SetTotalSpaceCount(int x) { TotalSpacesCount = x; }

void Sentence::SetNext(char x,char a)
{
	Sentence* obj = this;
	while (obj->Next != nullptr)
	{
		obj = obj->Next;
	}
	if (a == '.')
	{
		obj->check = false;
		obj->Next = new Sentence;
	}
	if (obj->Object == nullptr) {
		obj->Object = new Word;
	}
	obj->Object->SetNext(x,a);
	if (obj->check)
	{
		if (a == '.')
		{
			obj->check = false;
			obj->Next = new Sentence;
			dotCount++;
		}
		obj->TotalCharactersCount++;
		if (x==' ')
		{
			obj->TotalSpacesCount++;
			obj->TotalWordsCount++;
		}
		else if (Check_IfCharacter(x)==false)
		{
			obj->TotalPunctuationsCount++;
		}
	}
}

bool Sentence::Check_IfCharacter(char a) {
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

void Sentence::print(ostream& fout, Sentence*obj)
{
	Sentence* newobj = obj;
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

void Sentence::clearMemory()
{
	if (this->Object != nullptr)
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

void Sentence::GetFrequency(ostream& fout,int i) {
	if (dotCount!=1)
	{
		fout << "\nWords in Sentence no " << i << " : " << TotalWordsCount + 1;
		Object->GetFrequency(fout, 1, i);
		if (this->Next != nullptr)
		{
			this->Next->GetFrequency(fout, i + 1);
		}
	}
	
}

bool Sentence::operator==(const Sentence& obj)
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
bool Sentence::countCheck(const Sentence& obj) {

	if (this->TotalCharactersCount == obj.TotalCharactersCount)
	{
		if (this->TotalPunctuationsCount == obj.TotalPunctuationsCount)
		{ 
				if (this->TotalSpacesCount == obj.TotalSpacesCount)
				{
					if (this->TotalWordsCount == obj.TotalWordsCount)
					{
						return true;
					}
				}
		}
	}
	return false;
}

void Sentence::operator-() {
	Sentence* temp = this;
	if (temp->Next != nullptr)
		-(*temp->Next);
	-(*this->Object);
}

void Sentence::operator+() {
	Sentence* temp = this;
	if (temp->Next != nullptr)
		+ (*temp->Next);
	+(*this->Object);
}

void Sentence::operator^(int x) {
	Sentence* temp = this;
	if (temp->Next != nullptr)
		(*temp->Next) ^ x;
	(*this->Object) ^ x;
}
void Sentence::operator*(int x) {
	Sentence* temp = this;
	if (temp->Next != nullptr)
		(*temp->Next)* x;
	(*this->Object)* x;
}