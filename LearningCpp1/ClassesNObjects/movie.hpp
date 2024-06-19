#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>

using namespace std; 

class Movie{

    public:

        string title;
        string director;

        Movie(string title, string director, string rating);

        void setRating(string aRating);
        string getRating();

    private: 
        string rating;

};

//inheritence
class CartoonShows : public Movie{
    public:
    string TargetAgeGroup;

    CartoonShows(string title, string director, string rating, string TargetAgeGroup);

};

#endif // MOVIE_HPP