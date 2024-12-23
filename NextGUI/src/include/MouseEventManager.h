#pragma once
#ifndef _NEXT_GUI_MOUSEEVENTMANAGER_H_
#define _NEXT_GUI_MOUSEEVENTMANAGER_H_
#include"nConcept.h"

#include"stdafx.h"

namespace nGUI {
	class MouseEventManager : public IAddon {
	public:
		static bool leftClicked();

		static bool rightClicked();

		static bool leftPressed();

		static bool rightPressed();

		static bool leftReleased();

		static bool rightReleased();

		template<nConcept::PlanShape ShapeType>
		static bool mouseOver(const ShapeType& shape) {
			return _mouseOver(shape.mouseOver());
		}

		static void clearDown();

		static void clearPressed();

		static void clearUp();

		static void clearMouseOver();
	private:
		class MouseEventManagerImpl;
		std::shared_ptr<MouseEventManagerImpl> p_impl;
		
		static bool _mouseOver(bool is_over);

		bool init() override;

		bool update() override;
	};
}
#endif
