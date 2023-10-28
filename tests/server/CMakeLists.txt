add_executable(
    ${SERVER_TESTS_PROJECT_NAME}
    main.cpp
    GamesRepositoryTest.cpp
    HttpServerTest.cpp
)

target_link_libraries(
    ${SERVER_TESTS_PROJECT_NAME}
    gtest_main
    gmock_main
    ${SERVER_LIBRARY}
    ${QT_DEPENDIES}
)

set_target_properties(
    ${SERVER_TESTS_PROJECT_NAME}
    PROPERTIES
    LINK_FLAGS "-lgcov --coverage"
)

add_test(
    NAME ${SERVER_TESTS_PROJECT_NAME}
    COMMAND ${SERVER_TESTS_PROJECT_NAME}
)
