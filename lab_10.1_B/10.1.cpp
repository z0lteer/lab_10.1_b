#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;


enum Specialnist { KN, INF, ME, FI, TN };
string specialnistStr[] = { "����'����� �����", "�����������", "���������� �� ��������", "Գ���� �� �����������", "������� ��������" };


struct Student {
    string prizv;
    int kurs;
    Specialnist specialnist;
    int ocinka_fizyka;
    int ocinka_matematyka;
    union {
        int ocinka_programuvannia;
        int ocinka_chyselni_metody;
        int ocinka_pedahohika;
    };
};


void CreateStudents(Student* students, const int N) {
    for (int i = 0; i < N; i++) {
        cout << "������� � " << i + 1 << ":" << endl;
        cout << " �������: ";
        cin >> students[i].prizv;
        cout << " ����: ";
        cin >> students[i].kurs;

        int specialnist;
        cout << " ������������ (0 - ����'����� �����, 1 - �����������, 2 - ���������� �� ��������, 3 - Գ���� �� �����������, 4 - ������� ��������): ";
        cin >> specialnist;
        students[i].specialnist = static_cast<Specialnist>(specialnist);


        cout << " ������ � ������: ";
        cin >> students[i].ocinka_fizyka;
        cout << " ������ � ����������: ";
        cin >> students[i].ocinka_matematyka;


        if (students[i].specialnist == KN) {
            cout << " ������ � �������������: ";
            cin >> students[i].ocinka_programuvannia;
        }
        else if (students[i].specialnist == INF) {
            cout << " ������ � ��������� ������: ";
            cin >> students[i].ocinka_chyselni_metody;
        }
        else {
            cout << " ������ � ���������: ";
            cin >> students[i].ocinka_pedahohika;
        }
        cout << endl;
    }
}


void CountProgrammingGrades(const Student* students, const int N, int& count5, int& count4, int& count3) {
    count5 = count4 = count3 = 0;
    for (int i = 0; i < N; i++) {
        if (students[i].specialnist == KN) {
            if (students[i].ocinka_programuvannia == 5) count5++;
            else if (students[i].ocinka_programuvannia == 4) count4++;
            else if (students[i].ocinka_programuvannia == 3) count3++;
        }
    }
}


double CalculateHighPhysicsMathPercentage(const Student* students, const int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (students[i].ocinka_fizyka >= 4 && students[i].ocinka_matematyka >= 4) {
            count++;
        }
    }
    return (N == 0) ? 0 : (static_cast<double>(count) / N) * 100;
}


void PrintStudents(const Student* students, const int N) {
    cout << "==============================================================================================================================" << endl;
    cout << "| � | �������          | ���� | ������������          | Գ���� | ���������� | ������������� | ������� ������ | ��������� |" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++) {
        cout << "| " << setw(2) << i + 1 << " | " << setw(16) << left << students[i].prizv
            << " | " << setw(4) << right << students[i].kurs
            << " | " << setw(23) << left << specialnistStr[students[i].specialnist]
            << " | " << setw(6) << right << students[i].ocinka_fizyka
            << " | " << setw(10) << right << students[i].ocinka_matematyka;


        if (students[i].specialnist == KN) {
            cout << " | " << setw(12) << right << students[i].ocinka_programuvannia
                << " | " << setw(15) << "-"
                << " | " << setw(10) << "-";
        }
        else if (students[i].specialnist == INF) {
            cout << " | " << setw(12) << "-"
                << " | " << setw(15) << students[i].ocinka_chyselni_metody
                << " | " << setw(10) << "-";
        }
        else {
            cout << " | " << setw(12) << "-"
                << " | " << setw(15) << "-"
                << " | " << setw(10) << students[i].ocinka_pedahohika;
        }
        cout << " |" << endl;
    }
    cout << "==============================================================================================================================" << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N;
    cout << "������ ������� ��������: ";
    cin >> N;


    Student* students = new Student[N];


    CreateStudents(students, N);
    PrintStudents(students, N);


    int count5, count4, count3;
    CountProgrammingGrades(students, N, count5, count4, count3);
    cout << "ʳ������ ������ � �������������:" << endl;
    cout << "5: " << count5 << endl;
    cout << "4: " << count4 << endl;
    cout << "3: " << count3 << endl;


    double highPhysicsMathPercentage = CalculateHighPhysicsMathPercentage(students, N);
    cout << "³������ �������� � �������� �4� ��� �5� � ������ � ����������: ";
    cout << fixed << setprecision(2) << highPhysicsMathPercentage << "%" << endl;


    delete[] students;
    return 0;
}
