cmake_minimum_required(VERSION 3.25)

project(phh-tests)

# phh-is_test
add_executable(phh-is_test is_test.cc)
target_link_libraries(phh-is_test PRIVATE phh)

# phh-uuid_test
add_executable(phh-uuid_test uuid_test.cc)
target_link_libraries(phh-uuid_test PRIVATE phh)
