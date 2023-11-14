#include "pch.h"
#include "CppUnitTest.h"
#include "../main.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::string str = "123456789";
			Assert::AreEqual(sortString("987654321", 9), str);
		}
	};
}
