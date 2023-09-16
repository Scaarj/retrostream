add_executable(
    ${CLIENT_TESTS_PROJECT_NAME}
    main.cpp
)

target_link_libraries(
    ${CLIENT_TESTS_PROJECT_NAME}
    gtest_main
    gmock_main
)

set_target_properties(
    ${CLIENT_TESTS_PROJECT_NAME}
    PROPERTIES
    LINK_FLAGS "-lgcov --coverage"
)

add_test(
    NAME ${CLIENT_TESTS_PROJECT_NAME}
    COMMAND ${CLIENT_TESTS_PROJECT_NAME}
)
