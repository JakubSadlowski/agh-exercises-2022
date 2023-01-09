#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>
#include <fstream>
#include <string>
using namespace std;

/*
a) stwórz tablicê 2D reprezentuj¹c¹ graf. Wyœwietl tablicê.
b) napisz funkcjê, która przypisze pseudolosowe wagi krawêdziom grafu. U¿yj tej funkcji, aby
przypisaæ krawêdziom utworzonego grafu wagi bêd¹ce liczbami ca³kowitymi z zakresu [5; 25].
Wyœwietl tablicê.
c) napisz funkcjê, która wyœwietli numery wierzcho³ków po³¹czonych krawêdzi¹ o najwiêkszej
wadze. U¿yj funkcji.
d) napisz funkcjê, która zapisze tablicê 2D do pliku tekstowego. U¿yj tej funkcji, aby zapisaæ
utworzony graf do pliku.
e) stwórz now¹ tablicê 2D o takich samych wymiarach, jak tablica z punktu a. Napisz funkcjê,
która wype³ni nowoutworzon¹ tablicê 2D danymi zapisanymi w pliku tekstowym. U¿yj tej
funkcji. Wyœwietl tablicê
*/
class Exercise001 {
	int size = 8;	
	int graph[8][8] = {
		{0, 0, 1, 0, 1,	0, 0, 0},
		{0, 0, 1, 1, 0,	1, 0, 0},
		{1,	1, 0, 0, 0,	1, 0, 0},
		{0,	1, 0, 0, 1,	1, 1, 0},
		{1, 0, 0, 1, 0,	0, 0, 1},
		{0,	1, 1, 1, 0,	0, 0, 0},
		{0,	1, 1, 1, 0,	0, 0, 0},
		{0,	0, 0, 0, 1,	0, 1, 0}
	};

	void printGraph() {
		cout << "Graf poczatkowy:\n";
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << graph[i][j] << "\t";
				if (j == 7)
					cout << endl;
			}
		}
	}

	void changeEdges(){
		random_device rd;
		mt19937 e{ rd() };
		uniform_int_distribution<int> dist{ 5, 25 };

		cout << "\nGraf po zmianie:\n";
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {				
				if (graph[i][j] == 1) {
					graph[i][j] = dist(e);
					cout << graph[i][j] << "\t";
				}
				else cout << graph[i][j] << "\t";
				if (j == 7)
					cout << endl;
			}
		}	
	}

	void findTheBiggestEdge() {
		int maxEdge = 0;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (graph[i][j] > maxEdge) {
					maxEdge = graph[i][j];					
				}							
			}
		}
		cout << "\nWierzcholki o najwiekszej wadze: ";
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (graph[i][j] == maxEdge) {
					cout << "(" << i << ", " << j << ")" << ", ";
				}
			}
		}		
	}

	void printGraphToFile() {
		ofstream myfile;
		myfile.open("Graph.txt");
		if (myfile.is_open())
		{		
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					myfile << graph[i][j] << "\t";
					if (j == 7)
						myfile << endl;
				}				
			}
			myfile.close();
		}
		else cout << "Unable to open file.";
	}

	void createGraphCopyFromFile() {
		ifstream myfile;
		int graphCopy[8][8];		
		cout << "\n\nSkopiowany graf: " << endl;
		myfile.open("Graph.txt");
		if (myfile.is_open()) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					myfile >> graphCopy[i][j];
					cout << graphCopy[i][j] << "\t";
					if (j == 7)
						cout << endl;
				}
			}
			myfile.close();
		}
		else cout << "Unable to open file.";
	}

public:
	void execute() {
		printGraph();
		changeEdges();
		findTheBiggestEdge();
		printGraphToFile();
		createGraphCopyFromFile();
	}
};

int main(){
	Exercise001 exercise001;

	exercise001.execute();
	return 0;
}