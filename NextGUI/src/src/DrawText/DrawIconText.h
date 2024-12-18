#pragma once
#ifndef _NEXTGUI_DRAWICONTEXT_H_
#define _NEXTGUI_DRAWICONTEXT_H_

#include"stdafx.h"

namespace nGUI {
	void drawIconText(StringView str, const Vec2& pos, const Font& defaultFont, const Font& iconFont, const Color& color);
	void drawIconText(StringView str, const Arg::center_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color);
	void drawIconText(StringView str, const Arg::topLeft_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color);
	void drawIconText(StringView str, const Arg::topRight_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color);
	void drawIconText(StringView str, const Arg::topCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color);
	void drawIconText(StringView str, const Arg::bottomCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color);
	void drawIconText(StringView str, const Arg::bottomLeft_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color);
	void drawIconText(StringView str, const Arg::bottomRight_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color);
	void drawIconText(StringView str, const Arg::leftCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color);
	void drawIconText(StringView str, const Arg::rightCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color);

	RectF regionIconText(StringView str, const Vec2& pos, const Font& defaultFont, const Font& iconFont);
	RectF regionIconText(StringView str, const Arg::center_<Vec2>& pos, const Font& defaultFont, const Font& iconFont);
	RectF regionIconText(StringView str, const Arg::topLeft_<Vec2>& pos, const Font& defaultFont, const Font& iconFont);
	RectF regionIconText(StringView str, const Arg::topRight_<Vec2>& pos, const Font& defaultFont, const Font& iconFont);
	RectF regionIconText(StringView str, const Arg::topCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont);
	RectF regionIconText(StringView str, const Arg::bottomCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont);
	RectF regionIconText(StringView str, const Arg::bottomLeft_<Vec2>& pos, const Font& defaultFont, const Font& iconFont);
	RectF regionIconText(StringView str, const Arg::bottomRight_<Vec2>& pos, const Font& defaultFont, const Font& iconFont);
	RectF regionIconText(StringView str, const Arg::leftCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont);
	RectF regionIconText(StringView str, const Arg::rightCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont);
}
#endif
