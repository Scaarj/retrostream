project(server LANGUAGES CXX)

set(SERVER_SOURCES
    src/GamesRepository.cpp
    src/Database.cpp
    src/drivers/DatabaseDriver.cpp
    src/drivers/MemoryDriver.cpp
    src/util/Author.cpp
    src/util/Base.cpp
    src/util/Game.cpp
    src/util/Id.cpp
)

set(SERVER_HEADERS
    src/AbstractRepository.h
    src/Database.h
    src/drivers/DatabaseDriver.h
    src/drivers/Driver.h
    src/drivers/MemoryDriver.h
    src/GamesRepository.h
    src/util/Author.h
    src/util/Base.h
    src/util/Game.h
    src/util/Id.h
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
