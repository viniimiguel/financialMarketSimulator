cmake_minimum_required(VERSION 3.30)
project(financialMarketSimulator)

set(CMAKE_CXX_STANDARD 26)

add_executable(financialMarketSimulator main.cpp
        cppFiles/stock.cpp
        headerFiles/stock.h
        headerFiles/market.h
        cppFiles/market.cpp
)
