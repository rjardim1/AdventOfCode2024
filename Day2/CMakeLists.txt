# CMakeList.txt : CMake project for Day2, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Day2 "Day2.cpp" "Day2.h")

target_link_libraries(Day2 CommonLib)

# TODO: Add tests and install targets if needed.
