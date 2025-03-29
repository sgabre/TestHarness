#/TestHarness/Firmware/CMakeLists.txt

if(NOT CMAKE_BUILD_TYPE STREQUAL UnitTesting)
    # Include the Version.cmake file
    include(${CMAKE_SOURCE_DIR}/.cmake/Version/git.cmake)
    
    # Now you can use the version information
    message(STATUS "CMAKE_PROJECT_NAME: ${CMAKE_PROJECT_NAME}")
    message(STATUS "CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
    message(STATUS "MAJOR_VERSION: ${PROJECT_VERSION_MAJOR}")
    message(STATUS "MINOR_VERSION: ${PROJECT_VERSION_MINOR}")
    message(STATUS "PATCH_VERSION: ${PROJECT_VERSION_PATCH}")
    message(STATUS "Git Revision: ${BUILD_GIT_REVISION}")
    message(STATUS "Build Date: ${BUILD_DATE}")
    message(STATUS "Install Prefix: ${CMAKE_INSTALL_PREFIX}")
    
    
    # Now, configure the info.h.in file to create info.h with actual values
    configure_file(${CMAKE_SOURCE_DIR}/.cmake/Version/Version.h.in ${CMAKE_BINARY_DIR}/Application/Version.h)
    include_directories(${CMAKE_BINARY_DIR}/Application)

    add_subdirectory(Application)
endif()

add_subdirectory(Module)
add_subdirectory(Shell)
