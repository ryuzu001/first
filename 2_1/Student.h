#include <iostream>

using namespace std;

class Student{
    private:
        string name;
        int quizScore;
        int numQuizzes;
    public:
        Student (string);
        Student (string, int);
        string getName();
        void addQuiz(int);
        int getTotalScore();
        double getAverageScore();
};

