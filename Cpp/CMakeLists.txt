# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
project ("Code")

#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set (CMAKE_CXX_STANDARD 17)


include(cmake/Core.cmake)
enable_testing() 


#add_custom_target(doc) # DEPENDS docProjA docProjB) Note: with CMake 3.X the DEPENDS would work

# Include Seminars.
add_subdirectory ("Intro")
add_subdirectory ("Classes")
add_subdirectory ("Containers")
add_subdirectory ("Streams")
add_subdirectory ("Templates")

# Tasks
add_subdirectory ("Point")
add_subdirectory ("PointArray")

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)