#include <iostream>
using namespace std;
class Student
{
private:
    string *names;
    float *studentNumbers;
    float *midterms;
    float *secondExams;
    float *assignments;
    float *finals;
    int *attendance;
    int size;
    int capacity;

public:
    Student();
    ~Student();
    void readFromCSV(const string &fileName);
    float average(int index);
    void print(int arg, const string &outputFileName);
    void resize();
};
