#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int bingo[5][5], game = 0, razd = 0, bufrazd[75], var, oshib = 0, bv1, bv2;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 2 and j == 2)
            {
                bingo[i][j] = 0;
            }
            else
            {
                if (j == 0)
                {
                    bingo[i][j] = rand() % 15 + 1;
                }
                if (j == 1)
                {
                    bingo[i][j] = rand() % (30 - 16) + 16;
                }
                if (j == 2)
                {
                    bingo[i][j] = rand() % (45 - 31) + 31;
                }
                if (j == 3)
                {
                    bingo[i][j] = rand() % (60 - 46) + 46;

                }
                if (j == 4)
                {
                    bingo[i][j] = rand() % (75 - 61) + 61;
                }
            }
            for (int p = 0; p < 100000; p++)
            {
                for (int i1 = 0; i1 < 5; i1++)
                {
                    for (int j1 = 0; j1 < 5; j1++)
                    {
                        if ((bingo[i][j] == bingo[i1][j1]) and ((i != i1) or (j != j1)) and ((i != 2) and (j != 2) and (i1 != 2) and (j1 != 2)))
                        {
                            do
                            {
                                if (j == 0)
                                {
                                    bingo[i][0] = rand() % 15 + 1;
                                }

                                if (j == 1)
                                {
                                    bingo[i][1] = rand() % (30 - 16) + 16;
                                }

                                if (j == 2)
                                {
                                    bingo[i][2] = rand() % (45 - 31) + 31;
                                }

                                if (j == 3)
                                {
                                    bingo[i][3] = rand() % (60 - 46) + 46;
                                }

                                if (j == 4)
                                {
                                    bingo[i][4] = rand() % (75 - 61) + 61;
                                } while (bingo[i][j] == bingo[i1][j1]);

                            } while ((bingo[i][j] == bingo[i1][j1]) and ((i != i1) or (j != j1)) and ((i != 2) and (j != 2) and (i1 != 2) and (j1 != 2)));
                        }
                    }
                }
            }
        }
    }
    do
    {
        for (int i = 0; i < 5; i++)
        {
            if (i == 0)
            {
                cout << "   |----|---|----|---|----|---|----|---|----|" << "                       Количество текущих ошибок= " << oshib << endl;
                cout << setw(9) << "|  B |" << setw(9) << "|  I |" << setw(9) << "|  N |" << setw(9) << "|  G |" << setw(9) << "|  O |" << endl;
                cout << "   |----|---|----|---|----|---|----|---|----|" << endl;
                cout << "   |    |   |    |   |    |   |    |   |    |" << endl;
                cout << "   |----|---|----|---|----|---|----|---|----|" << endl;
            }
            for (int j = 0; j < 5; j++)
            {
                if (bingo[i][j] == 0)
                {
                    cout << setw(4) << "|" << setw(3) << "*" << setw(2) << "|";
                }
                else
                {
                    cout << setw(4) << "|" << setw(3) << bingo[i][j] << setw(2) << "|";
                }

            }
            cout << endl << "   |----|---|----|---|----|---|----|---|----|" << endl;
        }

        cout << "Нажмите для раздачи " << razd + 1 << endl;
        system("pause");
        bufrazd[razd] = rand() % 75 + 1;
        for (int p = 0; p < 100; p++)
        {
            for (int i = 0; i < 75; i++)
            {
                if ((bufrazd[razd] == bufrazd[i]) and (razd != i))
                {
                    do
                    {
                        bufrazd[razd] = rand() % 75 + 1;
                    } while ((bufrazd[razd] == bufrazd[i]) and (razd != i));
                }
            }
        }
        cout << "Число на раздаче= " << bufrazd[razd] << endl << "Это число есть на карточке?" << endl << "   1 - есть" << endl << "   2 - нет" << endl;
        do
        {
            cout << "";
            cin >> var;
            if (!var)
            {
                cout << "Неверный ввод, повторите попытку" << endl;
                cin.clear();
                cin.ignore(2147483647, '\n');
            }
        } while (!var);
        bv1 = 0;
        if (var == 1)
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (bufrazd[razd] == bingo[i][j])
                    {
                        bingo[i][j] = 0;
                        cout << "Вы правы, это число присутствует в билете" << endl;
                    }
                    else
                    {
                        bv1++;
                    }
                }
            }
            if (bv1 == 25)
            {
                oshib = oshib + 1;
                cout << "Вы ошиблись, этого числа тут нету" << endl;
            }
        }
        bv2 = 0;
        if (var == 2)
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (bufrazd[razd] == bingo[i][j])
                    {
                        oshib = oshib + 1;
                        cout << "Вы ошиблись, это число присутствует в билете" << endl;
                    }
                    else
                    {
                        bv2++;
                    }
                }
            }
            if (bv2 == 25)
            {
                cout << "Ага, его тут нету" << endl;
            }
        }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if ((bingo[i][0] == 0
                    and bingo[i][1] == 0
                    and bingo[i][2] == 0
                    and bingo[i][3] == 0
                    and bingo[i][4] == 0)
                    or
                    (bingo[0][j] == 0
                        and bingo[1][j] == 0
                        and bingo[2][j] == 0
                        and bingo[3][j] == 0
                        and bingo[4][j] == 0)
                    or
                    (bingo[0][0] == 0
                        and bingo[1][1] == 0
                        and bingo[2][2] == 0
                        and bingo[3][3] == 0
                        and bingo[4][4] == 0)
                    )
                {
                    game++;
                }
            }
        }
        razd++;
        if (game == 1)
        {
            if (oshib == 0)
            {
                cout << "Вы победили без ошибок, поздравляю!!!" << endl;
            }
            else
            {
                cout << "Вы победили, но допустили " << oshib << " ошибок." << endl;
            }
            system("pause");
        }
        if (razd == 75)
        {
            cout << "Числа кончились, но если бы вы не допустили " << oshib << " то смогли бы победить." << endl;
            game++;
        }
        cout << endl;
    } while (game == 0);
}