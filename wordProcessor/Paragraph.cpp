#include "Paragraph.h"

Paragraph::Paragraph() {
	Object = nullptr;
	Next = nullptr;
	TotalPunctuationsCount = 0;
	TotalSentencesCount = 0;
	TotalWordsCount = 0;
	TotalSpacesCount = 0;
	TotalCharactersCount = 0;
}
Paragraph::Paragraph(const Paragraph& obj) { 
	Paragraph *newobj = this;
	newobj->Object = new Sentence{ *obj.Object };
	if (obj.Next !=nullptr)
	{
		newobj->Next = new Paragraph{ *obj.Next };
	}
	this->TotalPunctuationsCount = obj.TotalPunctuationsCount;
	this->TotalSentencesCount = obj.TotalSentencesCount;
	this->TotalWordsCount = obj.TotalWordsCount;
	this->TotalSpacesCount = obj.TotalSpacesCount;
	this->TotalCharactersCount = obj.TotalCharactersCount;
 }

int Paragraph::GetTotalSentencesCount() { return TotalSentencesCount; }
int Paragraph::GetTotalWordsCount() { return TotalWordsCount; }
int Paragraph::GetTotalCharactersCount() { return TotalCharactersCount; }
int Paragraph::GetTotalPunctuationsCount() { return TotalPunctuationsCount; }
int Paragraph::GetTotalSpaceCount() { return TotalSpacesCount; }

void Paragraph::SetTotalSentencesCount(int x) { TotalSentencesCount = x; }
void Paragraph::SetTotalWordsCount(int x) { TotalWordsCount = x; }
void Paragraph::SetTotalCharactersCount(int x) { TotalCharactersCount = x; }
void Paragraph::SetTotalPunctuationsCount(int x) { TotalPunctuationsCount = x; }
void Paragraph::SetTotalSpaceCount(int x) { TotalSpacesCount = x; }

void Paragraph::SetNext(char x,char a)
{
	Paragraph* obj = this;
	while (obj->Next != nullptr)
	{
		obj = obj->Next;
	}
	if (a == '\n')
	{
		obj->check = false;
		obj->Next = new Paragraph;
	} 
	if (obj->Object == nullptr) {
		obj->Object = new Sentence;
	}
	obj->Object->SetNext(x,a);
	if (obj->check)
	{
		if (a == '\n')
		{
			obj->check = false;
			obj->Next = new Paragraph;
		}
		obj->TotalCharactersCount++;
		if (x == ' ')
		{
			obj->TotalSpacesCount++;
			obj->TotalWordsCount++;
		}
		else if (obj->Object->Check_IfCharacter(x) == false)
		{
			obj->TotalPunctuationsCount++;
			if (x == '.')
			{
				obj->TotalSentencesCount++;
			}
		}
	}
}

void Paragraph::clearMemory()
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

void Paragraph::print(ostream& fout, Paragraph* obj)
{
	Paragraph *newobj = obj;

	while (newobj->Object!=nullptr)
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

bool Paragraph::operator==(const Paragraph& obj)
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
bool Paragraph::countCheck(const Paragraph& obj) {

	if (this->TotalCharactersCount == obj.TotalCharactersCount)
	{ 
			if (this->TotalPunctuationsCount == obj.TotalPunctuationsCount)
			{
				if (this->TotalSentencesCount == obj.TotalSentencesCount)
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
	}
	return false;
}

void Paragraph::GetFrequency(ostream& fout,int p) {

	fout << "\nParagraph number : " << p;
	fout << "\nSentences in Paragraph " << p << " : " << TotalSentencesCount;
	Object->GetFrequency(fout,1);
	if (this->Next!=nullptr)
	{
		this->Next->GetFrequency(fout,p+1);
	}
}

Paragraph& Paragraph::operator+(const Paragraph& obj) {
	Paragraph newobj(obj);
	Temp = this;
	while (obj.Next!=nullptr)
	{
		Temp = Temp->Next;
	}
	Temp->Next = &newobj;
	return *this;
}

void Paragraph::operator-() {
	Paragraph *temp = this;
	if (temp->Next != nullptr)
		-(*temp->Next);
	-(*this->Object);
}
void Paragraph::operator+() {
	Paragraph* temp = this;
	if (temp->Next != nullptr)
		+(*temp->Next);
	+(*this->Object);
}

void Paragraph::operator^(int x) {
	Paragraph* temp = this;
	if (temp->Next != nullptr)
		(*temp->Next) ^ x;
	(*this->Object) ^ x;
}

void Paragraph::operator*(int x) {
	Paragraph* temp = this;
	if (temp->Next != nullptr)
		(*temp->Next)* x;
	(*this->Object)* x;
}