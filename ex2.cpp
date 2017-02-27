#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(0));
    list<int> l1;
    for(unsigned i = 0; i < 30; ++i){
        l1.push_back(rand() % 1000);
    }
    list<int>::iterator it;
    for(it = l1.begin(); it != l1.end(); ++it){
        cout << *it << ' ';
    }
    
    cout << endl << endl;
    
    // it = l1.begin();
    // it = l1.erase(it);
    
    for(it = l1.begin(); it != l1.end(); ){
        if(*it % 2 == 0){
            it = l1.erase(it);
        }
        else{
            it++;
        }
    }
    
    for(it = l1.begin(); it != l1.end(); ++it){
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}