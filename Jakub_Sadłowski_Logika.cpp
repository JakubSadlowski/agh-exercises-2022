#include <iostream>;
using namespace std;

/*
Stwórz funkcję, która zwróci wynik implikacji w zależności od przesłanych argumentów.
Wykorzystaj operatory logiczne oraz stworzoną funkcję do oceny prawdziwości powyższych zdań
złożonych.

a) p ∧ q
b) p ∨ q
c) ¬p ∧ (p ∨ q)
d) (p ∧ r) → q
e) ¬(p ↔ (q ∨ r))
f) p → (r ∧ ¬q) → (¬p ∨ q)
g) [(𝑝 → 𝑟) ∨ ¬𝑞] ↔ [𝑝 → (𝑟 ∧ ¬𝑞)]
h) [(¬𝑟 ∨ 𝑞) ∨ ¬(𝑞 ∧ 𝑟)] → [¬(𝑞 → 𝑝)]

*/
class Exercise001 
{	
		bool p, q, r;		
		
	/*class Operators
	{
	public:
		bool implication(bool p, bool q)
		{			
			return !p || q;
		}
		
		bool alternative(bool p, bool q) 
		{
			return p || q;
		}
		
		bool conjunction(bool p, bool q)
		{
			return p && q;
		}
		
		bool negation(bool p)
		{
			return !p;
		}

		bool equivalence(bool p, bool q)
		{
			return p == q;
		}
	};*/
	void exerciseDescription()
	{
		cout << "Program wylicza wynik dla następujących zdań logicznych:\n";
		cout << "a) p & q\n";
		cout << "b) p v q\n";
		cout << "";
	}

	void readInput()
	{
		

		cout << "Podaj wartosc dla p wpisujac [1] albo [0] = ";
		cin >> p;
		if (cin.fail()) 
		{
			throw std::logic_error("\nNiepoprawna wartosc dla p.");
		}
		cout << "\nPodaj wartosc dla q wpisujac [1] albo [0] = ";
		cin >> q;
		if (cin.fail())
		{
			throw std::logic_error("\nNiepoprawna wartosc dla q.");
		}
	}

	void subsectionA(bool p, bool q)
	{
		cout << "p & q = " << p && q;
	}

public:
	void execute()
	{		
		readInput();				
		subsectionA(p, q);
		
	}
};

void main()
{
	try 
	{
		Exercise001 exercise001;

		exercise001.execute();
	}
	catch (std::logic_error& e)
	{
		std::cout << e.what() << endl;
	}	
}