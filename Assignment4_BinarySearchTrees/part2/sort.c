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
	
	// Making variable for temporary arrays to use during the sort
	int a = 0;
	int b = 0;
	int c = l;

	int left = m - l + 1;
	int right = r - m;

	int leftArray[left];
	int rightArray[right];
	
	for (a = 0; a < left; a++) {
		leftArray[a] = arr[a + l];	
	}
	 
	for (b = 0; b < right; b++) {
		rightArray[b] = arr[b + 1 + m];
	}
	
	// Merging the temporary arrays to have the big one back again
	while (a < left && b < right){
		if(rightArray[b] >= leftArray[a]) {
			leftArray[a] = arr[c];
			a++;
		
		} else {
			rightArray[b] = arr[c];
			b++;	
		}
		c++;
	}
	
	// Going to copy any remaining components of leftArray
	while (left > a) {
		leftArray[a] = arr[c];
		a++;
		c++;
	}

	// Going to copy any remaining components of rightArray
	while (right > b) {
		rightArray[b] = arr[c];
		b++;
		c++;
	}
}

void mergeHelper(int arr[], int right, int left) {
	int middle = (right + left) / 2;
	
	// Checking if the right node is bigger than the left node
	// as larger values are on the right side and smaller ones 
	// are on the left side.
	if (right > left) {
		merge(arr, left, middle, right);
		merge(arr, middle + left, middle, right);
		merge(arr, left, middle, right);	
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
	mergeHelper(array, zero, newSize);	
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
