# include <Siv3D.hpp>

#include"nGUI.h"

void Main() {
	Window::Resize(1920, 1080);
	Scene::SetBackground(Palette::Aliceblue);

	nGUI::Button button{ nGUI::Preset::Button::Default({250,250}, nGUI::PositionType::center, {200,60}, U"$f019$ ダウンロード") };
	button.changeStyle().setR(20);

	nGUI::Panel panel1{ nGUI::PanelStyle{.pos = Scene::CenterF(),.size = {500,500},.position_type = nGUI::PositionType::center} };
	nGUI::Panel panel2{ nGUI::PanelStyle{.size = {500,400}} };
	button.changeStyle().text.text = U"button1";
	panel2.add(U"Button1", button);
	button.changeStyle().text.text = U"button2";
	panel2.add(U"Button2", button);
	button.changeStyle().text.text = U"button3";
	panel2.add(U"Button3", button);
	button.changeStyle().text.text = U"button4";
	panel2.add(U"Button4", button);
	button.changeStyle().text.text = U"button5";
	panel2.add(U"Button5", button);
	button.changeStyle().text.text = U"button6";
	panel2.add(U"Button6", button);
	panel2.addLayoutManager(nGUI::LayoutManager{ nGUI::LayoutManagerOptions{.type = nGUI::LayoutType::Flex,.containerAlignment = nGUI::PositionType::center} });
	panel1.add(U"panel2", panel2);
	panel1.addLayoutManager(nGUI::LayoutManager{ nGUI::LayoutManagerOptions{.containerAlignment = nGUI::PositionType::center} });

	while (System::Update()) {
		panel1.update();
		panel1.draw();
		panel1.drawDebug();
	}
}
