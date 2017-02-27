#include <iostream>
#include "1_25.h"
#include <stdlib.h>

using namespace std;

//BAG

void Bag::remove_food(){
    food = food - 1;
}
void Bag::remove_water(){
    water = water - 10;
}
int Bag::get_food(){
    return food;
}
int Bag::get_water(){
    return water;
}
Bag Bag::operator+(Bag b2){
    water = water + b2.water;
    food = food + b2.food;
}
Bag::Bag (int w, int f){
//:water(water), food(food)
    water = w;
    food = f;
}
ostream & operator<<(ostream &out, Bag &L){
    out << "Food remaining " << L.food << endl << "Water remaining: " << L.water << endl;
    return out;
}











// CHARACTER


Character::Character(string n, int h){
    name = n;
    health = h;
}
string Character::get_name(){
    return name;
}
int Character::get_health(){
    return health;
}
int Character::get_distance(){
    return distance;
}
void Character::eat(){
    if(b.get_food() == 0){
        cout << "You have no food!" << endl;
        return;
    }
    if(health >= 90){
        health = 100;
    }
    else{
        health = health + 10;
    }
    b.remove_food();
}
void Character::drink(){
    if(b.get_water() == 0){
        cout << "You have no water!" << endl;
        return;
    }
    if(health >= 95){
        health = 100;
    }
    else{
        health = health + 5;
    }
    b.remove_water();
}
void Character::move(){
    if(health < 10){
        cout << "Your health is too low to move!" << endl;
    }
    else{
        int temp = 0;
        temp = rand() % 10;
        temp += 2;
        distance = distance + temp;
        health = health - 10;
    }
}
void Character::store(int water, int food){
    Bag new_bag(water, food);
    b = b + new_bag;
}
void Character::change_name(string n){
    name = n;
}
ostream & operator<<(ostream &out, Character &c){
    out << "Identity: " << c.name << endl << "Health remaining: " << c.health << endl;
    out << c.b;
    return out;
}
















