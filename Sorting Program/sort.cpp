//
//  main.cpp
//  Sorting Algorithms
//
//  Created by Howard Miller on 4/22/19.
//  Copyright © 2019 Howard Miller. All rights reserved.
//
// Talal El Zeini CIST 004B


#include <iostream>
#include <iomanip>
#include <cmath>  // Used for log10()
#include <thread>  // Used for Multi-Threaded solution
#include <cstdlib>  // Used for bult-in q-sort routine
#include <chrono>  // used for timing functions
#include <ctime>   // Used to display time
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace std::chrono;

/************************
 ** STRUCT TO DEFINE A TEST PLUS NAME
 *************************/
struct sortRoutine {
    void (*function)( int *, size_t );
    const char * name;
};

/************************
 ** Utility Functions
 *************************/
int *getRandomNumbers (size_t num, int seed);
void printArray (int *array, size_t count);
bool checkSort  (int *array, size_t count);
duration<double> sortAndTime (int* testArray, size_t theSize, sortRoutine theTest, bool print =false);

/************************
 ** Sample Sort Functions Provided
 *************************/
void shakerSort (int *array, size_t count);
void cQuickSort (int *array, size_t count);
void quickSortBook  (int *array, size_t count);


/************************
 ** Student Created Sort Function
 *************************/
void bubbleSort (int *array, size_t count);             // REQUIRED
void selectionSort(int *data, size_t n);                // REQUIRED
void insertionSort(int *data, size_t n);                // REQUIRED

void bubbleSortOptimized (int *array, size_t count);        // EXTRA CREDIT (EASY, So I recommend you do this)

void quickSort  (int *array, size_t count);             // REQUIRED / Extra Credit if you do the non-recursive verison
void mergeSort  (int *array, size_t count);             // REQUIRED / Extra Credit if you do the non-recursive verison
void heapSort  (int *array, size_t count);                 // REQUIRED / Extra Credit if you do the non-recursive verison


void quickSortNonRecursive (int *array, size_t count);  // Extra Credit
void nonRecursiveMergeSort  (int *array, size_t count); // Extra Credit
void nonRecursiveHeapSort  (int *array, size_t count);
void quickSortBookOptimized  (int *array, size_t count);     // EXTRA CREDIT

void radixSort  (int *array, size_t count);                 // EXTRA CREDIT


void quickSortThreaded  (int *array, size_t count);         // EXTRA CREDIT
void quickSortHybrid  (int *array, size_t count);           // EXTRA CREDIT
void quickSortThreadedHybrid (int *array, size_t count);      //Just Crazy stuff!




/************************
 ** Sort Functions
 ** Add your function to this table
 *************************/

sortRoutine yourSortRoutines[] = {
    {shakerSort, "a sample Shaker Sort"},

    {quickSortBook, "the Quick Sort from the Book"},
   {bubbleSort, "the Bubble Sort"},
 {bubbleSortOptimized, "your Optimized Bubble Sort"},
   {selectionSort, "your Selection Sort"},
   {insertionSort, "your Insertion Sort"},
    
 //{radixSort, "your Radix Sort"},
   {cQuickSort, "the C++ Built-in Quick Sort"},
 //{quickSort, "your Quick Sort"},
 {heapSort, "your Heap Sort"},
 {nonRecursiveHeapSort, "your Non-Recursive Heap Sort"},
    //    {quickSortNonRecursive, "you1r Non-Recursive Quick Sort"},
    //    {quickSortHybrid, "your Hybrid Quick Sort"},  // Not worth it
    //    {quickSortThreaded, "your Multi-Threaded Quick Sort"},
    //    {quickSortThreadedHybrid, "your Hybrid Multi-Threaded Quick Sort"},
  {mergeSort, "your Merge Sort"},
{nonRecursiveMergeSort, "your Non-Recursive Merge Sort"},
    {nullptr , nullptr }  // Terminates the list
};

long long checkSum;  // Used to double check the sorted list

/************************
 ** main()
 ** Do not change this
 *************************/
