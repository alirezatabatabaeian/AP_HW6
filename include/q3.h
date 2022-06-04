#ifndef Q3_H
#define Q3_H
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

namespace q3 {
//----------------------------------------------------------------------------//
struct Flight {
    std::string flight_number;
    size_t duration;
    size_t connections;
    size_t connection_times;
    size_t price;
};
//----------------------------------------------------------------------------//
static std::priority_queue<Flight> gather_flights(std::string filename)
{
    std::priority_queue<Flight> flights {};
    Flight flight {};
    std::stringstream temp {};
    std::ifstream file(filename);
    std::stringstream buffer {};
    buffer << file.rdbuf();
    std::string text { buffer.str() };
    std::regex pattern(R"(\d+-\s\w+:(\w+)\s-\s\w+:(\d*)h?(\d*)m?\s-\s\w+:(\d)+\s-\s\w+:(\d*)h?(\d*)m?,?(\d*)h?(\d*)m?,?(\d*)h?(\d*)m?,?(\d*)h?(\d*)m?\s-\s\w+:(\d+))");
    std::smatch match;

    while (std::regex_search(text, match, pattern)) {
        // std::cout << match[0] << std::endl; // make comment
        flight.flight_number = match[1];
        // patient.name.append(" ");
        // patient.name.append(match[2]);
        // temp << match[3];
        // temp >> patient.age;
        // temp.clear();
        // temp << match[4];
        // temp >> patient.smokes;
        // temp.clear();
        // temp << match[5];
        // temp >> patient.area_q;
        // temp.clear();
        // temp << match[6];
        // temp >> patient.alkhol;
        // temp.clear();
        // patients.push_back(patient); //change
        text = match.suffix().str();
    }

    return flights;
};
//----------------------------------------------------------------------------//
}

#endif // Q3_H