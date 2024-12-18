#pragma once
#ifndef _NEXTGUI_DRAWTEXT_H_
#define _NEXTGUI_DRAWTEXT_H_

#include"PositionType.h"

namespace nGUI {
	void drawText(const RoundRect& rect, const String& label, const Font& font, const Font& iconFont, Color color, const PositionType& position, bool is_replace);
	RectF drawTextRegion(const RoundRect& rect, const String& label, const Font& font, const Font& iconFont, const PositionType& position, bool is_replace);
}

#endif
