#include "pch.h"
#include "CppUnitTest.h"

// Підключаємо файл з реалізацією функцій вашого основного проєкту
// Змініть шлях за потреби відповідно до назви папки вашого проєкту
#include "../Project 5.5/Project 5.5.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest55
{
    TEST_CLASS(UnitTest55)
    {
    public:

        // Тест 1: Перевірка базових значень p = 2, q = 5
        // Очікуваний результат: S(2, 5) = 2 + 3 + 4 + 5 = 14, глибина S = 4
        TEST_METHOD(TestMethod_S_BasicRange)
        {
            int depth_S = 0;
            int actual_S = S(2, 5, 1, depth_S);

            Assert::AreEqual(14, actual_S);      // Перевірка обчисленої суми
            Assert::AreEqual(4, depth_S);       // Перевірка глибини рекурсії S
        }

        // Тест 2: Перевірка для чисел з нулями на кінці (p = 8, q = 12)
        // f(8)=8, f(9)=9, f(10)=1, f(11)=1, f(12)=2
        // Очікуваний результат: S(8, 12) = 8 + 9 + 1 + 1 + 2 = 21, глибина S = 5
        TEST_METHOD(TestMethod_S_WithZeros)
        {
            int depth_S = 0;
            int actual_S = S(8, 12, 1, depth_S);

            Assert::AreEqual(21, actual_S);      // Перевірка суми
            Assert::AreEqual(5, depth_S);       // Перевірка глибини рекурсії S
        }

        // Тест 3: Перевірка функції f(n) для кількох рівнів рекурсії (n = 100)
        // 100 -> 10 -> 1 (ненульова цифра 1). Глибина f має дорівнювати 3
        TEST_METHOD(TestMethod_f_DeepRecursion)
        {
            int depth_f = 0;
            int actual_f = f(100, 1, depth_f);

            Assert::AreEqual(1, actual_f);       // Перевірка значення ненульової цифри
            Assert::AreEqual(3, depth_f);        // Перевірка глибини рекурсії f
        }
    };
}