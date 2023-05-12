cmake_minimum_required(VERSION 3.25)
project(c_call_java)

set(CMAKE_CXX_STANDARD 17)

find_package(JNI REQUIRED)

# java
include_directories(/home/xuda/env/jdk1.8.0_202//jre/lib/amd64/server/ /home/xuda/env/jdk1.8.0_202/include /home/xuda/env/jdk1.8.0_202/include/linux)

add_executable(c_call_java main.cpp)

target_link_libraries(c_call_java ${JNI_LIBRARIES})

