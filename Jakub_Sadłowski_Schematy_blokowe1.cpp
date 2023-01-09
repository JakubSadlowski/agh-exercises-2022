#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

/*
Stw�rz program, kt�ry wypisze x kolejnych pot�g liczby 3. narysuj schemat blokowy algorytmu.
*/
void exercise003() 
{
	cout << "Zadanie 3 Pot�gowanie liczby 3 \n";
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
Narysuj schemat blokowy funkcji, kt�ra wczytuje z klawiatury trzy r�ne liczby ca�kowite, kt�re s� 
zapisywane w zmiennych a, b i c, a nast�pnie wy�wietla je na ekranie w kolejno�ci rosn�cej. 
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
Bartek i Tomek przez n dni, ka�dego dnia otrzymuj� od taty kieszonkowe, przy czym:
a) ka�dego dnia pieni�dze otrzymuje tylko jeden ch�opiec
b) ch�opcy otrzymuj� pieni�dze na zmian�
c) pierwszego dnia pieni�dze w kwocie x otrzyma� Bartek
d) wysoko�� otrzymywanych pieni�dzy codziennie wzrasta o z %
Narysuj schemat blokowy algorytmu, kt�ry obliczy ilo�� pieni�dzy otrzymanych przez Bartka i Tomka.
Zaimplementuj rozwi�zanie
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

