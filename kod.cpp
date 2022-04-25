#include <iostream>
#include <string>
#include <vector>
using namespace std;

void out(int n, vector <string> surname, vector <int> gr, vector <int> mark, vector <string> sub) {
    cout << "Surname     Group numder     Mark     Subject" << endl;
    for (int i = 0; i < n; i++) {
        cout << surname[i] << "         ";
        cout << gr[i] << "               ";
        cout << mark[i] << "         ";
        cout << sub[i];
        cout << endl;
    }
}

int main()
{
    int to_do = 68, n;
    vector <string> surname(30);
    vector <int> gr(30);
    vector <int> mark(30);
    vector <string> sub(30);
    cout << "Hello!" << endl;
    while (to_do != 0) {
        cout << "If you want to exit, enter 0" << endl;
        cout << "If you want to rewrite the list, enter 1" << endl;
        cout << "If you want to look trough your list, enter 2" << endl;
        cin >> to_do;
        if (to_do == 0) cout << "Goodbye!";
        if (to_do == 1) {
            cout << "Enter number of students" << endl;
            cin >> n;
            cout << "Surname     Group numder     Mark     Subject" << endl;
            for (int i = 0; i < n; i++) {
                cin >> surname[i];
                cin >> gr[i];
                cin >> mark[i];
                cin >> sub[i];
            }
        }
        else if (to_do == 2) {
            out(n, surname, gr, mark, sub);
        }
    }
}
