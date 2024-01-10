#include "pch.h"
#include "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\VS\UnitTest\include\CppUnitTest.h"
#include "C:\Users\Lenovo\source\repos\CarService\Warehouse.h"
#include "C:\Users\Lenovo\source\repos\CarService\Warehouse.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(WarehouseTest)
	{
	public:

		TEST_METHOD(TestConstructor)
		{
			Part testedPart(1, "srubki", 10);

			Assert::AreEqual(1u, testedPart.getID());
			Assert::AreEqual(std::string("srubki"), testedPart.getName());
			Assert::AreEqual(10u, testedPart.getAmount());
		}

		TEST_METHOD(TestLoadingData)
		{
			Warehouse warehouse;
			warehouse.loadData();
			Part testedPart = warehouse.getVectorPart(1);

			Assert::AreEqual(1u, testedPart.getID());
			Assert::AreEqual(std::string("srubki"), testedPart.getName());
			Assert::AreEqual(10u, testedPart.getAmount());
		}

	};
}
