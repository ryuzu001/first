#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int rand_gen(int min, int max);
void generate_data_set(vector<int> & v, unsigned n);
void selection_sort(vector<int> &v, int numbersSize);
void merge_sort(vector<int> & v, int start, int end);
void merge(vector<int> & v, int start, int end);

int main()
{
    int sort_selection, size_selection;
    string to_output;
    vector<int> v;
    
    clock_t start;
    clock_t end;
    double dif;
    
    // FIX ME : Get data size to create
    cout << "what size data? "<< endl;
    cin >> size_selection;

    // FIX ME : Get whether or not to output to console
    cout << "output to console?(y/n)" << endl;
    cin >> to_output;

    // FIX ME : Allow user to choose between merge sort and selection sort
    cout << "merge or selection sort?(merge = 1,selection = 2)" << endl;
    cin >> sort_selection;
    

    // Generates random data set    
    generate_data_set(v, size_selection);
    
    // FIX ME : Output list before sort
    if(to_output == "y"){
        cout << "before: ";
        for(int x = 0; x < v.size(); x++){
            cout << v.at(x) << " ";
        }
    }
   cout << endl;
    // Call respective function based on selection 
    if (sort_selection == 1)//merge
    {
        start = clock();
        merge_sort(v,0,v.size() - 1);
        // Call respective function
        end = clock();
    }
    if(sort_selection == 2){//selectoin
        start = clock();
        selection_sort(v,size_selection);
        end = clock();
        
    }

    // FIX ME : Output list after sort
    if(to_output == "y"){
        cout << "after: ";
        for(int x = 0; x < v.size(); x++){
            cout << v.at(x) << " ";
        }
    }
    
    dif = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    cout << "\nThe loop took " << dif << " seconds\n";
    cout << endl;
    
    return 0;
}

int rand_gen(int min, int max)
{
    int range = max - min;
    
    if (range < 0)
    { 
        range = -range;
    }
    range += 1;
    
    return min + (rand() % range);
}

void generate_data_set(vector<int> & v, unsigned n)
{
    srand(time(0));

    int from = -100;
    int to = 100;

    for (unsigned i = 0; i < n; ++i)
    {
        v.push_back(rand_gen(from, to));
    }
}

void selection_sort(vector<int> & numbers, int numbersSize) {
    int indexSmallest = 0;
for (int i = 0; i < numbersSize; ++i) {
   // Find index of smallest remaining element
   indexSmallest = i;
   for (int j = i + 1; j < numbersSize; ++j) {
      if (numbers[j] < numbers[indexSmallest]) {
         indexSmallest = j;
      }
   }
   // Swap numbers[i] and numbers[indexSmallest]
   int temp = numbers[i];
   numbers[i] = numbers[indexSmallest];
   numbers[indexSmallest] = temp;
}
}

void merge(vector<int> & numbers, int i, int j, int k) {
   // FIX ME
   int mergedSize = k - i + 1;       // Size of merged partition
   int mergedNumbers[mergedSize];    // Temporary array for merged numbers
   int mergePos = 0;                 // Position to insert merged number
   int leftPos = 0;                  // Position of elements in left partition
   int rightPos = 0;                 // Position of elements in right partition
   
   leftPos = i;                      // Initialize left partition position
   rightPos = j + 1;                 // Initialize right partition position
   
   // Add smallest element from left or right partition to merged numbers
   while (leftPos <= j && rightPos <= k) {
      if (numbers[leftPos] < numbers[rightPos]) {
         mergedNumbers[mergePos] = numbers[leftPos];
         ++leftPos;
      }
      else {
         mergedNumbers[mergePos] = numbers[rightPos];
         ++rightPos;
         
      }
      ++mergePos;
   }
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (leftPos <= j) {
      mergedNumbers[mergePos] = numbers[leftPos];
      ++leftPos;
      ++mergePos;
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (rightPos <= k) {
      mergedNumbers[mergePos] = numbers[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   // Copy merge number back to numbers
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      numbers[i + mergePos] = mergedNumbers[mergePos];
   }
}

void merge_sort(vector<int> & numbers, int i, int k) {
  // FIX ME
     int j = 0;
   
   if (i < k) {
      j = (i + k) / 2;  // Find the midpoint in the partition
      
      // Recursively sort left and right partitions
      merge_sort(numbers, i, j);
      merge_sort(numbers, j + 1, k);
      
      // Merge left and right partition in sorted order
      merge(numbers, i, j, k);
   }
}