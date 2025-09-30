// COMSC 210 | Lab 19 | Sept 29 2025
// IDE: VS Code

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "movie.h"

using namespace std;


// Fn prototypes
Movie readReviews(string title, string filename);
void printReviews(const Movie& movie);

// Main
int main() {

    // Initialize movie vector
    vector<Movie> movies;

    // Read reviews
    srand(time(0));
    Movie movie1 = readReviews("movie1", "movie1.txt");
    movies.push_back(movie1);

    Movie movie2 = readReviews("movie2", "movie2.txt");
    movies.push_back(movie2);

    Movie movie3 = readReviews("movie3", "movie3.txt");
    movies.push_back(movie3);

    // Print
    for (const Movie& movie : movies) {
        printReviews(movie);
    }

    return 0;
}

// Programmer fns
Movie readReviews(string title, string filename) {
    // Reads text comments from file; generates random ratings; stores in a Movie instance
    // args: movie title, filename
    // returns: Movie instance

    // Open file
    ifstream fin(filename);
    if (!fin) {
        cerr << "Error opening file " << filename << endl;
        return Movie("");
    }

    // Read reviews into linked list of ReviewNodes
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

    fin.close();

    return Movie(title, head);
}

void printReviews(const Movie& movie) {
    // Prints all reviews for a movie
    // arg: Movie instance

    cout << "Reviews for " << movie.getTitle() << ":" << endl;
    ReviewNode* curr = movie.getReviews();
    while (curr) {
        cout << "Rating: " << curr->rating << " | Comment: " << curr->comment << endl;
        curr = curr->next;
    }
    cout << endl;
}