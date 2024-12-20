#include"DrawText.h"
#include"DrawIconText_impl.h"

namespace nGUI {
	void drawText(double size,const RoundRect& rect, const String& label, const Font& font,  Color color, const PositionType& position, bool is_replace) {
		switch (position) {
		case PositionType::center:
			font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).draw(size, Arg::center(rect.center()), color);
			break;
		case PositionType::bottomRight:
			font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).draw(size, Arg::bottomRight(rect.x + rect.w, rect.y + rect.h), color);
			break;
		case PositionType::bottomLeft:
			font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).draw(size, Arg::bottomLeft(rect.x, rect.y + rect.h), color);
			break;
		case PositionType::topRight:
			font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).draw(size, Arg::topRight(rect.x + rect.w, rect.y), color);
			break;
		case PositionType::topLeft:
			font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).draw(size, Arg::topLeft(rect.x, rect.y), color);
			break;
		case PositionType::rightCenter:
			font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).draw(size, Arg::rightCenter(rect.rightCenter()), color);
			break;
		case PositionType::leftCenter:
			font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).draw(size, Arg::leftCenter(rect.leftCenter()), color);
			break;
		case PositionType::topCenter:
			font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).draw(size, Arg::topCenter(rect.topCenter()), color);
			break;
		case PositionType::bottomCenter:
			font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).draw(size, Arg::bottomCenter(rect.bottomCenter()), color);
			break;
		default:
			font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).draw(size, Arg::topLeft(rect.x, rect.y), color);
			break;
		}
	}
	RectF drawTextRegion(double size, const RoundRect& rect, const String& label, const Font& font, const PositionType& position, bool is_replace) {
		switch (position) {
		case PositionType::center:
			return font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).region(size, Arg::center(rect.center()));
			break;
		case PositionType::bottomRight:
			return font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).region(size, Arg::bottomRight(rect.x + rect.w, rect.y + rect.h));
			break;
		case PositionType::bottomLeft:
			return font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).region(size, Arg::bottomLeft(rect.x, rect.y + rect.h));
			break;
		case PositionType::topRight:
			return font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).region(size, Arg::topRight(rect.x + rect.w, rect.y));
			break;
		case PositionType::topLeft:
			return font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).region(size, Arg::topLeft(rect.x, rect.y));
			break;
		case PositionType::rightCenter:
			return font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).region(size, Arg::rightCenter(rect.rightCenter()));
			break;
		case PositionType::leftCenter:
			return font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).region(size, Arg::leftCenter(rect.leftCenter()));
			break;
		case PositionType::topCenter:
			return font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).region(size, Arg::topCenter(rect.topCenter()));
			break;
		case PositionType::bottomCenter:
			return font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).region(size, Arg::bottomCenter(rect.bottomCenter()));
			break;
		default:
			return font(DrawIconText_impl::replaceUnicode(is_replace ? label.replaced(U'\\', U'\n') : label)).region(size, Arg::topLeft(rect.x, rect.y));
			break;
		}
	}
}
