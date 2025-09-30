// COMSC 210 | Lab 19 | Sept 29 2025
// IDE: VS Code

#include <iostream>
#include <string>

using namespace std;

// Structure for a review node in a linked list
struct reviewNode {
    float rating;
    string comment;
    reviewNode* next;
};

// Fn prototypes
void addReviewHead(reviewNode*& head, float rating, const string& comment);
void addReviewTail(reviewNode*& head, float rating, const string& comment);
void displayReviews(const reviewNode* head);
void deleteList(reviewNode*& head);

// Main
int main() {

    // Initialize linked list
    reviewNode* head = nullptr;

    // User choice of add method
    int choice;
    cout << "Which linked list method do you want to use?\n";
    cout << "   1. Add to head\n";
    cout << "   2. Add to tail\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();

    // User input
    float rating;
    string comment;
    char cont = 'Y';

    while (cont == 'Y' || cont == 'y') {
        cout << "\nEnter rating (0-5): ";
        cin >> rating;
        cin.ignore();

        cout << "Enter comment: ";
        getline(cin, comment);

        if (choice == 1) {
            addReviewHead(head, rating, comment);
        } else {
            addReviewTail(head, rating, comment);
        }

        cout << "Enter another review? Y/N: ";
        cin >> cont;
        cin.ignore();
    }

    // Display all reviews
    displayReviews(head);

    // Free memory
    deleteList(head);

    return 0;
}

// Programmer functions

void addReviewHead(reviewNode*& head, float rating, const string& comment) {
    // Adds node at the head of the linked list
    // args: ptr to head, data for new node

    reviewNode* newnode = new reviewNode{rating, comment, head};        // Create new node
    head = newnode;     // Update head to new node
}

void addReviewTail(reviewNode*& head, float rating, const string& comment) {
    // Adds node at the tail of the linked list
    // args: ptr to head, data for new node

    reviewNode* newnode = new reviewNode{rating, comment, nullptr};

    if (head==nullptr) {    // List is empty; put this at the head
        head = newnode;
    } else {                // Traverse to the end; put it there
        reviewNode* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = newnode;
    }
}

void displayReviews(const reviewNode* head) {
    // Displays all reviews in the linked list & average rating
    // arg: ptr to head

    int ctr = 1;
    float total = 0.0;
    const reviewNode* curr = head;  // Start at head; don't modify any node

    // Traverse list and print data; compute avg rating
    while (curr) {
        cout << "Review #" << ctr << ": ";
        cout << curr->rating << " : " << curr->comment << endl;
        ctr++;
        total += curr->rating;
        curr = curr->next;

    }
    cout << "Average rating: " << (total / ctr) << endl;
}

void deleteList(reviewNode*& head) {
    // Deletes all nodes in the linked list to free memory
    // arg: ptr to head

    while (head) {
        reviewNode* next = head->next;
        delete head;
        head = next;
    }
}