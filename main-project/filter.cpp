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
	return strcmp(element->author.first_name, "Иван") == 0 &&
		strcmp(element->author.middle_name, "Иванович") == 0 &&
		strcmp(element->author.last_name, "Иванов") == 0;

}

bool check_lecture_subscription_by_period(lecture_subscription* element)
{
	return  (element ->finish.hours - element->start.hours > 0) || (element -> finish.minutes - element->start.minutes > 15);
}
