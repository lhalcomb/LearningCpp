#include <iostream>
#include <vector>
#include "movie.hpp"

using namespace std;


       

      Movie::Movie(string title, string director, string rating){
        this->title = title;
        this->director = director;
        setRating(rating);

       }

       void Movie::setRating(string aRating){
           
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

       string Movie::getRating(){
        return rating;
       }



//inheritence

    CartoonShows::CartoonShows(string title, string director, string rating, string TargetAgeGroup)
     : Movie(title, director, rating){
        this ->TargetAgeGroup = TargetAgeGroup;
     }