int main(int argc, const char * argv[]) {
    size_t inputSize{0};
    char inputChar;
    
    do {
        cout << "Enter the size of Array you wish to sort (not more than 100,000,000): ";
        cin >> inputSize;
        if (inputSize > 100000000)
            cout << "Please try again!\n" << endl;
    } while (inputSize > 100000000 );
    
    do {
        cout << "Do you wish a single run (Y/N): ";
        cin >> inputChar;
        inputChar = toupper (inputChar);
    } while (inputChar != 'Y' && inputChar != 'N');
    
    if (inputChar == 'Y'){
        for ( size_t i{0} ;yourSortRoutines[i].function != nullptr ; ++ i  ){
            cout << fixed << setprecision(6);
            int* testArray = getRandomNumbers (inputSize, 0);
            
            cout<< "\nNow executing " << yourSortRoutines[i].name << " of "<< inputSize <<" items." << endl;
            duration<double> time_span_r = sortAndTime(testArray, inputSize, yourSortRoutines[i], true);
            cout << static_cast<char>(toupper(yourSortRoutines[i].name[0])) << &yourSortRoutines[i].name[1]
            << " took " << setw(7) << time_span_r.count() << " Seconds." << endl;
            
            cout<< "Now Executing " << yourSortRoutines[i].name << " of "<< inputSize <<" pre-sorted items." << endl;
            duration<double> time_span_r2 = sortAndTime(testArray, inputSize, yourSortRoutines[i], true);
            
            cout << static_cast<char>(toupper(yourSortRoutines[i].name[0])) << &yourSortRoutines[i].name[1]
            << " took " << setw(8) << time_span_r2.count() << " Seconds." << endl;
            delete[] testArray;
        }
        cout<< endl;
    } else {
        size_t ArraySize{0};
        time_t rawtime;
        cout << "\nTesting every Sort Routine with array sizes of from 0 to " << inputSize << " numbers."<< endl;;
        do {
            if (ArraySize % 100 == 1 ) {
                if (ArraySize == 1)
                    cout << "Starting at:\t\t\t";
                time (&rawtime);
                cout  << '\t' << ctime(&rawtime) << setw(log10(inputSize)+1)<< ArraySize-1; // Note: ctime has built-in '\n'
                // MS USERS       char str[26];
                //                ctime_s(str,sizeof str,&rawtime);
                //                cout  << '\t' << str << setw(log10(inputSize)+1)<< ArraySize-1; // Note: ctime has built-in '\n'
            }
            if (ArraySize % 10 == 9 )
                cout <<" .";
            for ( size_t i{0} ;yourSortRoutines[i].function != nullptr ; ++ i  ){
                int* testArray = getRandomNumbers (ArraySize, 0);
                sortAndTime(testArray, ArraySize, yourSortRoutines[i], true);      // Run sort and print array if an error
                delete[] testArray;
            }
        }  while(ArraySize++ < inputSize);
        cout <<endl;
        time (&rawtime);
        cout  << "Finished at:\t\t\t\t" << ctime(&rawtime)<<endl; // Note: ctime has built-in '\n'
        // MS USERS     ctime_s(str,sizeof str,&rawtime);
        //              cout  << "Finished at:\t\t\t\t" << str <<endl; // Note: ctime has built-in '\n'
    }
    return 0;
}

/************************
 ** Sample SHAKER SORT
 *************************/
void shakerSort (int *array, size_t count) {
    if (count <= 1)
        return; // No work for an empty or 1 element array.
    
    size_t p, i;
    for (p = 1; p <= count / 2; p++) {
        bool doneEarlyOptimization {true};
        for (i = p - 1; i < count - p; i++){  // Up Pass
            if (array[i] > array[i+1]) {
                int temp = array[i+1];
                array[i+1] = array[i];
                array[i] = temp;
                doneEarlyOptimization = false;
            }
        }
        for (i = count - p - 1; i >= p; i--) {  // Down Pass
            if (array[i] < array[i-1]) {
                int temp = array[i-1];
                array[i-1] = array[i];
                array[i] = temp;
                doneEarlyOptimization = false;
            }
        }
        if (doneEarlyOptimization)
            break;
    }
    return;
}

/************************
 ** BUILT-IN C-QUICK SORT
 *************************/
int cQuickSortCompare (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void cQuickSort (int *array, size_t count) {
    qsort (array, count, sizeof(int), cQuickSortCompare);
    return;
}


/************************
 ** BUBBLE SORT
 *************************/

// Talal El Zeini CIST 004B
void bubbleSort (int *array, size_t count) {
    int i, j, temp;
    if(count <= 1)
           return;
    for(i = 0; i < count-1; i++)
        for(j=0; j < count-i-1; j++)
            if(array[j+1] < array[j]){
                 temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
        }
    return;
}


/************************
 ** Optimized BUBBLE SORT
 *************************/

// Talal El Zeini CIST 004B
void bubbleSortOptimized(int *array, size_t count) {
 int i, j;
  bool isSwapped;
    if(count <= 1)
    return;
    for(i = 0; i < count-1; i++){
    isSwapped = false;
        for(j=0; j < count-i-1; j++){
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
                isSwapped = true;
        }
        }
           if(isSwapped == false)
        break;
    }
    return;
}

/************************
 ** SELECTION SORT
 *************************/


// Talal El Zeini CIST 004B
void selectionSort (int *array, size_t count){

    
    if(count <= 1)
    return;
    
    
    int i, j, small;
    for(i = 0; i < count-1; i++){
      small = i;
    for(j=i+1; j < count; j++){
      if(array[j] < array[small]){
        small = j;
      }
    }
    int temp = array[i];
    array[i] = array[small];
    array[small] = temp;
    }
    return;
}
/************************
 ** SELECTION SORT
 *************************/


