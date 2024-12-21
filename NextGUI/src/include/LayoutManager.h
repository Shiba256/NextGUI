#pragma once
#ifndef _NEXT_GUI_LAYOUTMANAGER_H_
#define _NEXT_GUI_LAYOUTMANAGER_H_

#include "Panel.h"
#include "PositionType.h"
#include "LayoutType.h"

#include"stdafx.h"

namespace nGUI {
	struct LayoutManagerOptions {
		LayoutType type = LayoutType::Flow;
		Vec2 spacing = { 10.0, 10.0 };
		size_t columns = 1;
		bool wrap = true;
		PositionType alignment = PositionType::topLeft;
		PositionType containerAlignment = PositionType::topLeft;
	};

	class LayoutManager {
	public:
		LayoutManager(const LayoutManagerOptions& options = {}) : options(options) {}

		void apply(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize) const;

	private:
		LayoutManagerOptions options;
	};
}

#endif
