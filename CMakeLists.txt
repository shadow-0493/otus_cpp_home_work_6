cmake_minimum_required(VERSION 3.15)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(proxy_matrix VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(proxy_matrix src/main.cpp)

if (MSVC)
    target_compile_options(proxy_matrix PRIVATE /W4)
else ()
    target_compile_options(proxy_matrix PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

install(TARGETS proxy_matrix RUNTIME DESTINATION bin)

include(CPack)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME "proxy_matrix")
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT "j.morzhov@reglab.ru")
set(CPACK_PACKAGE_DESCRIPTION "proxy_matrix (Homework 6)")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${PROJECT_VERSION}-Linux")
