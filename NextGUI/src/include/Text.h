#pragma once
#ifndef _NEXTGUI_TEXT_H_
#define _NEXTGUI_TEXT_H_

#include"PositionType.h"

#include"stdafx.h"

namespace nGUI {
	struct Text {
		String text{};
		Color color = Palette::Black;
		PositionType position = PositionType::center;
	};
}

#endif
