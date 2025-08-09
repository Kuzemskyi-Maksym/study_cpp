cmake_minimum_required(VERSION 3.20)
project(oop LANGUAGES CXX)

# Встановлення стандарту C++20 уніфікованим способом
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Додаткові опції для MSVC/Clang
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

# Специфічні налаштування для clang-cl
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang" AND MSVC)
    add_compile_options(
        /Zc:__cplusplus
        /permissive-
    )
endif()

# Додаємо виконуваний файл (заголовки не потрібно явно вказувати)
add_executable(ITVDN_study 
    cpp/main.cpp     "include/Car.h" "cpp/Car.cpp")

# Вказуємо шляхи до заголовкових файлів
target_include_directories(ITVDN_study PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)