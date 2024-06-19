#include <iostream>

using namespace std;

class Person{
    public:
          Person(std::string &aname): name{aname}{};

          std::string getName() const {return name;}

    private:
        std::string name;

};

class Student: public Person{
    public:
        Student(std::string &aname, int asemester): Person::Person{aname}, semester{asemester}{}
        int getSemester(){
            return semester;
        }
    private:
       int semester;
};

int main(){
    Person Person;
    Student Student;
    
    Person.getName();
    Student.getSemester();
    return 0;
}