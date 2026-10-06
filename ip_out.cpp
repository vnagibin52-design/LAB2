#include <iostream>
#include <vector>
#include "ip_out.h"

int ip_out(std::vector<std::tuple<int, int, int, int>> list) {

    if (list.empty()) {
        return 1;
    }

    for (const auto& [item1, item2, item3, item4] : list) {
        std::cout << item1 << "." << item2 << "."<< item3 << "."<< item4 << "\n";
    }

    for (const auto& [item1, item2, item3, item4] : list) {
        if(item1 == 1){
            std::cout << item1 << "." << item2 << "."<< item3 << "."<< item4 << "\n";
        }
    }

    for (const auto& [item1, item2, item3, item4] : list) {
        if(item1 == 46 && item2 == 70){
            std::cout << item1 << "." << item2 << "."<< item3 << "."<< item4 << "\n";
        }
    }

    for (const auto& [item1, item2, item3, item4] : list) {
        if(item1 == 46 || item2 == 46 || item3 == 46 || item4 == 46){
            std::cout << item1 << "." << item2 << "."<< item3 << "."<< item4 << "\n";
        }
    }

    return 0;
}