//
// Created by Sergiu on 19/05/2021.
//

#ifndef OPENPROJECTS_DISPLAY_H
#define OPENPROJECTS_DISPLAY_H

#include <Windows.h>

void warn(char* warn_message){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf("WARN : %s",warn_message);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void error(char* warn_message){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf("ERROR : %s",warn_message);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

#endif //OPENPROJECTS_DISPLAY_H
