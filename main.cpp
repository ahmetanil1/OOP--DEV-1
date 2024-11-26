#include "function.h"
#include <cstdio>
#include <windows.h>

int main()
{
    SetConsoleOutputCP(65001);    // TÜRKÇE KARAKTERE ÇEVİRMEYİ SAĞLAR

    Student student;
    student.readFromCSV("girdi.csv");

    cout << "Tüm Öğrenciler:\n";
    student.print();

    cout << "\nKalan Öğrenciler:\n";
    student.print(0);

    cout << "\nGeçen Öğrenciler:\n";
    student.print(1);

    student.print(-1, "output.csv");
    return 0;
}
