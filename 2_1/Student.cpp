#include "Student.h"
Student::Student(string name){
    this-> name = name;
    quizScore = 0;
}
Student::Student(string name, int quizScore){
    this-> name = name;
    this-> quizScore = quizScore;
    numQuizzes++;
}
string Student::getName(){
    return name;
}
int Student::getTotalScore(){
    return quizScore;
}
void Student::addQuiz(int score){
    if(score > 0){
        quizScore += score;
        numQuizzes++;
    }
}
double Student::getAverageScore(){
    return static_cast<double>(quizScore) / numQuizzes;
}