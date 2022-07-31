// C++ implementation to print
// the string in Lexicographical order
#include <iostream>
#include <string>
using namespace std;
 
// Used for index in heap
int x = -1;
 
// Predefining the heap array
string heap[1000];
 
// Defining formation of the heap
void heapForm(string k)
{
    x++;
 
    heap[x] = k;
 
    int child = x;
 
    string tmp;
 
    int index = x / 2;
 
    // Iterative heapiFy
    while (index >= 0) {
 
        // Just swapping if the element
        // is smaller than already
        // stored element
        if (heap[index] > heap[child]) {
 
            // Swapping the current index
            // with its child
            tmp = heap[index];
            heap[index] = heap[child];
            heap[child] = tmp;
            child = index;
 
            // Moving upward in the
            // heap
            index = index / 2;
        }
        else {
            break;
        }
    }
}
 
// Defining heap sort
void heapSort()
{
    int left1, right1;
 
    while (x >= 0) {
        string k;
        k = heap[0];
 
        // Taking output of
        // the minimum element
        cout << k << " ";
 
        // Set first element
        // as a last one
        heap[0] = heap[x];
 
        // Decrement of the
        // size of the string
        x = x - 1;
 
        string tmp;
 
        int index = 0;
 
        int length = x;
 
        // Initializing the left
        // and right index
        left1 = 1;
 
        right1 = left1 + 1;
 
        while (left1 <= length) {
 
            // Process of heap sort
            // If root element is
            // minimum than its both
            // of the child then break
            if (heap[index] <= heap[left1]
                && heap[index] <= heap[right1]) {
                break;
            }
 
            // Otherwise checking that
            // the child which one is
            // smaller, swap them with
            // parent element
            else {
 
                // Swapping
                if (heap[left1] < heap[right1]) {
                    tmp = heap[index];
                    heap[index] = heap[left1];
                    heap[left1] = tmp;
                    index = left1;
                }
 
                else {
                    tmp = heap[index];
                    heap[index] = heap[right1];
                    heap[right1] = tmp;
                    index = right1;
                }
            }
 
            // Changing the left index
            // and right index
            left1 = 2 * left1;
            right1 = left1 + 1;
        }
    }
}
 
// Utility function
void sort(string k[], int n)
{
 
    // To heapiFy
    for (int i = 0; i < n; i++) {
        heapForm(k[i]);
    }
 
    // Calling heap sort function
    heapSort();
}


 
// Driver Code
int main()
{
    string arr[] = { "epsilon", "omega", "theta", 
"rho", "alpha", "beta", "phi", "gamma", 
"delta" };
 
    int n = sizeof(arr) / sizeof(arr[0]);
 
    sort(arr, n);
}
