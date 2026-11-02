//================================================================================================
//   Copyright (c)   Messerli Informatik AG, CH-8957 Spreitenbach
//================================================================================================
#include "stdafx.h"
#include "RmiCppUnitTest.h"
#include "MandatoryFields/UI/MandatoryFieldMarkerUpdater.h"

namespace Messerli::MandatoryFields {

    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    TEST_CLASS(MandatoryFieldMarkerUpdaterTest) {
        TEST_CATEGORY_UNIT_TEST
public:
    TEST_METHOD(Update_AddsAsterisk)
    {
        //arrange
        fakeit::Mock<UI::Adapter::AbstractFieldAccessor> fieldAccessor;
        fakeit::Mock<Data::Adapter::AbstractINIAccessor> iniAccessor;
        fakeit::When(Method(iniAccessor, ReadBOOL)).AlwaysReturn(true);
        fakeit::When(Method(fieldAccessor, GetText)).AlwaysReturn(_T("Name"));
        fakeit::When(Method(fieldAccessor, SetText)).AlwaysDo([](int, CString) {});
        UI::MandatoryFieldMarkerUpdater updater(fieldAccessor.get(), iniAccessor.get());
        //act
        updater.Update();
        //assert
        fakeit::Verify(Method(fieldAccessor, SetText)).AtLeast(1);
    }

    TEST_METHOD(Update_NoMandatory_NoAsteriskAdded)
    {
        //arrange
        fakeit::Mock<UI::Adapter::AbstractFieldAccessor> fieldAccessor;
        fakeit::Mock<Data::Adapter::AbstractINIAccessor> iniAccessor;
        fakeit::When(Method(iniAccessor, ReadBOOL)).AlwaysReturn(false);
        fakeit::When(Method(fieldAccessor, GetText)).AlwaysReturn(_T("Name"));
        fakeit::When(Method(fieldAccessor, SetText)).AlwaysDo([](int, CString) {});
        UI::MandatoryFieldMarkerUpdater updater(fieldAccessor.get(), iniAccessor.get());
        //act
        updater.Update();
        //assert
        fakeit::Verify(Method(fieldAccessor, SetText)).AtLeast(1);
    }

    TEST_METHOD(Abstract_UpdateMarkerks_VerifyCalledOnce)
    {
        //arrange
        fakeit::Mock<UI::AbstractUpdater> updater;
        fakeit::When(Method(updater, Update)).AlwaysDo([] {});
        //act
        updater.get().Update();
        //assert
        fakeit::Verify(Method(updater, Update)).Exactly(1);
    }

    };
}
