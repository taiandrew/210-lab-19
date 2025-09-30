// COMSC 210 | Lab 19 | Sept 29 2025
// IDE: VS Code

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "movie.h"

using namespace std;


// Fn prototypes
Movie readReviews(string filename);

// Main
int main() {

    // Initialize movie vector
    vector<Movie> movies;


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
        double rating = (rand() % 51) / 10.0;
        ReviewNode* newNode = new ReviewNode{rating, comment, nullptr};
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

}
