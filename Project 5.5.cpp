#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Прототипи функцій
int f(int n, int level, int& depth);
int S(int p, int q, int level, int& depth);

int main()
{
    int p, q;

    // Введення початкових даних p та q з клавіатури
    cout << "p = "; cin >> p;
    cout << "q = "; cin >> q;

    // Змінна для відстеження глибини рекурсії функції S(p, q)
    int depth_S = 0;

    // Обчислення суми S(p, q) з початковим рівнем рекурсії 1
    int result = S(p, q, 1, depth_S);

    // Виведення підсумкових результатів
    cout << "\n-----------------------------------" << endl;
    cout << "S(" << p << ", " << q << ") = " << result << endl;
    cout << "Hlybyna rekursii S: " << depth_S << endl;
    cout << "-----------------------------------" << endl;

    return 0;
}

// Рекурсивна функція f(n) за варіантом 9
int f(int n, int level, int& depth)
{
    // Оновлення максимальної глибини рекурсії f
    if (level > depth)
        depth = level;

    // 1. Базовий випадок: якщо n == 0, повертаємо 0
    if (n == 0)
        return 0;

    // Беремо модуль числа для коректної обробки від'ємних значень
    int remainder = abs(n) % 10;

    // 2. Базовий випадок: якщо остання цифра > 0, повертаємо її
    if (remainder > 0)
        return remainder;

    // 3. Рекурсивний виклик: відкидаємо нуль на кінці (n / 10)
    return f(n / 10, level + 1, depth);
}

// Рекурсивна функція обчислення суми S(p, q)
int S(int p, int q, int level, int& depth)
{
    // 1. Спочатку перевіряємо вихід з рекурсії
    // Якщо p перевищує q, завершуємо рекурсію без оновлення depth
    if (p > q)
        return 0;

    // 2. Оновлюємо глибину рекурсії S лише для дійсних кроків
    if (level > depth)
        depth = level;

    // Змінна для відстеження глибини функції f(p)
    int f_depth = 0;
    int current_f = f(p, 1, f_depth);

    // Виведення поточного рівня та результату для кожного p
    cout << "Riven S = " << level
        << " | p = " << p
        << " | f(" << p << ") = " << current_f
        << " | Hlybyna f = " << f_depth << endl;

    // 3. Рекурсивне додавання: f(p) + S(p + 1, q)
    return current_f + S(p + 1, q, level + 1, depth);
}