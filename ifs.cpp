#include <iostream>
#include <fstream>
#include <stdexcept>
#include <stack>
#include <vector>

using namespace std;

int main(){
    string name;
    cout << "enter name of text file" << endl;
    cin >> name;
    
    ifstream str;
    str.open(name.c_str());
    if(str.is_open()){
        cout << "file is open" << endl;
    }
    else{
        cout << "file is not open" << endl;
    }
    while(!str.eof()){
        string temp;
        getline(str,temp);
        cout << temp << endl;
    }
    cout << str << endl;
    str.close();
    
    stack<int, vector<int> > third;
    
    
    
    
    
    
    return 0;
}
        
        // while(!OFS.eof()){
        //     string temp;
        //     OFS.get(temp);
        //     cout << OFS << endl;
        // }