#include"DrawIconText.h"
#include"DrawIconText_impl.h"

namespace nGUI {
		void drawIconText(StringView str, const Vec2& pos, const Font& defaultFont, const Font& iconFont, const Color& color) {
			DrawIconText_impl::draw(str, pos, defaultFont, iconFont, color);
		}
		void drawIconText(StringView str, const Arg::center_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			DrawIconText_impl::draw(str, pos->movedBy(-region.w / 2, -region.h / 2), defaultFont, iconFont, color);
		}
		void drawIconText(StringView str, const Arg::topLeft_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color) {
			DrawIconText_impl::draw(str, *pos, defaultFont, iconFont, color);
		}
		void drawIconText(StringView str, const Arg::topRight_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			DrawIconText_impl::draw(str, pos->movedBy(-region.w, 0), defaultFont, iconFont, color);
		}
		void drawIconText(StringView str, const Arg::topCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			DrawIconText_impl::draw(str, pos->movedBy(-region.w / 2, 0), defaultFont, iconFont, color);
		}
		void drawIconText(StringView str, const Arg::bottomCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			DrawIconText_impl::draw(str, pos->movedBy(-region.w / 2, -region.h), defaultFont, iconFont, color);
		}
		void drawIconText(StringView str, const Arg::bottomLeft_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			DrawIconText_impl::draw(str, pos->movedBy(0, -region.h), defaultFont, iconFont, color);
		}
		void drawIconText(StringView str, const Arg::bottomRight_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			DrawIconText_impl::draw(str, pos->movedBy(-region.w, -region.h), defaultFont, iconFont, color);
		}
		void drawIconText(StringView str, const Arg::leftCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			DrawIconText_impl::draw(str, pos->movedBy(0, -region.h / 2), defaultFont, iconFont, color);
		}
		void drawIconText(StringView str, const Arg::rightCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont, const Color& color) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			DrawIconText_impl::draw(str, pos->movedBy(-region.w, -region.h / 2), defaultFont, iconFont, color);
		}

		RectF regionIconText(StringView str, const Vec2& pos, const Font& defaultFont, const Font& iconFont) {
			return DrawIconText_impl::region(str, pos, defaultFont, iconFont);
		}
		RectF regionIconText(StringView str, const Arg::center_<Vec2>& pos, const Font& defaultFont, const Font& iconFont) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			return DrawIconText_impl::region(str, pos->movedBy(-region.w / 2, -region.h / 2), defaultFont, iconFont);
		}
		RectF regionIconText(StringView str, const Arg::topLeft_<Vec2>& pos, const Font& defaultFont, const Font& iconFont) {
			return DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
		}
		RectF regionIconText(StringView str, const Arg::topRight_<Vec2>& pos, const Font& defaultFont, const Font& iconFont) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			return DrawIconText_impl::region(str, pos->movedBy(-region.w, 0), defaultFont, iconFont);
		}
		RectF regionIconText(StringView str, const Arg::topCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			return DrawIconText_impl::region(str, pos->movedBy(-region.w / 2, 0), defaultFont, iconFont);
		}
		RectF regionIconText(StringView str, const Arg::bottomCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			return DrawIconText_impl::region(str, pos->movedBy(-region.w / 2, -region.h), defaultFont, iconFont);
		}
		RectF regionIconText(StringView str, const Arg::bottomLeft_<Vec2>& pos, const Font& defaultFont, const Font& iconFont) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			return DrawIconText_impl::region(str, pos->movedBy(0, -region.h), defaultFont, iconFont);
		}
		RectF regionIconText(StringView str, const Arg::bottomRight_<Vec2>& pos, const Font& defaultFont, const Font& iconFont) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			return DrawIconText_impl::region(str, pos->movedBy(-region.w, -region.h), defaultFont, iconFont);
		}
		RectF regionIconText(StringView str, const Arg::leftCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			return DrawIconText_impl::region(str, pos->movedBy(0, -region.h / 2), defaultFont, iconFont);
		}
		RectF regionIconText(StringView str, const Arg::rightCenter_<Vec2>& pos, const Font& defaultFont, const Font& iconFont) {
			const auto& region = DrawIconText_impl::region(str, *pos, defaultFont, iconFont);
			return DrawIconText_impl::region(str, pos->movedBy(-region.w, -region.h / 2), defaultFont, iconFont);
		}
}
