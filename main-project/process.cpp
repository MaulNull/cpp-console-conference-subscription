#include "processing.h"

int diff(period a, period b)
{
	int x = a.hours * 60 + a.minutes;
	int y = b.hours * 60 + b.minutes;
	return (x > y ? x - y : y - x);
}

int process(lecture_subscription* array[], int size)
{
	int max = diff(array[0]->start, array[0]->finish);
	for (int i = 1; i < size; i++)
	{
		int curr = diff(array[i]->start, array[i]->finish);
		if (curr > max)
		{
			max = curr;
		}
	}
	return max;
}
