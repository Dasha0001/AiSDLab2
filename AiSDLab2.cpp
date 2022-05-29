#include <iostream>
#include <stdexcept>
#include"ShannonFanoALg.h"


int main() {
	string str;
	str = "it is testing string";
	int size = str.length();

	char* symbols = new char[size];
	int* symbolsNum = new int[size];
	string* inputStr = new string[size];
	string* strInbooleanCode = new string[size];
	char* decodInputString = new char[size];

	ShannonFanoALg(str, symbols, symbolsNum, inputStr, strInbooleanCode, decodInputString);
	cout << endl << "==============================Results strInbooleanCode===================================" << endl;
	for (int i = 0; i < str.length(); i++){ cout << strInbooleanCode[i]; }
		

	cout << endl << "==============================Results decodInputString===================================" << endl;
	for (int i = 0; i < str.length(); i++){ cout << decodInputString[i]; }
		
	clearArr(symbols, symbolsNum, inputStr, strInbooleanCode, decodInputString);

	return 0;
}
