cmake_minimum_required(VERSION 3.7)
project(MPI_Unemployed_morons)

set(CMAKE_CXX_STANDARD 14)

find_package(MPI REQUIRED)

include_directories(${MPI_INCLUDE_PATH})
include_directories(src/libs)

add_executable(run src/main.cpp src/domain/AgentOnQueue.h src/domain/Company.cpp src/domain/Company.h src/domain/Message.h src/domain/Configuration.h src/libs/json.hpp src/domain/Configuration.cpp src/domain/Agent.cpp src/domain/Agent.h src/include/Json.h src/domain/Companies.cpp src/domain/Companies.h src/MPIUtils/Messanger.cpp src/MPIUtils/Messanger.h)
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
