cmake_minimum_required(VERSION 3.10)
project(EmailProject)

set(CMAKE_CXX_STANDARD 11)

# Заголовочные файлы
include_directories(include)

# Исходные файлы
set(SOURCES
    src/email.cpp
    src/verifiedemail.cpp
    main.cpp
)

# Создаем исполняемый файл
add_executable(email_app ${SOURCES})
