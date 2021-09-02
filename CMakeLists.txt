cmake_minimum_required(VERSION 3.15.0)
project(ljson VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ljson main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include(FetchContent)           # 引入FetchContent模块
FetchContent_Declare(
  json
  GIT_REPOSITORY  git@github.com:ArthurSonzogni/nlohmann_json_cmake_fetchcontent.git
  GIT_TAG         v3.10.2       # 指定版本
  GIT_SHALLOW     TRUE          # 不拉取完整历史
)

FetchContent_GetProperties(json)
if(NOT json_POPULATED)          # 变量json_POPULATED被FetchContent_Populate设置，防止重复拉取
  FetchContent_Populate(json)   # 拉取代码，同时设置一些变量信息
  add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()

target_link_libraries(ljson PRIVATE nlohmann_json::nlohmann_json)
