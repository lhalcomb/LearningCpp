#include <iostream>
#include "movie.hpp"

int main(){
    // Create a new object of the class

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