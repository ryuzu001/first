//write a function recurse merge that alphabetically merges 2 string srecursively.
// assume both string spassed in are alerady sorted



#include <iostream>
using namespace std;

void recurse_merge(const string & s1, const string & s2, string & s3, unsigned i1, unsigned i2){
    if(s1.length() == 0 && s2.length() == 0 || s1.length() - 1 == i1 && s2.length() - 1 == i2){
        return;
    }
    if(s1.length() - 1 == i1 && s2.length() - 1 != i2 || s1.at(i1) > s2.at(i2)){
        s3 += s2.at(i2);
        i2++;
    }
    if(s1.at(i1) < s2.at(i2) || s2.length() - 1 == i2 && s1.length() - 1 != i1){
        s3 += s1.at(i1);
        i1++;
    }
    recurse_merge(s1,s2,s3,i1,i2);
}

int main(){
    int i1 = 0;
    int i2 = 0;
    string s2 = "aaabdefffgjkkkkllmoppqsvzz";
    string s1 = "aaaaaaaaaaaccdddgghjlmnpqrsyzzzzzzz";
    string s3 = "";
    
    recurse_merge(s1,s2,s3,i1,i2);
    
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;
    return 0;
}