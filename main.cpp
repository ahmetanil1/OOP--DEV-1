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
        student.print(secim, "cikti.csv");
        cout << "\n";

        break;
    case 1:
        cout << "\nGeçen Öğrenciler:\n";
        student.print(1);
        student.print(secim, "cikti.csv");
        cout << "\n";
        break;
    case 2:
        cout << "\nTüm Öğrenciler\n";
        student.print();
        student.print(secim, "cikti.csv");
        cout << "\n";

        break;
    }
    main();

    return 0;
}
// CONST STRİNG TANIMLAMA NEDENİM PRİNT İÇERİİSNDE ORAYA ARGÜMAN GELİRSE ARGÜMANI ÇAĞIR GELMEZSE BO STRİNG OLARAK ATA
// CONST OLARAK TANIMLANMAZSA ORAYA HERAHNGİ BİR ARGÜMAN GELDİĞİNDE O ARGÜMANI SABİR OLARAK ALIR ÇÜNKÜ OUTPUTFİLENAME REFERANS İLE ÇAĞRILDI.
// ALTERNATİF KULLANIMI : string outputFileName = ""
// YUKARDAKİ İFADENİN DEZAVANTAJI HERHANGİ BİR VERİ DEĞİŞİRSE O VERİYİ YAZZMAK İÇİN YENİ BİR BELLEK HÜCRESİ OLUŞTURUR VE ORAYA YAZAR
// AMPERSAND KULLANIM AMACI İLK HÜCRENİN ÜZERİNE YAZ VE PERFORMANSIA ARTIR