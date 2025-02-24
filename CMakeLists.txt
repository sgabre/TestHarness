cmake_minimum_required(VERSION 3.15)

SET(APPLICATION_NAME Sample)

# set the project name and version
project(${APPLICATION_NAME} VERSION 1.0.0)




#set(TARGET_GROUP production CACHE STRING "Group to build")

add_subdirectory(Module)
add_subdirectory(Protocol)
add_subdirectory(Shell)

#if(TARGET_GROUP STREQUAL production)
#    add_subdirectory(Application)
#elseif(TARGET_GROUP STREQUAL test)
    include(CTest)

    add_subdirectory(external)
    add_subdirectory(UnitTesting)
#else()
#    message(FATAL_ERROR "Given TARGET_GROUP unknown")
#endif()
