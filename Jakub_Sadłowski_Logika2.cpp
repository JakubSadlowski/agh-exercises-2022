#include <iostream>;

using namespace std;

/*
Napisz funkcjê, która sprawdzi czy trójk¹t o bokach danej d³ugoœci jest trójk¹tem pitagorejskim.
Funkcja ma przyj¹æ trzy argumenty bêd¹ce liczbami ca³kowitymi dodatnimi, które reprezentuj¹
d³ugoœci boków trójk¹ta. Funkcja ma zwróciæ 1, jeœli trójk¹t jest pitagorejski albo 0, jeœli nie jest.
*/
class Exercise003
{
	int x, y, z;

	bool validateInput()
	{
		cout << "Podaj dlugosc dla pierwszej przyprostokatnej trojkata: x = ";
		cin >> x;
		if (cin.fail() || x <= 0)
			return false;
		cout << "Podaj dlugosc dla drugiej przyprostokatnej trojkata: y = ";
		cin >> y;
		if (cin.fail() || y <= 0)
			return false;
		cout << "Podaj dlugosc dla przeciwprostokatnej trojkata: z = ";
		cin >> z;
		if (cin.fail() || z <= 0)
			return false;
		return true;
	}
	void checkIfPythagorasTriangle()
	{
		int rectangularSum = (x*x) + (y*y);
		if (rectangularSum == z * z)
		{
			cout << "1";
		}
		else cout << "0";
	}
public:
	void execute()
	{
		validateInput();
		checkIfPythagorasTriangle();
	}
};

/*
Dana jest tablica liczb ca³kowitych tab[]. Stwórz funkcjê, która zwróci tablicê dwuelementow¹, w której
pierwszym elementem bêdzie iloœæ dodatnich liczb z tablicy tab[], a drugim elementem bêdzie suma
liczb ujemnych z tablicy tab[]. Wyœwietl zwrócon¹ tablicê.
*/
class Exercise004 
{
	int size = 0;
	int* tab = new int[size];

	void createArrayFromInput()
	{		
		int position = 0;
		
		cout << "Zacznij podawac liczby, nacisnij (q) aby przerwac.\n";
		while (true)
		{
			int input;
			cin >> input;
			if (cin.fail())
				break;
			size++;
			tab[position] = input;
			position++;
		}		
	}

	int* countPositiveAndNegative()
	{
		int positiveAndNegativeSum[2] = {0, 0};
		for (int i = 0; i < size; i++)
		{
			if (tab[i] > 0) 
			{
				positiveAndNegativeSum[0]+= tab[i];
			}				
			else positiveAndNegativeSum[1]+= tab[i];
		}
		cout << "\nSuma liczb dodatnich: " << positiveAndNegativeSum[0] << "\nSuma liczb ujemnych: " << positiveAndNegativeSum[1];
		return positiveAndNegativeSum;
	}

public:
	void execute()
	{
		createArrayFromInput();
		countPositiveAndNegative();
	}
};

/*
Napisz funkcjê, która przyjmie dowoln¹ liczbê naturaln¹. Funkcja ma zwróciæ najwiêksz¹ mo¿liw¹ liczbê
utworzon¹ z cyfr przyjêtej liczby naturalnej. Wyœwietl zwrócon¹ liczbê.
*/
class Exercise005
{
	
};

void main()
{
	try
	{
		Exercise003 exercise003;
		Exercise004 exercise004;

		cout << "Prosze podac numer zadania 3, 4: ";
		int exerciseNo = 0;
		cin >> exerciseNo;
		switch (exerciseNo)
		{
		case 3:
			exercise003.execute();
			break;
		case 4:
			exercise004.execute();
			break;
		default:
			cout << "Niepoprawny numer zadania";
		}
	}
	catch (std::logic_error& e)
	{
		std::cout << e.what() << endl;
	}
}