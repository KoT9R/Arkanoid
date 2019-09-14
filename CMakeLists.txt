cmake_minimum_required(VERSION 3.14)
project(KursWork)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(KursWork main.cpp Ball.cpp Ball.h Racket.cpp Racket.h Constants.h Engine.cpp Engine.h Block.cpp Block.h Rectangle.h Bonus.cpp Bonus.h)

target_link_libraries(KursWork sfml-graphics sfml-audio)
