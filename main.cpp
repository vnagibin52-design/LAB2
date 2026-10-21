#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <cstdint>
#include <algorithm>
#include "ip_out.h"
#include "isRightTuple.h"

int main(int argc, char* argv[]) {

    try {

        if (argc < 2) {
            std::cerr << "Need path to file!" << std::endl;
            return 1;
        }

        std::string filePath = argv[1];

        std::ifstream file(filePath);
        
        if (!file.is_open()) {
            std::cerr << "No such file!" << std::endl;
            return 1;
        }

        std::vector<std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>> list_of_tuples;


        std::string line;

        std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> myTuple;

        while (std::getline(file, line, '.')) {
            
            std::get<0>(myTuple) = std::stoi(line);

            for (int i = 1; i <= 3; i++){

                std::getline(file, line, '.');

                switch (i)
                {
                case 1:
                    std::get<1>(myTuple) = std::stoi(line);
                    break;

                case 2:
                    std::get<2>(myTuple) = std::stoi(line);
                    break;

                case 3:
                    std::get<3>(myTuple) = std::stoi(line);
                    break;

                default:
                    break;
                }
            }

            list_of_tuples.push_back(myTuple);
        
            std::getline(file, line);
        }

        if(isRightTuple(list_of_tuples) == false){
            std::cerr << "Wrong data in vector!" << std::endl;
            return 1;
        }

        file.close(); // Закрываем файл

        std::sort(list_of_tuples.begin(), list_of_tuples.end(), [](const auto& a, const auto& b) {
        if (std::get<0>(a) != std::get<0>(b)) {
            return std::get<0>(a) > std::get<0>(b); 
        }
        else if (std::get<1>(a) != std::get<1>(b)) {
            return std::get<1>(a) > std::get<1>(b); 
        }
        else if (std::get<2>(a) != std::get<2>(b)) {
            return std::get<2>(a) > std::get<2>(b); 
        }
        else return std::get<3>(a) > std::get<3>(b); 
        });

        ip_out(list_of_tuples);

        return 0;
    }

    catch (const std::exception& e) {
        std::cerr << "Критическая ошибка: " << e.what() << std::endl;
        return 1;
    }
}
