#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <string>
#include <sstream>
#include<tuple>

using namespace std;

/*
Dane s¹ nastêpuj¹ce pliki tekstowe:
• „Graph.csv” – zawiera macierz grafu wraz z wagami krawêdzi.
• „Coordinates.csv” – zawiera wspó³rzêdne wszystkich wierzcho³ków grafu.
Uwaga: wszystkie polecenia wykonaj przy u¿yciu osobnych funkcji
a) Wczytaj dane z plików tekstowych i zapisz je w tablicach. Wyœwietl tablice.
b) Wypisz wszystkie wierzcho³ki i wierzcho³ki bezpoœrednio z nimi po³¹czone. Przyk³adowy zapis
znajduje siê poni¿ej:
v0: v1, v3, v5
v1: v0, v6
v2: v3, v4
...
c) ZnajdŸ po³¹czone ze sob¹ wierzcho³ki, które znajduj¹ siê najbli¿ej siebie. Wyœwietl te
wierzcho³ki oraz odleg³oœæ miêdzy nimi.
d) Za³ó¿my, ¿e wagi krawêdzi grafu reprezentuj¹ prêdkoœæ, jaka jest wykorzystywana przy
przemieszczaniu siê pomiêdzy po³¹czonymi wierzcho³kami. Im wiêksza waga, tym wiêksza
prêdkoœæ. Pomiêdzy którymi wierzcho³kami odleg³oœæ mo¿na pokonaæ najszybciej? Wypisz te
wierzcho³ki.
przyk³ad:
Odleg³oœæ miêdzy wierzcho³kami v1 i v2 wynosi 10, a waga krawêdzi ³¹cz¹cej je wynosi 1.
Odleg³oœæ miêdzy wierzcho³kami v3 i v4 wynosi 5, a waga krawêdzi ³¹cz¹cej je wynosi 0.5.
Oznacza to, ¿e odleg³oœci zostan¹ pokonane w tym samym czasie.
e) Wyœwietl losow¹ œcie¿kê przejœcia po grafie z wybranego wierzcho³ka. Niech œcie¿ka sk³ada siê
z 8 wierzcho³ków.
przyk³ad:
v0->v1->v4->v3->v1->v0->v5->v6
*/
class Exercise {

	class Table {		
		float** graph;
		int graph_rows, graph_columns;
	public:
		Table() {}

		Table(float** inGraph, int rows, int columns) {
			graph = inGraph;
			graph_rows = rows;
			graph_columns = columns;
		}
		string tableToString()
		{
			stringstream ss;
			for (int i = 0; i < graph_rows; i++)
			{
				for (int j = 0; j < graph_columns; j++)
				{
					ss << graph[i][j] << ";";
				}
				ss << endl;
			}
			return ss.str();
		}

		string connectedVertices() {
			stringstream ss;
			for (int i = 0; i < graph_rows; i++)
			{
				ss << "v" << i << ": ";
				for (int j = 0; j < graph_columns; j++)
				{
					if (graph[i][j] != 0) {
						ss << "v" << j << ", ";
					}
					
				}
				ss << endl;
			}
			return ss.str();
		}

		float distanceBetweenVertices(int v1, int v2) {
			float x1 = graph[v1][0];
			float y1 = graph[v1][1];
			float x2 = graph[v2][0];
			float y2 = graph[v2][1];
			return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
		}

		void shortestDistanceBetweenVertices(Table coordinates) {						
			float shortestDistance = 0;
			int v1 = 0, v2 = 0;

			for (int i = 0; i < graph_rows; i++)
			{
				for (int j = 0; j < graph_columns; j++)
				{
					if (graph[i][j] != 0) {
						float distance = coordinates.distanceBetweenVertices(i, j);
						float sDistance = shortestDistance;
						if ( sDistance == 0 || sDistance > distance) {
							 shortestDistance = distance;
							 v1 = i;
							 v2 = j;
						}
					}					
				}
			}	
			cout << "Shortest distance: " << shortestDistance << " between vertices: v" << v1 << ", v" << v2;
		}

		void fastestPath(Table coordinates) {
			float shortestTime = 0;
			int v1 = 0, v2 = 0;

			for (int i = 0; i < graph_rows; i++)
			{
				for (int j = 0; j < graph_columns; j++)
				{
					if (graph[i][j] != 0) {
						float time = coordinates.distanceBetweenVertices(i, j) / graph[i][j];
						float sTime = shortestTime;
						if (sTime == 0 || sTime > time) {
							shortestTime = time;
							v1 = i;
							v2 = j;
						}
					}
				}
			}
			cout << "Fastest path: " << shortestTime << " between vertices: v" << v1 << ", v" << v2;
		}

