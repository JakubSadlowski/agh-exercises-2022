#include <iostream>;

using namespace std;

/*
Napisz funkcj�, kt�ra sprawdzi czy tr�jk�t o bokach danej d�ugo�ci jest tr�jk�tem pitagorejskim.
Funkcja ma przyj�� trzy argumenty b�d�ce liczbami ca�kowitymi dodatnimi, kt�re reprezentuj�
d�ugo�ci bok�w tr�jk�ta. Funkcja ma zwr�ci� 1, je�li tr�jk�t jest pitagorejski albo 0, je�li nie jest.
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
Dana jest tablica liczb ca�kowitych tab[]. Stw�rz funkcj�, kt�ra zwr�ci tablic� dwuelementow�, w kt�rej
pierwszym elementem b�dzie ilo�� dodatnich liczb z tablicy tab[], a drugim elementem b�dzie suma
liczb ujemnych z tablicy tab[]. Wy�wietl zwr�con� tablic�.
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
Napisz funkcj�, kt�ra przyjmie dowoln� liczb� naturaln�. Funkcja ma zwr�ci� najwi�ksz� mo�liw� liczb�
utworzon� z cyfr przyj�tej liczby naturalnej. Wy�wietl zwr�con� liczb�.
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