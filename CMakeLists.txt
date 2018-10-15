cmake_minimum_required(VERSION 2.6)
project("Words With Friends")
add_executable(wwf grid.cpp main.cpp permutation.cpp trie.cpp)
target_link_libraries(wwf SDL2 SDL2main SDL2_image SDL2_ttf)