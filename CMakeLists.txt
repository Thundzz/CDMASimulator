cmake_minimum_required(VERSION 2.6)
project(CDMASimulator)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")

set(PROJECT_INCLUDE_DIR "include")

include_directories("${PROJECT_INCLUDE_DIR}")

file(GLOB_RECURSE source_files
       "src/*.c"
       "src/*.cpp"
       "src/*.hpp")   

add_executable(main ${source_files})
