//================================================================================================
//   Copyright (c)   Messerli Informatik AG, CH-8957 Spreitenbach
//================================================================================================
#include "stdafx.h"
#include "RmiCppUnitTest.h"
#include "MandatoryFields/BL/MandatoryService.h"
#include "MandatoryFields/Data/MandatoryFieldsMap.h"

namespace Messerli::MandatoryFields {

    using namespace Microsoft::VisualStudio::CppUnitTestFramework;

    TEST_CLASS(MandatoryFieldServiceTest) {
        TEST_CATEGORY_UNIT_TEST
public:
    TEST_METHOD(ValidateField_FieldNotFound_ReturnsTrue)
    {
        //arrange
        fakeit::Mock<UI::Adapter::AbstractFieldAccessor> fieldAccessor;
        fakeit::Mock<UI::AbstractUpdater> updater;
        fakeit::Mock<Data::Adapter::AbstractINIAccessor> iniAccessor;
        BL::MandatoryFieldService service(iniAccessor.get(), fieldAccessor.get(), updater.get());
        //act
        let result = service.ValidateField(9999, false);
        //assert
        Assert::IsTrue(result);
    }

    TEST_METHOD(ValidateField_NotMandatory_ClearsInvalid)
    {
        //arrange
        fakeit::Mock<UI::Adapter::AbstractFieldAccessor> fieldAccessor;
        fakeit::Mock<UI::AbstractUpdater> updater;
        fakeit::Mock<Data::Adapter::AbstractINIAccessor> iniAccessor;
        fakeit::When(Method(iniAccessor, ReadBOOL)).AlwaysReturn(false);
        fakeit::When(Method(fieldAccessor, ClearInvalid)).AlwaysDo([](int) {});
        BL::MandatoryFieldService service(iniAccessor.get(), fieldAccessor.get(), updater.get());
        //act
        service.ValidateField(Data::MandatoryFieldsMap[0].EditID, false);
        //assert
        fakeit::Verify(Method(fieldAccessor, ClearInvalid)).Exactly(1);
    }

    TEST_METHOD(ValidateField_EmptyMandatoryField_MarksInvalid)
    {
        //arrange
        fakeit::Mock<UI::Adapter::AbstractFieldAccessor> fieldAccessor;
        fakeit::Mock<UI::AbstractUpdater> updater;
        fakeit::Mock<Data::Adapter::AbstractINIAccessor> iniAccessor;
        fakeit::When(Method(iniAccessor, ReadBOOL)).AlwaysReturn(true);
        fakeit::When(Method(fieldAccessor, GetText)).AlwaysReturn(_T(""));
        fakeit::When(Method(fieldAccessor, MarkInvalid)).AlwaysDo([](int) {});
        BL::MandatoryFieldService service(iniAccessor.get(), fieldAccessor.get(), updater.get());
        //act
        service.ValidateField(Data::MandatoryFieldsMap[0].EditID, false);
        //assert
        fakeit::Verify(Method(fieldAccessor, MarkInvalid)).Exactly(1);
    }

    TEST_METHOD(ValidateField_RestoreFocus_SetsFocus)
    {
        //arrange
        fakeit::Mock<UI::Adapter::AbstractFieldAccessor> fieldAccessor;
        fakeit::Mock<UI::AbstractUpdater> updater;
        fakeit::Mock<Data::Adapter::AbstractINIAccessor> iniAccessor;
        fakeit::When(Method(iniAccessor, ReadBOOL)).AlwaysReturn(true);
        fakeit::When(Method(fieldAccessor, GetText)).AlwaysReturn(_T(""));
        fakeit::When(Method(fieldAccessor, MarkInvalid)).AlwaysDo([](int) {});
        fakeit::When(Method(fieldAccessor, SetFocus)).AlwaysDo([](int) {});
        BL::MandatoryFieldService service(iniAccessor.get(), fieldAccessor.get(), updater.get());
        //act
        service.ValidateField(Data::MandatoryFieldsMap[0].EditID, true);
        //assert
        fakeit::Verify(Method(fieldAccessor, SetFocus)).Exactly(1);
    }

    TEST_METHOD(ValidateField_FilledMandatoryField_ClearsInvalid)
    {
        //arrange
        fakeit::Mock<UI::Adapter::AbstractFieldAccessor> fieldAccessor;
        fakeit::Mock<UI::AbstractUpdater> updater;
        fakeit::Mock<Data::Adapter::AbstractINIAccessor> iniAccessor;
        fakeit::When(Method(iniAccessor, ReadBOOL)).AlwaysReturn(true);
        fakeit::When(Method(fieldAccessor, GetText)).AlwaysReturn(_T("abc"));
        fakeit::When(Method(fieldAccessor, ClearInvalid)).AlwaysDo([](int) {});
        BL::MandatoryFieldService service(iniAccessor.get(), fieldAccessor.get(), updater.get());
        //act
        service.ValidateField(Data::MandatoryFieldsMap[0].EditID, false);
        //assert
        fakeit::Verify(Method(fieldAccessor, ClearInvalid)).Exactly(1);
    }

    TEST_METHOD(UpdateMarkers_CallsUpdater)
    {
        //arrange
        fakeit::Mock<UI::Adapter::AbstractFieldAccessor> fieldAccessor;
        fakeit::Mock<UI::AbstractUpdater> updater;
        fakeit::Mock<Data::Adapter::AbstractINIAccessor> iniAccessor;
        fakeit::When(Method(updater, Update)).AlwaysDo([] {});
        BL::MandatoryFieldService service(iniAccessor.get(), fieldAccessor.get(), updater.get());
        //act
        service.UpdateMarkers();
        //assert
        fakeit::Verify(Method(updater, Update)).Exactly(1);
    }

    };

}
