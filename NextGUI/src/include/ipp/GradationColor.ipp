namespace nGUI {
	template<nConcept::Siv3DColorType color_type>
	void GradationColor<color_type>::draw(const RectF& rect) const {
		switch (type) {
		case nGUI::GradationType::none:
			rect.draw(color_from);
			break;
		case nGUI::GradationType::left_right:
			rect.draw(Arg::left = color_from, Arg::right = color_to);
			break;
		case nGUI::GradationType::top_bottom:
			rect.draw(Arg::top = color_from, Arg::bottom = color_to);
			break;
		case nGUI::GradationType::topRight_bottomLeft:
			rect.draw(Arg::topRight = color_from, Arg::bottomLeft = color_to);
			break;
		case nGUI::GradationType::topLeft_bottomRight:
			rect.draw(Arg::topLeft = color_from, Arg::bottomRight = color_to);
			break;
		default:
			rect.draw(color_from);
			break;
		}
	}

	template<nConcept::Siv3DColorType color_type>
	void GradationColor<color_type>::draw(const GradationRoundRect& rect)const {
		switch (type) {
		case nGUI::GradationType::none:
			rect.round_rect.draw(color_from);
			break;
		case nGUI::GradationType::left_right:
			rect.draw(Arg::left = color_from, Arg::right = color_to);
			break;
		case nGUI::GradationType::top_bottom:
			rect.draw(Arg::top = color_from, Arg::bottom = color_to);
			break;
		case nGUI::GradationType::topRight_bottomLeft:
			rect.draw(Arg::topRight = color_from, Arg::bottomLeft = color_to);
			break;
		case nGUI::GradationType::topLeft_bottomRight:
			rect.draw(Arg::topLeft = color_from, Arg::bottomRight = color_to);
			break;
		default:
			rect.round_rect.draw(color_from);
			break;
		}
	}
}
