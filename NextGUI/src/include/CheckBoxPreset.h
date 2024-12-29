#pragma once
#ifndef _NEXT_GUI_CHECKBOXPRESET_
#define _NEXT_GUI_CHECKBOXPRESET_

#include"CheckBox.h"

namespace nGUI {
	namespace Preset {
		namespace CheckBox {
			static inline CheckBoxStyle Default(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				CheckBoxStyle style{};
				style.rrs = {
					.background_color = {.color_from = Palette::White},
					.shadow = {.offset = {0, 4}, .blur = 8, .spread = 0, .color = ColorF(0.0, 0.2)}
				};
				style.rrs_mouseover = {
					.background_color = {.color_from = Palette::White},
					.outline = {.thickness = 0.5,.color = Palette::Lightskyblue},
					.shadow = {.offset = {0, 6}, .blur = 10, .spread = 0, .color = ColorF(0.0, 0.3)}
				};
				style.rrs_clicked = {
					.background_color = {.color_from = Palette::White},
					.shadow = {.offset = {0, 2}, .blur = 6, .spread = 0, .color = ColorF(0.0, 0.15)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = Palette::Lightgray},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};

				style.checkbox = {
					.background_color = {.color_from = ColorF{0.9}},
					.outline = {.thickness = 0.5,.color = Palette::Black},
					.shadow = {.offset = {0, 2}, .blur = 4, .spread = 0, .color = ColorF(0.0, 0.3)},
					.r = 6.0
				};
				style.checkbox_mouseover = {
					.background_color = {.color_from = ColorF{0.9}},
					.outline = {.thickness = 0.5,.color = Palette::Black},
					.shadow = {.offset = {0, 2}, .blur = 4, .spread = 0, .color = ColorF(0.0, 0.3)},
					.r = 6.0
				};
				style.checkbox_clicked = {
					.background_color = {.color_from = ColorF{0.95}},
					.outline = {.thickness = 0.5,.color = Palette::Lightskyblue},
					.shadow = {.offset = {0, 2}, .blur = 4, .spread = 0, .color = ColorF(0.0, 0.3)},
					.r = 6.0
				};
				style.checkbox_unable = {
					.background_color = {.color_from = Palette::Gray},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)},
					.r = 6.0
				};

				style.text = { .text = text, .color = Palette::Black };
				style.check_color = Palette::Skyblue;
				style.checkbox_margin = { 10, 0 };
				style.checkbox_size = { 20, 20 };
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

			static inline CheckBoxStyle Modern(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				CheckBoxStyle style = Default(pos, position_type, size, text);
				style.rrs.background_color = { .color_from = ColorF(0.95), .color_to = ColorF(0.9), .type = GradationType::top_bottom };
				style.rrs.outline = { .thickness = 1.5, .color = ColorF(0.8) };
				style.rrs.shadow = { .offset = {0, 4}, .blur = 12, .spread = 0, .color = ColorF(0.0, 0.2) };

				style.checkbox.background_color = { .color_from = Palette::White };
				style.checkbox.shadow = { .offset = {0, 2}, .blur = 6, .spread = 0, .color = ColorF(0.0, 0.15) };
				style.checkbox_outline = { .thickness = 1.5, .color = ColorF(0.8) };
				return style;
			}

			static inline CheckBoxStyle Frosted(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				CheckBoxStyle style = Default(pos, position_type, size, text);
				style.rrs.background_color = { .color_from = Scene::GetBackground().lerp(ColorF(1.0), 0.85), .color_to = Scene::GetBackground().lerp(ColorF(1.0), 0.75), .type = GradationType::top_bottom };
				style.rrs.outline = { .thickness = 1.0, .color = ColorF(0.7) };
				style.rrs.shadow = { .offset = {0, 6}, .blur = 15, .spread = 0, .color = ColorF(0.0, 0.25) };

				style.checkbox.background_color = { .color_from = Scene::GetBackground().lerp(ColorF(0.0), 0.2) };
				style.checkbox.shadow = { .offset = {0, 2}, .blur = 8, .spread = 0, .color = ColorF(0.0, 0.3) };
				style.checkbox_outline = { .thickness = 1.0, .color = ColorF(0.6) };
				return style;
			}

			static inline CheckBoxStyle Glassy(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				CheckBoxStyle style = Default(pos, position_type, size, text);
				style.rrs.background_color = { .color_from = Scene::GetBackground().lerp(ColorF(1.0), 0.9), .color_to = Scene::GetBackground().lerp(ColorF(1.0), 0.8), .type = GradationType::top_bottom };
				style.rrs.outline = { .thickness = 2.0, .color = ColorF(0.85) };
				style.rrs.shadow = { .offset = {0, 8}, .blur = 20, .spread = 0, .color = ColorF(0.0, 0.3) };

				style.checkbox.background_color = { .color_from = Palette::White, .color_to = Palette::Lightgray, .type = GradationType::top_bottom };
				style.checkbox.shadow = { .offset = {0, 4}, .blur = 10, .spread = 0, .color = ColorF(0.0, 0.25) };
				style.checkbox_outline = { .thickness = 2.0, .color = ColorF(0.8) };
				return style;
			}
		}
	}
}

#endif
