# cmake needs this line
cmake_minimum_required(VERSION 3.1)

# Define project name
project(ellipseDetection)

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
# set(OpenCV_DIR )
find_package(OpenCV 4.5.5 REQUIRED)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../dist)
SET(CMAKE_BUILD_TYPE "Debug")

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
# message(STATUS sus)
if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif(UNIX AND NOT APPLE)
if(LINUX)
    # message(STATUS Linux)
    include_directories(/home/wu/codes/libELSDc/install/include)
    LINK_DIRECTORIES(/home/wu/codes/libELSDc/install/lib)
endif(LINUX)
if(APPLE)
    message(STATUS Apple)
    include_directories(/Users/zihanwu/codes/libELSDc/install/include)
    LINK_DIRECTORIES(/Users/zihanwu/codes/libELSDc/install/lib)
endif(APPLE)

# message(STATUS ${CMAKE_SYSTEM_NAME})
# message(STATUS ${LDFLAGS})

# Declare the executable target built from your sources
add_executable(${PROJECT_NAME} main.cpp Find_arcs.cpp Debug.cpp)
add_compile_options(-Wwritable-strings)
# Link your application with OpenCV libraries
target_link_libraries(${PROJECT_NAME} PRIVATE ${OpenCV_LIBS} JointArc)


