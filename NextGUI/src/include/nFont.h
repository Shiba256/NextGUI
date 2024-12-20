#pragma once
#ifndef _NEXTGUI_FONT_H_
#define _NEXTGUI_FONT_H_

#include"stdafx.h"

namespace nGUI {
	class nFont {
	public:
		static nFont& instance() {
			static nFont instance_;
			return instance_;
		}

		const Font& get() const noexcept {
			return regular;
		}

	private:
		nFont(int32 font_size = 30) :
			regular(FontMethod::SDF,font_size),
			icon_material(FontMethod::SDF,font_size, Typeface::Icon_MaterialDesign),
			icon_awesome_brand(FontMethod::SDF, font_size, Typeface::Icon_Awesome_Brand),
			icon_awesome_solid(FontMethod::SDF, font_size, Typeface::Icon_Awesome_Solid),
			emoji(FontMethod::SDF,font_size,Typeface::ColorEmoji)
		{
			regular.addFallback(icon_material);
			regular.addFallback(icon_awesome_brand);
			regular.addFallback(icon_awesome_solid);
		}

		Font regular;
		Font icon_material;
		Font icon_awesome_brand;
		Font icon_awesome_solid;
		Font emoji;
	};
}

#endif
