#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7_3_rek/lab_7_3_rek.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestFindEqualRowsAndCols)
        {
            // Setup a 3x3 matrix
            int n = 3;
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];

            // Test case where row 0 == column 0 and row 1 == column 1
            a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
            a[1][0] = 2; a[1][1] = 1; a[1][2] = 4;
            a[2][0] = 3; a[2][1] = 4; a[2][2] = 3;

            // Redirect cout to a string stream
            std::ostringstream oss;
            std::streambuf* originalCout = std::cout.rdbuf(oss.rdbuf());

            // Call the function
            FindEqualRowsAndCols(a, n, 0);

            // Restore cout
            std::cout.rdbuf(originalCout);

            // Check the output
            std::string output = oss.str();
            Assert::IsTrue(output.find("Row 0 is equal to Column 0") != std::string::npos);
            Assert::IsTrue(output.find("Row 1 is equal to Column 1") != std::string::npos);

            // Clean up
            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
        }

	};
}