		int getNoOfVertices() {
			return graph_rows;
		}

		int getNextVertices(int vertice, int excludeVertice) {
			for (int j = 0; j < graph_columns; j++)
			{
				if (graph[vertice][j] != 0 && j != excludeVertice) {
					return j;
				}
			}
			return vertice;
		}

		void showTopVertices(int startVertice) {
			int counter = 0;
			int currentVertice = startVertice;
			int excludeVertice = startVertice;
			while (counter < 8) {
				int nextVertice = getNextVertices(currentVertice, excludeVertice);
				cout << "v" << nextVertice << ", ";
				excludeVertice = currentVertice;
				currentVertice = nextVertice;
				counter++;
			}
		}
	};
	
	class TableLoader {
		int graph_rows, graph_columns;
		float** graph;
		string line, number;
		ifstream myfile;

		void countRowsAndColumns(string filePath) {
			myfile.open(filePath, ios::binary);
			if (myfile.is_open()) {
				while (getline(myfile, line))
				{
					++graph_rows;
					istringstream iss(line);
					while (getline(iss, number, ';') && graph_rows == 1)
					{
						++graph_columns;
					}
				}
				myfile.close();
			}
		}

		void initializingGraph() {
			graph = new float* [graph_rows];
			for (int i = 0; i < graph_rows; i++)
			{
				graph[i] = new float[graph_columns];
				for (int j = 0; j < graph_columns; j++)
				{
					graph[i][j] = 0.0;
				}
			}
		}

		void readGraph(string filePath) {
			myfile.open(filePath, ios::binary);
			if (myfile.is_open()) {
				for (int i = 0; getline(myfile, line); i++)
				{

					istringstream iss(line);
					for (int j = 0; getline(iss, number, ';'); j++)
					{
						float f;
						istringstream(number) >> f;
						graph[i][j] = stof(number);
					}
				}
				myfile.close();
			}
		}

	public:
		Table readFromFile(string filePath) {
			countRowsAndColumns(filePath);
			initializingGraph();
			readGraph(filePath);
			return Table(graph, graph_rows, graph_columns);
		}
	};


public:
	Exercise() {}
	Table graph;
	Table coordinates;
	

public:
	void execute() {
		readFiles();
		findConnectedVertices();
		shortestDistanceBetweenVertices();
		fastestPath();
		randomPath();
		
	}

	void readFiles() {
		cout << "a) Wczytaj dane z plikow tekstowych i zapisz je w tablicach. Wyswietl tablice.:\n";
		TableLoader graphLoader;
		graph = graphLoader.readFromFile("Graph.csv");
		cout << graph.tableToString() << endl;
		TableLoader coordinatesLoader;
		coordinates = coordinatesLoader.readFromFile("Coordinates.csv");
		cout << coordinates.tableToString();
		cout << endl;
	}

	void findConnectedVertices() {
		cout << "\nb) Wypisz wszystkie wierzcholki i wierzcholki bezposrednio z nimi polaczone.\n";
		cout << graph.connectedVertices();
		cout << endl;
	}

	void shortestDistanceBetweenVertices() {
		cout << "\nc) Znajdz polaczone ze soba wierzcholki, ktore znajduja sie najblizej siebie. Wyswietl te wierzcholki oraz odleglosc miedzy nimi.\n";
		graph.shortestDistanceBetweenVertices(coordinates);
		cout << endl;
	}

	void fastestPath() {
		cout << "\nd) Zalozmy, ze wagi krawedzi grafu reprezentuja predkosc, jaka jest wykorzystywana przy przemieszczaniu sie pomiedzy po³aczonymi wierzcholkami. Im wieksza waga, tym wieksza predkosc.Pomiedzy ktorymi wierzcholkami odleglosc mo¿na pokonac najszybciej ? Wypisz te wierzcholki.\n";
		graph.fastestPath(coordinates);
		cout << endl;
	}

	void randomPath() {
		cout << "\ne) Wyswietl losowa sciezke przejscia po grafie z wybranego wierzcholka. Niech sciezka sklada sie z 8 wierzcholkow.\n";
		random_device rd;
		mt19937 e{ rd() };
		uniform_int_distribution<int> dist{ 0, graph.getNoOfVertices()};
		int startVertice = dist(e);
		graph.showTopVertices(startVertice);
	}
};

void main() {
	Exercise exercise;

	exercise.execute();
}