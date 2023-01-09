#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

/*
a) Stwórz tablice dynamiczne liczb ca³kowitych o rozmiarach: 1 000, 10 000, 30 000, 60 000, 100 000. Przypisz
elementom losowe wartoœci z zakresu od 1 do 1000.
b) Stwórz funkcjê, która posortuje dan¹ tablicê przy u¿yciu wybranego algorytmu sortowania (uwzglêdnij: Bubble
Sort, Quick Sort, Heap Sort i Selection Sort) i zmierzy czas trwania sortowania. Zmierz czasy sortowania dla
wszystkich tablic i wszystkich algorytmów. Jeœli czas trwania sortowania jest dla danego algorytmu wzglêdnie
nied³ugi, to rozwa¿ stworzenie dodatkowych, wiêkszych tablic dynamicznych.
c) Przy wykorzystaniu pozyskanych czasów sortowania utwórz wykresy funkcji dla poszczególnych algorytmów
sortowania (mo¿esz to zrobiæ np. przy wykorzystaniu Excela).
*/
class Exercise001 {

	class SelectionSort {
		
	public:
		void sort(int* arr, int size) {			
			for (int i = 0; i < size - 1; i++) {
				int idxOfMinValue = i;
				for (int j = i + 1; j < size; j++) {
					if (arr[j] < arr[idxOfMinValue])
						idxOfMinValue = j;
				}
				if (idxOfMinValue != i) {
					int value = arr[i];
					arr[i] = arr[idxOfMinValue];
					arr[idxOfMinValue] = value;
				}		
			}			
		}
	};

	class HeapSort {		
		void heapify(int* arr, int n, int i) {
			int largest = i;
			int left = 2 * i + 1;
			int right = 2 * i + 2;

			if (left < n && arr[left] > arr[largest])
				largest = left;

			if (right < n && arr[right] > arr[largest])
				largest = right;
		
			if (largest != i) {
				swap(arr[i], arr[largest]);
				heapify(arr, n, largest);
			}
		}

	public:	
		void sort(int* arr, int size) {
			for (int i = size / 2 - 1; i >= 0; i--) {
				heapify(arr, size, i);
			}
				
			for (int i = size - 1; i >= 0; i--) {
				swap(arr[0], arr[i]);
				heapify(arr, i, 0);
			}
		}
	};
	
	class QuickSort {

		void swap(int* a, int* b) {
			int t = *a;
			*a = *b;
			*b = t;
		}

		int partition(int* arr, int low, int high) {
			int pivot = arr[high];
			int i = (low - 1);

			for (int j = low; j < high; j++) {
				if (arr[j] <= pivot) {
					i++;
					swap(&arr[i], &arr[j]);
				}
			}

			swap(&arr[i + 1], &arr[high]);

			return (i + 1);
		}


		void sort(int* arr, int low, int high) {			
			if (low < high) {
				int pi = partition(arr, low, high);
				sort(arr, low, pi - 1);
				sort(arr, pi + 1, high);
			}
		}
	public:
		void sort(int* arr, int size) {
			sort(arr, 0, size - 1);
		}
	};

	class BubbleSort {

	public:
		void sort(int* arr, int size) {
			int i, j, temp;
			for (i = 0; i < size; i++) {
				for (j = 0; j < (size - i - 1); j++) {
					if (arr[j] > arr[j + 1]) {
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}
			}
		}
	};

	int* createDynamicArray(int size) {
		random_device rd;
		mt19937 e(rd());
		uniform_real_distribution<double> dist(1, 1000);

		int* array = new int[size];
		for (int i = 0; i < size; i++) {
			array[i] = dist(rd);
		}
		return array;
	}

	void printArray(int* arr, int size) {						
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	int* copyArray(int* arr, int size) {
		int* arrCopy = new int[size];
		for (int i = 0; i < size; i++) {
			arrCopy[i] = arr[i];
		}
		return arrCopy;
	}

	void countTimeToSort(int size) {
		QuickSort quickSort;
		HeapSort heapSort;
		SelectionSort selectionSort;
		BubbleSort bubbleSort;

		int* array = createDynamicArray(size);

		cout << "Tablica o rozmiarze " << size << endl;
		auto start = high_resolution_clock::now();
		int* quickSortArray = copyArray(array, size);
		quickSort.sort(quickSortArray, size);
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "Czas wykonania dla quickSort: " << duration.count() << " mikrosekund" << endl;

		start = high_resolution_clock::now();
		int* heapSortArray = copyArray(array, size);
		heapSort.sort(heapSortArray, size);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "Czas wykonania dla heapSort: " << duration.count() << " mikrosekund" << endl;

		start = high_resolution_clock::now();
		int* selectionSortArray = copyArray(array, size);
		selectionSort.sort(selectionSortArray, size);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "Czas wykonania dla selectionSort: " << duration.count() << " mikrosekund" << endl;

		start = high_resolution_clock::now();
		int* bubbleSortArray = copyArray(array, size);
		bubbleSort.sort(bubbleSortArray, size);
		stop = high_resolution_clock::now();
		duration = duration_cast<microseconds>(stop - start);
		cout << "Czas wykonania dla bubbleSort: " << duration.count() << " mikrosekund" << endl << endl;
	}
	
public:
	void execute() {				
		countTimeToSort(1000);
		countTimeToSort(10000);
		countTimeToSort(30000);
		countTimeToSort(60000);
		countTimeToSort(100000);
	}
};

class Exercise002 {

};

int main(){
	Exercise001 exercise001;

	exercise001.execute();
	return 0;
}