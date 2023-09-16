project(server LANGUAGES CXX)

set(SERVER_SOURCES
    src/GamesRepository.cpp
    src/Util/Author.cpp
    src/Util/Game.cpp
    src/Util/Id.cpp
)

set(SERVER_HEADERS
    src/AbstractRepository.h
    src/GamesRepository.h
    src/Util/Author.h
    src/Util/Game.h
    src/Util/Id.h
)

add_library(
    ${SERVER_LIBRARY}
    STATIC
    ${SERVER_SOURCES}
)

target_link_libraries(
    ${SERVER_LIBRARY}
    PRIVATE
    ${QT_DEPENDIES}
)

add_executable(
    ${SERVER_PROJECT_NAME}
    src/main.cpp
    ${SERVER_HEADERS}
    ${SERVER_SOURCES}
)

target_link_libraries(
    ${SERVER_PROJECT_NAME}
    PRIVATE
    ${QT_DEPENDIES}
)

include(GNUInstallDirs)
install(
    TARGETS ${SERVER_PROJECT_NAME}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
