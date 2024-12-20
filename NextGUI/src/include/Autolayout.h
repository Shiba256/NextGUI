#pragma once
#ifndef _NEXT_GUI_AUTOLAYOUT_H_
#define _NEXT_GUI_AUTOLAYOUT_H_

#include "stdafx.h"
#include "Panel.h"
#include "PositionType.h"

namespace nGUI {

	enum class LayoutType {
		Flex,
		Flow,
		Grid
	};

	struct AutolayoutOptions {
		LayoutType type = LayoutType::Flex;
		Vec2 spacing = { 10.0, 10.0 }; // Spacing between components
		Optional<SizeF> fixedSize = none; // Optional fixed size for components
		size_t columns = 1; // Only relevant for grid layout
		bool wrap = true; // Whether to wrap items in Flow layout
		PositionType alignment = PositionType::topLeft; // Alignment within rows/cells
		PositionType containerAlignment = PositionType::topLeft; // Alignment of the whole container
	};

	class Autolayout {
	public:
		Autolayout(const AutolayoutOptions& options = {}) : options(options) {}

		void apply(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize) const;

	private:
		AutolayoutOptions options;

		void applyFlexLayout(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize) const;

		void applyFlowLayout(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize) const;

		void applyGridLayout(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize) const;

		void alignComponents(Array<Panel::Record>& components, const Vec2& containerPos, const SizeF& containerSize) const;

		RectF calculateBoundingRect(const Array<Panel::Record>& components) const;

		Vec2 calculateAlignmentOffset(const RectF& boundingRect, const Vec2& containerPos, const SizeF& containerSize, PositionType alignmentType) const;
	};
}

#endif
