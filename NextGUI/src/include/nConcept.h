#pragma once
#ifndef _NEXTGUI_NCONCEPT_H_
#define _NEXTGUI_NCONCEPT_H_

#include"AbstractComponent.h"

#include"stdafx.h"

namespace nGUI {
	namespace nConcept {
		template<class Type>
		concept Siv3DColorType = requires {
			std::same_as<Color, Type> ||
				std::same_as<ColorF, Type> ||
				std::same_as < HSV, Type >;
		};

		template<class Type>
		concept Component = std::is_base_of<AbstractComponent, Type>::value;
	}
}
#endif
