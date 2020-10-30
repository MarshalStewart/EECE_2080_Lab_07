cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#add_library (applibrary Zerg.cpp ShipFactory.cpp IRace.cpp Iship.cpp)

add_library (racelibrary Races/NAZI.cpp Races/SPQR.cpp Races/USA.cpp Races/USSR.cpp)
#add_library (classlibrary ship.cpp)


# Link runTests with what we want to test and the GTest and pthread library
add_executable(Run/runTests tests.cpp)
target_link_libraries(Run/runTests ${GTEST_LIBRARIES} pthread racelibrary classlibrary) 

add_executable(Run/runMain Main.cpp)
target_link_libraries(Run/runMain racelibrary classlibrary)

