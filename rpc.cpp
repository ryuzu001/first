#include <list>
#include <iostream>
#include <sstream>
#include <stdlib.h>
using namespace std;

int main(){
    
    int destroy = 0;
    
    stringstream ss;
    string eq;
    cout << "Enter an equation in reverse polish notation" << endl;
    getline(cin, eq);
    
    ss.str(eq);
    
    eq.erase(eq.begin());
    
    
    
    int result = 0;
    
    int x = 0;
    ss >> x;  // x is now the first number entered
    
    int y = 0;  // y is the second number
    ss >> y;
    
    char z;
    
    ss >> z;     //z is operand;
    
    if(z == '*'){
        result = x*y;
    }
    else if(z == '/'){
        result = x/y;
    }
    else if(z == '+'){
        result = x+y;
    }
    else if(z == '-'){
        result = x-y;
    }
    else{
        cout << "error, i am not programmed that well yet" << endl;
    }
    
    
    
    
    // for(int x = 0; x < eq.length(); x++){
    //     ss << eq;
    //     if(eq[x] == '*'){
            
    //     }
    //     else if(eq[x] == '/'){
            
    //     }
    //     else if(eq[x] == '+'){
            
    //     }
    //     else if(eq[x] == '-'){
            
    //     }
    //     else{   //number
    //         ss << eq;
    //         if(eq[x+1] == '*'){
                
    //         }
    //         else if(eq[x+1] == '/'){
                
    //         }
    //         else if(eq[x+1] == '+'){
                
    //         }
    //         else if(eq[x+1] == '-'){
                
    //         }
    //         else{  // number again
    //             if(eq[x+2]){
                    
    //             }
    //         }
    //     }
    //     ss.str("");
    // }
    
    cout << "result:" << result << endl;
    
    return 0;
}
