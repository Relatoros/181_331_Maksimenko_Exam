#include "pch.h"
#include "CppUnitTest.h"
#include "..\TestingApp\Matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
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
	};
}
