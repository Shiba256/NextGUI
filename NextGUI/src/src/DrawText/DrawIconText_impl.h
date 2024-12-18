#pragma once
#ifndef _NEXTGUI_DRAWICONTEXTIMPL_H_
#define _NEXTGUI_DRAWICONTEXTIMPL_H_

#include"stdafx.h"

namespace nGUI {
	struct DrawIconText_impl {
		static void draw(StringView str, const Vec2& pos, const Font& defaultFont, const Font& iconFont, const Color& color);
		static RectF region(StringView str, const Vec2& pos, const Font& defaultFont, const Font& iconFont);
	private:
		struct iconData {
			char32 icon;
			Vec2 pos;
		};
	};
}

#endif
