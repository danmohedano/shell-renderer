# CMAKE minimum version requirement
cmake_minimum_required(VERSION 3.10)

# Project definition
project(shell-renderer VERSION 1.0 LANGUAGES CXX)

# Set compilter flags
if (UNIX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

# Build all libraries (might need modifications for more complex libraries)
list(APPEND ALL_LIBS utils render)
foreach(l IN LISTS ALL_LIBS)
    add_library(${l} "${PROJECT_SOURCE_DIR}/src/${l}/${l}.cpp")
    target_include_directories(${l} PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/src")
endforeach()

# Link libraries to each other when necessary
target_link_libraries(render utils)

# Define libraries used by the executables 
list(APPEND EXE_LIBS utils render)
foreach(l IN LISTS EXE_LIBS)
    list(APPEND EXE_INCLUDES "${PROJECT_SOURCE_DIR}/src/${l}")
endforeach()

# Define executables and build them
list (APPEND EXES test cube luminance)
foreach(e IN LISTS EXES)
    add_executable("${e}.exe" "${PROJECT_SOURCE_DIR}/src/${e}.cpp")
    target_link_libraries("${e}.exe" ${EXE_LIBS})
    target_include_directories("${e}.exe" PUBLIC "${PROJECT_BINARY_DIR}" ${EXE_INCLUDES})
endforeach()



