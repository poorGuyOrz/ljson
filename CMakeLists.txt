cmake_minimum_required(VERSION 3.0.0)
project(ljson VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ljson main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include(FetchContent)

FetchContent_Declare(json
  GIT_REPOSITORY git@github.com:ArthurSonzogni/nlohmann_json_cmake_fetchcontent.git
  GIT_TAG v3.10.2)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)
  FetchContent_Populate(json)
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

target_link_libraries(ljson PRIVATE nlohmann_json::nlohmann_json)
