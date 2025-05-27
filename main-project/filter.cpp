#include "filter.h"
#include <cstring>
#include <iostream>

lecture_subscription** filter(lecture_subscription* array[], int size, bool (*check)(lecture_subscription* element), int& result_size)
{
	lecture_subscription** result = new lecture_subscription * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_lecture_subscription_by_author(lecture_subscription* element)
{
	return element->author.first_name == "Иван" &&
		element->author.middle_name == "Иванович" &&
		element->author.last_name == "Иванов";
}

bool check_book_subscription_by_period(lecture_subscription* element)
{
	return  element->start.hours > 0 || element->start.minutes >= 15;
}
