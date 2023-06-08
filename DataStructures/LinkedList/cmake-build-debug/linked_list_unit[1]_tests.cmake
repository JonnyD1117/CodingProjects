add_test([=[HelloTest.BasicAssertions]=]  /home/indy/repos/CodingProjects/DataStructures/LinkedList/cmake-build-debug/linked_list_unit [==[--gtest_filter=HelloTest.BasicAssertions]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[HelloTest.BasicAssertions]=]  PROPERTIES WORKING_DIRECTORY /home/indy/repos/CodingProjects/DataStructures/LinkedList/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  linked_list_unit_TESTS HelloTest.BasicAssertions)
