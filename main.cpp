//
//  main.cpp
//  Class Grade Report
//
//  Created by Videsh Bridgelal on 10/21/20.
//  Copyright © 2020 Videsh Bridgelal. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//Functions to fill the averageGrade vector
void AverageGrade(vector<double>& firstGrade, vector<double>& secondGrade, vector<double>& thirdGrade, vector<double>& fourthGrade, vector<double>& finalGrade, vector<double>& averageGrade, int vectorSize){
    
    unsigned int i;
    double average;
    for(i = 0; i < vectorSize; i++){
        average = (firstGrade.at(i) + secondGrade.at(i) + thirdGrade.at(i) + fourthGrade.at(i) + (finalGrade.at(i) * 2)) / 5;
        averageGrade.push_back(average);
    }
}

//Function to fill the letterGrade vector
void LetterGrade(vector<double>& averageGrade, vector<char>& letterGrade, int vectorSize){
    unsigned int i;
    
    char letter;
    for(i = 0; i < vectorSize; i++){
        if(averageGrade.at(i) <= 100 && averageGrade.at(i) > 89) {      //Checks range 90-100
            letter = 'A';
        }
        else if (averageGrade.at(i) < 90 && averageGrade.at(i) > 79){   //Checks range 89-80
            letter = 'B';
        }
        else if(averageGrade.at(i) < 80 && averageGrade.at(i) > 69){    //Checks range 79-70
            letter = 'C';
        }
        else if(averageGrade.at(i) < 70 && averageGrade.at(i) > 59){    //Checks range 69-60
            letter = 'D';
        }
        else if (averageGrade.at(i) < 60){
            letter = 'F';
        }
        
        letterGrade.push_back(letter);      //Enters letter grade into next element in vector
    }
}

//Function to find the test average
void TestAverage(vector<double>& testAverage, vector<double>& firstGrade, vector<double>& secondGrade, vector<double>& thirdGrade, vector<double>& fourthGrade, vector<double>& finalGrade, int vectorSize){
    
    unsigned int i;
    double averageScore = 0.0;
    for(i = 0; i < firstGrade.size(); i++){
            averageScore = averageScore + firstGrade.at(i);
        }
    averageScore = averageScore / vectorSize;
    testAverage.push_back(averageScore);

    averageScore = 0.0;     //Resets averageScore to enter the next value into the vector
    
    for(i = 0; i < firstGrade.size(); i++){
            averageScore = averageScore + secondGrade.at(i);
        }
    averageScore = averageScore / vectorSize;
    testAverage.push_back(averageScore);
    
    averageScore = 0.0;
    for(i = 0; i < firstGrade.size(); i++){
            averageScore = averageScore + thirdGrade.at(i);
        }
    averageScore = averageScore / vectorSize;
    testAverage.push_back(averageScore);
    
    averageScore = 0.0;
    for(i = 0; i < firstGrade.size(); i++){
            averageScore = averageScore + fourthGrade.at(i);
        }
    averageScore = averageScore / vectorSize;
    testAverage.push_back(averageScore);
    
    averageScore = 0.0;
    for(i = 0; i < firstGrade.size(); i++){
            averageScore = averageScore + finalGrade.at(i);
        }
    averageScore = averageScore / vectorSize;
    testAverage.push_back(averageScore);
}

