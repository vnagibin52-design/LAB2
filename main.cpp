#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <algorithm>

int main() {
    std::ifstream file("ip_filter.tsv"); // Открываем файл для чтения
    
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return 1;
    }

    std::vector<std::tuple<int, int, int, int>> list_of_tuples;


    std::string line;

    std::tuple<int, int, int, int> myTuple;

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

    for (const auto& [item1, item2, item3, item4] : list_of_tuples) {
        std::cout << item1 << "." << item2 << "."<< item3 << "."<< item4 << "\n";
    }

    std::cout << "\n" << "NEXT" << "\n" << "\n";

    for (const auto& [item1, item2, item3, item4] : list_of_tuples) {
        if(item1 == 1){
            std::cout << item1 << "." << item2 << "."<< item3 << "."<< item4 << "\n";
        }
    }

    std::cout << "\n" << "NEXT" << "\n" << "\n";

    for (const auto& [item1, item2, item3, item4] : list_of_tuples) {
        if(item1 == 46 && item2 == 70){
            std::cout << item1 << "." << item2 << "."<< item3 << "."<< item4 << "\n";
        }
    }

    std::cout << "\n" << "NEXT" << "\n" << "\n";

    for (const auto& [item1, item2, item3, item4] : list_of_tuples) {
        if(item1 == 46 || item2 == 46 || item3 == 46 || item4 == 46){
            std::cout << item1 << "." << item2 << "."<< item3 << "."<< item4 << "\n";
        }
    }


    system("pause");

    return 0;
}