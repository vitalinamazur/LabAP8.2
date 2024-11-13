#include "pch.h"
#include "CppUnitTest.h"
#include "../labAP8.2/labAP8.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest82
{
    TEST_CLASS(UnitTest82)
    {
    public:



        TEST_METHOD(TestProcessStringToSpace_MultipleGroups)
        {
            std::string input = "test.12345 other.6789 value";
            std::string expectedOutput = "test.12 other.67 value";
            std::string actualOutput = processStringToSpace(input);

            Assert::AreEqual(expectedOutput, actualOutput);
        }

        TEST_METHOD(TestProcessStringToSpace_NoChangesNeeded)
        {
            std::string input = "simple.test 1.23 space";
            std::string expectedOutput = "simple.test 1.23 space";
            std::string actualOutput = processStringToSpace(input);

            Assert::AreEqual(expectedOutput, actualOutput);
        }

        TEST_METHOD(TestProcessStringToSpace_SingleGroup)
        {
            std::string input = "value 0.123456";
            std::string expectedOutput = "value 0.12";
            std::string actualOutput = processStringToSpace(input);

            Assert::AreEqual(expectedOutput, actualOutput);
        }


    };
}