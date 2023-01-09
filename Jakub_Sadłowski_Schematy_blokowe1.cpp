#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

/*
Stwórz program, który wypisze x kolejnych potêg liczby 3. narysuj schemat blokowy algorytmu.
*/
void exercise003() 
{
	cout << "Zadanie 3 Potêgowanie liczby 3 \n";
	cout << "Prosze podac wartosc wykladnika potegi: ";
	double x = 0;
	cin >> x;
	if (cin.fail() || x < 1 || x > 500) 
	{
		cout << "Niepoprawna wartosc, zakres: <1 ; 1000000> ";
		return;
	}
	double powerValue = pow(3, x);
	cout << "Wynik: " << powerValue;
}


/* 
Narysuj schemat blokowy funkcji, która wczytuje z klawiatury trzy ró¿ne liczby ca³kowite, które s¹ 
zapisywane w zmiennych a, b i c, a nastêpnie wyœwietla je na ekranie w kolejnoœci rosn¹cej. 
Zaimplementuj algorytm. 
*/
void exercise004() 
{
	int a, b, c;
	cout << "Prosze podac 3 liczby calkowite: ";
	cin >> a;
	cin >> b;
	cin >> c;
	int numbers[3] = {a, b, c};

	cout << "Tablica przed sortowaniem: ";
	for (int number: numbers)
	{
		cout << number << " ";
	}

	std::sort(numbers, numbers + size(numbers));
	
	cout << "\n Tablica po sortowaniu: ";
	for (int number : numbers)
	{
		cout << number << " ";
	}
}


/*
Bartek i Tomek przez n dni, ka¿dego dnia otrzymuj¹ od taty kieszonkowe, przy czym:
a) ka¿dego dnia pieni¹dze otrzymuje tylko jeden ch³opiec
b) ch³opcy otrzymuj¹ pieni¹dze na zmianê
c) pierwszego dnia pieni¹dze w kwocie x otrzyma³ Bartek
d) wysokoœæ otrzymywanych pieniêdzy codziennie wzrasta o z %
Narysuj schemat blokowy algorytmu, który obliczy iloœæ pieniêdzy otrzymanych przez Bartka i Tomka.
Zaimplementuj rozwi¹zanie
*/
void exercise005()
{
	cout << "Prosze podac ilosc dni: ";
	int noOfDays;
	cin >> noOfDays;
	cout << "Podaj ile pieniedzy dostanie Bartek w pierwszy dzien: ";
	double dailyAmount;
	cin >> dailyAmount;
	cout << "Podaj % o jaki wzrosnie liczba otrzymywanych pieniedzy: ";
	int percentage;
	cin >> percentage;
	double amountB = 0, amountT = 0;
	for (int i = 0; i < noOfDays; i++)
	{
		if (i % 2 == 0)
		{
			amountB += dailyAmount;
		}
		else
		{
			amountT += dailyAmount;
		}
		dailyAmount = (dailyAmount * percentage / 100) + dailyAmount;
	}
	cout << "Pieniadze jakie otrzymal Bartek: " << amountB << endl;
	cout << "Pieniadze jakie otrzymal Tomek: " << amountT;

}
int main()
{
	cout << "Prosze podac numer zadania 3, 4, 5: ";
	int exerciseNo = 0;
	cin >> exerciseNo;
	switch(exerciseNo) 
	{
		case 3: 
			exercise003();
			break;
		case 4:
			exercise004();
			break;
		case 5:
			exercise005();
			break;
		default: 
			cout << "Niepoprawny numer zadania";
	}
	return 0;
}

