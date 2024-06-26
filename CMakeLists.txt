cmake_minimum_required(VERSION 3.12)
project(Ramen VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Option to build examples
option(BUILD_EXAMPLES "Build examples" ON)

# Add include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Create Ramen library
add_library(ramen STATIC ${SOURCES})

# Set include directories for the library
target_include_directories(ramen PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# If you're using any external libraries, link them here
# For example, if you're using Boost ASIO:
# find_package(Boost REQUIRED COMPONENTS system)
# target_link_libraries(ramen PUBLIC Boost::system)

# Build examples if the option is ON
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Install rules
install(TARGETS ramen
    EXPORT ramenTargets
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
    INCLUDES DESTINATION include
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT ramenTargets
    FILE RamenTargets.cmake
    NAMESPACE Ramen::
    DESTINATION lib/cmake/Ramen
)

# Create a ConfigVersion.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/RamenConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

# Configure the Config.cmake file
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/RamenConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/RamenConfig.cmake"
    INSTALL_DESTINATION lib/cmake/Ramen
)

# Install the Config.cmake and ConfigVersion.cmake files
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/RamenConfig.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/RamenConfigVersion.cmake"
    DESTINATION lib/cmake/Ramen
)

# Enable testing
enable_testing()
add_subdirectory(tests)