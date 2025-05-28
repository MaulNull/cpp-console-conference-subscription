#include <iostream>
#include <iomanip>

using namespace std;

#include "lecture_subscription.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include "sort.h"
void output(lecture_subscription* subscription) {
    
        /********** ����� ������� **********/
        cout << "������...........: ";
        // ����� ������� ������
        cout << subscription->author.last_name << " ";
        // ����� ������ ����� ����� ������
        cout << subscription->author.first_name[0] << ". ";
        // ����� ������ ����� �������� ������
        cout << subscription->author.middle_name[0] << ".";
        cout << ", ";
        // ����� ��������
        cout << '"' << subscription->title << '"';
        cout << '\n';
        /********** ����� ������� ������ ������� **********/
        // ����� �����
        cout << "����� ������ �������.....: ";
        cout << setw(2) << setfill('0') << subscription->start.hours << setfill('0') << ':';
        // ����� �����
        cout << setw(2)  << subscription->start.minutes << setfill('0');
        cout << '\n';
        /********** ����� ������� ����� ������� **********/
        // ����� �����
        cout << "����� ����� �������...: ";
        cout << setw(2) << setfill('0') << subscription->finish.hours << setfill('0') << ':';
        // ����� �����
        cout << setw(2)  << subscription->finish.minutes << setfill('0');

        cout << '\n';
        cout << '\n';
    
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #4. GIT\n";
    cout << "Variant #2. Conference Subscription\n";
    cout << "Author: Vladislav Fedotov\n";
    cout << "Group: 24\n";
    lecture_subscription* subscriptions[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", subscriptions, size);
        
        
        int option = 1;
        int methodChoice=2;
        int criterionChoice=2;
        int filterChoice=2;
        bool (*check_function)(lecture_subscription*) = NULL;
        while (option != 2) {
            cout << "�������� �����\n"
                << "0 - ����������\n"
                << "1 - ����������\n"
                << "2 - ����������\n";
            cin >> option;
            switch (option) {
            case 0:
                cout << "�������� ��� ����������\n"
                    << "0 - ���������� �� ������\n"
                    << "1 - ���������� �� �������\n";
                cin >> filterChoice;
                break;
            case 1:
                cout << "�������� ��� ����������\n"
                    << "0 - ������������� ����������\n"
                    << "1 - ���������� ��������\n";
                cin >> methodChoice;
                cout << "�������� �������� ����������\n"
                    << "0 - �� �������� ������������ �������\n"
                    << "1 - �� ����������� ������� ������ �������\n";
                cin >> criterionChoice;
                break;
            case 2:
                
                break;
            default:
                option = 2;
                
            }
            switch (filterChoice) {
            case 0:
                check_function = check_lecture_subscription_by_author;
                break;
            case 1:
                check_function = check_lecture_subscription_by_period;
                break;
            default:
                check_function = NULL;
            }
            if (check_function)
            {
                int new_size;
                lecture_subscription** filtered = filter(subscriptions, size, check_function, new_size);
                for (int i = 0; i < new_size; i++)
                {
                    output(filtered[i]);
                }
                delete[] filtered;
            }
            if ((methodChoice == 0 || methodChoice == 1) && (criterionChoice == 0 || criterionChoice == 1)) {
                SortFunc sortFunc = sortMethods[methodChoice];
                CompareFunc cmpFunc = compareFuncs[criterionChoice];
                lecture_subscription* lectures = new lecture_subscription[size];
                for (int i = 0; i < size; i++) {
                    lectures[i] = *subscriptions[i];
                }
                sortFunc(lectures, size, cmpFunc);
                
                for (int i = 0;i < size;i++) {
                    
                    output(&lectures[i]);
                }
                delete lectures;
            }
            
            
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

    

    return 0;
}