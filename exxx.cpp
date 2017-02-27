#include <iostream>
#include <stdexcept>
#include <stack>
using namespace std;
// int main(){
//     try{
//         cout << "would you like a runtime error? yes or no" << endl;
//         string temp;
//         cin >> temp;
//         if(temp == "yes"){
//             throw runtime_error("here's your runtime error");
//         }
//         cout << "would you like a logic error? yes or no" << endl;
//         string temp2;
//         cin >> temp2;
//         if(temp2 == "yes"){
//             throw logic_error("here's your logic error");
//         }
//     }
//     catch(runtime_error & error){
//         cout << "error: " << endl;
//         cout << error.what() << endl;
//         return 0;
//     }
//     catch (logic_error & error){
//         cout << "error< " << endl;
//         cout << error.what() << endl;
//         return 0;
//     }
//     cout << "no error, program ending" << endl;
//     return 0;
// }


class Queue{
  public: 
    Queue(int);
    void printAll();
    void push_q(int t);
    int pop_q(); // removes and returns the top element
    bool isEmpty(); 
  private:
    stack<int> s1;
    stack<int> s2;
    unsigned sz;  // the number of elements currently being used in Queue
    unsigned cap; // the size of Queue
};
Queue::Queue(int x){
    cap = x;
    sz = 0;
}
void Queue::printAll(){
    int x = 0;
    while(!s1.empty()){
        cout << s1.get() << " ";
        s1.pop();
    }
    x = 0;
    while(!s2.empty()){
        cout << s2.get() << " ";
        s2.pop();
    }
}
void Queue::push_q(int x){
    
}
int Queue::pop_q(){
    
}

int main(){
    return 0;
}