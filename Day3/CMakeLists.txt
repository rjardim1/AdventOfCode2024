# CMakeList.txt : CMake project for Day3, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Day3 "Day3.cpp" "Day3.h")

target_link_libraries(Day3 CommonLib)

# TODO: Add tests and install targets if needed.
