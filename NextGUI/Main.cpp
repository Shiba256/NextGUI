# include <Siv3D.hpp>

#include"Button.h"

void Main(){
	Scene::SetBackground(Palette::Aliceblue);
	nGUI::ButtonStyle style{
		nGUI::StyleBase{
			.pos = Scene::CenterF(),
			.size = {200,50},
			.position_type = nGUI::PositionType::center,
		}
	};


	style.setR(10);
	style.text = nGUI::Text{
		.text = U"こんにちは",
	};
	nGUI::Button button{ style };

	while (System::Update()) {
		button.update();
		button.draw();
	}
}
