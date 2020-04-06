/*random-map.cpp
Nathan Damon
CS 201
4/04/2020
This program will generate random numbers and their histograms
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
#include <string>
#include <map>
using std::map;
#include <random>
using std::random_device;
using std::mt19937;
#include <cmath>
#include <stdlib.h>


int RandomBetweenU(
    const int& first,
    const int& last,
    random_device& r);

int RandomBetweenN(
    const int& first,
    const int& last,
    const int& mean,
    mt19937& e2);

int RandomBetween(
    const int& first,
    const int& last);

void PrintDistribution(
    const map<int, int>& numbers,
    const int& star);

int main()
{
    // Seed with a real random value, if available
    random_device r;

    std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
    mt19937 e2(seed2);

    std::srand(std::time(nullptr));

    int first;
    cout << "First: ";
    cin >> first;
    
    int last;
    cout << "Last: ";
    cin >> last;

    while ((last - first) < 4)
    {
        cout << "The difference between first and last needs to be at least 4." << endl;
        cout << "Last: ";
        cin >> last;
    }


    int mean = (first + last) / 2;
    int star = (1000/(last - first));

    map<int, int> hist1;
    for (int n = 0; n < 10000; ++n) {
        ++hist1[std::round(RandomBetweenU(first, last, r))];
    }
    map<int, int> hist2;
    for (int n = 0; n < 10000; ++n) {
        ++hist2[std::round(1 + RandomBetweenN(first, last, mean, e2))];
    }
    map<int, int> hist3;
    for (int n = 0; n < 10000; ++n) {
        ++hist3[std::round(RandomBetween(first, last))];
    }


    cout << "Uniform distribution between " << first << " and " << last << ":\n";
    PrintDistribution(hist1, star);
    cout << "Normal distribution around " << mean << ":\n";
    PrintDistribution(hist2, star);
    cout << "Random distribution between " << first << " and " << last << ":\n";
    PrintDistribution(hist3, star);

    cin >> last;
}



// Returns a uniform random number between first and last
int RandomBetweenU(
    const int& first,
    const int& last, 
    random_device& r)
{
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(first, last);
    return uniform_dist(e1);
}



// Returns a normally distributed random number between first and last
int RandomBetweenN(
    const int& first,
    const int& last,
    const int& mean,
    mt19937& e2)
{ 
    // Spreads out the numbers around the mean
    std::normal_distribution<> normal_dist(mean, ((last - first) / 4)); 
    return normal_dist(e2);
}



// Returns a random number between first and last using rand() varies with time
int RandomBetween(
    const int& first,
    const int& last)
{
    int random_number = first + (rand() % (last - first + 1));
    return random_number;
}



// Prints a list of the random numbers showing normal or uniform distribution
void PrintDistribution(
    const map<int, int>& numbers,
    const int& star)
{
    for (auto p : numbers) {
    cout << std::fixed << std::setprecision(1) << std::setw(2)
        // Replaced the 200 with a variable that changes with the difference between first and last.
         << p.first << ' ' << std::string(p.second / star, '*') << '\n';
    }
}