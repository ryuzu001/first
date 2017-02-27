#include<sstream>
#include<string>
#include<iostream>

using namespace std;

// 1. get a line of text
// 2. put that line into a string stream
// 3. pull 3 numbers from the string stream, and report any errors.


int main(){
    string userText;
    stringstream ss;
    
    ss.str("");
    
    getline(cin, userText);
    ss << userText;
    
    
    
    return 0;
    
}