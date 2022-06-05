#ifndef Q2_H
#define Q2_H
#include <cmath>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

namespace q2 {
//----------------------------------------------------------------------------//
struct Patient { // patient features
    std::string name;
    size_t age;
    size_t smokes;
    size_t area_q;
    size_t alkhol;
};
//----------------------------------------------------------------------------//
static std::vector<Patient> read_file(std::string filename) // read and search file
{
    std::vector<Patient> patients {};
    Patient patient {};
    std::stringstream temp {};
    std::ifstream file(filename); // read file
    std::stringstream buffer {};
    buffer << file.rdbuf();
    std::string text { buffer.str() };
    std::regex pattern(R"((\w+)\s?,(\w+)\s?,(\d+),(\d+),(\d+),(\d+))"); // regular expresion
    std::smatch match;

    while (std::regex_search(text, match, pattern)) { // search in text
        patient.name = match[1]; // first name
        patient.name.append(" ");
        patient.name.append(match[2]); // last name
        temp << match[3]; // age
        temp >> patient.age;
        temp.clear();
        temp << match[4]; // smoke
        temp >> patient.smokes;
        temp.clear();
        temp << match[5]; // area_q
        temp >> patient.area_q;
        temp.clear();
        temp << match[6]; // alkhol
        temp >> patient.alkhol;
        temp.clear();
        patients.push_back(patient); // add to vector
        text = match.suffix().str(); // modify text
    }

    return patients;
};
//----------------------------------------------------------------------------//
static void sort(std::vector<Patient>& patients) // sort patients
{
    auto func { [](const Patient& patient1, // lambda function for sorting
                    const Patient& patient2) { return (3 * patient1.age + 5 * patient1.smokes
                                                          + 2 * patient1.area_q + 4 * patient1.alkhol)
                                                   > (3 * patient2.age + 5 * patient2.smokes
                                                       + 2 * patient2.area_q + 4 * patient2.alkhol); } };

    std::sort(patients.begin(), patients.end(), func); // sort using STL
};
//----------------------------------------------------------------------------//
}

#endif // Q2_H