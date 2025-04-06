#/TestHarness/UnitTesting/ModuleSuite/CMakeLists.txt

# Find all unit test source files ending with _Suite.c
file(GLOB SUITE_SOURCES *_Suite.c)

# Loop over each test source and create a runner
foreach(SUITE_FILE ${SUITE_SOURCES})
    # Get the file name without extension and path
    get_filename_component(SUITE_NAME ${SUITE_FILE} NAME_WE)

    # Get the parent directory of the test suite file
   # get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} NAME)

    # Extract the first part of the directory name (e.g., 'ShellSuite' -> 'Shell')
   # string(REGEX REPLACE "(.*Suite)" "\\1" MODULE_NAME ${PARENT_DIR})

   # message(STATUS "MODULE_NAME: ${PARENT_DIR},  ${MODULE_NAME}")


    # Create executable
    add_executable(${SUITE_NAME} ${SUITE_FILE})

    # Link with your test dependencies
    target_link_libraries(${SUITE_NAME} PRIVATE Shell Unity)

    # Link the module dynamically (e.g., 'ShellLib', 'ModuleALib') and Unity
   # target_link_libraries(${SUITE_NAME} PRIVATE ${MODULE_NAME} Unity)



    # Register test with CTest
    add_test(NAME ${SUITE_NAME} COMMAND ${SUITE_NAME})

    # Optional: install it under bin/tests
    install(TARGETS ${SUITE_NAME} RUNTIME DESTINATION bin/tests)
endforeach()