/************************
 ** INSERTION SORT
 *************************/
// Talal El Zeini CIST 004B
void insertionSort (int *array, size_t count){

int i, value, index;
for(i = 0; i < count; i++){
  value = array[i];
  index = i;
  while(index > 0 && array[index-1] > value){
    array[index] = array[index-1];
    index = index-1;
  }
  array[index] = value;
}
return;
}


/************************
 ** MERGE SORT
 *************************/

// Talal El Zeini CIST 004B
void merge(int *array, size_t n1, size_t n2)

{
    int *temp;
    size_t copied  = 0;
    size_t copied1 = 0;
    size_t copied2 = 0;
    size_t i;

    temp = new int[n1+n2];
    while ((copied1 < n1) && (copied2 < n2))
    {
        if (array[copied1] < (array + n1)[copied2])
            temp[copied++] = array[copied1++];
        else
            temp[copied++] = (array + n1)[copied2++];
    }

    while (copied1 < n1)
        temp[copied++] = array[copied1++];
    while (copied2 < n2)
        temp[copied++] = (array+n1)[copied2++];

    for (i = 0; i < n1+n2; i++)
        array[i] = temp[i];
    delete [ ] temp;
}

// Talal El Zeini CIST 004B
void mergeSort(int array[ ], size_t count)

{
    size_t n1;
    size_t n2;

    if (count > 1)
    {
        // Compute sizes of the subarrays.
        n1 = count / 2;
        n2 = count- n1;

        mergeSort(array, n1);
        mergeSort((array + n1), n2);
        merge(array, n1, n2);
    }
}



    
/************************
 ** Non-recursive MERGE SORT
 *************************/

/************************
 ** HEAP SORT
 *************************/

// Talal El Zeini CIST 004B
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2
  
    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;
  
    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;
  
    // If largest is not root
    if (largest != i)
    {
         swap(arr[i], arr[largest]);
          
                // Recursively heapify the affected sub-tree
                heapify(arr, n, largest);
            }
        }


