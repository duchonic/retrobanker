cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)

set(DCMAKE_CXX_FLAGS="-Werror -Wall -Wextra")

project(Sandbox VERSION 1.0.0)

include_directories(
  .
  /Library/Frameworks/SDL2.framework/Headers/*
)


add_executable(Sandbox src/main.cpp)

target_link_libraries(
  Sandbox PRIVATE
  /Library/Frameworks/SDL2.framework/Versions/A/SDL2
  /Library/Frameworks/SDL2_image.framework/Versions/A/SDL2_image
  /Library/Frameworks/SDL2_ttf.framework/Versions/A/SDL2_ttf
)

target_include_directories(
  Sandbox PRIVATE
  /Library/Frameworks/SDL2.framework/Versions/A/Headers
  /Library/Frameworks/SDL2_image.framework/Versions/A/Headers
  /Library/Frameworks/SDL2_ttf.framework/Versions/A/Headers
)