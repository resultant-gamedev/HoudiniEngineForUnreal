/*
* Copyright (c) <2017> Side Effects Software Inc.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Produced by:
*      Mykola Konyk
*      Side Effects Software Inc
*      123 Front Street West, Suite 1401
*      Toronto, Ontario
*      Canada   M5J 2M2
*      416-504-9876
*
*/

#pragma once

#include "HoudiniAssetParameter.h"
#include "HoudiniAssetParameterButton.generated.h"

UCLASS()
class HOUDINIENGINERUNTIME_API UHoudiniAssetParameterButton : public UHoudiniAssetParameter
{
    GENERATED_UCLASS_BODY()

    public:

        /** Destructor. **/
        virtual ~UHoudiniAssetParameterButton();

    public:

        /** Create instance of this class. **/
        static UHoudiniAssetParameterButton * Create(
            UObject * InPrimaryObject,
            UHoudiniAssetParameter * InParentParameter,
            HAPI_NodeId InNodeId,
            const HAPI_ParmInfo & ParmInfo );

    public:

        /** Create this parameter from HAPI information. **/
        virtual bool CreateParameter(
            UObject * InPrimaryObject,
            UHoudiniAssetParameter * InParentParameter,
            HAPI_NodeId InNodeId,
            const HAPI_ParmInfo & ParmInfo ) override;

#if WITH_EDITOR

        /** Create widget for this parameter and add it to a given category. **/
        virtual void CreateWidget( IDetailCategoryBuilder & DetailCategoryBuilder ) override;

#endif // WITH_EDITOR

        /** Upload parameter value to HAPI. **/
        virtual bool UploadParameterValue() override;

        /** Set parameter value. **/
        virtual bool SetParameterVariantValue(
            const FVariant & Variant, int32 Idx = 0, bool bTriggerModify = true,
            bool bRecordUndo = true ) override;

    protected:

#if WITH_EDITOR

        /** Handler for button click. **/
        FReply OnButtonClick();

#endif // WITH_EDITOR
};
