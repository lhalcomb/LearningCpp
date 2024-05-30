#include <iostream>

using namespace std;

/*
    Just like other object oriented programming languages, cpp classes
    are rules or the template of the specifications of some class.

    Whereas, the object is the actual instantiation of the class that 
    we are working with. 
*/
class Book
{
    public:
        string title;
        string author;
        int pages;

        //Special function that gets called when we create an object
        Book()
        {
            cout << "Book created" << endl;
        }

};

int main()
{
    Book ParableOfTheSower;
    ParableOfTheSower.title = "Parable Of The Sower";
    ParableOfTheSower.author = "Octavia E. Butler";
    ParableOfTheSower.pages = 329;

    cout << ParableOfTheSower.title << endl;

    return 0;
}