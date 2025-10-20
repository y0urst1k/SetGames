#include <iostream>
#include "THW.h"

using std::cin;
using std::cout;
using std::endl;

void PrintMenu()
{
    WriteSeparator(50);
    cout << "Во что поиграем?" << endl
        << "1.The Hero's Way" << endl
        << "0.Хочу выйти"<< endl;
    WriteSeparator(50);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int choice = -1;

    while (true)
    {
        PrintMenu();
        cin >> choice;

        WriteSeparator(50);

        if (choice == 0)
        {
            cout << "До свидания!" << endl;
            break;
        }
        switch (choice)
        {
        case 1:
            Episode1();
            break;
        default:
            cout << "Упс! Игра не найдена, повторите попытку" << endl;
            break;
        }
    }
}