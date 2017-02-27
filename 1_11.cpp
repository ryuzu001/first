#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string createUsername ( string first_name, string last_name, int age) {
    ostringstream usernameOSS;
    string firstChar = "";
    string lastpart = "";
    
    firstChar = first_name.substr(0, 1);
    
    lastpart = last_name.substr(0, 4);
    
    usernameOSS << firstChar << lastpart << age;
    
    return usernameOSS.str();
    
    
    
// use ostringstream to create the patient’s username following the convention below
//username = (first charc of first name)(last 4 charc of last name)(age)
}

int main() {
    cout << createUsername("Ryan", "Yuzuki", 19) << endl;
    cout << createUsername("Tim", "Newman", 24) << endl;
    
    
    
    return 0;
}