cmake_minimum_required ( VERSION 3.1.0 )

project ( TE566_BookKeeper
  VERSION 3.0.0
  LANGUAGES CXX
)

# Set to c++11
set ( CMAKE_CXX_STANDARD 11 )

include_directories(src/)
set ( MAIN src/main.cpp )

add_executable(bookkeeper ${MAIN})


add_custom_target(run
    COMMAND bookkeeper
    DEPENDS bookkeeper
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
)