add_executable(test_parameters
        test_parameters.cpp
)

target_link_libraries(test_parameters
        uc
)

add_test("param_cmd_type_text" test_parameters 0 unicodeConverter -t atech "ação")
add_test("param_cmd_wrong_name" test_parameters 1 test)
add_test("param_cmd_without_param" test_parameters 1 unicodeConverter )
add_test("param_cmd_without_text" test_parameters 1 unicodeConverter -t atech)
add_test("param_cmd_without_type" test_parameters 1 unicodeConverter "ação")
