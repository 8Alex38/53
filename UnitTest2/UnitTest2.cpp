#include "pch.h"
#include "CppUnitTest.h"
#include "../5.3/5.3.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			double x1 = 1.5;
			double expected1 = (sin(x1) + cos(x1)) / (pow(sin(x1), 2) + exp(x1));
			Assert::AreEqual(expected1, p(x1), 0.000001, L"Тест для x >= 1 провалено");

			double x2 = 0.5;
			double sum = 0;
			for (int j = 0; j <= 4; ++j) {
				sum += pow(-1, j) * pow(x2, 2 * j) / tgamma(2 * j + 1);
			}
			double expected2 = 1 / cos(x2) * sum;
			Assert::AreEqual(expected2, p(x2), 0.000001, L"Тест для x < 1 провалено");
		}
	};
}
