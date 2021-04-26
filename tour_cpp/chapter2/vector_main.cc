#include <iostream>
#include "tour_cpp/chapter2/vector.h"

using std::cin;
using std::cout;
using std::endl;
using tcpp::Vector;

double read_and_sum(int number)
{
    // read number integers from cin and return their sum;
    // number is assumed to be positive
    Vector vector{number};

    for (int i = 0; i < number; i++)
    {
        cout << "Type a number: ";
        cin >> vector[i];
    }

    double sum = 0;
    for (int i = 0; i < number; i++)
    {
        sum += vector[i];
    }
    return sum;
}

int main()
{
    double sum = read_and_sum(3);
    cout << "The sum is " << sum << endl;
    return 0;
}