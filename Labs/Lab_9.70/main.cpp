#include <time.h>
#include <random>
#include <iostream>

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds

const int NUMBERS_SIZE = 50000;

void Quicksort_midpoint(int numbers[], int i, int k);
void Quicksort_medianOfThree(int numbers[], int i, int k);
void InsertionSort(int numbers[], int numbersSize);

void fillArrays(int arr1[], int arr2[],int arr3[]);
int genRandInt(int low, int high);

using namespace std;

int main()
{
    int Array1[NUMBERS_SIZE];
    int Array2[NUMBERS_SIZE];
    int Array3[NUMBERS_SIZE];

    fillArrays(Array1, Array2, Array3);
    
    cout<<endl;
    cout<<"Quicksort midpoint: "<<endl;
        clock_t Start = clock();
        //call sort function here
        Quicksort_midpoint(Array1, 0, NUMBERS_SIZE);
        clock_t End = clock();
        int elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
        cout<<elapsedTime<<endl;

   
    // cout<<endl;
    // for(int num : Array1)
    // {
    //     cout<<num<<", ";
    // }
    cout<<"Quicksort medianOfThree: "<<endl;
        Start = clock();
        //call sort function here
        Quicksort_medianOfThree(Array2, 0, NUMBERS_SIZE);
        End = clock();
        elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
        cout<<elapsedTime<<endl;
    // for(int num : Array2)
    // {
    //     cout<<num<<", ";
    // }
    cout<<"Quicksort InsertionSort: "<<endl;
        Start = clock();
        //call sort function here
        InsertionSort(Array3, NUMBERS_SIZE);
        End = clock();
        elapsedTime = (End - Start)/CLOCKS_PER_MS; // converts elapsed time from microseconds to milliseconds.
        cout<<elapsedTime<<endl;
}

int genRandInt(int low, int high) 
{
   return low + rand() % (high - low + 1);
}//end of getRandInt

void fillArrays(int arr1[], int arr2[],int arr3[])
{
    for(int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0,NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }//end of for loop
}//end of fill Arrays

/* * * * * * * * * * * * * * * * * * * * * * *
 *              --------------               *
 *           Quick sort midpoint             *
 *              --------------               *
 *           worst case: 0(n^2)              *
 *            average case: O(N log N)       *
 *                                           *
 * * * * * * * * * * * * * * * * * * * * * * */
void Quicksort_midpoint(int numbers[], int i, int k)//O(N log N)
{
   if (i >= k) return;

    int low = i;
    int high = k;
    int pivot = i + (k - i) / 2;
    pivot = numbers[pivot];

    //sort lower and higher side of midpoints
    bool done = false;
    while(!done) 
    {
        while (numbers[i] < pivot) i++;
        while (numbers[k] > pivot) k--;

        if (i >= k) done = true;
        else
        {
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
                // Update lowIndex and highIndex
            i++;
            k--;
        }
    }
    //call it again for left and right
    Quicksort_midpoint(numbers, low, k);
    Quicksort_midpoint(numbers, k + 1, high);
}

/* * * * * * * * * * * * * * * * * * * * * * *
 *              --------------               *
 *       Quick sort median of three          *
 *              --------------               *
 *            worst case: O(N log N)          *
 * * * * * * * * * * * * * * * * * * * * * * */
void Quicksort_medianOfThree(int numbers[], int i, int k)//O(N log N)
{
    if (i >= k) return;

    int low = i;
    int high = k;
    int pivot = i + (k - i) / 2;
    if (numbers[i] < numbers[pivot])
    {
        if (numbers[pivot] > numbers[k])
            pivot = k;
    }
    else if (numbers[k] < numbers[pivot])
    {
        if (numbers[pivot] > numbers[i])
            pivot = i;
    }
    pivot = numbers[pivot];

    //sort lower and higher side of midpoints
    bool done = false;
    while(!done) 
    {
        while (numbers[i] < pivot) i++;
        while (numbers[k] > pivot) k--;

        if (i >= k) done = true;
        else
        {
            int temp = numbers[i];
            numbers[i] = numbers[k];
            numbers[k] = temp;
             // Update lowIndex and highIndex
            i++;
            k--;
        }
    }
    //call it again for left and right
    Quicksort_medianOfThree(numbers, low, k);
    Quicksort_medianOfThree(numbers, k + 1, high);
}


/* * * * * * * * * * * * * * * * * * * * * * *
 *              --------------               *
 *              Insertion Sort               *
 *              --------------               *
 *            worst case: O(n^2)             *
 *         nearly sorted/best case: O(n)     *
 * * * * * * * * * * * * * * * * * * * * * * */
void InsertionSort(int numbers[], int numbersSize) {
   int temp = 0;  // Temporary variable used for swap
   for (int i = 1; i < numbersSize; ++i) {
      int j = i;
      while (j > 0 && numbers[j] < numbers[j - 1]) {     
         // Swap numbers[j] and numbers[j - 1]
         temp = numbers[j];
         numbers[j] = numbers[j - 1];
         numbers[j - 1] = temp;
         --j;
      }
   }
}