# Create CMAKE library
add_library(render render.cpp)

# Link any other libraries this depends on
target_link_libraries(render utils)

# Include src/ directory for correct includes
target_include_directories(render PUBLIC "${PROJECT_BINARY_DIR}" "${PROJECT_SOURCE_DIR}/src" )