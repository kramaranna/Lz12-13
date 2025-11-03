#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream fin("number.txt");
    if (!fin) {
        cout << "Не вдалося відкрити файл number.txt" << endl;
        return 1;
    }

    int n; 
    int count = 1;

    while (fin>>n) { // зчитування чисел
        if (n % 4 == 0) { // перевірка подільності на 4
            count=count*n;   // добуток чисел
        }
    }

    cout << "Добуток чисел, що діляться на 4: " << count << endl;
    fin.close();
}