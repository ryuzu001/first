#include <iostream>
using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int data;
};

class doublyLL{
    public:
    doublyLL();
    doublyLL(const doublyLL*);
    doublyLL operator=(doublyLL*);
    ~doublyLL();
    void push_front();
    void push_back();
    void pop_front();
    void pop_back();
    bool contains();
    void reverse();
    int size();
    private:
    Node* header;
    Node* trailer;
};

doublyLL::doublyLL(){
    header = 0;
    trailer = 0;
}
doublyLL::doublyLL(const doublyLL* temp){
    this->header = temp->header;
    this->trailer = temp->trailer;
}
doublyLL doublyLL::operator=(doublyLL* temp){
    header = temp->header;
    trailer = temp->trailer;
}
doublyLL::~doublyLL(){
    Node* temp = header;
    while(temp != 0){
        Node* temp2 = temp->next;
        delete temp;
        temp = temp2;
    }
}
void doublyLL::push_back(){
    
}
void doublyLL::push_front(){
    
}
void doublyLL::pop_front(){
    
}
void doublyLL::pop_back(){
    
}
bool doublyLL::contains(){
    
}
void doublyLL::reverse(){
    
}
int doublyLL::size(){
    
}

int main(){
    cout << endl;
    cout << "hey there" << endl;
    cout << endl;
    return 0;
}