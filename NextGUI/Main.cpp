# include <Siv3D.hpp>

#include"Button.h"
#include"Box.h"
#include"ButtonPreset.h"
#include"Panel.h"
#include"Autolayout.h"

void Main() {
	Window::Resize(1920, 1080);
	Scene::SetBackground(Palette::Aliceblue);

	nGUI::Button button{ nGUI::Preset::Button::Default({250,250}, nGUI::PositionType::center, {200,60}, U"$f019$ ダウンロード") };
	button.changeStyle().setR(20);

	nGUI::Panel panel{ nGUI::PanelStyle{nGUI::StyleBase{.pos = {Scene::CenterF()},.size = {500,500},.position_type = nGUI::PositionType::center}} };
	nGUI::Box box{ nGUI::BoxStyle{nGUI::StyleBase{.size = {100,100}}} };
	panel.add(U"button", std::make_shared<nGUI::Button>(button));
	panel.add(U"button2", std::make_shared<nGUI::Button>(button));
	panel.add(U"button3", std::make_shared<nGUI::Button>(button));
	panel.add(U"button4", std::make_shared<nGUI::Button>(button));
	panel.add(U"button5", std::make_shared<nGUI::Button>(button));
	panel.addLayoutManager(nGUI::Autolayout{
		nGUI::AutolayoutOptions{
		.type = nGUI::LayoutType::Flow,
		.spacing = {10,10},
		.alignment = nGUI::PositionType::center,
		.containerAlignment = nGUI::PositionType::center,
		}
		});

	while (System::Update()) {
		panel.update();
		panel.draw();
		panel.drawDebug();
	}
}
