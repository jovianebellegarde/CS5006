// Task: Implement the 'sortIntegers' function below

// =================== Libraries ==================
#include <stdio.h> // Include file for standart input/output
// 
// =============== Helper Functions ===============

// Reference: // geek for geeks: https://www.geeksforgeeks.org/merge-sort/
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
	
    // Implement merge
    int left = m - l + 1;
    int right = r - m;
    int leftArray[left];
    int rightArray[right];
    int i;

    for (i = 0; i <left; i++) {
       
        leftArray[i] = arr[l + i];
    }
    for (i = 0; i < right; i++) {
       
        rightArray[i] = arr[i + m + 1];
    }
    
    // Merging
    i = 0;
    int j = 0;
    int k = l;

    while (i < left && j < right) {
       
        if (leftArray[i] < rightArray[j]) {
    
            arr[k] = leftArray[i];
            i++;
        } else {
      
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < left) {

        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < right) {
       
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}



void mergeSort(int arr[], int l, int r) {
    if (l == r) return;
    else {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


// Provided below is a sort function. We have also
// provided a template for how to document functions
// to help organize your code.
// Name: sortIntegers
// Input(s):
//          (1) 'array' is a pointer to an integer address. 
//              This is the start of some 'contiguous block of memory' that we will sort.
//          (2) 'size' tells us how big the array of data is we are sorting.
// Output: No value is returned, but 'array' should be modified to store a sorted array of numbers.
void sortIntegers(int* array, unsigned int size){
	int newSize = size - 1;
	int zero = 0;
	
	// Calling the mergeHelper function
	mergeSort(array, zero, newSize);	
}


// Input: A pointer to an array (i.e. the array itself points to the first index)
//        The size of the array (Because we do not know how big the array is automatically)
void printIntArray(int* array, unsigned int size){
  unsigned int i; // Note: 'unsigned int' is a datatype for storing positive integers.
  for(i = 0; i < size; i=i+1){
    printf("%d ",array[i]);
  }
  printf("\n");
}

int main(){
  
  // Some test data sets.
  int dataset1[] = {0,1,2,3,4,5,6,7,8,9,10};
  int dataset2[] = {10,9,8,7,6,5,4,3,2,1,0};
  int dataset3[] = {0,3,2,1,4,7,6,5,8,9,10};
  int dataset4[] = {2,1,1,1,1,1,1,1,1,1,1};
  int dataset5[] = {100,201,52,3223,24,55,623,75,8523,-9,150};
  int dataset6[] = {-1,1,2,-3,4,5,-6,7,8,-9,10};
  
  // Sort our integer array
  sortIntegers(dataset1, 11);
  sortIntegers(dataset2, 11);
  sortIntegers(dataset3, 11);
  sortIntegers(dataset4, 11);
  sortIntegers(dataset5, 11);
  sortIntegers(dataset6, 11);
  
  // Print out an array
  printIntArray(dataset1, 11);
  printIntArray(dataset2, 11);
  printIntArray(dataset3, 11);
  printIntArray(dataset4, 11);
  printIntArray(dataset5, 11);
  printIntArray(dataset6, 11);
  
  return 0;
}
