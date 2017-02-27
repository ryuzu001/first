#include <fstream>
#include <iostream>
#include <cstdlib> //needed for exit function

using namespace std;

int fileSum(string filename){
   int total = 0;
   int temp = 0;
   
   ifstream inFS;
   inFS.open(filename.c_str());
   
   if (!inFS.is_open()) {
      cout << "Error opening " << filename << endl;
      return 1; // 1 indicates error
   }
   
   while(!inFS.eof()){
      total += temp;
      inFS >> temp;
      
   }
   
   
   return total;
}

int main() {
   string filename;
   cout << "Enter the name of the input file: ";
   cin >> filename;
   if(fileSum(filename) != 1){
      cout << "Sum: " << fileSum(filename) << endl;
   }
   
   return 0;
}