//Prints all the information to a .txt file
void PrintToFile(vector<string>& firstNameVector, vector<string>& lastNameVector,vector<double>& firstGradeVector, vector<double>& secondGradeVector, vector<double>& thirdGradeVector, vector<double>& fourthGradeVector, vector<double>& finalGradeVector, vector<double>& averageGradeVector, vector<char> letterGradeVector, vector<double> testAverageVector, int vectorSize, double highestGrade){
    ofstream outFile;
    outFile.open("GradeReport.txt", ios::out);          //Opens the file "GradeReport.txt" for outputing information
    
    string firstName;                                   //Initialize the variables again to feed into the file
    string lastName;
    double firstGrade;
    double secondGrade;
    double thirdGrade;
    double fourthGrade;
    double finalGrade;
    double averageGrade;
    char   letterGrade;
    double testAverage;
    
    outFile <<"First name:\tLast name:\tFirst Test Grade:\tSecond Test Grade:\tThird Test Grade:\tFourth Test Grade:\tFinal Test Grade:\tAverage Grade:\tLetter Grade" << endl;
    
    unsigned int i;
    for(i = 0; i < vectorSize; i++){                        //Loop changes the assignments to output every student.
        firstName = firstNameVector.at(i);
        lastName = lastNameVector.at(i);                    //This block of assignments is to enter the vector element
        firstGrade = firstGradeVector.at(i);                //so that I could send the information to the file "GradeReport.txt"
        secondGrade = secondGradeVector.at(i);
        thirdGrade = thirdGradeVector.at(i);
        fourthGrade = fourthGradeVector.at(i);
        finalGrade = finalGradeVector.at(i);
        averageGrade = averageGradeVector.at(i);
        letterGrade = letterGradeVector.at(i);              //  For the next bit of code:
                                                            //  "outFile"    acts like   "cout"   but outputs to the file instead.
                                                            //  Included in the loop to output each student's information.
        outFile << fixed << setprecision(2);
        outFile << firstName << "\t\t" << setw(7) << left << lastName << " \t" << setw(5) << right << firstGrade << "\t\t\t" << secondGrade << "\t\t\t" << thirdGrade << "\t\t\t" << fourthGrade << "\t\t\t" << finalGrade << "\t\t\t" << averageGrade <<"\t\t" << letterGrade << endl;
    }
    
    //Ouputs the average of each test
    outFile << endl <<"Test Averages:\t\t\t";
    for(i = 0; i < 5; i++){
        testAverage = testAverageVector.at(i);
        outFile << testAverage << "\t\t\t";
    }
    
    for(i = 0; i < vectorSize; i++){                        //Finds the highest grade in the class
        if(averageGradeVector.at(i) > highestGrade){
            highestGrade = averageGradeVector.at(i);
        }
    }
    
    //Outputs the student names that scored above a 99
    outFile << endl << endl << "Highest Average Grade: " << highestGrade << endl << endl;
    outFile << "Students w/ highest grades:" << endl;
    for(i = 0; i < vectorSize; i++){
        if(averageGradeVector.at(i) > 99){
            outFile << "\t\t\t\t" << firstNameVector.at(i) << " " << lastNameVector.at(i) << endl;
        }
    }
    
    outFile.close();        //Closes the file
}

int main() {
    
    string firstName;
    string lastName;
    double firstGrade;
    double secondGrade;
    double thirdGrade;
    double fourthGrade;
    double finalGrade;
    double highestGrade = 0.0;        //Used to store the highest grade found with the HighestGrade Function
    int    vectorSize = 0;
    
    vector<string> firstNameVector;
    vector<string> lastNameVector;
    vector<double> firstGradeVector;
    vector<double> secondGradeVector;
    vector<double> thirdGradeVector;
    vector<double> fourthGradeVector;
    vector<double> finalGradeVector;
    vector<double> averageGrade;
    vector<char>   letterGrade;
    vector<double> testAverage;
    
    cout << "Input student information:\t\tType 'end' to end the input\t" << endl;
    
    while(vectorSize < 30){
        
        cin >> firstName;
        if (firstName == "end"){
            break;                               //Stops the loop if input is "end"
        }
        cin >> lastName;
        cin >> firstGrade;
        cin >> secondGrade;
        cin >> thirdGrade;
        cin >> fourthGrade;
        cin >> finalGrade;
        
        firstNameVector.push_back(firstName);       //Fills the vectors with user input
        lastNameVector.push_back(lastName);
        firstGradeVector.push_back(firstGrade);
        secondGradeVector.push_back(secondGrade);
        thirdGradeVector.push_back(thirdGrade);
        fourthGradeVector.push_back(fourthGrade);
        finalGradeVector.push_back(finalGrade);
        vectorSize = vectorSize + 1;
    }
    
    //Functions fill in the other vectors
    AverageGrade(firstGradeVector, secondGradeVector, thirdGradeVector, fourthGradeVector, finalGradeVector, averageGrade, vectorSize);
    
    LetterGrade(averageGrade, letterGrade, vectorSize);
    
    TestAverage(testAverage, firstGradeVector, secondGradeVector, thirdGradeVector, fourthGradeVector, finalGradeVector, vectorSize);
    
    //Prints all information to a .txt file
    PrintToFile(firstNameVector, lastNameVector, firstGradeVector, secondGradeVector, thirdGradeVector, fourthGradeVector, finalGradeVector, averageGrade, letterGrade, testAverage, vectorSize, highestGrade);
    
    return 0;
}
