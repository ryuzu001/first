#include <iostream>
using namespace std;


bool isPalindrome(string s){
    if(s.size() <= 1){
        return true;
    }
    if(s.at(0) != s.at(s.size() - 1)){
        return false;
    }
    return isPalindrome(s.substr(1,s.size() - 2));
}


int main(){
    string userString;
    cout<<"Enter a string"<<endl;
    cin>>userString;
    
    if(isPalindrome(userString)){
        cout<<"True";
    }
    else{cout<<"false";}
    
return 0;}