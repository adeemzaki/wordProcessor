#include "WordProcessor.h"

WordProcessor::WordProcessor() {
	Object = nullptr;
}
WordProcessor::WordProcessor(const WordProcessor& obj): WordProcessor(){
	this->Object = new Paragraph(*obj.Object);
}

WordProcessor& WordProcessor::operator=(WordProcessor& obj)
{
	this->clearMemory();
	this->Object = new Paragraph(*obj.Object);
	return *this;
}

bool WordProcessor::operator!=(const WordProcessor& obj)
{
	if (*this==obj)
	{
		return false;
	}
	return true;
}
bool WordProcessor::operator==(const WordProcessor& obj)
{
	if (obj.Object==nullptr && this->Object==nullptr)
	{
		return true;
	}
	else
	{
		if (*this->Object == *obj.Object)
			{
				return true;
			}
	}
	return false;
}

WordProcessor& WordProcessor::operator+(const WordProcessor& obj) {
	 this->Object->operator+(*obj.Object);
	 return *this;
}

void WordProcessor::SetNext(char x,char a)
{
	if(this->Object==nullptr)
	this->Object= new Paragraph;
	this->Object->SetNext(x,a);
}

void WordProcessor::clearMemory()
{
	if (this->Object != nullptr)
	{
		this->Object->clearMemory();
	}
}

istream& operator>>(istream& fin, WordProcessor& obj)
{
	char a='\0',prev;
	while (fin)
	{
		prev = a;
		fin.get(a);
		if (a == '.' && prev == '.')
		{
			continue;
		}
		else
		{
			obj.SetNext(a, prev);
		}
	}
	return fin;
}

ostream& operator<<(ostream& fout, WordProcessor& obj)
{
	if (obj.Object==nullptr)
	{
		fout << "No Data available to print.";
	}
	else {
		obj.Object->print(fout,obj.Object);
	}
	return fout;
}

void WordProcessor::GetFrequency(ostream& fout) {
	
	Object->GetFrequency(fout,1);
}

void WordProcessor::operator-() {
	-(*this->Object);
}
void WordProcessor::operator+() {
	+(*this->Object);
}
void WordProcessor::operator^(int x){
	(*this->Object)^ x;
}
void WordProcessor::operator*(int x) {
	(*this->Object) * x;
}