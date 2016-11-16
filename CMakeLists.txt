cmake_minimum_required(VERSION 2.6)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

include(ExternalProject)

# set(WAMP_CPP_DIR         ${CMAKE_CURRENT_BINARY_DIR}/wamp_cpp")
# set(wamp_cpp_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/wamp_cpp")
# set(wamp_cpp_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/wamp_cpp")
# set(wamp_cpp_INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/wamp_cpp")
# set(wamp_cpp_CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${wamp_cpp_INSTALL_DIR})

# ExternalProject_Add(wamp_cpp
#   SOURCE_DIR ${wamp_cpp_SOURCE_DIR}
#   BINARY_DIR ${wamp_cpp_BINARY_DIR}
#   INSTALL_DIR ${wamp_cpp_INSTALL_DIR}
#   CMAKE_ARGS ${wamp_cpp_CMAKE_ARGS}
# )



# ExternalProject_Add(wampcpp_demo
#   DEPENDS wamp_cpp
#   SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/wampcpp_demo"
#   BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/wampcpp_demo"
#   INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/wampcpp_demo"
# )

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
add_subdirectory(wamp_cpp)
include_directories(${WAMP_CPP_HEADERS})
add_subdirectory(wampcpp_demo)