#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\wiatr\source\repos\CarService\PriceList.h"
#include "C:\Users\wiatr\source\repos\CarService\PriceList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PriceListTests
{
	TEST_CLASS(PriceListTests)
	{
	public:
		
		TEST_METHOD(TestConstructor)
		{
			Service service(1, "TestService", 100);
			Assert::AreEqual(1u,service.getIdService());
			Assert::AreEqual(std::string("TestService"), service.getName());
			Assert::AreEqual(100u, service.getPrice());
			//
		}
	};
}
