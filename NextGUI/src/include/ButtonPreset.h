#pragma once
#ifndef _NEXT_GUI_BUTTONPRESET_H_
#define _NEXT_GUI_BUTTONPRESET_H_
#include"Button.h"
namespace nGUI {
	namespace Preset {
		namespace Button {
			static inline ButtonStyle Default(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				ButtonStyle style;
				style.rrs = {
					.background_color = {.color_from = Palette::White},
					.shadow = {.offset = {0, 4}, .blur = 8, .spread = 0, .color = ColorF(0.0, 0.2)}
				};
				style.rrs_pressed = {
					.background_color = {.color_from = Palette::Lightgray},
					.shadow = {.offset = {0, 2}, .blur = 6, .spread = 0, .color = ColorF(0.0, 0.15)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = Palette::Gray},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};
				style.text = { .text = text, .color = Palette::Black };
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

			static inline ButtonStyle Primary(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				ButtonStyle style;
				style.rrs = {
					.background_color = {.color_from = Palette::Blue, .color_to = Palette::Skyblue, .type = GradationType::top_bottom},
					.outline = {.thickness = 2.0, .color = Palette::Darkblue},
					.shadow = {.offset = {0, 6}, .blur = 10, .spread = 0, .color = ColorF(0.0, 0.3)}
				};
				style.rrs_pressed = {
					.background_color = {.color_from = Palette::Darkblue, .color_to = Palette::Blue, .type = GradationType::top_bottom},
					.outline = {.thickness = 2.0, .color = Palette::Navy},
					.shadow = {.offset = {0, 3}, .blur = 8, .spread = 0, .color = ColorF(0.0, 0.25)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = Palette::Gray},
					.outline = {.thickness = 2.0, .color = Palette::Darkgray},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};
				style.text = { .text = text, .color = Palette::White };
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

			static inline ButtonStyle Danger(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				ButtonStyle style;
				style.rrs = {
					.background_color = {.color_from = Palette::Red, .color_to = Palette::Orange, .type = GradationType::top_bottom},
					.outline = {.thickness = 2.0, .color = Palette::Darkred},
					.shadow = {.offset = {0, 6}, .blur = 12, .spread = 0, .color = ColorF(0.1, 0.4)}
				};
				style.rrs_pressed = {
					.background_color = {.color_from = Palette::Darkred, .color_to = Palette::Red, .type = GradationType::top_bottom},
					.outline = {.thickness = 2.0, .color = Palette::Black},
					.shadow = {.offset = {0, 3}, .blur = 8, .spread = 0, .color = ColorF(0.1, 0.3)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = Palette::Gray},
					.outline = {.thickness = 2.0, .color = Palette::Darkgray},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};
				style.text = { .text = text, .color = Palette::White };
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

			static inline ButtonStyle Success(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				ButtonStyle style;
				style.rrs = {
					.background_color = {.color_from = Palette::Green, .color_to = Palette::Lightgreen, .type = GradationType::top_bottom},
					.outline = {.thickness = 2.0, .color = Palette::Darkgreen},
					.shadow = {.offset = {0, 6}, .blur = 12, .spread = 0, .color = ColorF(0.0, 0.35)}
				};
				style.rrs_pressed = {
					.background_color = {.color_from = Palette::Darkgreen, .color_to = Palette::Green, .type = GradationType::top_bottom},
					.outline = {.thickness = 2.0, .color = Palette::Forestgreen},
					.shadow = {.offset = {0, 3}, .blur = 8, .spread = 0, .color = ColorF(0.0, 0.3)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = Palette::Gray},
					.outline = {.thickness = 2.0, .color = Palette::Darkgray},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};
				style.text = { .text = text, .color = Palette::White };
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

			// Neutral Tone - Calm and Elegant
			static inline ButtonStyle Neutral(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				ButtonStyle style;
				style.rrs = {
					.background_color = {.color_from = ColorF(0.9), .color_to = ColorF(0.8), .type = GradationType::top_bottom},
					.shadow = {.offset = {0, 5}, .blur = 10, .spread = 0, .color = ColorF(0.0, 0.2)}
				};
				style.rrs_pressed = {
					.background_color = {.color_from = ColorF(0.8), .color_to = ColorF(0.7), .type = GradationType::top_bottom},
					.shadow = {.offset = {0, 3}, .blur = 8, .spread = 0, .color = ColorF(0.0, 0.15)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = ColorF(0.85), .color_to = ColorF(0.85)},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};
				style.text = { .text = text, .color = ColorF(0.2) };
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

			// Minimalist Accent - Subtle Modern Contrast
			static inline ButtonStyle Accent(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				ButtonStyle style;
				style.rrs = {
					.background_color = {.color_from = ColorF(0.3, 0.6, 0.8), .color_to = ColorF(0.5, 0.7, 0.9), .type = GradationType::top_bottom},
					.outline = {.thickness = 1.5, .color = ColorF(0.2, 0.5, 0.7)},
					.shadow = {.offset = {0, 4}, .blur = 8, .spread = 0, .color = ColorF(0.0, 0.25)}
				};
				style.rrs_pressed = {
					.background_color = {.color_from = ColorF(0.2, 0.5, 0.7), .color_to = ColorF(0.4, 0.6, 0.8), .type = GradationType::top_bottom},
					.outline = {.thickness = 1.5, .color = ColorF(0.1, 0.4, 0.6)},
					.shadow = {.offset = {0, 2}, .blur = 6, .spread = 0, .color = ColorF(0.0, 0.2)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = ColorF(0.6, 0.6, 0.6)},
					.outline = {.thickness = 1.5, .color = ColorF(0.5)},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};
				style.text = { .text = text, .color = Palette::White };
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

			// Subtle Glow - Futuristic Look
			static inline ButtonStyle Glow(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				ButtonStyle style;
				style.rrs = {
					.background_color = {.color_from = ColorF(0.1, 0.2, 0.3), .color_to = ColorF(0.15, 0.25, 0.35), .type = GradationType::top_bottom},
					.shadow = {.offset = {0, 6}, .blur = 15, .spread = -3, .color = ColorF(0.1, 0.6)}
				};
				style.rrs_pressed = {
					.background_color = {.color_from = ColorF(0.08, 0.18, 0.28), .color_to = ColorF(0.1, 0.2, 0.3), .type = GradationType::top_bottom},
					.shadow = {.offset = {0, 3}, .blur = 12, .spread = -2, .color = ColorF(0.1, 0.5)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = ColorF(0.2, 0.2, 0.2)},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};
				style.text = { .text = text, .color = Palette::White };
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}
			// Soft Gradient - Calm and Modern
			static inline ButtonStyle SoftGradient(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				ButtonStyle style;
				style.rrs = {
					.background_color = {.color_from = ColorF(0.95, 0.96, 0.97), .color_to = ColorF(0.85, 0.87, 0.9), .type = GradationType::top_bottom},
					.shadow = {.offset = {0, 4}, .blur = 8, .spread = 0, .color = ColorF(0.0, 0.15)}
				};
				style.rrs_pressed = {
					.background_color = {.color_from = ColorF(0.87, 0.88, 0.9), .color_to = ColorF(0.8, 0.82, 0.85), .type = GradationType::top_bottom},
					.shadow = {.offset = {0, 2}, .blur = 6, .spread = 0, .color = ColorF(0.0, 0.1)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = ColorF(0.9, 0.9, 0.9)},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};
				style.text = { .text = text, .color = ColorF(0.3) };
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

			// Glass Effect - Transparent and Elegant
			static inline ButtonStyle Glass(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				ButtonStyle style;
				style.rrs = {
					.background_color = {.color_from = ColorF(0.9, 0.9, 0.9, 0.8), .color_to = ColorF(0.8, 0.8, 0.8, 0.6), .type = GradationType::top_bottom},
					.outline = {.thickness = 1.0, .color = ColorF(0.8, 0.8, 0.8, 0.5)},
					.shadow = {.offset = {0, 4}, .blur = 12, .spread = 0, .color = ColorF(0.0, 0.25)}
				};
				style.rrs_pressed = {
					.background_color = {.color_from = ColorF(0.8, 0.8, 0.8, 0.7), .color_to = ColorF(0.7, 0.7, 0.7, 0.5), .type = GradationType::top_bottom},
					.outline = {.thickness = 1.0, .color = ColorF(0.7, 0.7, 0.7, 0.4)},
					.shadow = {.offset = {0, 3}, .blur = 10, .spread = 0, .color = ColorF(0.0, 0.2)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = ColorF(0.85, 0.85, 0.85, 0.5)},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};
				style.text = { .text = text, .color = Palette::Black };
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

			// Vibrant Dark - Modern Dark Mode
			static inline ButtonStyle VibrantDark(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				ButtonStyle style;
				style.rrs = {
					.background_color = {.color_from = ColorF(0.2, 0.25, 0.3), .color_to = ColorF(0.15, 0.2, 0.25), .type = GradationType::top_bottom},
					.shadow = {.offset = {0, 6}, .blur = 14, .spread = 0, .color = ColorF(0.0, 0.4)}
				};
				style.rrs_pressed = {
					.background_color = {.color_from = ColorF(0.1, 0.15, 0.2), .color_to = ColorF(0.08, 0.12, 0.18), .type = GradationType::top_bottom},
					.shadow = {.offset = {0, 3}, .blur = 10, .spread = 0, .color = ColorF(0.0, 0.3)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = ColorF(0.3, 0.3, 0.3)},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};
				style.text = { .text = text, .color = ColorF(0.9) };
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

			// Pastel Harmony - Soft and Friendly
			static inline ButtonStyle Pastel(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				ButtonStyle style;
				style.rrs = {
					.background_color = {.color_from = ColorF(0.8, 0.9, 0.85), .color_to = ColorF(0.7, 0.85, 0.8), .type = GradationType::top_bottom},
					.shadow = {.offset = {0, 4}, .blur = 10, .spread = 0, .color = ColorF(0.0, 0.2)}
				};
				style.rrs_pressed = {
					.background_color = {.color_from = ColorF(0.7, 0.8, 0.75), .color_to = ColorF(0.6, 0.75, 0.7), .type = GradationType::top_bottom},
					.shadow = {.offset = {0, 2}, .blur = 8, .spread = 0, .color = ColorF(0.0, 0.15)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = ColorF(0.85, 0.85, 0.85)},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};
				style.text = { .text = text, .color = ColorF(0.2) };
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}
			static inline ButtonStyle BackgroundBlend(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				const auto bgColor = Scene::GetBackground();
				ButtonStyle style;

				style.rrs = {
					.background_color = {.color_from = bgColor.lerp(Palette::White, 0.8), .color_to = bgColor, .type = GradationType::top_bottom},
					.outline = {.thickness = 1.5, .color = bgColor.lerp(Palette::Black, 0.3)},
					.shadow = {.offset = {0, 4}, .blur = 10, .spread = 0, .color = ColorF(0.0, 0.25)}
				};
				style.rrs_pressed = {
					.background_color = {.color_from = bgColor.lerp(Palette::Black, 0.2), .color_to = bgColor.lerp(Palette::Black, 0.5), .type = GradationType::top_bottom},
					.outline = {.thickness = 1.5, .color = bgColor.lerp(Palette::Black, 0.5)},
					.shadow = {.offset = {0, 2}, .blur = 8, .spread = 0, .color = ColorF(0.0, 0.2)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = bgColor.lerp(Palette::Gray, 0.5)},
					.outline = {.thickness = 1.5, .color = bgColor.lerp(Palette::Gray, 0.7)},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};
				style.text = { .text = text, .color = Palette::Black }; // 適切に背景とコントラストを取る色を使用
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

			static inline ButtonStyle Minimalistic(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				const auto bgColor = Scene::GetBackground();
				ButtonStyle style;

				style.rrs = {
					.background_color = {.color_from = bgColor.lerp(Palette::White, 0.9)},
					.outline = {.thickness = 1.0, .color = bgColor.lerp(Palette::Black, 0.2)},
					.shadow = {.offset = {0, 2}, .blur = 6, .spread = 0, .color = ColorF(0.0, 0.15)}
				};
				style.rrs_pressed = {
					.background_color = {.color_from = bgColor.lerp(Palette::Black, 0.1)},
					.outline = {.thickness = 1.0, .color = bgColor.lerp(Palette::Black, 0.3)},
					.shadow = {.offset = {0, 1}, .blur = 4, .spread = 0, .color = ColorF(0.0, 0.1)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = bgColor.lerp(Palette::Gray, 0.6)},
					.outline = {.thickness = 1.0, .color = bgColor.lerp(Palette::Gray, 0.8)},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};
				style.text = { .text = text, .color = Palette::Black }; // シンプルなデザイン
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

			static inline ButtonStyle FrostedGlass(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				const auto bgColor = Scene::GetBackground();
				ButtonStyle style;

				style.rrs = {
					.background_color = {.color_from = bgColor.lerp(Palette::White, 0.5), .color_to = bgColor.lerp(Palette::White, 0.8), .type = GradationType::top_bottom},
					.outline = {.thickness = 0.5, .color = bgColor.lerp(Palette::Black, 0.1)},
					.shadow = {.offset = {0, 8}, .blur = 16, .spread = -4, .color = ColorF(0.0, 0.2)}
				};
				style.rrs_pressed = {
					.background_color = {.color_from = bgColor.lerp(Palette::White, 0.3), .color_to = bgColor.lerp(Palette::White, 0.5), .type = GradationType::top_bottom},
					.outline = {.thickness = 0.5, .color = bgColor.lerp(Palette::Black, 0.2)},
					.shadow = {.offset = {0, 4}, .blur = 12, .spread = -4, .color = ColorF(0.0, 0.15)}
				};
				style.rrs_unable = {
					.background_color = {.color_from = bgColor.lerp(Palette::Gray, 0.5)},
					.outline = {.thickness = 0.5, .color = bgColor.lerp(Palette::Gray, 0.7)},
					.shadow = {.offset = {0, 0}, .blur = 0, .spread = 0, .color = ColorF(0.0, 0.0)}
				};
				style.text = { .text = text, .color = bgColor.lerp(Palette::Black, 0.8) }; // 背景に溶け込む
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

			static inline ButtonStyle SuperModern(const Vec2& pos, PositionType position_type, const SizeF& size, const String& text) {
				ButtonStyle style;
				style.rrs = {
					.background_color = Scene::GetBackground(),
					.shadow = {.offset = {5,5},.blur = 5.0}
				};
				style.rrs_pressed = {
					.background_color = Scene::GetBackground(),
					.shadow = {.offset = {1,1},.blur = 1.0}
				};
				style.rrs_unable = {
					.background_color = Scene::GetBackground(),
				};
				style.text = { .text = text,.color = Palette::Black };
				style.pos = pos;
				style.position_type = position_type;
				style.size = size;
				return style;
			}

		}
	}
}

#endif
