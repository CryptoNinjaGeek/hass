set(CMAKE_CXX_STANDARD 20)

FetchContent_Declare(
        cpr
        GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 1.10.1
)

FetchContent_Declare(
        jsoncons
        GIT_REPOSITORY https://github.com/danielaparker/jsoncons.git
        GIT_TAG v0.170.0
)

FetchContent_Declare(
        zutano
        GIT_REPOSITORY https://github.com/CryptoNinjaGeek/zutano.git
        GIT_TAG origin/main
)

FetchContent_MakeAvailable(zutano)
FetchContent_MakeAvailable(cpr)
FetchContent_MakeAvailable(jsoncons)

add_library(hass SHARED
        include/hass/Exceptions.h
        include/hass/Controller.h
        include/hass/drivers/DockerController.h
        include/hass/drivers/ArangoGraphController.h
        src/Controller.cpp
        src/DockerController.cpp
        include/hass/Tools.h)

target_link_libraries(hass PRIVATE
        cpr::cpr
        zutano
        )

target_link_libraries(hass PUBLIC
        jsoncons
        )

target_include_directories(hass PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
        )
