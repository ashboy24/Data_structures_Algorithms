// Write a C++ code for the implementation of linear search algorithm which is used to search or check if the element is present in the list or not

/*
#include <iostream>
using namespace std;

int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {1, 10, 30, 15};
    int x = 30;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << x << " is present at index " << search(arr, n, x);
    return 0;
}
*/

// Given an array of integers arr[] of size N and an integer, the task is to rotate the array elements to the left by d positions

//Method 1

/*
// Fuction to rotate array
void Rotate(int arr[], int d, int n)
{
    // Storing rotated version of array
    int temp[n];

    // Keepig track of the current index
    // of temp[]
    int k = 0;

    // Storing the n - d elements of
    // array arr[] to the front of temp[]
    for (int i = d; i < n; i++)
    {
        temp[k] = arr[i];
        k++;
    }

    // Storing the first d elements of array arr[]
    //  into temp
    for (int i = 0; i < d; i++)
    {
        temp[k] = arr[i];
        k++;
    }

    // Copying the elements of temp[] in arr[]
    // to get the final rotated array
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

// Function to print elements of array
void PrintTheArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int N = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    // Function calling
    Rotate(arr, d, N);
    PrintTheArray(arr, N);

    return 0;
}
*/

//Method 2

/*
#include <iostream>
using namespace std;

// function to left rotate arr[] of size n by d
void Rotate(int arr[], int d, int n)
{
    int p = 1;
    while (p <= d)
    {
        int last = arr[0];
        for (int i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[n - 1] = last;
        p++;
    }
}
// function to print an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int N = sizeof(arr) / sizeof(arr[0]);
    int d = 2;
    Rotate(arr, d, N);
    printArray(arr, N);

    return 0;
}
*/

// Concept of reversing an array using reversal algorithm
/*
#include <iostream>
using namespace std;

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void leftRotate(int arr[], int d, int n)
{
    if (d == 0)
    {
        return;
    }
    d = d % n;
    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
    reverseArray(arr, 0, n - 1);
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int N = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    leftRotate(arr, d, N);
    printArray(arr, N);
    return 0;
}
*/

//BLOCK SWAP ALGORITHM FOR ARRAY ROTATION
// Write a function rotate(arr[], d, n) that rotates arr[] of size n by d elements

/*
//Prototype for utility functions 
void printArray(int arr[], int size);
void swap(int arr[], int fi, int si, int d);

void leftRotate(int arr[], int d, int n)
{
    // Return If number of elements to be rotated is zero or equal to array size 
    if (d == 0 || d == n)
        return;
    //If number of elements to be rotated is more than array size
    if (d > n)
        d = d % n;
    //If number of elements to be rotated is exactly half of array size 
    if (n - d == d)
    {
        swap(arr, 0, n - d, d);
        return;
    }

    // If A is shorter
    if (d < n - d)
    {
        swap(arr, 0, n - d, d);
        leftRotate(arr, d, n - d);
    }
    else // If B is shorter
    {
        swap(arr, 0, d, n - d);
        leftRotate(arr + n - d, 2 * d - n, d); //This is tricky
    }
}

//UTILITY FUNCTIONS
// function to print an array 
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//This function swaps d elements starting at index fi with d elements starting at index si 
void swap(int arr[], int fi, int si, int d)
{
    int i, temp;
    for (i = 0; i < d; i++)
    {
        temp = arr[fi + i];
        arr[fi + i] = arr[si + i];
        arr[si + i] = temp;
    }
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    leftRotate(arr, 2, 7);
    printArray(arr, 7);
    return 0;
}
*/

// above code can also be done using iterative implementation
// Here is iterative implementation of the same algorithm. Same utility function swap() is used here.

/*
void leftRotate(int arr[], int d, int n)
{
    int i, j;
    if (d == 0 || d == n)
        return;

    // If number of elements to be rotated is more than array size
    if (d > n)
        d = d % n;

    i = d;
    j = n - d;
    while (i != j)
    {
        if (i < j) //A is shorter
        {
            swap(arr, d - i, d + j - i, i);
            j -= i;
        }
        else //B is shorter
        {
            swap(arr, d - i, d, j);
            i -= j;
        }

        // printArray(arr, 7);
    }

    //Finally, block swap A and B
    swap(arr, d - i, d, i);
}
*/