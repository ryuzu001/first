#include <iostream>
#include <stack>
#include <sstream>
#include <stdlib.h>

using namespace std;

int main(){
    cout << "Please enter a math expression (use space inbetween characters and numbers." << endl;
    string userExpression;
    getline(cin, userExpression);
    stringstream ss;
    cout << userExpression;
    ss.str(userExpression);
    
    while(){
        if(isdigit(ss)){
            
        }
    }
    
    return 0;
}