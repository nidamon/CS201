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

    int mean = (first + last) / 2;

    cout << "U: " << RandomBetweenU(first, last, r); 
    cout << endl;
    cout << "N: " << RandomBetweenN(first, last, mean, e2);
    cout << endl;
    cout << "R: " << RandomBetween(first, last);
    cout << endl;

    std::map<int, int> hist1;
    for (int n = 0; n < 10000; ++n) {
        ++hist1[std::round(RandomBetweenU(first, last, r))];
    }
    cout << "Uniform distribution between " << first << " and " << last << ":\n";
    for (auto p : hist1) {
        cout << std::fixed << std::setprecision(1) << std::setw(2)
            << p.first << ' ' << std::string(p.second / 200, '*') << '\n';
    }

    std::map<int, int> hist2;
    for (int n = 0; n < 10000; ++n) {
        ++hist2[std::round(RandomBetweenN(first, last, mean, e2))];
    }
    cout << "Normal distribution around " << mean << ":\n";
    for (auto p : hist2) {
        cout << std::fixed << std::setprecision(1) << std::setw(2)
            << p.first << ' ' << std::string(p.second / 200, '*') << '\n';
    }

    std::map<int, int> hist3;
    for (int n = 0; n < 10000; ++n) {
        ++hist3[std::round(RandomBetween(first, last))];
    }
    cout << "Random distribution between " << first << " and " << last << ":\n";
    for (auto p : hist3) {
        cout << std::fixed << std::setprecision(1) << std::setw(2)
            << p.first << ' ' << std::string(p.second / 200, '*') << '\n';
    }

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
    std::normal_distribution<> normal_dist(mean, ((last - first) / 4));
    return normal_dist(e2);
}



// Returns a random number between first and last using rand() varies with time
int RandomBetween(
    const int& first,
    const int& last)
{
    int random_number = first + (rand() % (last - first));
    return random_number;
}