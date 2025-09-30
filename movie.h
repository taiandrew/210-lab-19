#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using namespace std;

class Movie {
    public:
        // Constructor
        Movie(string comment = "", double rating = 0.0) {this->comment = comment; this->rating = rating;}

        // Getters
        string getComment() const {return comment;}
        double getRating() const {return rating;}

        // Setters
        void setComment(string comment) {this->comment = comment;}
        void setRating(double rating) {this->rating = rating;}

    private:
        string comment;
        double rating;


};

#endif // MOVIE_H