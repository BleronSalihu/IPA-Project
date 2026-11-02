//================================================================================================
//   Copyright (c)   Messerli Informatik AG, CH-8957 Spreitenbach
//================================================================================================
#include "stdafx.h"
#include "RmiCppUnitTest.h"
#include "MandatoryFields/MandatoryFields.h"

namespace Messerli::MandatoryFields {

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(ConnectionTests){
    TEST_CATEGORY_UNIT_TEST
public:
    TEST_METHOD(Resource_Test)
    {
        //assert
        Assert::IsTrue(UsesResources());
    }

    BEGIN_TEST_METHOD_ATTRIBUTE(DB_Test)
        TEST_METHOD_ATTRIBUTE(L"TestCategory", L"DatabaseTest")
    END_TEST_METHOD_ATTRIBUTE()
    TEST_METHOD(DB_Test)
    {
        //assert
        Assert::IsTrue(UsesRmiMyDb());
    }
};

}
