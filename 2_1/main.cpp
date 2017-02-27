#include <iostream>
#include "Student.h"
using namespace std;
int main() {
 Student s1("Josh");
 Student s2("Ann", 85);
 int k = 80;
 for(int i = 0; i < 3; ++i) {
 s2.addQuiz(k);
 k += 2;
 }

 s1.addQuiz(-10);
 s1.addQuiz(92);
 s1.addQuiz(86);

 cout << "Student 1: " << s1.getName() << endl;
 cout << "Total Score, Average score: " << s1.getTotalScore() << ", " <<
s1.getAverageScore() << endl;
 cout << "Student 2: " << s2.getName() << endl;
 cout << "Total Score, Average score: " << s2.getTotalScore() << ", " <<
s2.getAverageScore() << endl;

}