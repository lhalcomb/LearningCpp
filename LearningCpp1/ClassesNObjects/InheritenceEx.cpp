#include <iostream>
#include <string>

using namespace std;

class Person{
    public:
          explicit Person(const std::string &aname): name{aname}{};

          std::string getName() const {return name;}

    private:
        std::string name;

};

class Student: public Person{
    public:
        Student(const std::string &aname, int asemester): Person(aname), semester{asemester}{}
        int getSemester(){
            return semester;
        }
    private:
       int semester;
};

int main(){
    Person person("Layden");
    Student stud("Layden", 5);
    
    std::cout << person.getName() << std::endl;
    std::cout << stud.getSemester() << std::endl;
    return 0;
}