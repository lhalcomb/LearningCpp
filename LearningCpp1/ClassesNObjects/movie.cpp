#include <iostream>
#include <vector>

using namespace std;

class Movie
{
    public:
       string title;
       string director;
       

       Movie(string title, string director, string rating){
        this->title = title;
        this->director = director;
        setRating(rating);

       }

       void setRating(string aRating){
           
           vector<string> validRatings = {"G", "PG", "PG-13", "R", "NR"};

            for (size_t i = 0; i < validRatings.size(); i++)
            {
                if (aRating == validRatings[i]){
                    this->rating = aRating;
                    return;
                }
                        
            }

            cout << "Invalid rating" << endl;
       }

       string getRating(){
        return rating;
       }

       private: //The private access modifier for classes makes it where the class can only access a variable, function, etc. 
          string rating;
};


//inheritence
class CartoonShows : public Movie {
    string TargetAgeGroup;

    public:
    CartoonShows(string title, string director, string rating, string TargetAgeGroup)
     : Movie(title, director, rating){
        this ->TargetAgeGroup = TargetAgeGroup;
     }
};

int main()
{
    Movie PulpFiction("Pulp Fiction", "Quentin Tarintino", "R");
    cout << PulpFiction.title << endl;
    PulpFiction.setRating("PG-13");

    cout << PulpFiction.getRating() << endl;

    CartoonShows RickAndMorty("Rick and Morty", "Dan Harmond", "PG-13", "Adults");
    cout << RickAndMorty.title << endl;
    RickAndMorty.setRating("R");
    cout << RickAndMorty.getRating() << endl;

    return 0;

}