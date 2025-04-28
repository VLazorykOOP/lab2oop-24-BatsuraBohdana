#include <iostream>
#include <fstream>

using namespace std;

const int ROWS = 4;
const int COLS = 32;

void Deshifruvanna(unsigned short Rez[ROWS][COLS], char S[ROWS][COLS]) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            unsigned short r = Rez[row][col];
            // Витягуємо ASCII код символу
            char c = (r >> 7) & 0xFF;
            S[row][col] = c;
        }
    }
}

int main() {
    unsigned short Rez[ROWS][COLS];
    char S[ROWS][COLS] = {0};
    
    // Читання із бінарного файлу
    ifstream input("encrypted.bin", ios::binary);
    if (!input) {
        cerr << "Помилка відкриття файлу!" << endl;
        return 1;
    }
    input.read((char*)Rez, sizeof(Rez));
    input.close();
    
    // Розшифрування
    Deshifruvanna(Rez, S);
    
    // Вивід у консоль
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << S[i][j];
        }
        cout << endl;
    }
    
    // Запис у текстовий файл
    ofstream output("decrypted.txt");
    if (!output) {
        cerr << "Помилка створення файлу!" << endl;
        return 1;
    }
    for (int i = 0; i < ROWS; i++) {
        output.write(S[i], COLS);
        output << endl;
    }
    output.close();
    
    cout << "Розшифрований текст записано у файл 'decrypted.txt'." << endl;
    return 0;
}
