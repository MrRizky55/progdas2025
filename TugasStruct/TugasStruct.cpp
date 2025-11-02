#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct studentType{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void readData(int indexSize, studentType input[], ifstream& data){
    int j = indexSize;
    if(data.is_open()){
        for (int i=0; i<j; i++){
            data >> input[i].studentFName >> input[i].studentLName >> input[i].testScore;
        }
    } else cout << "Data is not found." << endl;
    data.close();
}

void grader(int indexSize, studentType input[]){
    int j = indexSize;
    for (int i=0; i<j; i++){
        if (input[i].testScore <= 25) input[i].grade = 'E';
        else if (input[i].testScore > 25 && input[i].testScore <= 50) input[i].grade = 'D';
        else if (input[i].testScore > 50 && input[i].testScore <= 75) input[i].grade = 'C';
        else if (input[i].testScore > 75 && input[i].testScore <= 85) input[i].grade = 'B';
        else if (input[i].testScore > 85 && input[i].testScore <= 100) input[i].grade = 'A';
        else input[i].grade = '?';
    }
}

int highestScore(int indexSize, studentType input[]){
    int j = indexSize;
    int highscore = 0;
    for (int i=0; i<j; i++){
        if (input[i].testScore > highscore) highscore = input[i].testScore;
    }
    return highscore;
}

void printData(int indexSize, studentType input[], int score){
    int j = indexSize;
    for (int i=0; i<j; i++){
        if (input[i].testScore == score && input[i].studentFName.length() != 0) cout << input[i].studentLName << ", " << input[i].studentFName << endl;
    }
}

int main(){
    ifstream inputFile("input.txt");
    int j = 20;

    studentType examResult[j];
    readData(j, examResult, inputFile);
    grader(j, examResult);
    printData(j, examResult, highestScore(j, examResult));
    return 0;
}