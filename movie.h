#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using namespace std;

// Each instance of a Movie has the title and a linked list of reviews

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

        // Destructor
        ~Movie() {
            ReviewNode* curr = head;
            while (curr) {
                ReviewNode* tmp = curr;
                curr = curr->next;
                delete tmp;
            }
        }

        // Getters
        string getTitle() const { return title; }
        ReviewNode* getReviews() const { return head; }
        
        // Setters
        void setTitle(const string& title) { this->title = title; }
        void setHead(ReviewNode* head) { this->head = head; }

    private:
        string title;       // Movie title
        ReviewNode* head;   // Ptr to linked list of reviews

};

#endif