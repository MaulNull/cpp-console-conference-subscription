#include <iostream>
#include <iomanip>

using namespace std;

#include "lecture_subscription.h"
#include "file_reader.h"
#include "constants.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #4. GIT\n";
    cout << "Variant #2. Conference Subscription\n";
    cout << "Author: Vladislav Fedotov\n";

    lecture_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        cout << "***** ������� ����������� *****\n\n";
        for (int i = 0; i < size; i++)
        {
            /********** ����� ������� **********/
            cout << "������...........: ";
            // ����� ������� ������
            cout << subscriptions[i]->author.last_name << " ";
            // ����� ������ ����� ����� ������
            cout << subscriptions[i]->author.first_name[0] << ". ";
            // ����� ������ ����� �������� ������
            cout << subscriptions[i]->author.middle_name[0] << ".";
            cout << ", ";
            // ����� ��������
            cout << '"' << subscriptions[i]->title << '"';
            cout << '\n';
            /********** ����� ������� ������ ������� **********/
            // ����� �����
            cout << "����� ������ �������.....: ";
            cout << setw(4) << setfill('0') << subscriptions[i]->start.hours << ':';
            // ����� �����
            cout << setw(2) << setfill('0') << subscriptions[i]->start.minutes;
            cout << '\n';
            /********** ����� ������� ����� ������� **********/
            // ����� �����
            cout << "����� ����� �������...: ";
            cout << setw(4) << setfill('0') << subscriptions[i]->finish.hours << ':';
            // ����� �����
            cout << setw(2) << setfill('0') << subscriptions[i]->finish.minutes;
            
            cout << '\n';
            cout << '\n';
        }
        for (int i = 0; i < size; i++)
        {
            delete subscriptions[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }

    cout << "Group: 24\n";

    return 0;
}