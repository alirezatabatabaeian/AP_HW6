#ifndef Q2_H
#define Q2_H
#include <cmath>
#include <fstream>
#include <iostream>
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
// std::vector<Patient> read_file(std::string filename)
void read_file(std::string filename)
{
    std::vector<Patient> patients {};
    std::ifstream file(filename);
    std::stringstream buffer {};
    buffer << file.rdbuf();
    std::string text { buffer.str() };
    // std::cout << text << std::endl;
    

    // return patients;
};
//----------------------------------------------------------------------------//
}

#endif // Q2_H