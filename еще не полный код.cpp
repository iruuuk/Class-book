#include <vector>
#include <string>
#include <iostream>

using namespace std;

string* vvod (int n, int m, int count, string** a, int i, int j)
{
    if (j == 0)
    {
        count = i + 1;
        a[i][j] = to_string(count);
    }
    if (j == 1)
    {
        cout << "Введите ФИО для " << i + 1 << " студента: ";
        getline(cin, a[i][j]);
    }
    if (j == 2)
    {
        cout << "Введите номер группы: ";
        getline(cin, a[i][j]);
    }
    if (j == 3)
    {
        cout << "Введите оценку: ";
        getline(cin, a[i][j]); 
    }
    if (j == 4)
    {
        cout << "Введите название дисциплины: ";
        getline(cin, a[i][j]);
    }
    return 0;
}

string* change(int n, int m, string** a, int choice3, int count)
{
    int i, j;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][0] == to_string(choice3))
            {
                if (j == 1)
                {
                    cout << "Введите новое ФИО: ";
                    getline(cin, a[i][j]);
                }
                if (j == 2)
                {
                    cout << "Введите номер группы: ";
                    getline(cin, a[i][j]);
                    }
                if (j == 3)
                {
                    cout << "Введите оценку: ";
                    getline(cin, a[i][j]); 
                }
                if (j == 4)
                {
                    cout << "Введите название дисциплины: ";
                    getline(cin, a[i][j]);
                }
            }
        }
    }
    return 0;
}

string* filtr(int n, int m, string** a, int choice4)
{
    int prove = 0;
    int k = 1;
    for (int i = 0; i < n; i++)
    {
        if (stoi(a[i][2]) == choice4)
        {
            if (k == 1)
                cout << "Подробная информация о " << choice4 << " группе: " << endl << "ФИО студента: " << a[i][1] << ", " << ", оценка: " << a[i][3] << ", название дисциплины: " << a[i][4] << endl;
            else
                cout << "ФИО студента: " << a[i][1] << ", " << ", оценка: " << a[i][3] << ", название дисциплины: " << a[i][4] << endl;
            k++;
            prove = 1;
        }
    }
    if (prove == 0)
        cout << "К сожалению, такого студента в этой группе найти не удалось. Повторите попытку позже." << endl;
        return 0;
}

string* sredniybal(int n, int m, string** a)
{
    int k = 0;
    int sum = 0;
    int max = 0;
    int l = 2;
    int b[n][l];
    while (k < n)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (stoi(a[k][4]) == stoi(a[i][4]))
                sum += stoi(a[i][3]);
        }
        if (max < sum)
            max = sum;
        b[k][0] = stoi(a[k][3]);
        b[k][3] = sum / n;
        k++;
    }
    k = 0;
    while (k < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (b[k][0] == b[i][0] && i != k)
            {
                b[i][4] = 0;
                b[i][0] = 0;
            }
        }
        k++;
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i][4] == max)
            cout << "название дисциплины " << b[i][4] << " (средний балл = " << max << ")" << endl;
    }
    return 0;
}

string* show(int n, int m, string** a, int nom)
{
    int str;
    cout << endl << "Подробная информация о студенте под номером " << nom << ": " ;
    for (int i = 0; i < n; i++)
    {
        if (stoi(a[i][0]) == nom)
            str = i;
    }
    cout << "ФИО: " << a[str][1] << ", " << " оценка: " << a[str][3] << ", название дисциплины: " << a[str][4] << endl;
    return 0;
}

string* sortirovka1(int n, int m, string** a)
{
    for (int I = 0; I < n; I++)
    {
        int Max = 0, MaxI;
        for (int i = I; i < n; i++)
        {
            if (stoi(a[i][1]) >= Max)
            {
                Max = stoi(a[i][1]);
                MaxI = i;
            }
        }
        for (int j = 0; j < 4; j++)
        {
            string word;
            word = a[I][j];
            (a[I][j]).clear();
            a[I][j] = a[MaxI][j];
            (a[MaxI][j]).clear();
            a[MaxI][j] = word;
            word.clear();
        }
    }
    return 0;
}

