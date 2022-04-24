#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int to_do, n;
    cout << "Enter number of students" << endl;
    cin >> n;
    int len = 0;
    vector <string> surname(n);
    vector <int> gr(n);
    vector <int> mark(n);
    vector <string> sub(n);
    cout << "Hello, what you want to do?" << endl;
    cout << "If you want to rewrite the list, enter 1" << endl;
    cin >> to_do;
    if (to_do == 1 ) {
        cout << "Surname     Group numder     Mark     Subject";
        for (int i = 0; i < n; i++) {
            cin >> surname[i];
            string bb = surname[i];
            len = bb.size();
            for (int j = 0; j < 12 - len; j++) cout << " ";
            cin >> gr[i];
            int k = gr[i];
            len = 0;
            while (k != 0) {
                k = k / 10;
                len++;
            }
            for (int  f= 0; f < 17 - len; f++) cout << " ";
            cin >> mark[i];
            k = mark[i];
            len = 0;
            while (k != 0) {
                k = k / 10;
                len++;
            }
            for (int x = 0; x < 9 - len; x++) cout << " ";
            cin >> sub[i];
        }
    }
}
