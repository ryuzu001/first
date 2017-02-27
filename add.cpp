#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h>
using namespace std;
int total = 0;

void add(int size, vector <string> v){
    if(size != 3){
        cout << "Error!" << endl;
        return;
    }
    cout << atoi(v.at(1)) + atoi(v.at(2));
    
}
main(){
    
}