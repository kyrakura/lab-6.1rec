#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 6.1(2)/lab 6.1.2.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
    public:

        TEST_METHOD(TestMethod1)
        {
            const int N = 25;
            int a[N];
            Create(a, N, -11, 13, 0);
            Assert::AreEqual(-37, Sum(a, N, 0), 0.00001);
        }

        TEST_METHOD(TestMethod2)
        {
            const int N = 20;
            int a[N];
            Create(a, N, -11, 13, 0);
            Assert::AreEqual(1, Count(a, N, 0), 0.00001);
        }
    };
}
