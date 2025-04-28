#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void Shifruvanna(char text[4][32], unsigned short Rez[4][32]) {
    for (int line = 0; line < 4; line++) {
        for (int pos = 0; pos < 32; pos++) {
            unsigned short r = 0;
            unsigned char c = text[line][pos];
            
            // 1. Номер рядка (2 біти)
            r = line & 0x03; // 00000011
            
            // 2. Позиція символу в рядку (5 бітів)
            r |= (pos & 0x1F) << 2; // 00011111 зсунуто на 2 біти
            
            // 3. ASCII код (8 бітів)
            r |= (c << 7);
            
            // 4. Біт парності для всіх попередніх бітів (1 біт)
            bool parity = false;
            for (int j = 0; j < 15; j++) {
                if (r & (1 << j)) parity = !parity;
            }
            r |= (parity << 15);
            
            Rez[line][pos] = r;
        }
    }
}

int main() {
    char text[4][32] = {0};  // Ініціалізація нулями
    unsigned short Rez[4][32];
    
    // Читання з файлу
    ifstream input("input.txt");
    if (!input) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }
    
    // Зчитуємо 4 рядки, кожен до 32 символів
    for (int i = 0; i < 4; i++) {
        input.getline(text[i], 32);
        // Доповнюємо пробілами до 32 символів
        int len = strlen(text[i]);
        for (int j = len; j < 32; j++) {
            text[i][j] = ' ';
        }
    }
    input.close();

    // Шифрування
    Shifruvanna(text, Rez);
    
    // Вивід у консоль (для перевірки)
    cout << hex;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 32; j++) {
            cout << Rez[i][j] << " ";
        }
        cout << endl;
    }
    
    // Запис у бінарний файл
    ofstream output("encrypted.bin", ios::binary);
    if (!output) {
        cerr << "Помилка створення файлу!" << endl;
        return 1;
    }
    output.write((char*)Rez, sizeof(Rez));
    output.close();

    cout << "Результат записано у файл 'encrypted.bin'." << endl;
    return 0;
}