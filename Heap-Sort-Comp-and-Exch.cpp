#include <iostream>
#include <string>
using namespace std;



void heapify(int arr[], int n, int i, int& countComparisons, int& countSwaps)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
    {
        countComparisons++;
        largest = l;
    }

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
    {
        countComparisons++;
        largest = r;
    }

    // If largest is not root
    if (largest != i)
    {
        countSwaps++;
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest, countComparisons, countSwaps);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n, int& countComparisons, int& countSwaps)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, countComparisons, countSwaps);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        countSwaps++;
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0, countComparisons, countSwaps);
    }
}

void printArray(int a[],int n){
	for(int i=0;i<n;i++)
      cout<<a[i]<<" ";
  	cout<<endl;
}

int main()
{
    int countComp = 0, countSwap = 0;
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n, countComp, countSwap);

    cout << "Sorted array is \n";
    printArray(arr, n);

    cout << "comparisons: " << countComp <<  " swaps: " << countSwap << endl;
}
