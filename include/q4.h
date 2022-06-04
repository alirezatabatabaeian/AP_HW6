#ifndef Q4_H
#define Q4_H
#include <cmath>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

namespace q4 {
//----------------------------------------------------------------------------//
struct Vector2D {
    Vector2D()
        : x { 0 }
        , y { 0 } {};
    Vector2D(double _x, double _y)
        : x { _x }
        , y { _y } {};
    Vector2D(const Vector2D& _pos)
        : x { _pos.x }
        , y { _pos.y } {};
    double x {};
    double y {};
};
//----------------------------------------------------------------------------//
struct Sensor {
    Sensor(const Vector2D& _pos, double _accuracy)
        : pos { _pos }
        , accuracy { _accuracy } {};
    Vector2D pos;
    double accuracy;
};
//----------------------------------------------------------------------------//
static Vector2D kalman_filter(std::vector<Sensor> sensors)
{

    Vector2D final_pos {};
    return final_pos;
}
//----------------------------------------------------------------------------//
}
#endif // Q4_H