#pragma once
#ifndef TAG_GROUPS_H
#define TAG_GROUPS_H
#include "..\stdafx.h"
#include "..\Enums\Tags\TagGroups.h"
#include "DataTypes\Strings.h"

#define TAG_GROUP_SIZE_ASSERT(tagGroup,size)\
static_assert (sizeof(tagGroup) == (size),"Invalid Size for TagGroup <" #tagGroup">");
namespace Blam
{
	namespace Cache
	{		
		//Base definition for a TagGroup
		template <const LONG GroupTag>
		struct TagGroup
		{
			static const LONG GroupTagValue = GroupTag;				
			static virtual std::string GetLongName()
			{
				return std::string(0);
			}
		};
		
			
		
	}
}

#endif