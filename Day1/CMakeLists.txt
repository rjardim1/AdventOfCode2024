﻿# CMakeList.txt : CMake project for Day1, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Day1 "Day1.cpp" "Day1.h")

target_link_libraries(Day1 CommonLib)

# TODO: Add tests and install targets if needed.
