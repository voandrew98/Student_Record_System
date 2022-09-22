#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>

using namespace std; 

struct student  //info
{
    string id;
    string first;
    string last;
    string dob;
    string gpa;
    student *next;
    student *prev;
};

class Student
{
    private:
    student *head;   
    student *tail; 

    public:

        Student(){head=nullptr;} //constructor

        void add(string id,string first,string last,string dob,string gpa);
        void print(ofstream& output);
        void deleteNode(string line);
        void swap(student *point1, student *point2);
        void bubbleSort(string sortname);
        void openFile(ifstream& file); //not working

};
