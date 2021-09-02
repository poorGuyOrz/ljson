#include <iostream>
#include <fstream> 

#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main(int, char **) {
  json j{{"name", "Judd Trump"}, {"credits", 1754500}, {"ranking", 1}};

  json j1 = R"(
    {
    "name": "Judd Trump",
    "credits": 1754500,
    "ranking": 1
    }
  )"_json;

  auto s = R"(
    {
      "name": "Judd Trump",
      "credits": 1754500,
      "ranking": 1
    }
  )";

  json j3;

  std::ifstream("../rankings.json") >> j3;

  std::cout << "j3: " << j3 << std::endl;

  auto j2 = json::parse(s);

  std::cout << j2.dump() << std::endl;

  std::cout << j1.dump() << std::endl;

  std::cout << j1 << std::endl;

  j["name"] = "Ding Junhui";  // j.at("name") = "Ding Junhui";　　
  std::cout << j << std::endl;
}
