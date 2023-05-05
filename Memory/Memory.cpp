#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

void showField(unsigned char** field, int ROW, int COL) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if ((int)field[i][j] >= 10) {
                cout << " " << (int)field[i][j] << "\t";
            } else if((int)field[i][j] >= 100) {
                cout << " " << (int)field[i][j] << "\t";
            } else {
                cout << " " << (int)field[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

void showGameField(unsigned char** field, int ROW, int COL, int x1, int y1, int x2, int y2) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            ((i == x1 && j == y1 && field[i][j]!=251) || (i == x2 && j == y2 && field[i][j] != 251)) ? cout << "\t" << (int)field[i][j] << "\t" : field[i][j] == 251? cout << "\t" << (unsigned char)((int)field[i][j]) << "\t" : cout << "\t" << (unsigned char)176 << "\t";
        }
        cout << endl;
    }
}

void endGame(unsigned char** field, int ROW) {
    for (int i = 0; i < ROW; i++) {
        delete[] field[i];
    }
    delete[] field;
}

int main() {
    int ROW{ 0 }, COL{ 0 }, wait{ 0 }, count{ 0 }, choose{ 0 };
    bool yes{ 0 };
    while (!yes) {
        do {
            system("cls");
            cout << "Input Heigh: ";
            cin >> ROW;
            cout << endl;
            cout << "Input Width: ";
            cin >> COL;
            cout << endl;
            if ((ROW * COL) % 2 != 0) {
                system("cls");
                cout << "Input coordinates at which there will be an EVEN number of elements and more than 2 identical and less than 150!" << endl;
                Sleep(2000);
            }
        } while ((ROW * COL) % 2 != 0 || (ROW * COL) == 0 || (ROW * COL) <= 4 || (ROW * COL) >= 300);
        do{
            system("cls");
            cout << "Do you want play at field with WIDTH " << COL << " and HEIGTH " << ROW << " ?" << endl <<
                "1.Yes!" << endl <<
                "2.No!" << endl <<
                "Choose: ";
            cin >> choose;
            switch (choose) {
            case 1:
                yes = true;
                break;
            }
        } while (choose <= 0 || choose > 2);
    }
    unsigned char** field = new unsigned char* [ROW] {0};
    for (int i = 0; i < ROW; i++) {
        field[i] = new unsigned char[COL] {0};
    }
    for (int j = 0; j < (ROW * COL / 2); j++) {
        int x{ 0 }, y{ 0 };
        while (true) {
            x = rand() % ROW;
            y = rand() % COL;
            if (field[x][y] == 0) {
                field[x][y] = j;
                break;
            }
        }
        while (true) {
            x = rand() % ROW;
            y = rand() % COL;
            if (field[x][y] == 0) {
                field[x][y] = j;
                break;
            }
        }
    }
    cout << "Get ready!" << endl;
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            count++;
            if (count % 4 == 0) {
                count = 0;
                wait++;
            }
        }
        cout << endl;
        if (wait >= 60) {
            break;
        }
    }
    Beep(530, 100); Sleep(100);
    Beep(530, 100); Sleep(300);
    Beep(530, 100); Sleep(300);
    Beep(462, 100); Sleep(100);
    Beep(530, 100); Sleep(300);
    Beep(592, 100); Sleep(700);
    Beep(396, 100); Sleep(700);
    

    system("cls");
    showField(field, ROW, COL);
    Sleep(wait * 1000);
    system("cls");

    clock_t t = clock();

    int x1{ 0 }, y1{ 0 }, x2{ 0 }, y2{ 0 };
    bool end{ 0 };
    while (!end) {
        end = true;
        do {
            do {            
                cout << "Input VERTICAL coordinats fo FIRST symbol!" << endl;
                cin >> x1;
                cout << "Input HORIZONTAL coordinats fo FIRST symbol!" << endl;
                cin >> y1;
                cout << "Input VERTICAL coordinats fo SECOND symbol!" << endl;
                cin >> x2;
                cout << "Input HORIZONTAL coordinats fo SECOND symbol!" << endl;
                cin >> y2;
            } while (x1 < 0 || x1 >= ROW || x2 < 0 || x2 >= ROW || y1 < 0 || y1 >= COL || y2 < 0 || y2 >= COL);
        } while (field[x1][y1] == 251 || field[x2][y2] == 251);
        system("cls");
        if (field[x1][y1] == field[x2][y2]) {
            cout << "They are identical!!!" << endl;
            Beep(1000, 300);
            Beep(1500, 300);
            field[x1][y1] = 251; field[x2][y2] = 251;
            showGameField(field, ROW, COL, x1, y1, x2, y2);
        } else {
            Beep(1500, 300);
            Beep(1000, 300);
            cout << "They are NOT identical!!!" << endl;
            showGameField(field, ROW, COL, x1, y1, x2, y2);
        }
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (field[i][j] != 251) {
                    end = false;
                }
            }
        }
    }

    endGame(field, ROW);
    int time = (clock() - t) / CLOCKS_PER_SEC;
    cout << "You played " << time << " sec!" << endl;
}


