#pragma once
#ifndef _NEXT_GUI_MOUSEEVENTMANAGER_H_
#define _NEXT_GUI_MOUSEEVENTMANAGER_H_
#include"nConcept.h"

#include"stdafx.h"

namespace nGUI {
	class MouseEventManager : public IAddon {
	public:
		static bool leftClicked();

		template<nConcept::PlanShape ShapeType>
		static bool leftClicked(const ShapeType& shape) {
			return shape.mouseOver() && leftClicked();
		}

		static bool rightClicked();

		template<nConcept::PlanShape ShapeType>
		static bool rightClicked(const ShapeType& shape) {
			return shape.mouseOver() && rightClicked();
		}

		static bool leftPressed();

		template<nConcept::PlanShape ShapeType>
		static bool leftPressed(const ShapeType& shape) {
			return shape.mouseOver() && leftPressed();
		}

		static bool rightPressed();

		template<nConcept::PlanShape ShapeType>
		static bool rightPressed(const ShapeType& shape) {
			return shape.mouseOver() && rightPressed();
		}

		static bool leftReleased();

		template<nConcept::PlanShape ShapeType>
		static bool leftReleased(const ShapeType& shape) {
			return shape.mouseOver() && leftReleased();
		}

		static bool rightReleased();

		template<nConcept::PlanShape ShapeType>
		static bool rightReleased(const ShapeType& shape) {
			return shape.mouseOver() && rightReleased();
		}

		template<nConcept::PlanShape ShapeType>
		static bool mouseOver(const ShapeType& shape) {
			return _mouseOver(shape.mouseOver());
		}

		static void clearDown();

		static void clearPressed();

		static void clearUp();

		static void clearMouseOver();

		static void clearAll() {
			clearUp();
			clearPressed();
			clearDown();
			clearMouseOver();
		}
	private:
		class MouseEventManagerImpl;
		std::shared_ptr<MouseEventManagerImpl> p_impl;
		
		static bool _mouseOver(bool is_over);

		bool init() override;

		bool update() override;
	};
}
#endif
