cmake_minimum_required(VERSION 3.10)
project(financialMarketSimulator)

set(CMAKE_CXX_STANDARD 20)


find_package(CURL REQUIRED)


include_directories(${CURL_INCLUDE_DIRS})

add_executable(financialMarketSimulator
        main.cpp
        cppFiles/stock.cpp
        headerFiles/stock.h
        headerFiles/market.h
        cppFiles/market.cpp
)

target_link_libraries(financialMarketSimulator ${CURL_LIBRARIES})
