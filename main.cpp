#include <iostream>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main(int, char **)
{
    json j{
        {"name", "Judd Trump"},
        {"credits", 1754500},
        {"ranking", 1}};

    std::cout << j << std::endl;

    j["name"] = "Ding Junhui"; //j.at("name") = "Ding Junhui";　　
    std::cout << j << std::endl;
}
