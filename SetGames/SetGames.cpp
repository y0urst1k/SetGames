#include <iostream>
#include "Modules/The Hero's Way/THW.h"

using std::cin;
using std::cout;

void PrintMenu()
{
    WriteSeparator(50);
    cout << "Во что поиграем?" << endl
        << "1.The Hero's Way" << endl
        << "0.Хочу выйти";
    WriteSeparator(50);
    cout << "Ваш выбор: ";
}

int main()
{
    int choice = -1;

    while (true)
    {
        PrintMenu();
        cin >> choice;
        if (choice == 0)
        {
            cout << "До свидания!" << endl;
            break;
        }
        switch (choice)
        {
        case 0:
            Episode1();
            break;
        default:
            cout << "Упс! Игра не найдена, повторите попытку" << endl;
            break;
        }
    }
}