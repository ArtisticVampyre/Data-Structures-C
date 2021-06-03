//
// Created by Sergiu on 19/05/2021.
//

#ifndef OPENPROJECTS_ASSERT_PLUS_H
#define OPENPROJECTS_ASSERT_PLUS_H

#include "assert.h"
#include "stdbool.h"
#include "Queue/queue.h"

#define assert_isfull(xtype, x) is_ ## xtype ##_full(x)

#endif //OPENPROJECTS_ASSERT_PLUS_H
