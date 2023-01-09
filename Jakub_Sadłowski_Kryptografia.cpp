#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <random>
#include <sstream>

using namespace std;

/*
a) Napisz funkcjê, która przyjmie s³owo i zwróci anagram, którego litery bêd¹ ustawione w
odwrotnej kolejnoœci.
przyk³ad:
wejœcie: „smok” wyjœcie: „koms”
b) Napisz funkcjê, która przyjmie tablicê s³ów, a nastêpnie utworzy i zwróci drug¹ tablicê, której
elementami bêd¹ anagramy, których litery bêd¹ ustawione w odwrotnej kolejnoœci.
przyk³ad:
wejœcie: {„smok”, „kartka”, „kosz”} wyjœcie: {„koms”, „aktrak”, „zsok”}
*/
class Exercise001 {
	string input;	

	string reverseString(string input) {				
		for (int i = 0; i < input.length()/2; i++) {
			swap(input[i], input[input.length() - i - 1]);
		}		
		return input;
	}

	vector<string> addWordsToArray() {
		string userInput;
		vector <string> arrayOfStrings;
		
		cout << "\nZacznij podawac slowa do tablicy, nacisnij 0 aby przerwac:\n";
		while (true) {		
			cin >> userInput;
			if (cin.fail() || userInput == "0") {
				cout << endl;
				break;
			}				
			arrayOfStrings.push_back(userInput);
		}
		return arrayOfStrings;
	}

	void reverseStringsInArray(vector<string> array) {
		string temp;
		for (int i = 0; i < array.size(); i++) {
			temp = array[i];			
			array[i] = reverseString(temp);
			cout << array[i] << endl;
		}
	}
	
public:
	void execute() {
		reverseString(input);
		vector <string> arrayOfWords = addWordsToArray();
		reverseStringsInArray(arrayOfWords);
	}
};

/*
Napisz funkcjê, która generuje has³o. D³ugoœæ has³a jest losowana z zakresu [10÷20]. Has³o musi
zawieraæ przynajmniej dwie du¿e litery, jedn¹ cyfrê i jeden znak specjalny.
*/
class Exercise002 {

	int passLen = generatePasswordLength();

	int generateValue(int from, int to) {
		int value;
		random_device rd;
		mt19937 e{ rd() };
		uniform_int_distribution<int> dist{ from, to };

		value = dist(e);
		return value;
	}

	int generateValue(int from, int to, vector <int> *positions) {
		int value, counter = 0;
		do	{
			value = generateValue(from, to);
			counter++;
		} while (contains(positions, value) || counter > 100);	
		positions -> push_back(value);

		return value;
	}

	bool contains(vector <int> *positions, int value) {
		for (int i = 0; i < positions -> size(); i++) {
			if (value == positions -> operator[](i))
				return true;		
		}
		return false;
	}

	int generateSign() {
		return generateValue(33, 127);
	}

	int generatePasswordLength() {		
		return generateValue(10, 20);
	}
	
	int generateBigLetter() {
		return generateValue(65, 90);
	}

	int generateNumber() {
		return generateValue(48, 57);
	}

	int generateSymbol() {
		return generateValue(33, 47);
	}

	vector <char> generateStartingPassword(int passLen) {
		vector <char> startPass;		
		for (int i = 0; i < passLen; i++) {
			char element = generateSign();
			startPass.push_back(element);
		}
		return startPass;
	}

	vector <char> generatePassword(int passLength) {
		vector <char> password = generateStartingPassword(passLength);
		vector <int> drawnPositions;
 			
		password[generateValue(1, passLength - 1, &drawnPositions)] = generateBigLetter();		
		password[generateValue(1, passLength - 1, &drawnPositions)] = generateBigLetter();		
		password[generateValue(1, passLength - 1, &drawnPositions)] = generateSymbol();		
		password[generateValue(1, passLength - 1, &drawnPositions)] = generateNumber();

		return password;
	}
	
	string printPassword(vector <char> array) {
		stringstream ss;
		for (int i = 0; i < passLen; i++) {
			ss << array[i];
		}
		return ss.str();
	}

public:
	void execute() {
		vector <char> password = generatePassword(passLen);
		cout << "[" << printPassword(password) << "]";
	}
};

/*
Napisz funkcjê do szyfrowania i odszyfrowania wiadomoœci za pomoc¹ szyfru Cezara. Uwzglêdnij
jedynie wielkie litery alfabetu i znak spacji (przyjmij, ¿e znak spacji nie jest szyfrowany).
a) zaszyfruj dowoln¹ wiadomoœæ
b) odszyfruj nastêpuj¹c¹ wiadomoœæ „FGHQVHWR VASBEZNGLXR GRPUAVPMAN” (przesuniêcie = 13)
*/
class Exercise003 {

