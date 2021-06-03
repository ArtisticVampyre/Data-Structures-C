cmake_minimum_required(VERSION 3.17)
project(OpenProjects C)

set(CMAKE_C_STANDARD 99)

add_executable(OpenProjects main.c DoubleLinkedList/list.h Stack/stack.h Shared/Structures/node.h Shared/Actions/display.h Shared/Actions/assert_plus.h Queue/queue.h)