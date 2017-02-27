#include <iostream>
#include "1_25.h"

using namespace std;

int main(){
    string userName;
    int userHealth;
    int userChoice;
    
    cout << "Please enter a name: " << endl;
    cin >> userName;
    
    Character c(userName, 100);    
    
    cout << "Welcome to life. Please refrain from dying." << endl;
    
    cout << c;
    
    while (c.get_health() > 0){
        cout << "Please choose an option: "<< endl;
        cout << "1. Eat" << endl;
        cout << "2. Drink" << endl;
        cout << "3. Move" << endl;
        
        cin >> userChoice;
        
        if(userChoice == 1){
        c.eat();
        }
        if(userChoice == 2){
            c.drink();
        }
        if(userChoice == 3){
            c.move();
        }
        cout << c;
    }
    cout << "You died." << endl;
    cout << "You traveled " << c.get_distance() << " miles." << endl;
    return 0;
}