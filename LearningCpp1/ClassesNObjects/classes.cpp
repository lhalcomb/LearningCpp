#include <iostream>
#include <string.h>


using namespace std;

class Student
{

    public:
        string name;
        int* id; 

    Student()
    {
        //cout <<"Default Constructor called." <<endl; 
        id = nullptr;

    }
    
    void printId();

    Student(int& n)//: id(&n)
    {
        cout << "Parameterized Constructor called. " << endl;
        id = &n;
    }

    ~Student()
    {
        if (id != nullptr){
             cout << "Destructor called for ID: " << *id << endl; 
             delete id;
        }
       
    }

    void printName()
    {
        cout << "Name: " << name <<endl; 
    }

};

void Student::printId()
{
    cout << "Student ID: " << *id <<endl; 
}

int main()
{
    Student stud;

    stud.name = "Layden";
    stud.printName();

    int* idPtr = new int(509999);
    Student stud2(*idPtr);
    

    cout << "Student ID: " << *stud2.id << endl;

    Student stud3;
    int* newId = new int(999);
    stud3.id = newId;


    

    return 0;
}