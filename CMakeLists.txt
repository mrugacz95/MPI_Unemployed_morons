cmake_minimum_required(VERSION 3.7)
project(MPI_Unemployed_morons)

set(CMAKE_CXX_STANDARD 14)

find_package(MPI REQUIRED)

include_directories(${MPI_INCLUDE_PATH})

add_executable(run main.cpp AgentOnQueue.h Company.cpp Company.h Message.h Configuration.h json.hpp Configuration.cpp)
target_link_libraries(run ${MPI_LIBRARIES})

if(MPI_COMPILE_FLAGS)
    message("ASD")
    set_target_properties(run PROPERTIES
            COMPILE_FLAGS "MPI_COMPILE_FLAGS")
endif()

if(MPI_LINK_FLAGS)
    set_target_properties(run PROPERTIES
            LINK_FLAGS "${MPI_LINK_FLAGS}")
endif()