// Talal El Zeini CIST 004B
void heapSort(int *array, size_t count)
{
    // Build heap (rearrange array)
    for (int i = count / 2 - 1; i >= 0; i--)
        heapify(array, count, i);
  
    // One by one extract an element from heap
    for (int i=count-1; i>0; i--)
    {
        // Move current root to end
        swap(array[0], array[i]);
        
        // call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}

 void swap(int arr[], int index_1, int index_2){
    int temp = arr[index_1];
    arr[index_1] = arr[index_2];
    arr[index_2] = temp;
}


 void heapify_non_recursive(int arr[], int size, int current){
    int current_node = current;
    
    while(current_node * 2 + 1 < size){
        int left_node = current_node*2+1;
        int right_node = current_node*2+2;
        
        if(arr[left_node] > arr[current_node]){
            current_node = left_node;
        }
        if(right_node < size && arr[right_node] > arr[current_node]){
            current_node = right_node;
        }
        
        if(current_node != current){
            swap(arr, current_node, current);
            current = current_node;
        }else{
            break;
        }
    }
}

void nonRecursiveHeapSort(int *array, size_t count)
{

        for(int i=(count/2)-1; i>=0; i--){
            heapify_non_recursive(array, count, i);
        }
        
        for(int i=count-1; i>=0; i--){
            swap(array, 0, i);
            heapify_non_recursive(array, i, 0);
        }
    }

void mergeHelper(int number[], int left, int right, int mid) {
    int len = right - left + 1;
    int *tmp = new int[len];
    int index=0, i=left, j=mid+1;
    while (i <= mid and j <= right) {
        tmp[index++] = number[i]<=number[j] ? number[i++] : number[j++];
    }
    while (i <= mid) {
        tmp[index++] = number[i++];
    }
    while (j <= right) {
        tmp[index++] = number[j++];
    }
    for (int k=0; k < len; k++) {
        number[left++] = tmp[k];
    }
}
void nonRecursiveMergeSort(int *array, size_t count) {
    int left, mid, right;
    for (int i = 1; i < count; i *= 2) {
        left = 0;
        while (left + i < count) {
            mid = left + i - 1;
            right = mid + i < count ? mid + i : count - 1;
            mergeHelper(array, left, right, mid);
            left = right + 1;
        }
    }
}


/************************
 ** Multi-Threaded QUICK SORT
 *************************/

/************************
 ** Hybrid QUICK SORT
 *************************/


/************************
 ** Threaded Hybrid QUICK SORT
 *************************/


/************************
 ** QUICK SORT FROM BOOK
 *************************/
void partitionBook(int data[ ], size_t n, size_t& pivot_index)
// Library facilities used: itemtool.h, stdlib.h
//
// NOTES FROM THE IMPLEMENTOR:
// How the partition works on small arrays:
//
// Notice that n=0 is not permitted by the precondition.
//
// If n=1, then too_big_index is initialized as 1, and too_small_index is
// initialized as 0. Therefore, the body of the loop is never executed,
// and after the loop pivot_index is set to zero.
//
// If n=2, then both too_big_index and too_small_index are initialized as 1.
// The loop is entered, and there are two cases to consider:
// -- if data[1] <= pivot, then too_big_index increases to 2, and
//    too_small_index stays at 1. The if-statement at the bottom of the loop
//    is then skipped, and after the loop we copy data[1] down to data[0],
//    and copy the pivot into data[0]. Thus, the smaller element is in
//    data[0], and the larger element (the pivot) is in data[1].
// -- if data[1] > pivot, then too_big_index stays at 1, and too_small_index
//    decreases to 0. The if-statement at the bottom of the loop is then
//    skipped, and after the loop we end up copying the pivot onto data[0]
//    (leaving data[1] alone). Thus, the smaller element (the pivot) remains
//    at data[0], leaving the larger element at data[1].
{
    int pivot = data[0];
    size_t too_big_index = 1;     // Index of first item after pivot
    size_t too_small_index = n-1; // Index of last item
    
    // Partition the array, using pivot as the pivot element
    while (too_big_index <= too_small_index)
    {
        while ((too_big_index < n) && (data[too_big_index] <= pivot))
            too_big_index++;
        while (data[too_small_index] > pivot)
            too_small_index--;
        if (too_big_index < too_small_index){
            int temp = data[too_small_index];
            data[too_small_index] = data[too_big_index];
            data[too_big_index] = temp;
            // Too Slow            swap(data[too_small_index], data[too_big_index]);
        }
    }
    // Move the pivot element to its correct position
    pivot_index = too_small_index;
    data[0] = data[pivot_index];
    data[pivot_index] = pivot;
}

void quickSortBook(int data[ ], size_t n) {
    size_t pivot_index; // Array index for the pivot element
    size_t n1;          // Number of elements before the pivot element
    size_t n2;          // Number of elements after the pivot element
    
    if (n > 1)
    {
        // Partition the array, and set the pivot index
        partitionBook(data, n, pivot_index);
        
        // Compute the sizes of the subarrays
        n1 = pivot_index;
        n2 = n - n1 - 1;
        
        // Recursive calls to sort the subarrays
        quickSortBook(data, n1);
        quickSortBook((data + pivot_index + 1), n2);
    }
}







/************************
 ** Utility Functions
 ** Do not change these
 *************************/
duration<double> sortAndTime (int* testArray, size_t theSize, sortRoutine theTest, bool print){
    
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    theTest.function (testArray, theSize);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    if ( !checkSort  (testArray, theSize) && print){
        cout<< "Array size of: "<< theSize << " contents after " << theTest.name << " completed." << endl;
        printArray (testArray, theSize);
    }
    
    return t2 - t1;
}


int* getRandomNumbers(size_t num, int seed =0) {
    int *arr = nullptr;
    checkSum = 0;
    if (num > 0) {
        arr = new int[num+2];    // Array to hold the numbers
        srand(seed);
        int rnum = static_cast<int>(num);
        for (int count = 0; count < num; count++){
            arr[count] = rand() % (rnum*11) - rnum*11/2;
            checkSum += static_cast <long long>(arr[count]);
        }
        arr[num+1] = arr [num] = 999999;  // catch array overrun
    }
    return arr;
}

bool checkSort( int *a, size_t count) {
    if (count < 1)
        return true; // No work for an empty array.
    bool sorted = true;
    long long testCheckSum =0;
    for ( size_t i{0} ; i < count-1 ; ++i){
        testCheckSum += static_cast<long long>(a[i]);
        if ( a[i] > a[i+1] ) {
            sorted = false;
            cout << "Error Encountered!"<< endl;
            cout << "\tArray ["<< setw(log10(count)+1) <<i   << "] = " << a[i]   << endl;
            cout << "\tArray ["<< setw(log10(count)+1) <<i+1 << "] = " << a[i+1] << endl;
            break;
        }
    }
    if (testCheckSum+ static_cast<long long>(a[count-1]) != checkSum ) {
        cout <<"\nChecksum of Array does not match.  Orginal: " << checkSum;
        cout <<" New: " << testCheckSum+ static_cast<long long>(a[count-1]);
        cout <<"\nNot All numbers not present in the resulting array!\n";
        printArray(a, count);
        sorted = false;
    }
    return sorted;
}

void printArray (int* array, size_t count){
    for ( size_t i{0} ; i < count ; ++i){
        cout << "Array [" << setw(log10(count)+1) <<i<< "] = " << array[i] << endl;
    }
}
