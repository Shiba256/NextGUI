#pragma once
#ifndef _NEXTGUI_MAKEGRADATION_H_
#define _NEXTGUI_MAKEGRADATION_H_
namespace nGUI {
	namespace detail {
		inline void MakeGradationImage(DynamicTexture& texture, Arg::top_<ColorF> color1, Arg::bottom_<ColorF> color2, size_t size) {
			Image image{ size };
			for (int32 y = 0, ye = image.height(); y < ye; ++y) {
				for (int32 x = 0, xe = image.width(); x < xe; ++x) {
					double t = static_cast<double>(y) / ye;
					image[y][x] = ColorF{
						color1->r - (color1->r - color2->r) * t,
						color1->g - (color1->g - color2->g) * t,
						color1->b - (color1->b - color2->b) * t,
						color1->a - (color1->a - color2->a) * t,
					};
				}
			}
			texture.fill(image);
		}
		inline void MakeGradationImage(DynamicTexture& texture, Arg::left_<ColorF> color1, Arg::right_<ColorF> color2, size_t size) {
			Image image{ size };
			for (int32 y = 0, ye = image.height(); y < ye; ++y) {
				for (int32 x = 0, xe = image.width(); x < xe; ++x) {
					double t = static_cast<double>(x) / xe;
					image[y][x] = ColorF{
						color1->r - (color1->r - color2->r) * t,
						color1->g - (color1->g - color2->g) * t,
						color1->b - (color1->b - color2->b) * t,
						color1->a - (color1->a - color2->a) * t,
					};
				}
			}
			texture.fill(image);
		}
		inline void MakeGradationImage(DynamicTexture& texture, Arg::topLeft_<ColorF> color1, Arg::bottomRight_<ColorF> color2, size_t size) {
			Image image{ size };
			for (int32 y = 0, ye = image.height(); y < ye; ++y) {
				for (int32 x = 0, xe = image.width(); x < xe; ++x) {
					double t = static_cast<double>(x + y) / (xe + ye);
					image[y][x] = ColorF{
						color1->r - (color1->r - color2->r) * t,
						color1->g - (color1->g - color2->g) * t,
						color1->b - (color1->b - color2->b) * t,
						color1->a - (color1->a - color2->a) * t,
					};
				}
			}
			texture.fill(image);
		}
		inline void MakeGradationImage(DynamicTexture& texture, Arg::topRight_<ColorF> color1, Arg::bottomLeft_<ColorF> color2, size_t size) {
			Image image{ size };
			for (int32 y = 0, ye = image.height(); y < ye; ++y) {
				for (int32 x = 0, xe = image.width(); x < xe; ++x) {
					double t = static_cast<double>(xe - x + y) / (xe + ye);
					image[y][x] = ColorF{
						color1->r - (color1->r - color2->r) * t,
						color1->g - (color1->g - color2->g) * t,
						color1->b - (color1->b - color2->b) * t,
						color1->a - (color1->a - color2->a) * t,
					};
				}
			}
			texture.fill(image);
		}
	}
}
#endif
