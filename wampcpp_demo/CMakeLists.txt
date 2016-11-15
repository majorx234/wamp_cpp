cmake_minimum_required(VERSION 2.6)

project(wampcpp_demo)


find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(Jsoncpp REQUIRED)
find_package(websocketpp REQUIRED)
find_package( Threads REQUIRED)

SET(CMAKE_CXX_FLAGS "-std=c++11")
add_compile_options(-std=c++11)

set(WAMP_CPP_DEMO_SOURCEFILES 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/wampcpp_demo.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/DemoServer.cpp
  )
set(WAMP_CPP_DEMO_HEADERFILES 
  ${CMAKE_CURRENT_SOURCE_DIR}/include/DemoServer.h
  )

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(ALL_LIBS "")

include_directories(${PROJECT_INCLUDE_DIR})
include_directories(${WAMP_CPP_DIR})
include_directories(${Jsoncpp_INCLUDE_DIR})
include_directories(${WEBSOCKETPP_INCLUDE_DIR})
include_directories(${Boost_INCLUDE_DIR})

add_executable(wampcpp_demo 
  ${WAMP_CPP_DEMO_SOURCEFILES}
  ${WAMP_CPP_DEMO_HEADERFILES}
  )

target_link_libraries(wampcpp_demo 
                      ${Jsoncpp_LIBRARY}
                      ${websocketpp_LIBRARY} 
                      ${Boost_LIBRARIES}
                      ${WAMP_CPP_LIBRARY}
                      ${CMAKE_THREAD_LIBS_INIT}
                      )

# INSTALL(TARGETS wampcpp_demo
#	RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin)
