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


int RandomBetweenU(
    int first,
    int last,
    random_device& r);

int RandomBetweenN(
    const int& mean,
    mt19937& e2);

int main()
{
    // Seed with a real random value, if available
    random_device r;

    std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
    mt19937 e2(seed2);

    int first;
    cout << "First: ";
    cin >> first;
    
    int last;
    cout << "Last: ";
    cin >> last;

    int mean = first + ((last - first) / 2);

    cout << "U: " << RandomBetweenU(first, last, r); 
    cout << endl;
    cout << "N: " << RandomBetweenN(mean, e2);
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
        ++hist2[std::round(RandomBetweenN(mean, e2))];
    }
    cout << "Normal distribution around " << mean << ":\n";
    for (auto p : hist2) {
        cout << std::fixed << std::setprecision(1) << std::setw(2)
            << p.first << ' ' << std::string(p.second / 200, '*') << '\n';
    }

    cin >> last;
}



// Returns a uniform random number between first and last
int RandomBetweenU(
    int first, 
    int last, 
    random_device& r)
{
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(first, last);
    return uniform_dist(e1);
}



// Returns a normally distributed random number between first and last
int RandomBetweenN(
    const int& mean,
    mt19937& e2)
{ 
    std::normal_distribution<> normal_dist(mean, 2);
    return normal_dist(e2);
}
