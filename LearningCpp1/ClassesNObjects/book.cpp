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
        Book(string title, string author, int pages)
        {
            this->title = title;
            this->author = author;
            this->pages = pages;
            cout << "Book created" << endl;
        }

};

int main()
{
    Book ParableOfTheSower("Parable Of The Sower", "Octavia E. Butler", 329);
    ParableOfTheSower.title = "Parable Of The Sower";
    ParableOfTheSower.author = "Octavia E. Butler";
    ParableOfTheSower.pages = 329;

    cout << ParableOfTheSower.title << endl;


    Book NineteenEigthyFour("1984", "George Orwell", 244);

    cout << NineteenEigthyFour.author << endl;

    return 0;
}