project(liboai_cpp)

cmake_minimum_required (VERSION 3.10)
cmake_policy(SET CMP0054 NEW) # https://cmake.org/cmake/help/v3.10/policy/CMP0054.html


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
	endif()

if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
    add_compile_options(-O0 -ggdb3)
	else()
	    add_compile_options(-O3)
		endif()




#add_subdirectory(source)
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
						 FetchContent_MakeAvailable(cpr)

add_executable(${PROJECT_NAME}
    main.cpp
	request.cpp
	authorization.cpp
	response.cpp
	models.cpp
	    )

target_link_libraries(${PROJECT_NAME} PRIVATE cpr::cpr)

