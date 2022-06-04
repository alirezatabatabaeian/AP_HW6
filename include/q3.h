#ifndef Q3_H
#define Q3_H
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <regex>
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
static auto gather_flights(std::string filename)
{
    auto function { [](const Flight& flight1, const Flight& flight2) { return (flight1.duration + flight1.connection_times + 3 * flight1.price)
                                                                           > (flight2.duration + flight2.connection_times + 3 * flight2.price); } };
    std::priority_queue<Flight, std::vector<Flight>, decltype(function)> flights { function };
    Flight flight {};
    std::stringstream temp {};
    size_t min {};
    size_t hour {};
    std::ifstream file(filename);
    std::stringstream buffer {};
    buffer << file.rdbuf();
    std::string text { buffer.str() };
    std::regex pattern(R"(\d+-\s\w+:(\w+)\s-\s\w+:(\d*)h?(\d*)m?\s-\s\w+:(\d)+\s-\s\w+:(\d*)h?(\d*)m?,?(\d*)h?(\d*)m?,?(\d*)h?(\d*)m?,?(\d*)h?(\d*)m?\s-\s\w+:(\d+))");
    std::smatch match;

    while (std::regex_search(text, match, pattern)) {
        flight = {};
        min = {};
        hour = {};
        flight.flight_number = match[1];

        temp << match[2];
        temp >> flight.duration;
        flight.duration = flight.duration * 60;
        temp.clear();

        temp << match[3];
        temp >> min;
        flight.duration += min;
        temp.clear();
        min = {};

        temp << match[4];
        temp >> flight.connections;
        temp.clear();

        temp << match[5];
        temp >> flight.connection_times;
        flight.connection_times = flight.connection_times * 60;
        temp.clear();

        temp << match[6];
        temp >> min;
        flight.connection_times += min;
        temp.clear();
        min = {};

        temp << match[7];
        temp >> hour;
        flight.connection_times += hour * 60;
        temp.clear();
        hour = {};

        temp << match[8];
        temp >> min;
        flight.connection_times += min;
        temp.clear();
        min = {};

        temp << match[9];
        temp >> hour;
        flight.connection_times += hour * 60;
        temp.clear();
        hour = {};

        temp << match[10];
        temp >> min;
        flight.connection_times += min;
        temp.clear();
        min = {};

        temp << match[11];
        temp >> hour;
        flight.connection_times += hour * 60;
        temp.clear();
        hour = {};

        temp << match[12];
        temp >> min;
        flight.connection_times += min;
        temp.clear();
        min = {};

        temp << match[13];
        temp >> flight.price;
        temp.clear();

        flights.push(flight);

        text = match.suffix().str();
    }

    return flights;
};
//----------------------------------------------------------------------------//
}

#endif // Q3_H