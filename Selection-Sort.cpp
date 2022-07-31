#include <cstdlib>
#include <iostream>
#include <fstream>  

using namespace std;
void printArray(int array[], int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << array[i] << std::endl;
}

void selectionSort(int array[], int n)
{
    int temp;
    int min;
    int numComps = 0;
    int numSwap = 0;

    for (int i = 0; i < n; ++i)
    {
        min = i;
        for (int j = i + 1; j < n; ++j)
        {
        	numComps++;
            if (array[j] < array[min])
                min = j;
        }
        if (min != i)
        {
            temp = array[i];
            array[i] = array[min];
            array[min] = temp;
            numSwap++;
        }
    }
    cout << endl << "Number of Comparison:" << numComps << endl;
    cout << "Number of Swaps:" << numSwap << endl << endl;
}

int main()
{
    int array[] = {95, 45, 48, 98, 485, 65, 54, 478, 1, 2325};
    int n = 10;

    std::cout << "Before Selection Sort :" << std::endl;
    printArray(array, n);

    selectionSort(array, n);

    std::cout << "After Selection Sort :" << std::endl;
    printArray(array, n);
    return (0);
} 
