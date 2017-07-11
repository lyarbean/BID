cmake_minimum_required (VERSION 3.2)
project (P)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -g -ggdb -Wall")
set(P_SRC dataframeprovider.cpp main.cpp)

add_executable(p ${P_SRC})
target_link_libraries(p -lmysqlcppconn)
