#pragma once
#include "..\stdafx.h"
#include <codecvt>
namespace Blam
{
	namespace Shared
	{
		namespace DataTypes
		{
			/*********************************************************************
			* Blam::Shared::DataTypes::DatumIndex
			* 4 BYTE Tag Structure for any TagIndices of Halo 2 CacheFiles
			**********************************************************************/
			struct DatumIndex
			{
				//Defualt Constructor
				DatumIndex()
				{
					this->Index = 0xFFFF;
					this->Salt = 0xFFFF;
				}
				//Copy Constructor
				DatumIndex(INT32 Identifier)
				{
					this->Index = Identifier & 0x0000FFFF;
					this->Salt = Identifier & 0xFFFF0000;
				}
				static const INT32 Null = 0xFFFFFFFF;
			protected:
				//Returns Absolute Index
				INT16 ToAbsoluteIndex();
				//Returns Datum Salt
				INT16 ToIdentifier();
				//Returs true is DatumIndex is not Invalid
				bool IsNull();
				//Return in StringFormat
				std::string ToString();

				void operator = (const INT32 &Value);
				void operator = (const DatumIndex &DatumIndex);
				bool operator == (const INT32 &Value);
				bool operator == (const DatumIndex &DatumIndex);
				bool operator != (const INT32 &Value);
				bool operator != (const DatumIndex &DatumIndex);
			private:
				//Absolute Index 
				INT16 Index;

				//Salt for Unique Identification
				INT16 Salt;

			};
			static_assert(sizeof(DatumIndex) == 4, "Invalid Size for struct (DatumIndex)");
		}
	}
}
			
#pragma region DatumIndex
inline INT16 Blam::Shared::DataTypes::DatumIndex::ToAbsoluteIndex()
{
	return this->Index;
}
inline INT16 Blam::Shared::DataTypes::DatumIndex::ToIdentifier()
{
	return this->Salt;
}
inline bool Blam::Shared::DataTypes::DatumIndex::IsNull()
{

	return this->Salt = 0xFFFF && this->Index == 0xFFFF;

}
inline void Blam::Shared::DataTypes::DatumIndex::operator = (const INT32 &Value)
{
	this->Index = Value & 0x0000FFFF;
	this->Salt = Value & 0xFFFF0000;
}
inline void Blam::Shared::DataTypes::DatumIndex::operator = (const DatumIndex &DatumIndex)
{
	this->Index = DatumIndex.Index;
	this->Salt = DatumIndex.Salt;
}
inline bool Blam::Shared::DataTypes::DatumIndex::operator== (const INT32 &Value)
{
	return (this->Index == Value & 0x0000FFFF) && (this->Salt == Value & 0xFFFF0000);
}
inline bool Blam::Shared::DataTypes::DatumIndex::operator== (const DatumIndex &DatumIndex)
{
	return (this->Index == DatumIndex.Index) && (this->Salt == DatumIndex.Salt);
}
inline bool Blam::Shared::DataTypes::DatumIndex::operator!= (const INT32 &Value)
{
	return (this->Index != Value & 0x0000FFFF) || (this->Salt != Value & 0xFFFF0000);
}
inline bool Blam::Shared::DataTypes::DatumIndex::operator!= (const DatumIndex &DatumIndex)
{
	return (this->Index != DatumIndex.Index) || (this->Salt != DatumIndex.Salt);
}
inline std::string Blam::Shared::DataTypes::DatumIndex::ToString()
{
	std::string val;
	val = (UINT32)((this->Salt << 16) | this->Index);
	return val;
}

#pragma endregion