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
