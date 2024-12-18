#pragma once
#ifndef _NEXTGUI_GRADATIONROUNDRECT_H_
#define _NEXTGUI_GRADATIONROUNDRECT_H_

#include"stdafx.h"

namespace nGUI {
	class GradationRoundRect {
	public:
		GradationRoundRect(RoundRect round_rect) :
			round_rect(round_rect)
		{}

		void draw(Arg::topLeft_<ColorF> color1, Arg::bottomRight_<ColorF> color2) const;
		void draw(Arg::topRight_<ColorF> color1, Arg::bottomLeft_<ColorF> color2) const;
		void draw(Arg::left_<ColorF> color1, Arg::right_<ColorF> color2) const;
		void draw(Arg::top_<ColorF> color1, Arg::bottom_<ColorF> color2) const;

		RoundRect round_rect;
	private:
		mutable DynamicTexture texture{};
		mutable TexturedRoundRect textured_round_rect{};
		mutable ColorF cash_color1{};
		mutable ColorF cash_color2{};
	};

}

#endif
