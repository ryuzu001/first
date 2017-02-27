#include <iostream>
using namespace std;
int fac(int n){
    if(n==1){
        int*bar = 0;
        cout<<*bar<<endl;
    }
    return n* fac(n-1);
}
int main(){
    cout<<fac(5)<<endl;
    return 0;
}