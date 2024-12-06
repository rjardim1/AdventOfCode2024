# CMakeList.txt : CMake project for Day4, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Day4 "Day4.cpp" "Day4.h")

target_link_libraries(Day4 CommonLib)
# TODO: Add tests and install targets if needed.
