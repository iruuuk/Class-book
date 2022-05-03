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
    cout <<  endl << "Нажмите " << endl << "1 - перезапись списка студентов" << endl << "2 - просмотр списка студентов" << endl << "3 - изменение информации о студенте под номером N" << endl << "4 - фильтрация по номеру группы" << endl << "5 - подсчет дисциплины с высоким средним баллом" << endl << "6 - показать под номером N" << endl << "7 - сортировка по ФИО" << endl << "8 - добавить под номером N" << endl << "9 - удалить под номером N" << endl << "10 - вывести среднее время обслуживание клиента" << endl << "0 - выход из приложения" << endl;
    cin >> choice;
    while (choice != 0)
    {
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
    }
}  
