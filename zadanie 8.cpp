#include <iostream>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    char answers[8]; // Массив для хранения ответов
    char answer;
    ofstream file("answers.txt", ios::binary); // Открываем файл для записи в бинарном режиме

    // Задаем вопросы и сохраняем ответы
    for (int i = 0; i < 8; i++) {
        cout << "Вопрос " << i + 1 << ": Да или Нет? (D/N): ";
        cin >> answer;
        if (answer == 'D' || answer == 'd') {
            answers[i] = 'D';
        }
        else if (answer == 'N' || answer == 'n') {
            answers[i] = 'N';
        }
        else {
            cout << "Некорректный ответ" << endl;
            i--; // Повторяем вопрос, если ответ некорректный
        }
    }

    // Записываем ответы в файл
    file.write(answers, sizeof(answers));
    file.close(); // Закрываем файл

    // Проверяем успешность записи
    if (!file) {
        cerr << "Ошибка при записи в файл." << endl;
        return 1;
    }

    // Пользователь может изменить ответы
    cout << "Хотите изменить ответы? (Y/N): ";
    cin >> answer;
    if (answer == 'Y' || answer == 'y') {
        ifstream readFile("answers.txt", ios::binary); // Открываем файл для чтения
        readFile.read(answers, sizeof(answers)); // Читаем ответы из файла
        readFile.close(); // Закрываем файл

        if (!file.is_open()) {
            cerr << "Не удалось открыть файл для изменения ответов." << endl;
            return 1;

        for (int i = 0; i < 8; i++) {
            cout << "Текущий ответ на вопрос " << i + 1 << ": " << answers[i] << endl;
            cout << "Введите новый ответ (D/N): ";
            cin >> answer;
            if (answer == 'D' || answer == 'd') {
                answers[i] = 'D';
            }
            else if (answer == 'N' || answer == 'n') {
                answers[i] = 'N';
            }
            else {
                cout << "Некорректный ответ" << endl;
                i--; // Повторяем вопрос, если ответ некорректный
            }
        }

        // Записываем измененные ответы обратно в файл
        ofstream writeFile("answers.txt", ios::binary);
        writeFile.write(answers, sizeof(answers));
        writeFile.close();
    }

    return 0;
}