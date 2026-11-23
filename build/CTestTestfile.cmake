# CMake generated Testfile for 
# Source directory: C:/web/OOP/lab2
# Build directory: C:/web/OOP/lab2/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(StringTests "C:/web/OOP/lab2/build/Debug/lab2_tests.exe")
  set_tests_properties(StringTests PROPERTIES  _BACKTRACE_TRIPLES "C:/web/OOP/lab2/CMakeLists.txt;63;add_test;C:/web/OOP/lab2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(StringTests "C:/web/OOP/lab2/build/Release/lab2_tests.exe")
  set_tests_properties(StringTests PROPERTIES  _BACKTRACE_TRIPLES "C:/web/OOP/lab2/CMakeLists.txt;63;add_test;C:/web/OOP/lab2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(StringTests "C:/web/OOP/lab2/build/MinSizeRel/lab2_tests.exe")
  set_tests_properties(StringTests PROPERTIES  _BACKTRACE_TRIPLES "C:/web/OOP/lab2/CMakeLists.txt;63;add_test;C:/web/OOP/lab2/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(StringTests "C:/web/OOP/lab2/build/RelWithDebInfo/lab2_tests.exe")
  set_tests_properties(StringTests PROPERTIES  _BACKTRACE_TRIPLES "C:/web/OOP/lab2/CMakeLists.txt;63;add_test;C:/web/OOP/lab2/CMakeLists.txt;0;")
else()
  add_test(StringTests NOT_AVAILABLE)
endif()
subdirs("_deps/googletest-build")
