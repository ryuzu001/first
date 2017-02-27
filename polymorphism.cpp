#include <iostream>
#include <cstdio>
#include <limits>
#include <cstdint>
#include <cinttypes>
using namespace std;

class Enemy{
    protected:
        int attackPower;
    public:
        void setAttackPower(int a){
            attackPower = a;
        }
};

class Ninja:public Enemy{
    public:
        void attack(){
            printf("ninja attacked for %i \n",attackPower);
        }
};
class Monster:public Enemy{
    public:
        void attack(){
            printf("monster attacked for %i \n",attackPower);
        }
};
int main(){
    Ninja n;
    Monster m;
    Enemy * enemy1 = &n;
    Enemy * enemy2 = &m;
    
    enemy1->setAttackPower(29);
    enemy2->setAttackPower(99);
    
    n.attack();
    m.attack();
}