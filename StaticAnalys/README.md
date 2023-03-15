# 181_331_Maksimenko_Exam

## Назначение
В проекте TestingApp реализован класс для сложения и вычитания квадратных матриц.
## Содержание
```c++
class Matrix {
public:

    Matrix() = default;
    Matrix(size_t size);
    Matrix(Matrix& matrix);
    ~Matrix();

    void fillRand();
    void setData(int** data);

    int** getData();
    size_t getSize();
    void show();

    Matrix& operator+(Matrix& matrix);
    Matrix& operator-(Matrix& matrix);

};
```

## Статический анализ

Для статического анализа кода использовался CppCheck.
GUI:<br>
![image](https://user-images.githubusercontent.com/100855284/225326608-7b0ef8d0-4b35-4f2c-ac3a-8b6e461b66cb.png)
<br>
Console:<br>
![image](https://user-images.githubusercontent.com/100855284/225328265-ead36b3b-61e6-491f-a966-32d61d764734.png)
<br>
## Описание проблемы<br>
Из-за того, что в коде заведомо допущена ошибка утечки памяти: создан двумерный масиив, размером меньше, чем инициализирован.<br>
## Исправление ошибки<br>
Исправм ошибку в коде, путем изменения значения размера массив, и снова прогоняем тест, получаем результат:
![image](https://user-images.githubusercontent.com/100855284/225329559-c7d1047d-140c-46dd-ac5d-98ae3461245a.png)
