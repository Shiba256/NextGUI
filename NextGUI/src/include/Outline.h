#pragma once
#ifndef _NEXTGUI_OUTLINE_H_
#define _NEXTGUI_OUTLINE_H_

#include"nPalette.h"

#include"stdafx.h"

namespace nGUI{
	struct Outline {
		double thickness = 0.0;
		ColorF color = nPalette::Clear;
	};
}

#endif