string* sortirovka2(int n, int m, string** spisok)
{
    int znach;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            znach = stoi(spisok[i + 1][2]);
            if (stoi(spisok[i][2]) > znach)
            {
                for (int j = 0; j < m; j++)
                {
                    string save;
                    save = spisok[i + 1][j];
                    spisok[i + 1][j].clear();
                    spisok[i + 1][j] = spisok[i][j];
                    spisok[i][j].clear();
                    spisok [i][j] = save;
                }
            }
        }
    }
    return 0;
}

string* deleting(int n, int m, string** a, int choice9)
{
    choice9 -= 1;
    if (choice9 + 1 > n || choice9 <= 0) 
        cout << "Успешно удалено!" << endl;
    if (choice9 + 1 == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                a[choice9][j].clear();
        }
    }
    else
    {
        for (choice9; choice9 < n - 1; choice9++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j != 0)
                    a[choice9][j] = a[choice9 + 1][j];
            }
        }
    }
    return 0;
}

string* middle(int n, int m, string** spisok)
{
    int summa = 0;
    cout << "Средний балл студентов по всем предметам: ";
    for (int i = 0; i < n; i++)
    {
        summa = summa + stoi(spisok[i][4]);
    }
    cout << summa/n << endl;
    summa = 0;
    cout << "??? ";
    for (int i = 0; i < n; i++)
    {
        summa = summa + stoi(spisok[i][4]) + stoi(spisok[i][3]);
    }
    cout << summa/n << endl;
    return 0;
}

