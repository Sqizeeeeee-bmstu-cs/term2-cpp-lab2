cmake_minimum_required(VERSION 3.10)
project(EmailProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Библиотека с реализацией Email и VerifiedEmail
add_library(email_library
    src/email.cpp
    src/verifiedemail.cpp
)

target_include_directories(email_library
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Демонстрационное приложение
add_executable(email_app
    main.cpp
)

target_link_libraries(email_app
    PRIVATE
        email_library
)
