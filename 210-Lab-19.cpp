// COMSC-210 | Lab 19 | Joaquin Felix

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const string REVIEW_FILE = "reviews.txt";
const int NUM_MOVIES = 4;
const int REVIEWS_PER_MOVIE = 3;
const int MIN_RANDOM = 10; // 1.0
const int MAX_RANDOM = 50; // 5.0

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

// Function Prototypes
double generateRandomRating();
vector<string>loadCommentsFromFile();

int main()
{
    srand(static_cast<unsigned>(time(0)));

    vector<string> comments = loadCommentsFromFile();

    if (comments.size() < NUM_MOVIES * REVIEWS_PER_MOVIE)
    {
        cout << "ERROR: Not enough comments in file.\n";
        return 1;
    }

    vector<Movie> movies;

    movies.push_back(Movie("Inception"));
    movies.push_back(Movie("The Matrix"));
    movies.push_back(Movie("Interstellar"));
    movies.push_back(Movie("The Godfather"));

    int commentIndex = 0;

    for (int i = 0; i < NUM_MOVIES; i++)
    {
        for (int j = 0; j < REVIEWS_PER_MOVIE; j++)
        {
            double rating = generateRandomRating();
            movies[i].addReview(rating, comments[commentIndex]);
            commentIndex++;
        }
    }

    for (int i = 0; i < NUM_MOVIES; i++)
    {
        movies[i].outputReviews();
    }
    
    return 0;
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
    while (head != nullptr)
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

//outputReviews() prints movie and reviews
//arguments: none
// returns: none
void Movie::outputReviews() const
{
    cout << "\nMovie: " << title << endl;

    const ReviewNode* temp = head;
    double sum = 0.0;
    int count = 0;

    while (temp != nullptr)
    {
        cout << " Rating: "
             << temp->rating
             << " | Comment: "
             << temp->comment << endl;

        sum += temp->rating;
        count++;
        temp = temp->next;
    }

    if (count > 0)
    {
        cout << " Average Rating: "
             << sum / count << endl;
    }
}

// getTitle() returns movie title
// arguments: none
// returns: string title
string Movie::getTitle() const
{
    return title;
}

// generateRandomRating() returns 1.0-5.0
// arguments: none
// returns: random double (1 decimal place)
double generateRandomRating()
{
    int randomValue = rand() %
        (MAX_RANDOM - MIN_RANDOM + 1)
        + MIN_RANDOM;
    return randomValue / 10.0;
}

// loadCommentsFromFile() reads comments
// arguments: none
// returns: vector of strings
vector<string> loadCommentsFromFile()
{
    vector<string> comments;
    ifstream infile(REVIEW_FILE);

    if (!infile)
    {
        cout << "ERROR: could not open"
             << REVIEW_FILE << endl;
        return comments;
    }

    string line;

    while (getline(infile, line))
    {
        comments.push_back(line);
    }

    infile.close();
    return comments;
}