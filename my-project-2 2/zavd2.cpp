#include <iostream>
#include <fstream>
using namespace std;

const int rows = 3;  // кількість рядків у матриці
const int cols = 3;  // кількість стовпців у матриці

int main() {
    ifstream inFile("2D.txt");  // відкриваємо файл для читання
    if (!inFile) {
        cerr << "Не вдалося відкрити файл 2D.txt для читання." << endl;
        return 1;
    }

    int matrix[rows][cols];  // двовимірний масив для зчитування даних

    // Зчитування даних з файлу в масив
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            inFile >> matrix[i][j];  // зчитуємо кожен елемент матриці
        }
    }

    inFile.close();  // закриваємо файл після читання

    cout << "Початкова матриця:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    //збільшити всі парні елементи на 10
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] % 2 == 0) {  // якщо елемент парний
                matrix[i][j] += 10;       // додаємо до нього 10
            }
        }
    }

    cout << "\nРезультуюча матриця (парні елементи збільшено на 10):" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }

    // Запис результату в новий файл
    ofstream outFile("result.txt");  // створюємо файл для запису
    if (!outFile) {
        cerr << "Не вдалося відкрити файл result.txt для запису." << endl;
        return 1;
    }

    outFile << "Результуюча матриця:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            outFile << matrix[i][j] << ' ';  // запис елементів у файл
        }
        outFile << endl;
    }

    outFile.close();  // закриваємо файл після запису

    cout << "\nМатрицю збережено у файлі result.txt" << endl;

    return 0;
}