#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char** argv){
    for(unsigned int x = 0; x < argc; x++){
        cout << argv[x] << " ";
    }
    cout << endl;
    return 0;
}