# CMake generated Testfile for 
# Source directory: /home/emartini/Documenti/Heap
# Build directory: /home/emartini/Documenti/Heap/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IntHeapTest "./heap_test" "[IntHeapTest]")
set_tests_properties(IntHeapTest PROPERTIES  WORKING_DIRECTORY "/home/emartini/Documenti/Heap/build")
add_test(FloatHeapTest "./heap_test" "[FloatHeapTest]")
set_tests_properties(FloatHeapTest PROPERTIES  WORKING_DIRECTORY "/home/emartini/Documenti/Heap/build")
add_test(DoubleHeapTest "./heap_test" "[DoubleHeapTest]")
set_tests_properties(DoubleHeapTest PROPERTIES  WORKING_DIRECTORY "/home/emartini/Documenti/Heap/build")
