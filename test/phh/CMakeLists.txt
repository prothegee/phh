# unit_test_string
add_executable(unit_test_string unit/unit_test_string.cc)
target_link_libraries(unit_test_string PRIVATE phh)

# unit_test_uuid
add_executable(unit_test_uuid unit/unit_test_uuid.cc)
target_link_libraries(unit_test_uuid PRIVATE phh)

# unit_test_buffer
add_executable(unit_test_buffer unit/unit_test_buffer.cc)
target_link_libraries(unit_test_buffer PRIVATE phh)


