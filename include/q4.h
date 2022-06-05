#ifndef Q4_H
#define Q4_H
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

namespace q4 {
//----------------------------------------------------------------------------//
struct Vector2D { // vector 2D
    Vector2D() // default constructor
        : x { 0 }
        , y { 0 } {};
    Vector2D(double _x, double _y) // main constructor
        : x { _x }
        , y { _y } {};
    Vector2D(const Vector2D& _pos) // copy constructor
        : x { _pos.x }
        , y { _pos.y } {};
    double x {};
    double y {};
};
//----------------------------------------------------------------------------//
struct Sensor { // sensor class
    Sensor(const Vector2D& _pos, double _accuracy) // main constructor
        : pos { _pos }
        , accuracy { _accuracy } {};
    Vector2D pos;
    double accuracy;
};
//----------------------------------------------------------------------------//
static Vector2D kalman_filter(std::vector<Sensor> sensors)
{
    Vector2D final_pos {};
    double sum_weight {};

    auto func { // lambda function for elements in vector
        [&final_pos, &sum_weight](const Sensor& sensor) {
            final_pos.x += sensor.pos.x * sensor.accuracy;
            final_pos.y += sensor.pos.y * sensor.accuracy;
            sum_weight += sensor.accuracy;
        }
    };

    std::for_each(sensors.begin(), sensors.end(), func); // automatic for

    final_pos.x = final_pos.x / sum_weight; // normalization
    final_pos.y = final_pos.y / sum_weight; // normalization

    return final_pos;
}
//----------------------------------------------------------------------------//
}
#endif // Q4_H