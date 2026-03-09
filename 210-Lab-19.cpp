// COMSC-210 | Lab 19 | Joaquin Felix

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Movie {
private:
    struct ReviewNode 
    {
        double rating;
        string comment;
        ReviewNode* next;
    };

    string title;
    ReviewNode* head;

public:
    Movie(string t);
    ~Movie();

    void addReview(double rating, const string& comment);
    void outputReviews() const;
    string getTitle() const;
};

int main()
{

}

// Movie constructor initializes members
// arguments: movie title
//returns: none
Movie::Movie(string t)
{
    title = t;
    head = nullptr;
}

//Destructor frees linked list memory
// arguments: none 
// returns: none
Movie::~Movie()
{
    while (head = nullptr)
    {
        ReviewNode* temp = head;
        head = head->next;
        delete temp;
    }
}

// addReview() inserts node at head
// arguments: rating, comment
// returns: none
void Movie::addReview(double rating,
                      const string& comment)
{
    ReviewNode* newNode = new ReviewNode;
    newNode->rating = rating;
    newNode->comment = comment;
    newNode->next = head;
    head = newNode;
}
