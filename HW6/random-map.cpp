/*random-map.cpp
Nathan Damon
CS 201
4/04/2020
This program will 
*/

#include <iostream>
using std::cin;
using std::cout;
#include <iomanip>
#include <string>
#include <map>
#include <random>
using std::random_device;
#include <cmath>


int RandomBetweenU
(int first,
 int last,
 random_device& r);

int main()
{
    // Seed with a real random value, if available
    random_device r;

    int first;
    cout << "First: ";
    cin >> first;
    
    int last;
    cout << "Last: ";
    cin >> last;

    int mean = RandomBetweenU(first, last, r);


    // Generate a normal distribution around that mean
    std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
    std::mt19937 e2(seed2);
    std::normal_distribution<> normal_dist(mean, 2);

    std::map<int, int> hist;
    for (int n = 0; n < 10000; ++n) {
        ++hist[std::round(normal_dist(e2))];
    }
    cout << "Normal distribution around " << mean << ":\n";
    for (auto p : hist) {
        cout << std::fixed << std::setprecision(1) << std::setw(2)
            << p.first << ' ' << std::string(p.second / 200, '*') << '\n';
    }
}

// Chooses a random mean between first and last
int RandomBetweenU
(int first, 
 int last, 
 random_device& r)
{
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(first, last);
    int mean = uniform_dist(e1);
    std::cout << "Randomly-chosen mean: " << mean << '\n';
    return mean;
}