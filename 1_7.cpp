#include<iostream>
#include<vector>
using namespace std;

int posOfSmallest(vector<int> v){
    int check = v.at(0);
    int pos = 0;
    for(unsigned int x = 1; x < v.size(); x++){
        if(v.at(x) < check){
            check = v.at(x);
            pos = x;
        }
    }
    return pos;
}


int main(){
    
    vector<int> v;
    v.push_back(0);
    v.push_back(3);
    v.push_back(5);
    v.push_back(9);
    v.push_back(-6);
    v.push_back(-99);
    
    for(unsigned int x = 0; x < v.size(); x++){
        cout << v.at(x) << " ";
    }
    cout << endl;
    cout << "Lowest value is at position " << posOfSmallest(v) + 1 << endl;
    return 0;
}