int main()
{
    cout << "Добро пожаловать в приложение!" << endl << "Начнем выставлять оценки студентам " << endl << endl << "Введите количество студентов: "; 
    int n;
    cin >> n;
    cin.ignore();
    int m = 5; 
    cout << endl;
    int count;
    int choice;
    int replace = 0;
    string** spisok = new string*[n];
    for (int i = 0; i < n; i++)
        spisok[i] = new string[m];
    int z = n + 1;
    string add[z][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            vvod(n, m, count, spisok, i, j);
        cout << endl;
    }
    cout <<  endl << "Нажмите " << endl << "1 - перезапись списка студентов" << endl << "2 - просмотр списка студентов" << endl << "3 - изменение информации о студенте под номером N" << endl << "4 - фильтрация по номеру группы" << endl << "5 - подсчет дисциплины с высоким средним баллом" << endl << "6 - показать под номером N" << endl << "7 - сортировка по ФИО и номеру группы" << endl << "8 - добавить под номером N" << endl << "9 - удалить под номером N" << endl << "10 - вывод рейтинга группы" << endl << "0 - выход из приложения" << endl;
    cin >> choice;
    while (choice != 0)
    {
        if (choice == 1)
        {
            cout << endl << "Введите новое число студентов, не превышающее " << n << ": ";
            int student;
            cin >> student;
            cin.ignore();
            cout << endl;
            if (student > n)
                cout << "Введено количество студентов, не соответствующее требованию. Повторите попытку позже. " << endl;
            else
            {
                for (int i = 0; i < student; i++)
                {
                    for (int j = 0; j < m; j++)
                        vvod (n, m, count, spisok, i, j);
                    cout << endl;
                }
                n = student;
            }
        }
        if (choice == 2)
        {
            cout << endl << "Текущий список студентов: " << endl;
            cout << "№ |      ФИО      |   Номер группы   | Оценка | Название дисциплины " << endl; 
            for (int i = 0; i < n; i++)
            {
                if (replace == 0)
                    cout << spisok[i][0] << "          " << spisok[i][1] << "          " << spisok[i][2] << "             " << spisok[i][3] << "          " << spisok[i][4] << endl;
                else
                    cout << add[i][0] << "          " << add[i][1] << "          " << add[i][2] << "             " << add[i][3] << "          " << add[i][4] << endl;
            } 
        }
        if (choice == 3)
        {
            int choice3;
            cout << endl << "У какого студента требуется отредактировать данные? ";
            cin >> choice3;
            cin.ignore();
            if (choice3 > n || choice3 <= 0)
                cout << endl << "Такого студента в списке нет. Повторите попытку позже. " << endl;
            else
                change(n, m, spisok, choice3, count);
        }
        if (choice == 4)
        {
            cout << endl << "Введите номер группы для фильтрации: ";
            int choice4;
            cin >> choice4;
            cout << endl;
            cout << filtr(n, m, spisok, choice4);
        }
        if (choice == 5)
        { 
            cout << endl << "Дисциплина с высоким средним баллом: " << endl;
            sredniybal(n, m, spisok);
        } 
        if (choice == 6)
        {
            cout << endl << "Под каким номером студента посмотреть? ";
            int nom;
            cin >> nom;
            if (nom > n)
                cout << endl << "Студента под таким номером нет в базе. Повторите попытку позже. " << endl;
            else
                show(n, m, spisok, nom);
        }
        if (choice == 7)
        {
            cout << "Выберите сортировку: " << endl << "1 - по ФИО " << endl << "2 - по номеру группы " << endl;
            int choice7;
            cin >> choice7;
            if (choice7 == 1)
            {
                cout << endl << "Список студентов по ФИО: " << endl << endl << "№ |    ФИО    |   Номер группы   | Оценка | Название дисциплины " << endl; 
                sortirovka1(n, m, spisok);
            }
            if (choice7 == 2)
            {
                cout << endl << "Список студентов по номеру группы: " << endl << endl << "№ |      ФИО     |   Номер группы   | Оценка | Дисциплина " << endl; 
                sortirovka2(n, m, spisok);
            }
            for (int i = 0; i < n; i++)
                cout << spisok[i][0] << "                          " << spisok[i][1] << "          " << spisok[i][2] << "               " << spisok[i][3] << "                           " << spisok[i][4] << endl;
        }
        if (choice == 8)
        {
            z = n + 1;
            cout << "Введите детали другого студента: " << endl << endl;
            cin.ignore();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    add[i][j] = spisok[i][j];
                }
            }
            for (int j = 0; j < m; j++)
            {
                if (j == 0)
                    add[z - 1][j] = to_string(z);
                if (j == 1)
                {
                    cout << "Введите ФИО студента: ";
                    getline(cin, add[z - 1][j]);
                }
                if (j == 2)
                {
                    cout << "Введите номер группы: ";
                    getline(cin, add[z - 1][j]);
                }
                if (j == 3)
                {
                    cout << "Введите оценку: ";
                    getline(cin, add[z - 1][j]); 
                }
                if (j == 4)
                {
                    cout << "Введите название дисциплины: ";
                    getline(cin, add[z - 1][j]);
                }
            }
            cout << endl;
            n += 1;
            replace = 1;
        }
        if (choice == 9)
        {
            cout << endl << "Под каким номером удалить студента? " << endl;
            int choice9;
            cin >> choice9;
            deleting(n, m, spisok, choice9);
            cout << "Успешно удалено! " << endl;
            n = n - 1;
        }
        if (choice == 10)
        {
            middle(n, m, spisok);
        }
        cout <<  endl << "Нажмите " << endl << "1 - перезапись списка студентов" << endl << "2 - просмотр списка студентов" << endl << "3 - изменение информации о студенте под номером N" << endl << "4 - фильтрация по номеру группы" << endl << "5 - подсчет дисциплины с высоким средним баллом" << endl << "6 - показать под номером N" << endl << "7 - сортировка по ФИО и номеру группы" << endl << "8 - добавить под номером N" << endl << "9 - удалить под номером N" << endl << "10 - вывод рейтинга группы" << endl << "0 - выход из приложения" << endl;
        cin >> choice;
    }
    if (choice == 0) {
    cout << "Хорошая работа! Ждём вашего возвращения! ";
    return 0;
    }
}
