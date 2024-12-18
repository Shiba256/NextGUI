#pragma once
#ifndef _NEXTGUI_ROUNDRECTSTYLE_H_
#define _NEXTGUI_ROUNDRECTSTYLE_H_

#include"GradationColor.h"
#include"Outline.h"
#include"Shadow.h"

#include"stdafx.h"

namespace nGUI {
	struct RoundRectStyle {
		GradationColor<ColorF> background_color{};
		Outline outline{};
		Shadow shadow{};
		double r = 0.0;
	};
}


#endif
