#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(void) 
	{
		int array[] = { 1,2 ,5, 4, 3 }, i = 0;
		int num = sizeof(array)/sizeof(array[0]);
		insertionSort(array,num);
		for (i = 0; i < num; i++)
		{
			   cout << array[i] << " " << endl;
		}		
	}
