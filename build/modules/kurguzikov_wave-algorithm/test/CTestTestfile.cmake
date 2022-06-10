# CMake generated Testfile for 
# Source directory: C:/Users/usero/Desktop/DevTools/devtools-course-practice/modules/kurguzikov_wave-algorithm/test
# Build directory: C:/Users/usero/Desktop/DevTools/devtools-course-practice/build/modules/kurguzikov_wave-algorithm/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(kurguzikov_wave-algorithm_gtest "C:/Users/usero/Desktop/DevTools/devtools-course-practice/build/bin/test_kurguzikov_wave-algorithm.exe")
  set_tests_properties(kurguzikov_wave-algorithm_gtest PROPERTIES  LABELS "kurguzikov_wave-algorithm" _BACKTRACE_TRIPLES "C:/Users/usero/Desktop/DevTools/devtools-course-practice/modules/kurguzikov_wave-algorithm/test/CMakeLists.txt;22;add_test;C:/Users/usero/Desktop/DevTools/devtools-course-practice/modules/kurguzikov_wave-algorithm/test/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(kurguzikov_wave-algorithm_gtest "C:/Users/usero/Desktop/DevTools/devtools-course-practice/build/bin/test_kurguzikov_wave-algorithm.exe")
  set_tests_properties(kurguzikov_wave-algorithm_gtest PROPERTIES  LABELS "kurguzikov_wave-algorithm" _BACKTRACE_TRIPLES "C:/Users/usero/Desktop/DevTools/devtools-course-practice/modules/kurguzikov_wave-algorithm/test/CMakeLists.txt;22;add_test;C:/Users/usero/Desktop/DevTools/devtools-course-practice/modules/kurguzikov_wave-algorithm/test/CMakeLists.txt;0;")
else()
  add_test(kurguzikov_wave-algorithm_gtest NOT_AVAILABLE)
endif()
