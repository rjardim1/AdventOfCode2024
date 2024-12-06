# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#

set(CMAKE_CXX_STANDARD 20)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("AdventOfCode2024")

# Include sub-projects.
add_subdirectory ("Base")
add_subdirectory ("Day1")
add_subdirectory ("Day2")
add_subdirectory ("Day3")
add_subdirectory ("Day4")