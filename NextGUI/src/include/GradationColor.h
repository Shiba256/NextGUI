#pragma once
#ifndef _NEXTGUI_GRADATIONCOLOR_H_
#define _NEXTGUI_GRADATIONCOLOR_H_

#include"nConcept.h"
#include"GradationType.h"
#include"GradationRoundRect.h"
#include"nPalette.h"

#include"stdafx.h"

namespace nGUI {
	template<nConcept::Siv3DColorType color_type = ColorF>
	struct GradationColor {
		color_type color_from = nPalette::Clear;
		color_type color_to = nPalette::Clear;
		GradationType type = GradationType::none;
		inline void draw(const RectF& rect) const;
		inline void draw(const GradationRoundRect& rect)const;
	};
}
#include"./ipp/GradationColor.ipp"

#endif
