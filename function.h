#include "class.h"
#include <fstream>
#include <sstream>
#include <string>

Student::Student()
{
    size = 0;     // öğrencsi sayısı
    capacity = 1; // array boyutu
    names = new string[capacity];
    studentNumbers = new float[capacity];
    midterms = new float[capacity];
    secondExams = new float[capacity];
    assignments = new float[capacity];
    finals = new float[capacity];
    attendance = new int[capacity];
}

void Student::resize()
{
    int newCapacity = capacity * 2;

    string *newNames = new string[newCapacity];
    float *newStudentNumbers = new float[newCapacity];
    float *newMidterms = new float[newCapacity];
    float *newSecondExams = new float[newCapacity];
    float *newAssignments = new float[newCapacity];
    float *newFinals = new float[newCapacity];
    int *newAttendance = new int[newCapacity];

    for (int i = 0; i < size; i++)
    {
        newNames[i] = names[i];
        newStudentNumbers[i] = studentNumbers[i];
        newMidterms[i] = midterms[i];
        newSecondExams[i] = secondExams[i];
        newAssignments[i] = assignments[i];
        newFinals[i] = finals[i];
        newAttendance[i] = attendance[i];
    }

    delete[] names;
    delete[] studentNumbers;
    delete[] midterms;
    delete[] secondExams;
    delete[] assignments;
    delete[] finals;
    delete[] attendance;

    names = newNames;
    studentNumbers = newStudentNumbers;
    midterms = newMidterms;
    secondExams = newSecondExams;
    assignments = newAssignments;
    finals = newFinals;
    attendance = newAttendance;
    capacity = newCapacity;
}

void Student::readFromCSV(const string &fileName)
{
    ifstream file(fileName);
    if (!file.is_open())
    {
        cerr << "Dosya açılamadı: " << fileName << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        if (size == capacity)
        {
            // ARRAYDA MAX ELEMAN SAYISINA ULAŞILIRSA RESİZE FONKSIYONU CAGIRILIR VE KAPASİTE ARTILIP DAHA FAZLA ELEMAN KOYMAYA OLANAK SAĞLAR.
            resize();
        }
        stringstream ss(line);
        getline(ss, names[size], ',');

        ss >> studentNumbers[size];
        ss.ignore(1); // STUDENTNUMBER İFADESİNİN TÜRÜNDEKİ DEĞERLER BİTTİKTEN SONRAKİ İLK İFADEYE KADAR AL

        ss >> midterms[size];
        ss.ignore(1);

        ss >> secondExams[size];
        ss.ignore(1);

        ss >> assignments[size];
        ss.ignore(1);

        ss >> finals[size];
        ss.ignore(1);

        if (ss.peek() != EOF)
        {
            ss >> attendance[size];
        }
        else
        {
            attendance[size] = 0; // Varsayılan değer
        }
        size++;
    }
    file.close();
}

void Student::print() // dosyayý okur ve konsola tüm öðrenci listesini yazdirir
{
    for (int i = 0; i < size; ++i)
    {
        float avg = average(i);

        cout << "Ad: " << names[i] << ", Öğrenci Numarası" << studentNumbers[i] << ", Ortalama: " << avg << ", Devam Sayısı" << attendance[i] << '\n';
    }
}

void Student::print(int arg) // seçime göre konsola kalan-gecenleri yazdirir
{

    for (int i = 0; i < size; ++i)
    {
        float avg = average(i);
        bool isAvailable = attendance[i] < 10;
        if ((arg == 0 && isAvailable) || (arg == 0 && avg < 50))
        {
            cout << "Ad: " << names[i] << ", Öğrenci Numarası" << studentNumbers[i] << ", Ortalama: " << avg << ", Devam Sayısı" << attendance[i] << '\n';
        }

        else if ((arg == 1 && avg >= 50 && !isAvailable))
        {
            cout << "Ad: " << names[i] << ", Öğrenci Numarası" << studentNumbers[i] << ", Ortalama: " << avg << ", Devam Sayısı" << attendance[i] << '\n';
        }
    }
}

void Student::print(int secim, const string &outputFileName) // secime göre DOSYAYA secilen þeyi yazdýrýr
{

    ofstream file("cikti.csv");

    if (!file)
    { // Dosya açýlmazsa hata ver
        cerr << "cikti dosyasi acilamadi!" << endl;
        return;
    }

    for (int i = 0; i < size; ++i)
    {
        float avg = average(i);
        bool isAvailable = attendance[i] < 10;
        if ((secim == 0 && isAvailable) || (secim == 0 && avg < 50))
        {
            file << "Ad: " << names[i] << ", Öğrenci Numarası" << studentNumbers[i]
                 << ", Ortalama: " << avg << ", Devam Sayısı" << attendance[i] << '\n';
        }

        else if ((secim == 1 && avg >= 50 && !isAvailable))
        {
            file << "Ad: " << names[i] << ", Öğrenci Numarası" << studentNumbers[i]
                 << ", Ortalama: " << avg << ", Devam Sayısı" << attendance[i] << '\n';
        }

        else if (secim == 2)
        {
            file << "Ad: " << names[i] << ", Öğrenci Numarası" << studentNumbers[i]
                 << ", Ortalama: " << avg << ", Devam Sayısı" << attendance[i] << '\n';
        }
    }
}
float Student::average(int index)
{
    return midterms[index] * 0.2 + secondExams[index] * 0.2 +
           assignments[index] * 0.2 + finals[index] * 0.4;
}

Student::~Student()
{
    delete[] names;
    delete[] studentNumbers;
    delete[] midterms;
    delete[] secondExams;
    delete[] assignments;
    delete[] finals;
    delete[] attendance;
}