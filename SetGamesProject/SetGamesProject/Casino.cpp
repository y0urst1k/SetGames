#include "casino.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

void showSlotRules() {
    cout << "\n=== ПРАВИЛА СЛОТ-МАШИНЫ ===" << endl;
    cout << "1. Из каждого барабана выбирается случайный символ" << endl;
    cout << "2. Если все три символа совпадут - ВЫ ВЫИГРАЛИ!" << endl;
    cout << "3. Коэффициенты выигрыша:" << endl;
    cout << "   V - Вишня (x2), L - Лимон (x2), O - Апельсин (x2)" << endl;
    cout << "   * - Звезда (x3), B - Колокол (x5), 7 - Семерка (x10)" << endl;
    cout << "4. Додеп можно использовать только 1 раз за сессию" << endl;
}

void playSlotMachine() {
    srand(time(0));

    int bet = 10;
    bool hasUsedDodep = false;

    vector<string> symbols = { "V", "L", "O", "*", "B", "7" };
    vector<string> symbolNames = { "Вишня", "Лимон", "Апельсин", "Звезда", "Колокол", "Семерка" };

    vector<vector<string>> reels(3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            int randomIndex = rand() % symbols.size();
            reels[i].push_back(symbols[randomIndex]);
        }
    }

    int choice;
    int localBalance = 150;

    cout << "\n*** ДОБРО ПОЖАЛОВАТЬ В СЛОТ-МАШИНЫ! ***" << endl;
    cout << "Ваш баланс: $" << localBalance << endl;

    do {
        cout << "\n=== СЛОТ-МАШИНА ===" << endl;
        cout << "Баланс: $" << localBalance << " | Ставка: $" << bet << endl;
        cout << "1. Крутить барабаны" << endl;
        cout << "2. Изменить ставку" << endl;
        cout << "3. Правила игры" << endl;
        cout << "4. Сделать додеп (+200$)" << endl;
        cout << "0. Выйти в главное меню" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            if (localBalance < bet) {
                cout << "Недостаточно средств для ставки!" << endl;
                break;
            }

            localBalance -= bet;
            vector<string> result;

            cout << "\n=== ВРАЩЕНИЕ ===" << endl;

            for (int i = 0; i < 3; i++) {
                int randomPosition = rand() % 6;
                string selectedSymbol = reels[i][randomPosition];
                result.push_back(selectedSymbol);

                string symbolName = "";
                for (int j = 0; j < symbols.size(); j++) {
                    if (symbols[j] == selectedSymbol) {
                        symbolName = symbolNames[j];
                        break;
                    }
                }

                cout << "Барабан " << (i + 1) << ": " << selectedSymbol
                    << "(" << symbolName << ")" << endl;
            }

            cout << "Результат: ";
            for (const auto& symbol : result) {
                cout << symbol << " ";
            }
            cout << endl;

            if (result[0] == result[1] && result[1] == result[2]) {
                int winAmount = 0;
                string symbol = result[0];

                if (symbol == "7") winAmount = bet * 10;
                else if (symbol == "B") winAmount = bet * 5;
                else if (symbol == "*") winAmount = bet * 3;
                else if (symbol == "O") winAmount = bet * 2;
                else if (symbol == "L") winAmount = bet * 2;
                else if (symbol == "V") winAmount = bet * 2;

                cout << "*** ДЖЕКПОТ! Все символы совпали! ***" << endl;
                cout << "Выигрыш: $" << winAmount << endl;
                localBalance += winAmount;
            }
            else {
                cout << "К сожалению, вы не выиграли. Попробуйте еще раз!" << endl;
            }
        }
        break;

        case 2:
        {
            int newBet;
            cout << "Текущая ставка: $" << bet << endl;
            cout << "Введите новую ставку: ";
            cin >> newBet;
            if (newBet > 0 && newBet <= localBalance) {
                bet = newBet;
                cout << "Ставка изменена на: $" << bet << endl;
            }
            else {
                cout << "Недопустимая ставка!" << endl;
            }
        }
        break;

        case 3:
            showSlotRules();
            break;

        case 4:
            if (hasUsedDodep) {
                cout << "Вы уже использовали додеп! Больше нельзя." << endl;
            }
            else {
                int variant;
                cout << "Заложить квартиру и получить 200$?" << endl;
                cout << "1 - Да, 0 - Нет: ";
                cin >> variant;
                if (variant == 1) {
                    localBalance += 200;
                    hasUsedDodep = true;
                    cout << "*** ДОДЕП ВЫПОЛНЕН! ***" << endl;
                    cout << "Ваш баланс теперь: $" << localBalance << endl;
                }
                else {
                    cout << "Зря....." << endl;
                }
            }
            break;

        case 0:
            cout << "Выходим из слот-машины..." << endl;
            break;

        default:
            cout << "Неверный выбор!" << endl;
        }

        if (localBalance <= 0 && choice != 0) {
            cout << "\n=== БАЛАНС ИСЧЕРПАН! ===" << endl;

            if (!hasUsedDodep) {
                int dodepChoice;
                cout << "Хотите сделать додеп и получить 200$?" << endl;
                cout << "1 - Да, 0 - Нет (выйти из игры): ";
                cin >> dodepChoice;

                if (dodepChoice == 1) {
                    localBalance += 200;
                    hasUsedDodep = true;
                    cout << "Додеп выполнен! Баланс: $" << localBalance << endl;
                }
                else {
                    cout << "Игра окончена! Возвращаемся в меню..." << endl;
                    break;
                }
            }
            else {
                cout << "А все. Квартиры уже нет. Ты всё проиграл(а)!" << endl;
                break;
            }
        }

    } while (choice != 0);

    cout << "Ваш итоговый баланс: $" << localBalance << endl;
}