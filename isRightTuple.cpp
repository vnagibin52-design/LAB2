#include <iostream>
#include <vector>
#include <cstdint>
#include "isRightTuple.h"

bool isRightTuple(std::vector<std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>>& list) {

    if (list.empty()) {
        return false;
    }
    int i = 0;

    for (const auto& [item1, item2, item3, item4] : list) {
        if (+item1 >=0 && +item1 <= 255 && +item2 >=0 && +item2 <= 255 && +item3 >=0 && +item3 <= 255 && +item4 >=0 && +item4 <= 255)
            i = i;
        else
            i++;
    }

    if (i == 0)
        return true;
    else
        return false;

}