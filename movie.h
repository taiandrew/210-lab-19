#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using namespace std;

struct ReviewNode{
    double rating;
    string comment;
    ReviewNode* next;
};

class Movie {
    public:
        // Constructor
        Movie(string title, ReviewNode* head = nullptr) {
            this->title = title;
            this->head = head;
        }

        // Getters
        string getTitle() const { return title; }
        string getReviews() const {
            string reviews;
            ReviewNode* current = head;
            while (current != nullptr) {
                reviews += "Rating: " + to_string(current->rating) + ", Comment: " + current->comment + "\n";
                current = current->next;
            }
            return reviews;
        }
        
        // Setters
        void setComment(string comment) { this->comment = comment; }
        void setRating(double rating) { this->rating = rating; }

    private:
        string title;       // Movie title
        ReviewNode* head;   // Ptr to linked list of reviews


};

#endif