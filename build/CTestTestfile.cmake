# CMake generated Testfile for 
# Source directory: /home/emartini/Documenti/Heap
# Build directory: /home/emartini/Documenti/Heap/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(IntHeapMax "./heap_test" "[IntHeapMax]")
set_tests_properties(IntHeapMax PROPERTIES  WORKING_DIRECTORY "/home/emartini/Documenti/Heap/build")
add_test(FloatHeapTestMax "./heap_test" "[FloatHeapTestMax]")
set_tests_properties(FloatHeapTestMax PROPERTIES  WORKING_DIRECTORY "/home/emartini/Documenti/Heap/build")
add_test(DoubleHeapTestMax "./heap_test" "[DoubleHeapTestMax]")
set_tests_properties(DoubleHeapTestMax PROPERTIES  WORKING_DIRECTORY "/home/emartini/Documenti/Heap/build")
add_test(IntHeapTestMin "./heap_test" "[IntHeapTestMin]")
set_tests_properties(IntHeapTestMin PROPERTIES  WORKING_DIRECTORY "/home/emartini/Documenti/Heap/build")
