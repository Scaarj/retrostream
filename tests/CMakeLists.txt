add_definitions(-DGTEST_LANGUAGE_CXX11)

include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        main
)

FetchContent_MakeAvailable(googletest)

enable_testing()

#add_subdirectory(client)
add_subdirectory(server)
