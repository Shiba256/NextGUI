#include"DrawText.h"
#include"DrawIconText.h"

namespace nGUI {
	void drawText(const RoundRect& rect, const String& label, const Font& font, const Font& iconFont, Color color, const PositionType& position, bool is_replace) {
		switch (position) {
		case PositionType::center:
			drawIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::center(rect.center()), font, iconFont, color);
			break;
		case PositionType::bottomRight:
			drawIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::bottomRight(rect.x + rect.w, rect.y + rect.h), font, iconFont, color);
			break;
		case PositionType::bottomLeft:
			drawIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::bottomLeft(rect.x, rect.y + rect.h), font, iconFont, color);
			break;
		case PositionType::topRight:
			drawIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::topRight(rect.x + rect.w, rect.y), font, iconFont, color);
			break;
		case PositionType::topLeft:
			drawIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::topLeft(rect.x, rect.y), font, iconFont, color);
			break;
		case PositionType::rightCenter:
			drawIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::rightCenter(rect.rightCenter()), font, iconFont, color);
			break;
		case PositionType::leftCenter:
			drawIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::leftCenter(rect.leftCenter()), font, iconFont, color);
			break;
		case PositionType::topCenter:
			drawIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::topCenter(rect.topCenter()), font, iconFont, color);
			break;
		case PositionType::bottomCenter:
			drawIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::bottomCenter(rect.bottomCenter()), font, iconFont, color);
			break;
		default:
			drawIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::topLeft(rect.x, rect.y), font, iconFont, color);
			break;
		}
	}
	RectF drawTextRegion(const RoundRect& rect, const String& label, const Font& font, const Font& iconFont, const PositionType& position, bool is_replace) {
		switch (position) {
		case PositionType::center:
			return regionIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::center(rect.center()), font, iconFont);
			break;
		case PositionType::bottomRight:
			return regionIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::bottomRight(rect.x + rect.w, rect.y + rect.h), font, iconFont);
			break;
		case PositionType::bottomLeft:
			return regionIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::bottomLeft(rect.x, rect.y + rect.h), font, iconFont);
			break;
		case PositionType::topRight:
			return regionIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::topRight(rect.x + rect.w, rect.y), font, iconFont);
			break;
		case PositionType::topLeft:
			return regionIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::topLeft(rect.x, rect.y), font, iconFont);
			break;
		case PositionType::rightCenter:
			return regionIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::rightCenter(rect.rightCenter()), font, iconFont);
			break;
		case PositionType::leftCenter:
			return regionIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::leftCenter(rect.leftCenter()), font, iconFont);
			break;
		case PositionType::topCenter:
			return regionIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::topCenter(rect.topCenter()), font, iconFont);
			break;
		case PositionType::bottomCenter:
			return regionIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::bottomCenter(rect.bottomCenter()), font, iconFont);
			break;
		default:
			return regionIconText(is_replace ? label.replaced(U'\\', U'\n') : label, Arg::topLeft(rect.x, rect.y), font, iconFont);
			break;
		}
	}
}
