#ifndef ShannonFanoALg
#pragma once
#include"RBTreeRealisation.h"
#include"Node_List.h"
#include"QueueForRBTree.h"

using namespace std;
void FindCoefficient(string str, char* symbols, int size, string* booleanCode, string* strInbooleanCode) {


	double sizeOfString = 0;
	double sizeOfBooleanCode = 0;

	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < size; j++) {
			if (symbols[j] == str[i]) {
				strInbooleanCode[i] = booleanCode[j];
				sizeOfBooleanCode += booleanCode[j].length();
				sizeOfString += 8;
				break;
			}
		}

	}
	cout << endl << "==============================Aspect coefficient===================================" << endl;
	cout << sizeOfBooleanCode << "  -  sizeOfBooleanCode" << endl;
	cout << sizeOfString << "  -  sizeOfString" << endl;
	double k = sizeOfBooleanCode / sizeOfString;
	cout << "coefficient  -   " << k<< endl;


}

void RecursiveFunction(int* frequencyWeight, string* booleanCode, int startingNum, int endingNum) {

	if (startingNum < endingNum) {

		int leftElem = startingNum, rightElem = endingNum;
		int leftNum = 0, rightNum = 0;
		while (leftElem <= rightElem){
			if (leftNum <= rightNum) { leftNum += frequencyWeight[leftElem++]; }
			else { rightNum += frequencyWeight[rightElem--]; }
		}
		for (int i = leftElem; i <= endingNum; i++){booleanCode[i] += "1";}
        for (int i = startingNum; i < leftElem; i++){ booleanCode[i] += "0"; }
			
		RecursiveFunction(frequencyWeight, booleanCode, leftElem, endingNum);
		RecursiveFunction(frequencyWeight, booleanCode, startingNum, leftElem - 1);
	}
}

void ShannonFanoALg(string str, char* symbols, int* frequencyWeight, string* booleanCode, string* strInbooleanCode, char* decodInputString) {
	Map<char, int> map;

	for (int i = 0; i < str.length(); i++) {
		Map<char, int>::Node* node = map.findNode(str[i]);
		if (node == NULL)
			map.insert(str[i], 1);
		else {
			int value = node->value + 1;
			map.removeNode(str[i]);
			map.insert(str[i], value);
		}

	}
	List <char> symbolsList = map.getKeys();
	List <int> frequencyList = map.getValues();

	int size = symbolsList.get_size();

	for (int i = 0; i < size; i++) {
		symbols[i] = symbolsList.at(i);
		frequencyWeight[i] = frequencyList.at(i);
	}
	quickSortForQueue(frequencyWeight, symbols, size);
	RecursiveFunction(frequencyWeight, booleanCode, 0, size - 1);
	FindCoefficient(str, symbols, size, booleanCode, strInbooleanCode);
	

	cout <<endl <<"==============================Results AlgShennonaFano===================================" << endl;
	for (int i = 0; i < size; i++) {
		cout << "symbols  -  " << symbols[i]<<"    frequencyWeight  -  "<<frequencyWeight[i]<< "    booleanCode  -  "<< booleanCode[i] << endl;
	}

	for (int i = 0; i < str.length(); i++)
		for (int j = 0; j < size; j++)
			if (strInbooleanCode[i] == booleanCode[j]) {
				decodInputString[i] = symbols[j];
				break;
			}

}
void clearArr(char* symbols ,int* symbolsNum ,string* code ,string* strInbooleanCode,char* decodInputString) {
	delete[] symbolsNum;
	delete[] symbols;
	delete[] code;
	delete[] strInbooleanCode;
	delete[] decodInputString;
}


#endif // !ShannonFanoALg