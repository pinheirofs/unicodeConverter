add_executable(test_parameters
        test_parameters.cpp
)

target_link_libraries(test_parameters
        uc
)

add_test("param_cmd_type_text" test_parameters 0 test_parameters -t atech "ação")
add_test("param_cmd_wrong_name" test_parameters 1 test)
add_test("param_cmd_without_text" test_parameters 1 test_parameters)
