#include "pch.h"
#include "CppUnitTest.h"
#include <sstream> 
#include "../lab_10.1_B/10.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestCreateStudents)
        {

            istringstream input("Ivanenko\n2\n0\n4\n5\n5\n");
            streambuf* cin_backup = cin.rdbuf(input.rdbuf());

            const int N = 1;
            Student* students = new Student[N];


            CreateStudents(students, N);


            Assert::AreEqual(string("Ivanenko"), students[0].prizv, L"Прізвище студента неправильне.");
            Assert::AreEqual(2, students[0].kurs, L"Курс студента неправильний.");
            Assert::AreEqual((int)KN, (int)students[0].specialnist, L"Спеціальність студента неправильна.");
            Assert::AreEqual(4, students[0].ocinka_fizyka, L"Оцінка з фізики неправильна.");
            Assert::AreEqual(5, students[0].ocinka_matematyka, L"Оцінка з математики неправильна.");
            Assert::AreEqual(5, students[0].ocinka_programuvannia, L"Оцінка з програмування неправильна.");


            delete[] students;


            cin.rdbuf(cin_backup);
        }

        TEST_METHOD(TestCountProgrammingGrades)
        {

            Student students[3] = {
                { "Ivanenko", 1, KN, 4, 5, 5 },
                { "Petrenko", 2, KN, 4, 4, 4 },
                { "Shevchenko", 3, KN, 3, 3, 3 }
            };

            int count5, count4, count3;
            CountProgrammingGrades(students, 3, count5, count4, count3);


            Assert::AreEqual(1, count5, L"Кількість оцінок '5' з програмування неправильна.");
            Assert::AreEqual(1, count4, L"Кількість оцінок '4' з програмування неправильна.");
            Assert::AreEqual(1, count3, L"Кількість оцінок '3' з програмування неправильна.");
        }

        TEST_METHOD(TestCalculateHighPhysicsMathPercentage)
        {

            Student students[3] = {
                { "Ivanenko", 1, KN, 4, 5, 5 },
                { "Petrenko", 2, KN, 4, 4, 4 },
                { "Shevchenko", 3, KN, 3, 3, 3 }
            };

            double percentage = CalculateHighPhysicsMathPercentage(students, 3);


            Assert::AreEqual(66.67, percentage, 0.01, L"Відсоток студентів з оцінками '4' або '5' з фізики і математики неправильний.");
        }
    };
