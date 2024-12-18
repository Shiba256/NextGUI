#pragma once
#ifndef _NEXTGUI_FONT_H_
#define _NEXTGUI_FONT_H_

#include"stdafx.h"

namespace nGUI {
	class nFont {
	public:
		static const nFont& instance() {
			static nFont instance_;
			return instance_;
		}

		const Font& getRegular() const noexcept {
			return regular;
		}

		const Font& getIcon() const noexcept {
			return icon;
		}

	private:
		nFont(int32 font_size = 15) :
			regular(font_size),
			icon(font_size, Typeface::Icon_MaterialDesign)
		{}

		Font regular;
		Font icon;
	};
}

#endif
