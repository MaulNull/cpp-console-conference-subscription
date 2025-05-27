#ifndef LECTURE_SUBSCRIPTION_H
#define LECTURE_SUBSCRIPTION_H

#include "constants.h"

struct time
{
    int hours;
    int minutes;
};

struct person
{
    char first_name[MAX_STRING_SIZE];
    char middle_name[MAX_STRING_SIZE];
    char last_name[MAX_STRING_SIZE];
};

struct lecture_subscription
{
    time start;
    time finish;
    person author;
    char title[MAX_STRING_SIZE];
};

#endif
