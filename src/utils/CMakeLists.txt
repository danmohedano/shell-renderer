# Create CMAKE library
add_library(utils utils.cpp)

# Link any other libraries this depends on
#target_link_libraries(libb liba)

# Include src/ directory for correct includes
target_include_directories(utils PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/src" )