#include"WordProcessor.h"
#include<fstream>

int main() {
	WordProcessor software;
	ifstream fin;
	fin.open("abc.txt");
	fin >> software; 
	WordProcessor newobj;
	newobj=software;
	cout << software;

//	if (newobj== software)
//	{
//		cout << "\n\nboth are equal\n\n";
//	}

//	if (newobj != software)
//	{
//		cout << "\n\n\tboth are not equal\n\n";
//	}
	//^ Encryption and * Decryption
//	software^4;
//	cout << "After Encryption";
//	cout << "\n";
//	cout << software;
//	cout << "\n\n\t \n\n";
//	software * 4;
//	cout << "After Decryption";
//	cout << "\n";
//	cout << software;
//	cout << "\n\n\t \n\n";
//	-software;
//	cout << software;
//	cout << endl << endl;
//	+software;
//	cout << software;
//	cout << endl << endl;


//	ofstream fout;
//	fout.open("Frequency.txt");
//	software.GetFrequency(fout);
//	fout.close();
}