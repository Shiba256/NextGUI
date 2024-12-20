#pragma once
#ifndef _NEXTGUI_DRAWTEXT_H_
#define _NEXTGUI_DRAWTEXT_H_

#include"PositionType.h"

namespace nGUI {
	void drawText(double size, const RoundRect& rect, const String& label, const Font& font, Color color, const PositionType& position, bool is_replace = true);
	RectF drawTextRegion(double size, const RoundRect& rect, const String& label, const Font& font, const PositionType& position, bool is_replace = true);
}

#endif
