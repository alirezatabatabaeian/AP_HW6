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
struct Patient {
    std::string name;
    size_t age;
    size_t smokes;
    size_t area_q;
    size_t alkhol;
};
//----------------------------------------------------------------------------//
static std::vector<Patient> read_file(std::string filename)
{
    std::vector<Patient> patients {};
    Patient patient {};
    std::stringstream temp {};
    std::ifstream file(filename);
    std::stringstream buffer {};
    buffer << file.rdbuf();
    std::string text { buffer.str() };
    std::regex pattern(R"((\w+)\s?,(\w+)\s?,(\d+),(\d+),(\d+),(\d+))");
    std::smatch match;

    while (std::regex_search(text, match, pattern)) {
        patient.name = match[1];
        patient.name.append(" ");
        patient.name.append(match[2]);
        temp << match[3];
        temp >> patient.age;
        temp.clear();
        temp << match[4];
        temp >> patient.smokes;
        temp.clear();
        temp << match[5];
        temp >> patient.area_q;
        temp.clear();
        temp << match[6];
        temp >> patient.alkhol;
        temp.clear();
        patients.push_back(patient);
        text = match.suffix().str();
    }

    return patients;
};
//----------------------------------------------------------------------------//
static void sort(std::vector<Patient>& patients)
{
    std::sort(patients.begin(), patients.end(),
        [](const Patient& patient1,
            const Patient& patient2) { return (3 * patient1.age + 5 * patient1.smokes + 2 * patient1.area_q + 4 * patient1.alkhol)
                                           > (3 * patient2.age + 5 * patient2.smokes + 2 * patient2.area_q + 4 * patient2.alkhol); });
};
}

#endif // Q2_H