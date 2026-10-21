#include <iostream>
#include <vector>
#include <cstdint>
#include <string>
#include "isRightTuple.h"

bool isRightTuple(std::string& line) {

    if (line.empty()) {
        return false;
    }

    if (std::stoi(line) >= 0 && std::stoi(line) <= 255)
        return true;
    else
        return false;
}