cmake_minimum_required(VERSION 2.6)
project("Words With Friends")

add_executable(wwf
    wwf/src/grid.cpp
    wwf/src/main.cpp
    wwf/src/solution.cpp
    wwf/src/trie.cpp
)

target_include_directories(wwf PUBLIC wwf/include)
target_link_libraries(wwf SDL2 SDL2main)

add_executable(wwf_tests
    wwf/src/test.cpp
    wwf/src/grid.cpp
    wwf/src/solution.cpp
    wwf/src/trie.cpp
)

target_include_directories(wwf_tests PUBLIC wwf/include)
target_link_libraries(wwf_tests SDL2 SDL2main gtest)