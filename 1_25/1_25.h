#include <iostream>

using namespace std;




class Bag{
    private:
        int water;
        int food;
    public:
        void remove_food();    //remove 1 food item
        void remove_water();   //remove 10 from water
        int get_food();
        int get_water();
        Bag operator+(Bag b2);
        Bag (int water = 100, int food = 10);
        friend ostream & operator<<(ostream& out, Bag& L);
};
class Character{
    private:
        string name;
        int health;
        int distance;
        Bag b;
    public:
        Character(string n = "none", int h = 100);
        string get_name();
        int get_health();
        int get_distance();
        void eat();
        void drink();
        void move();
        void store(int water, int food);
        void change_name(string n);
        friend ostream & operator<<(ostream &out, Character& c);
};