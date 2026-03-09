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