	string encrypt(string text, int shift){
		if (shift > 26)shift = shift % 26;
		for (int i = 0; i < text.length(); i++){
			if (text[i] == ' ')continue;
			text[i] += shift;
			if (text[i] > 'Z') text[i] -= 26;
		}
		return text;
	}

	string decrypt(string text, int shift) {
		return encrypt(text, -shift);
	}

	void printMessage(vector <char> array, int size) {
		for (int i = 0; i < size; i++) {
			cout << array[i];
		}
	}

public:
	void execute() {
		string text1 = "ALA MA KOTA";
		string text1Encrypted = encrypt(text1, 2);
		string text1Decrypted = decrypt(text1Encrypted, 2);
		cout << "Start: " << text1 << endl << "Enkrypcja: " << text1Encrypted << endl << "Dekrypcja: " << text1Decrypted;				
	}
};

class Exercise004 {

	vector <int> toIntArray(int value) {		
		string valueStr = to_string(value);
		vector <int> array;
		for (int i = 0; i < valueStr.size(); i++) {
			char chr = valueStr[i];
			int valueInt = chr - 48;
			array.push_back(valueInt);
		}
		return array;
	}

	vector <int> encrypt(string text, int inputKey) {
		vector <int> key = toIntArray(inputKey);		
		int keyIdxCnt = 0;
		
		vector <int> output;
		for (int i = 0; i < text.length(); i++) {
			int chr = text[i];
			int code = chr - 64;						

			if (keyIdxCnt > key.size() - 1) keyIdxCnt = 0;
			int shift = key[keyIdxCnt++];
			int finalCode = code + shift;	
			output.push_back(finalCode);
		}
		return output;
	}

	string decrypt(vector <int> encryptedMessage, int inputKey) {
		vector <int> key = toIntArray(inputKey);
		int keyIdxCnt = 0;
		stringstream ss;

		for (int i = 0; i < encryptedMessage.size(); i++) {
			int encryptedCode = encryptedMessage[i];

			if (keyIdxCnt > key.size() - 1) keyIdxCnt = 0;
			int shift = key[keyIdxCnt++];
			int code = encryptedCode - shift;
			char finalCode = code + 64;
			ss << finalCode;
		}
		return ss.str();
	}

	string decrypt2(int* encryptedMessage, int messageLength,int inputKey) {
		vector <int> key = toIntArray(inputKey);		
		int keyIdxCnt = 0;
		stringstream ss;

		for (int i = 0; i < messageLength; i++) {
			int encryptedCode = encryptedMessage[i];

			if (keyIdxCnt > key.size() - 1) keyIdxCnt = 0;
			int shift = key[keyIdxCnt++];
			int code = encryptedCode - shift;
			char finalCode = code + 64;
			ss << finalCode;
		}
		return ss.str();
	}

	string printArray(vector <int> array) {
		stringstream ss;
		for (int i = 0; i < array.size(); i++) {
			ss << array[i];
		}
		return ss.str();
	}

public:
	void execute() {
		vector <int> encryptedMessage = encrypt("JAKASWIADOMOSC", 402);
		cout << decrypt(encryptedMessage, 402);

		cout << "\n\n";
		int encryptedMessage2[] = {19, 26, 18, 23, 13, 13, 24, 26, 26, 30, 33, 22, 21, 33, 9, 27, 18, 8, 20, 13, 26, 21,29, 30, 13, 9, 32, 4, 21, 13, 13, 26, 8, 14, 19, 34, 7, 7, 8, 18, 17, 7, 17, 8, 17, 9, 15, 15, 8, 6, 13, 32, 26,
32, 15, 23, 24, 29, 32, 23, 28, 7, 17, 16, 5, 31, 11, 14, 27, 19, 26, 21, 26, 11, 19, 27, 26, 4, 21, 13, 13,
22, 15, 28, 23, 24, 21, 15, 26, 24, 23, 22, 17, 16, 5, 12, 21, 18, 10, 9, 22, 31 };
		cout << decrypt2(encryptedMessage2, size(encryptedMessage2), 86374);
	}
};

int main(){
	Exercise001 exercise001;
	Exercise002 exercise002;
	Exercise003 exercise003;
	Exercise004 exercise004;

	cout << "Prosze podac numer zadania 1, 2, 3, 4: ";
	int exerciseNo = 0;
	cin >> exerciseNo;
	switch (exerciseNo)
	{
	case 1:
		exercise001.execute();
		break;
	case 2:
		exercise002.execute();
		break;
	case 3:
		exercise003.execute();
		break;
	case 4:
		exercise004.execute();
		break;
	default:
		cout << "Niepoprawny numer zadania";
	}
	return 0;
}
