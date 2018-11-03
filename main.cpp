/*
 * created by Danil Kireev, PFUR NFI-201,12.09.18, 09:50/10:40
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

/*
 * № 43
 * Дана матрица размера M x N
 * Зеркально отразить ее элементы относительно горизонтальной оси симметрии матрицы
 * (при этом поменяются местами строки с номерами 1 и M, 2 и M – и т.д.)
 */

int main() {
    srand((unsigned)(time(nullptr)));
    int n,m, **A, *B, t;
    cout << "зеркальное отражение матрицы относительно горизонтальной оси симметрии матрицы" << endl;
    cout << "Выберите тип ввода:\n-  1:заполнение вручную\n-  2:заполнение из файла" << endl;
    cin >> t;
    switch(t) {
        case 0: {
            cout << "введите кол-во строк(N)" << endl;
            cin >> n;
            while (n<=0) {
                cout << "введите положительное кол-во строк(N)" << endl;;
                cin >> n;
            }
            cout << "введите количество столбцов(M)" << endl;
            cin >> m;
            while (m<=0) {
                cout << "введите положительное количество столбцов(M)";
                cin >> m;
            }
            A = new int*[n];
            for (int i = 0; i < n; ++i) A[i] = new int[m];
            cout << "полученная матрица: " << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    A[i][j]=rand()%100;
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
            for (int i = 0; i < n/2; ++i) {
                B = A[i];
                A[i] = A[n-1-i];
                A[n-1-i] = B;
            }
            cout << "полученная зеркально отражённая матрица относительно горизонтальной оси симметрии матрицы: " << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }
        case 1: {
            cout << "введите кол-во строк(N)" << endl;
            cin >> n;
            while (n<=0) {
                cout << "введите положительное кол-во строк(N)" << endl;;
                cin >> n;
            }
            cout << "введите количество столбцов(M)" << endl;
            cin >> m;
            while (m<=0) {
                cout << "введите положительное количество столбцов(M)";
                cin >> m;
            }
            A = new int*[n];
            for (int i = 0; i < n; ++i) A[i] = new int[m];
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << "введите элемент" << i << " " << j << endl;
                    cin >> A[i][j];
                }
                cout << endl;
            }
            for (int i = 0; i < n/2; ++i) {
                B = A[i];
                A[i] = A[n-1-i];
                A[n-1-i] = B;
            }
            cout << "полученная зеркально отражённая матрица относительно горизонтальной оси симметрии матрицы: " << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
            break;
        }
        case 2: {
            string line;
            ifstream fin;
            fin.open("/home/danai/Projects/c-cpp/aad_2_lab02/input", ios::in);
            ofstream fout;
            fout.open("/home/danai/Projects/c-cpp/aad_lab02/output", ios::out);
            getline(fin, line, ';');
            try {
                n = stoi(line);
            }
            catch(...) {
                cout << "Ошибка считывания" << endl;
                return 0;
            }
            cout << "количество строк(N): " << n << endl;
            getline(fin, line, ';');
            try {
                m = stoi(line);
            }
            catch(...) {
                cout << "Ошибка считывания" << endl;
                return 0;
            }
            cout << "количество столбцов(M): " << m << endl;
            A = new int*[n];
            for (int i = 0; i < n; ++i) A[i] = new int[m];
            cout << "полученная матрица: " << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    getline(fin, line, ',');
                    try {
                        A[i][j]=stoi(line);
                    }
                    catch(...) {
                        cout << "Ошибка считывания" << endl;
                        return 0;
                    }
                    cout << A[i][j] << " ";
                }
                cout << endl;
            }
            for (int i = 0; i < n/2; ++i) {
                B = A[i];
                A[i] = A[n-1-i];
                A[n-1-i] = B;
            }
            cout << "полученная зеркально отражённая матрица относительно горизонтальной оси симметрии матрицы: " << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    cout << A[i][j] << " ";
                    fout << A[i][j] << " ";
                }
                cout << endl;
                fout << endl;
            }
            break;
        }
        default:break;
    }
    return 0;
}