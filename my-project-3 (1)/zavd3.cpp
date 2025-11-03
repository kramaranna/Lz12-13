#include <iostream>
#include <string>
#include <limits>      // для numeric_limits
#include <fstream>     // для роботи з файлами
using namespace std;

struct Student {
    string PIB; // ПІБ студента
    int NG;     // Номер групи
    int RN;     // Рік народження
};

int main() {
    const int SIZE = 5;  // змінено на 5 студентів
    Student st[SIZE];

    // Введення даних користувачем
    cout << "Введіть дані для 5 студентів:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\n" << i + 1 << "-й студент:\n";
        cout << "Введіть ПІБ: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очищення буфера
        getline(cin, st[i].PIB);
        cout << "Введіть номер групи: ";
        cin >> st[i].NG;
        cout << "Введіть рік народження: ";
        cin >> st[i].RN;
    }

    // Сортування масиву студентів за номером групи (метод бульбашки)
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (st[j].NG > st[j + 1].NG) {
                Student temp = st[j];
                st[j] = st[j + 1];
                st[j + 1] = temp;
            }
        }
    }

    // Відкриття файлу для запису результатів
    ofstream fout("results.txt");
    if (!fout) {
        cout << "Помилка відкриття файлу для запису!\n";
        return 1;
    }

    // Виведення відсортованого списку на екран і у файл
    cout << "\nВідсортований список студентів за номером групи:\n";
    fout << "Відсортований список студентів за номером групи:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << st[i].PIB << " — група " << st[i].NG 
             << ", рік народження " << st[i].RN << endl;
        fout << st[i].PIB << " — група " << st[i].NG 
             << ", рік народження " << st[i].RN << endl;
    }

    // Пошук студентів за роком народження
    int searchYear;
    cout << "\nВведіть рік народження для пошуку: ";
    cin >> searchYear;

    bool found = false;
    cout << "\nСтуденти, народжені у " << searchYear << " році:\n";
    fout << "\nСтуденти, народжені у " << searchYear << " році:\n";

    for (int i = 0; i < SIZE; i++) {
        if (st[i].RN == searchYear) {
            cout << st[i].PIB << " — група " << st[i].NG << endl;
            fout << st[i].PIB << " — група " << st[i].NG << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Немає студентів, народжених у цьому році.\n";
        fout << "Немає студентів, народжених у цьому році.\n";
    }

    fout.close(); // Закриття файлу
    cout << "\nДані записано у файл results.txt\n";

    return 0;
}
