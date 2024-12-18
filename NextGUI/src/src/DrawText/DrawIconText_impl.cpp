#include"DrawIconText_impl.h"

namespace nGUI {
	void DrawIconText_impl::draw(StringView str, const Vec2& pos, const Font& defaultFont, const Font& iconFont, const Color& color) {
			String stack;
			bool is_stack_start = false;
			Vec2 pen{ pos };
			Array<iconData> icons;

			const auto heightOffset = defaultFont.ascender() - iconFont.ascender();
			const auto fontOffset = defaultFont.fontSize() - iconFont.fontSize();

			for (const auto& glyph : defaultFont.getGlyphs(str)) {
				if (glyph.codePoint == U'$' && not is_stack_start) {
					is_stack_start = true;
					stack.clear();
					pen.x += iconFont.fontSize();
					continue;
				}
				if (glyph.codePoint == U'$' && is_stack_start) {
					is_stack_start = false;
					uint32 unicodeValue = std::stoul(stack.toWstr(), nullptr, 16);
					char32 unicode = static_cast<char32>(unicodeValue);
					icons << iconData{ unicode, pen.movedBy(-iconFont.fontSize(), heightOffset) };
					continue;
				}
				if (is_stack_start) {
					stack += glyph.codePoint;
				}
				else {
					glyph.texture.draw(pen + glyph.getOffset(), color);
					pen.x += glyph.xAdvance;
				}
			}
			for (const auto& icon : icons) {
				iconFont(icon.icon).draw(icon.pos.movedBy(0, -fontOffset / 2.0), color);
			}
		}
	RectF DrawIconText_impl::region(StringView str, const Vec2& pos, const Font& defaultFont, const Font& iconFont) {
			String stack;
			bool is_stack_start = false;
			Vec2 pen{ pos };
			Array<iconData> icons;

			const auto heightOffset = defaultFont.ascender() - iconFont.ascender();

			for (const auto& glyph : defaultFont.getGlyphs(str)) {
				if (glyph.codePoint == U'$' && not is_stack_start) {
					is_stack_start = true;
					stack.clear();
					pen.x += iconFont.fontSize();
					continue;
				}
				if (glyph.codePoint == U'$' && is_stack_start) {
					is_stack_start = false;
					uint32 unicodeValue = std::stoul(stack.toWstr(), nullptr, 16);
					char32 unicode = static_cast<char32>(unicodeValue);
					icons << iconData{ unicode, pen.movedBy(-iconFont.fontSize(), heightOffset) };
					continue;
				}
				if (is_stack_start) {
					stack += glyph.codePoint;
				}
				else {
					pen.x += glyph.xAdvance;
				}
			}
			return RectF{ pos,pen.movedBy(0,defaultFont.height()) - pos };
		}
}
