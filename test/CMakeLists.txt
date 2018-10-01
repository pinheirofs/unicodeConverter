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

add_executable(test_text_converter
    test_text_converter.cpp
)

target_link_libraries(test_text_converter
        uc
)

add_test("convert_text_ok" test_text_converter 0 atech "ação" "a@#231;@#227;o")
