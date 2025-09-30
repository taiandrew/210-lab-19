// COMSC 210 | Lab 19 | Sept 29 2025
// IDE: VS Code

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "movie.h"

using namespace std;


// Fn prototypes
Movie readReviews(string title, string filename);

// Main
int main() {

    // Initialize movie vector
    vector<Movie> movies;

    // Read reviews
    movies.push_back(readReviews("movie1", "movie1.txt"));

    return 0;
}

// Programmer fns
Movie readReviews(string title, string filename) {

    // Open file
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error opening file " << filename << endl;
        return Movie("");
    }

    // Read reviews into linked list
    srand(time(0));
    ReviewNode* head = nullptr;
    string comment;

    while (getline(fin, comment)) {
        double rating = (rand() % 51) / 10.0;       // Random rating 0.0 - 5.0
        ReviewNode* newNode = new ReviewNode{rating, comment, nullptr};
        if (!head) {        // If first node, make head
            head = newNode;
        } else {             // Else, insert at front
            newNode->next = head;
            head = newNode;
        }
    }

    return Movie(title, head);
}
