cmake_minimum_required(VERSION 2.6)

project(wamp_cpp)


find_package(Jsoncpp REQUIRED)
find_package(websocketpp REQUIRED)
find_package(Boost COMPONENTS system filesystem REQUIRED)

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(ALL_LIBS "")

include_directories(${PROJECT_INCLUDE_DIR})
include_directories(${Jsoncpp_INCLUDE_DIR})
include_directories(${WEBSOCKETPP_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIR})

SET(CMAKE_CXX_FLAGS "-std=c++11")
add_compile_options(-std=c++11)

set(INSTALL_INCLUDE_DIR include CACHE PATH "Installation directory for header files")
set (DEF_INSTALL_CMAKE_DIR lib/cmake/wamp_cpp)
set (INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACHE PATH "Installation directory for CMake files")

set(WAMP_CPP_SOURCFILES 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Directory.cpp  
  ${CMAKE_CURRENT_SOURCE_DIR}/src/EventManager.cpp  
  ${CMAKE_CURRENT_SOURCE_DIR}/src/MessageHandler.cpp  
  ${CMAKE_CURRENT_SOURCE_DIR}/src/Topic.cpp  
  ${CMAKE_CURRENT_SOURCE_DIR}/src/WAMPServer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/JsonConvert.cpp
)

set(WAMP_CPP_HEADERFILES
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Directory.h  
  ${CMAKE_CURRENT_SOURCE_DIR}/include/EventManager.h  
  ${CMAKE_CURRENT_SOURCE_DIR}/include/MessageHandler.h  
  ${CMAKE_CURRENT_SOURCE_DIR}/include/RPCallable.h  
  ${CMAKE_CURRENT_SOURCE_DIR}/include/Topic.h  
  ${CMAKE_CURRENT_SOURCE_DIR}/include/WAMPServer.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/JsonConvert.h
)

add_library(wamp_cpp 
             ${WAMP_CPP_SOURCFILES}
             )

target_link_libraries(wamp_cpp 
                      ${websocketpp_LIBRARY} 
                      ${JSONCPP_LIBRARIES}
                      ${Boost_LIBRARIES}                   
                      )

export(PACKAGE wamp_cpp)

set(WAMP_CPP_HEADERS ${PROJECT_INCLUDE_DIR} PARENT_SCOPE)
set(WAMP_CPP_LIBRARY wamp_cpp PARENT_SCOPE)

configure_file (wamp_cpp-config.cmake.in "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/wamp_cpp-config.cmake" @ONLY)

install (FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/wamp_cpp-config.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)


