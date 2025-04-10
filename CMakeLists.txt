cmake_minimum_required(VERSION 3.10)
project(financialMarketSimulator)

set(CMAKE_CXX_STANDARD 20)


find_package(CURL REQUIRED)


include_directories(${CURL_INCLUDE_DIRS})

add_executable(financialMarketSimulator
        main.cpp
        cppFiles/stock.cpp
        headerFiles/stock.h
        headerFiles/util.h
        cppFiles/util.cpp
        cppFiles/stocks.cpp
        headerFiles/events.h
        cppFiles/events.cpp
        headerFiles/cripto.h
        cppFiles/criptos.cpp
        cppFiles/cripto.cpp
        groqIa/groq.cpp
        groqIa/groq.h
)

target_link_libraries(financialMarketSimulator ${CURL_LIBRARIES})
