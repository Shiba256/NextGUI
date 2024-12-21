# include <Siv3D.hpp>

#include"nGUI.h"

void Main() {
	Window::Resize(1920, 1080);
	Scene::SetBackground(Palette::Aliceblue);

	nGUI::Button button{ nGUI::Preset::Button::Default({250,250}, nGUI::PositionType::center, {200,60}, U"$f019$ ダウンロード") };
	button.changeStyle().setR(20);

	nGUI::Panel panel1{ nGUI::PanelStyle{.pos = Scene::CenterF(),.size = {500,500},.position_type = nGUI::PositionType::center} };
	panel1.add(U"Button", std::make_shared<nGUI::Button>(button));

	while (System::Update()) {
		panel1.update();
		panel1.draw();
	}
}
