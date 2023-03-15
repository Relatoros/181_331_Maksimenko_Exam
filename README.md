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

## Unit Тестирование
Для модульного тестирования создан проект UnitTest и используется Framework CppUnitTestFramework.<br>
Один позитивный P1 и один негативный N1.<br>
![image](https://user-images.githubusercontent.com/100855284/225324060-f30167b9-6abe-4771-955f-680d4cde23d1.png)

```c++

TEST_METHOD(P1)
{
	Matrix a(2), c(2);

	int** test1 = new int* [2];
	test1[0] = new int[2]{ 1,2 };
	test1[1] = new int[2]{ 3,4 };
	a.setData(test1);

	c = a - a;

	int** test2 = c.getData();
	for (size_t i = 0; i < c.getSize(); i++)
		for (size_t j = 0; j < c.getSize(); j++)
			Assert::AreEqual(test2[i][j], 0);
}
TEST_METHOD(N1)
{
	

	auto func = []
	{
		Matrix a(2), b(3);

		a.fillRand();
		b.fillRand();
		
		a + b;
	};
	Assert::ExpectException<std::exception>(func);
}
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


#FUZZING 


## Назначение
В проекте Fuzzing написан код сортировки массива двумя способакми: пузырёк и вставка (расческа).

## Содержание
```c++
#include <stdlib.h>
#include <stdio.h>


size_t len(const char* s)
{
    size_t len = 0;
    while (*s++)
        len++;
    return len;
}

int* generateRand(size_t size)
{

    int* mass = (int*)malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i)
        mass[i] = rand() % 10;
    return mass;

}

void show(size_t size, int* mass)
{
    for (int i = 0; i < size; i++)
        printf("%d ", mass[i]);

    printf("\n");

}


void PSort(size_t size, int* mass)
{
    int tmp, noSwap;

    for (int i = size - 1; i >= 0; i--)
    {
        noSwap = 1;
        for (int j = 0; j < i; j++)
        {
            if (mass[j] > mass[j + 1])
            {
                tmp = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = tmp;
                noSwap = 0;
            }
        }
        if (noSwap == 1)
            break;
    }


}


void ISort(size_t size, int* mass)
{
    int newElement, location;

    for (int i = 1; i < size; i++)
    {
        newElement = mass[i];
        location = i - 1;

        while (location >= 0 && mass[location] > newElement)
        {
            mass[location + 1] = mass[location];
            location = location - 1;
        }

        mass[location + 1] = newElement;
    }

}




#define TEST
#ifdef TEST

int LLVMFuzzerTestOneInput(const char* Data, size_t Size)
{

    int s = len(Data);
    PSort(s, Data);
    ISort(s, Data);

    return 0;
}

#else // Not Test
#pragma warning(disable : 4996)

int main()
{
    int* a = generateRand(10);
    int* b = generateRand(8);

    printf("Generate array a:\n");
    show(10, a);
    printf("Generate array b:\n");
    show(8, b);


    printf("Sorted array a:\n");
    PSort(10, a);
    show(10, a);

    printf("Sorted array b:\n");
    ISort(8, b);
    show(8, b);


    free(a);
    free(b);
    return 0;
}
#endif
```

## Анализ Фаззингом
![image](https://user-images.githubusercontent.com/100855284/225352441-a0e7097e-8aff-4d9c-a450-9316cd6224c2.png)
На выводе мы видим, что фаззинг нашел набор данных, который привел вк "падению" программы.

## Описание проблемы<br>
![image](https://user-images.githubusercontent.com/100855284/225353514-1474de55-edb9-4a1a-8fa0-f6022454ec88.png)
Ошибка в строчке 37: выход за пределы массива
## Исправление ошибки<br>
![image](https://user-images.githubusercontent.com/100855284/225353750-eed3e548-17ee-48c2-9832-45be5335400c.png)
Исправлен выход за пределы массива.
## Повторный фаззинг
![image](https://user-images.githubusercontent.com/100855284/225354239-4600fa8e-5aad-4f92-a170-57fd3fec4e9a.png)
Как, после исправления видим тест фаззингом прошел без "падений"



