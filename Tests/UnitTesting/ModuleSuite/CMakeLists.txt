#/TestHarness/UnitTesting/ModuleSuite/CMakeLists.txt

ADD_EXECUTABLE(ModuleFunctionSuiteRunner Module_Function_Suite.c)
TARGET_LINK_LIBRARIES(ModuleFunctionSuiteRunner Module Unity)
ADD_TEST(Module_Function_Suite ModuleFunctionSuiteRunner)






