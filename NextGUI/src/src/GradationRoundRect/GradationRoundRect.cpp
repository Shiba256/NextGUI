#include"GradationRoundRect.h"
#include"MakeGradation.h"

namespace nGUI {
	void GradationRoundRect::draw(Arg::topLeft_<ColorF> color1, Arg::bottomRight_<ColorF> color2) const {
		if (color1.value() != cash_color1 || color2.value() != cash_color2) {
			cash_color1 = color1.value();
			cash_color2 = color2.value();
			detail::MakeGradationImage(texture,color1, color2, 10);
			textured_round_rect = round_rect(texture);
		}
		textured_round_rect.draw();
	}
	void GradationRoundRect::draw(Arg::topRight_<ColorF> color1, Arg::bottomLeft_<ColorF> color2) const {
		if (color1.value() != cash_color1 || color2.value() != cash_color2) {
			cash_color1 = color1.value();
			cash_color2 = color2.value();
			detail::MakeGradationImage(texture,color1, color2, 10);
			textured_round_rect = round_rect(texture);
		}
		textured_round_rect.draw();
	}
	void GradationRoundRect::draw(Arg::left_<ColorF> color1, Arg::right_<ColorF> color2) const {
		if (color1.value() != cash_color1 || color2.value() != cash_color2) {
			cash_color1 = color1.value();
			cash_color2 = color2.value();
			detail::MakeGradationImage(texture,color1, color2, 10);
			textured_round_rect = round_rect(texture);
		}
		textured_round_rect.draw();
	}
	void GradationRoundRect::draw(Arg::top_<ColorF> color1, Arg::bottom_<ColorF> color2) const {
		if (color1.value() != cash_color1 || color2.value() != cash_color2) {
			cash_color1 = color1.value();
			cash_color2 = color2.value();
			detail::MakeGradationImage(texture,color1, color2, 10);
			textured_round_rect = round_rect(texture);
		}
		textured_round_rect.draw();
	}

}
