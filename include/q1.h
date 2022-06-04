#ifndef Q1_H
#define Q1_H
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

namespace q1 {
template <typename T1, typename T2>
double gradient_descent(T1 initial_value, T1 step_size, T2 func = {})
{
    double X { initial_value };
    double temp { X + 0.1 };
    while (std::abs(X - temp) > 1e-8) {
        temp = X;
        X = X - step_size * ((func(X + 1e-8) - func(X)) / 1e-8);
    }
    return X;
}
}

#endif // Q1_H