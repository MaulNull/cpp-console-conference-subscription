#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

period convert(char* str)
{
    period result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.hours = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.minutes = atoi(str_number);
    
    return result;
}

void read(const char* file_name, lecture_subscription* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            lecture_subscription* item = new lecture_subscription;
            file >> tmp_buffer;
            item->start = convert(tmp_buffer);
            file >> tmp_buffer;
            item->finish = convert(tmp_buffer);
            file >> item->author.last_name;
            file >> item->author.first_name;
            file >> item->author.middle_name;
            file.read(tmp_buffer, 1); // ������ ������� ������� �������
            file.getline(item->title, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "������ �������� �����";
    }
}