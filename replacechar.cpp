#include<iostream>
#include<string>
using namespace std;

int main(){
    string sentenceText = "Hello. There. My. Name. is. Bob.";
    while(sentenceText.find(".") != string::npos){
        sentenceText.replace(sentenceText.find("."), 1, "!");
    }
    cout << sentenceText << endl;
return 0;
}