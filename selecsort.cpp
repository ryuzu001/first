#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    v.push_back(5);
    v.push_back(7);
    v.push_back(1);
    v.push_back(6);
    v.push_back(9);
    v.push_back(9);
    v.push_back(10);
    v.push_back(2);
    v.push_back(12);
    
    for(int x = 0; x < v.size(); x++){
        cout << v[x] << " ";
    }
    
    cout << endl;
    
    for(int y = 0; y < v.size() - 1; y++){
        for(int z = y + 1; z < v.size(); z++){
            if(v[y] > v[z]){
                int temp = v[y];
                v[y] = v[z];
                v[z] = temp;
            }
        }
    }
    
    
    
    for(int x = 0; x < v.size(); x++){
        cout << v[x] << " ";
    }    
    
    
    return 0;
}