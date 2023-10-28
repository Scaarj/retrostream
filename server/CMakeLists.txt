project(server LANGUAGES CXX)

set(SERVER_SOURCES
    src/GamesRepository.cpp
    src/Database.cpp
    src/drivers/DatabaseDriver.cpp
    src/drivers/MemoryDriver.cpp
    src/data/Author.cpp
    src/data/Base.cpp
    src/data/Game.cpp
    src/data/Id.cpp
    src/http/HttpServer.cpp
)

set(SERVER_HEADERS
    src/AbstractRepository.h
    src/Database.h
    src/drivers/DatabaseDriver.h
    src/drivers/Driver.h
    src/drivers/MemoryDriver.h
    src/GamesRepository.h
    src/data/Author.h
    src/data/Base.h
    src/data/Game.h
    src/data/Id.h
    src/http/HttpServer.h
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
