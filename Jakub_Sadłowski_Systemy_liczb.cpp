#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <random>
#include <sstream>
#include <bitset>
using namespace std;

/*
a) przyjmie liczbę z systemu dziesiętnego i zwróci jej odpowiednik w systemie binarnym (typ:
string). Przy użyciu funkcji przekonwertuj liczby: 20; 254
przykład:
wejście: 44 wyjście: 101100
b) przyjmie liczbę z systemu dziesiętnego i zwróci jej odpowiednik w systemie szesnastkowym
(typ: string). Przy użyciu funkcji przekonwertuj liczby: 953; 10863
przykład:
wejście: 44 wyjście: 2C
c) przyjmie liczbę z systemu binarnego (typ: string) i zwróci jej odpowiednik w systemie
dziesiętnym. Przy użyciu funkcji przekonwertuj liczby: 1101; 1011100
przykład:
wejście: 101 wyjście: 5
d) przyjmie liczbę z systemu szesnastkowego (typ: string) i zwróci jej odpowiednik w systemie
dziesiętnym. Przy użyciu funkcji przekonwertuj liczby: A93; 80F73ED
przykład:
wejście: B5 wyjście: 181
e) przyjmie liczbę z systemu ósemkowego (typ: string) i zwróci jej odpowiednik w systemie
szesnastkowym (typ: string). Przy użyciu funkcji przekonwertuj liczby: 701; 63272
przykład:
wejście: 16 wyjście: E
*/
class Exercise002 {
	
	string decimalToBinary(int number) {
		string value = bitset<8>(number).to_string();
		return value;
	}

	string decimalToHex(int number) {
		stringstream value;
		value << hex << number;
		return value.str();
	}

	int binaryToDecimal(string binaryString) {
		int value = 0;
		int indexCounter = 0;
		for (int i = binaryString.length() - 1; i >= 0; i--) {

			if (binaryString[i] == '1') {
				value += pow(2, indexCounter);
			}
			indexCounter++;
		}
		return value;
	}

	int hexToDecimal(string hexNumber) {
		const char* num = hexNumber.c_str();
		int len = strlen(num);
		int base = 1;
		int temp = 0;
		for (int i = len - 1; i >= 0; i--) {
			if (num[i] >= '0' && num[i] <= '9') {
				temp += (num[i] - 48) * base;
				base = base * 16;
			}
			else if (num[i] >= 'A' && num[i] <= 'F') {
				temp += (num[i] - 55) * base;
				base = base * 16;
			}
		}
		return temp;
	}

	string octalToHex(string octalString) {
		int octalNumber = stoi(octalString);
		int decimalNumber = 0, i = 0, rem;
		while (octalNumber != 0)
		{
			rem = octalNumber % 10;
			octalNumber /= 10;
			decimalNumber += rem * pow(8, i);
			++i;
		}
		string hexNumber = decimalToHex(decimalNumber);
		return hexNumber;
	}

public:
	void execute() {
		cout << "Konwersja z systemu dziesietnego na binarny liczb:\n20 -> " << decimalToBinary(20) << endl << "254 -> " << decimalToBinary(254) << endl;
		cout << "Z dziesietnego na szesnastkowy:\n953 -> " << decimalToHex(953) << endl << "10863 -> " << decimalToHex(10863) << endl;
		cout << "Z binarnego na dziesietny:\n1101 -> " << binaryToDecimal("1101") << endl << "1011100 -> " << binaryToDecimal("1011100") << endl;
		cout << "Z szesnastkowego na dziesietny:\nA93 -> " << hexToDecimal("A93") << endl << "80F73ED -> " << hexToDecimal("80F73ED") << endl;
		cout << "Z osemkowego na szesnastkowy:\n701 -> " << octalToHex("701") << endl << "63272 -> " << octalToHex("63272") << endl;
	}
};

class Exercise003 {

	string decimalToBinary(int number) {
		string value = bitset<32>(number).to_string();
		return value;
	}

	int binaryToDecimal(string binaryString) {
		int value = 0;
		int indexCounter = 0;
		for (int i = binaryString.length() - 1; i >= 0; i--) {

			if (binaryString[i] == '1') {
				value += pow(2, indexCounter);
			}
			indexCounter++;
		}
		return value;
	}

	int findClosestHighestNumber(int number) {
		string binaryNumber = decimalToBinary(number);
		for (int i = binaryNumber.length() - 1; i >= 0; i--) {
			if (binaryNumber[i] == '1') {
				for (int j = i - 1; j >= 0; j--) {
					if (binaryNumber[j] == '0') {
						char temporary;
						temporary = binaryNumber[j];
						binaryNumber[j] = binaryNumber[i];
						binaryNumber[i] = temporary;
						break;
					}
				}
				break;
			}
		}
		int result = binaryToDecimal(binaryNumber);
		return result;
	}

public:
	void execute() {
		cout << "Najwieksza najblizsza liczba od 44 to: " << findClosestHighestNumber(44) << endl;
		cout << "Najwieksza najblizsza liczba od 8902 to: " << findClosestHighestNumber(8902) << endl;
	}
};

int main(){
	Exercise002 exercise002;
	Exercise003 exercise003;
	
	cout << "Podaj numer zadania 2, 3: ";
	int exerciseNo;
	cin >> exerciseNo;
	switch (exerciseNo) {
		case 2:
			exercise002.execute();
			break;
		case 3:
			exercise003.execute();
			break;
		default:
			cout << "Niepoprawny numer zadania";
	}
	return 0;
}