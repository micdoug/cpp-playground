#include <iostream>
#include <stdexcept>
#include "tour_cpp/chapter2/vector.h"

using std::cin;
using std::cout;
using std::endl;
using tcpp::Vector;

double read_and_sum(int number)
{
    // read number integers from cin and return their sum;
    // number is assumed to be positive
    Vector vector;

    for (int i = 0; i < number; i++)
    {
        cout << "Type a number: ";
        int new_number;
        cin >> new_number;
        vector.push_back(new_number);
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
    tcpp::Vector v1 {1, 2, 3};
    std::cout << v1 << std::endl;

    double sum = read_and_sum(3);
    cout << "The sum is " << sum << endl;

    Vector vec{3};
    try
    {
        vec[4];
    }
    catch (std::out_of_range &ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}