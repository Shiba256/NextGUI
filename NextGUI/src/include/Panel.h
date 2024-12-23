#pragma once
#ifndef _NEXT_GUI_PANEL_H_
#define _NEXT_GUI_PANEL_H_

#include"StyleBase.h"
#include"AbstractComponent.h"
#include"RoundRectStyle.h"
#include"stdafx.h"

namespace nGUI {
	struct PanelStyle {
		COMMON_STYLE
		bool auto_size = false;
		bool hide_overflow = false;
		Rect margin = { 0,0,0,0 };
	};

	class LayoutManager;

	class Panel : public AbstractComponent {
	public:
		struct Record {
			Record(size_t id, StringView key, const std::shared_ptr<AbstractComponent>& value) :
				id(id),
				key(key),
				value(value)
			{}
			size_t getID() const {
				return id;
			}
			StringView key;
			std::shared_ptr<AbstractComponent> value;
		private:
			size_t id;
		};

		Panel(const PanelStyle& style = PanelStyle{}) :
			style(style)
		{}

		void  update()override;

		void draw()const override;

		void drawDebug(const Outline& outline = { .thickness = 1.0 ,.color = Palette::Red }, bool debug_all = true,size_t depth = 0ull);

		template<nConcept::Component Type>
		void add(StringView name, Type component) {
			this->add(name, std::make_shared<Type>(component));
		}

		void add(StringView name, const std::shared_ptr<AbstractComponent>& component);

		void erase(StringView name);

		void erase(size_t id);

		void addLayoutManager(LayoutManager&& manager);

		void callLayoutManager();

		template<class Type>
		Type* get(StringView name) const;

		constexpr Vec2 getPos() const override {
			return style.pos;
		}
		constexpr Vec2 getLT() const override {
			return style.getCalculatedPosition();
		}
		constexpr SizeF getSize() const override {
			return style.size;
		}
		constexpr int32 getZIndex() const override {
			return style.z_index;
		}
		void setPos(const Vec2& pos, PositionType position_type = PositionType::topLeft) override;
		void setSize(const SizeF& _size) override {
			style.size = _size;
		}
		void ReConstruct() override;

	private:

		PanelStyle style;
		size_t id_count = 0ull;
		Array<Record> components;
		mutable std::unordered_map<StringView, void*> cache;
		std::shared_ptr<LayoutManager> layout_manager;
	};
}

#include"./ipp/Panel.ipp"
#endif
