#include "function.h"
#include <cstdio>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001); // TÜRKÇE KARAKTERE ÇEVİRMEYİ SAĞLAR

    Student student;
    student.readFromCSV("girdi.csv");
    int secim;
    cout << "0-Kalan Öğrenciler\n1-Geçen Öğrenciler\n2-Tüm Öğrenciler\nİşlemi gir: ";
    cin >> secim;

    switch (secim)
    {
    case 0:
        cout << "\nKalan Öğrenciler:\n";
        student.print(0);
        cout << "\n";

        break;
    case 1:
        cout << "\nGeçen Öğrenciler:\n";
        student.print(1);
        cout << "\n";
        break;
    case 2:
        cout << "\nTüm Öğrenciler\n";
        student.print();
        cout << "\n";

        break;
    default:
        student.print(-1, "output.csv");
        break;
    }

    return 0;
}
