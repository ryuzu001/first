#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool guess(int,int);
int main(){
    int userNum = 0;
    int r;
    srand (time(NULL));
    r = rand() % 100 + 1;

    if(guess(userNum, r)){
        cout << "you win" << endl;
    }
    else{
        cout << "you suck" << endl;
    }
    return 0;
}
bool guess(int a,int b){
    cout << "Please enter a number between 1 and 100" << endl;
    cin >> a;
    if(a > 100 || a < 1){
        cout << "Ayy lmao" << endl;
        return false;
    }
    if(a == b){
        cout << "awesome" << endl;
        return true;
    }
    if(a > b){
        cout << "too high" << endl;
        guess(a,b);
    }
    if(a < b){
        cout << "too low" << endl;
        guess(a,b);
    }
}