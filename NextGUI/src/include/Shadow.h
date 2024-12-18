#pragma once
#ifndef _NEXTGUI_SHADOW_H_
#define  _NEXTGUI_SHADOW_H_

#include"stdafx.h"

namespace nGUI {
	struct Shadow {
		Vec2 offset = { 0,0 };
		double blur = 0.0;
		double spread = 0.0;
		ColorF color = ColorF{ 0,0.5 };
		bool fill = true;
	};
}

#endif
