/*
Title: Sorting Runtimes
Name: Shoeb Rehman
Date: March 5, 2014
About: Definition of various functions used throughout the driver program
References: 
Quicksort algorithm found at: http://www.sourcetricks.com/2011/06/what-is-quick-sort-algorithm-how-to.html
Mergesort Algorithm found at: http://www.sanfoundry.com/cpp-program-implement-merge-sort/
*/

#include <iostream>
#include <time.h>

using namespace std;

//Asks the user for the size of the array and returns the size
int selectSize(){
	int choice;
	char ans = 'n';
	do{
		cout << "Please enter the size of the array. Choose from the following: \n"
			<< "100 \n1000 \n5000 \n10000 \n50000 \n75000 \n100000 \n200000 \n400000 \n750000 \n" << endl;
		cin >> choice;

		cout << "You have chosen " << choice << ", is this correct? y/n" << endl;
		cin >> ans;
	} while (ans != 'y'); // asks user if this was the intended choice
	return choice;
}

//Fills array with seeded random, positive integers
void fillArray(int *array, int size){
	for (int i = 0; i < size; i++){
		array[i] = rand();
	}
}

//Outputs the array for testing purposes
void outputArray(int *array, int size){
	for (int i = 0; i < size; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

//Copies the original array into a dynamically allocated one
void copyArray(int *array, int *copiedArray, int size){
	for (int i = 0; i < size; i++){
		copiedArray[i] = array[i];
	}
}

// Merges sorted arrays, bottum up method
void merge(int* copiedArray, int low, int mid, int high, int* tmp){
	int i = low;
    int j = mid+1;
    int k = low;
    while ((i <= mid) && (j <= high)){ // arranges the array while there's still numbers left
		if (copiedArray[i] < copiedArray[j]){ // rearranges according to size of numbers
			tmp[k++] = copiedArray[i++];
		}
		else{
			tmp[k++] = copiedArray[j++];
		}
    }
        
	while (i <= mid){
		tmp[k++] = copiedArray[i++];
    }
    while (j <= high){
		tmp[k++] = copiedArray[j++];
    }
	for (i = low; i < k; i++){ //copies the dynamically allocated temporary array into the original
		copiedArray[i] = tmp[i];
	}
}

// Recursive Merge sort, found online.
void mergeArray(int* copiedArray, int low, int high, int size){
	
	int mid;
	if (low < high){
		mid = (low + high) / 2;
		mergeArray(copiedArray, low, mid, size);
		mergeArray(copiedArray, mid + 1, high, size);
		int* tmp = new int[size];
		merge(copiedArray, low, mid, high, tmp);
		delete[] tmp;
	}
}

// Partitions the array based on the randomized pivot (Online)
int partition(int* copiedArray, int p, int r)
{
	int pivot = copiedArray[r];

	while (p < r)
	{
		while (copiedArray[p] < pivot)
			p++;

		while (copiedArray[r] > pivot)
			r--;

		if (copiedArray[p] == copiedArray[r])
			p++;
		else if (p < r)
		{
			int tmp = copiedArray[p];
			copiedArray[p] = copiedArray[r];
			copiedArray[r] = tmp;
		}
	}

	return r;
}

// The quicksort recursive function (Online)
void quicksort(int* copiedArray, int p, int r)
{
	if (p < r)
	{
		int j = partition(copiedArray, p, r);
		quicksort(copiedArray, p, j - 1);
		quicksort(copiedArray, j + 1, r);
	}
}

void insertionSort(int *copiedArray, int size){
	time_t now, end;
	cout << "Insertion Sort is about to start. Press any key to start the sort." << endl;
	cin.ignore();
	cin.get();

	time(&now); // time at the start of the sort

	for (int i = 1; i < size; i++){
		for (int j = i; j > 0; j--){
			if(copiedArray[j - 1] > copiedArray[j]){
				int temp = copiedArray[j];
				copiedArray[j] = copiedArray[j - 1];
				copiedArray[j - 1] = temp;
			}
		}
	}

	time(&end); // time at the end of the sort
	cout << "Insertion Sort took " << (end - now) << " seconds.\n" << endl; // calculates how long the sort took
}

void bubbleSort(int *copiedArray, int size){
	time_t now, end;
	cout << "Bubble Sort is about to start. Press any key to start the sort." << endl;
	cin.ignore();
	cin.get();

	time(&now); // time at the start of the sort

	bool swapped = false;
	int sorted = 0;
	do{
		swapped = false;
		sorted++;
		for (int i = 0; i < (size - sorted - 1); i++){
			if (copiedArray[i + 1] < copiedArray[i]){
				swapped = true;
				int temp;
				temp = copiedArray[i];
				copiedArray[i] = copiedArray[i + 1];
				copiedArray[i + 1] = temp;
			}
		}

	} while (swapped);

	time(&end); // time at the end of the function
	cout << "Bubble Sort took " << (end - now) << " seconds.\n" << endl; // calculates how long the sort took
}

void mergeSort(int *copiedArray, int size){
	time_t now, end;
	cout << "Merge Sort is about to start. Press any key to start the sort." << endl;
	cin.ignore();
	cin.get();
	time(&now); // time at the start of the sort
	
	mergeArray(copiedArray, 0, size-1, size);
	time(&end); // time at the end of the sort
	cout << "Merge Sort took " << (end - now) << " seconds.\n" << endl; // calculates how long the sort took
}

void quickSort(int *copiedArray, int size){
	time_t now, end;

	cout << "Quick Sort is about to start. Press any key to start the sort." << endl;
	cin.ignore();
	cin.get();
	time(&now); // time at the start of the sort

	quicksort(copiedArray, 0, size - 1);

	time(&end); // time at the end of the sort
	cout << "Quick Sort took " << (end - now) << " seconds.\n" << endl; // calculates how long the sort took
}
