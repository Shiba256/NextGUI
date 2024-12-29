# NextGUI
## ���ݐ�^�H����
���Ƃ���**iGUI**�Ƃ��č쐬���Ă��܂��������悢�݌v���v����������**NextGUI**�Ƃ��Ď�����i�߂Ă��܂��B
�����_�ł��啝�ȕύX�\�肪����̂Œ����X�p���������č쐬���悤�Ǝv���܂��B

�ȉ���iGUI��README�����̂܂܃R�s�[�������ł��B

- ListBase
- EINI�ɂ��ǂݍ���<br>

�ȏ�2���ڂ�**NextGUI**�ō폜�\��ł�

---
---
# iGUI
## 1. ����
- INI���g������EINI���g�p
- EINI����GUI��ǂݍ��ݕҏW�\
- GUIContainer��p�����O���[�v��
- AutoLayout�Ή�

## 2. GUIs
- Header
- Button
- Pulldown
- ProgressBar
- ProgressBarButton
- TextBox
- Slider
- DoubleSlider
- GUIContainer
- (ListBase) ... �p�����邱�Ƃ�List���쐬�\

## 3. �T���v���v���O����
```C++
#include <Siv3D.hpp>
#include"iGUI.h"

void Main() {
	lib::EINI e_ini{ U"./layout/1.layout" };

	//�ϐ���o�^
	e_ini.setVars(U"center_x", Scene::Width() / 2);
	e_ini.setVars(U"center_y", Scene::Height() / 2);

	//�w�i�F��ݒ�
	Scene::SetBackground(e_ini.getOr(U"window", U"color", Color{ 240,240,255 }));

	//GUI�̃R���e�i�N���X
	iGUI::GUIContainer gui_container;

	//GUI��ǉ�
	gui_container.append<iGUI::Header>(U"header", e_ini);
	gui_container.append<iGUI::Button>(U"button1", e_ini);
	gui_container.append<iGUI::Button>(U"button2", e_ini);
	gui_container.append<iGUI::TextBox>(U"textbox1", e_ini);
	gui_container.append<iGUI::ProgressBar>(U"progressbar", e_ini);
	gui_container.append<iGUI::Pulldown>(U"pulldown", e_ini);

	Stopwatch stopwatch{ StartImmediately::Yes };

	while (System::Update()) {
		//�R���e�i�̍X�V
		gui_container.update();

		//�v���O���X�o�[�̒l��ݒ�
		gui_container.get<iGUI::ProgressBar>(U"progressbar")->setProgress(stopwatch.sF() / 10.0);


		if (gui_container.get<iGUI::Button>(U"button1")->isClicked()) {
			Print << U"�{�^���������ꂽ��I";
		}

		if (gui_container.get<iGUI::Button>(U"button2")->isClicked()) {
			stopwatch.restart();
		}

		//�v���_�E���ŃA�C�e�����I�����ꂽ��GUI���ēx�ǂݍ���
		if (gui_container.get<iGUI::Pulldown>(U"pulldown")->isClicked()) {

			//���݂� index ���擾
			auto index = gui_container.get<iGUI::Pulldown>(U"pulldown")->selectedIndex();

			//�t�@�C���������[�h
			e_ini.reload(U"./layout/{}.layout"_fmt(1 + index));

			//�w�i�F��ݒ�
			Scene::SetBackground(e_ini.getOr(U"window", U"color", Color{ 240,240,255 }));

			//�ēo�^
			gui_container.reappend<iGUI::Header>(U"header", iGUI::Header::make(e_ini, U"header"));
			gui_container.reappend<iGUI::Button>(U"button1", iGUI::Button::make(e_ini, U"button1"));
			gui_container.reappend<iGUI::Button>(U"button2", iGUI::Button::make(e_ini, U"button2"));
			gui_container.reappend<iGUI::TextBox>(U"textbox1", iGUI::TextBox::make(e_ini, U"textbox1"));
			gui_container.reappend<iGUI::ProgressBar>(U"progressbar", iGUI::ProgressBar::make(e_ini, U"progressbar"));
			gui_container.reappend<iGUI::Pulldown>(U"pulldown", iGUI::Pulldown::make(e_ini, U"pulldown"));
			gui_container.get<iGUI::Pulldown>(U"pulldown")->setIndex(index);
		}

		//�R���e�i�̕`�揈��
		gui_container.draw();
	}
}
```
���s����
![option1](./img/option1.png)
![option4](./img/option4.png)
![option5](./img/option5.png)


## 4. �Ή����Ă���ϐ�
![�ϐ��ꗗ](./img/vars.png)

## 5. EINI�`��
```INI
;���̃t�@�C���Œ�`�����ϐ���ǂݍ��߂�
import = hoge.eini

;�萔�̒�`
def <window_size_x> = 1920
def <window_size_y> = 1080

;":"�ň͂�ꂽ�����͌v�Z���Ƃ��Ĉ�����
def <scale> = :80/100:

[window]
width = :<window_size_x>*<scale>:
height = :<window_size_y>*<scale>:
```

## 6. XML�`��
EINI�̋@�\�������p�����܂܍\�������\��XML�`����ǉ����܂����BXML�`���ł�autolayout�̓ǂݍ��݂ɑΉ����Ă��܂��B

### iGUI��XML������
## �T�v
iGUI�̐ݒ�́A�R���e�i��GUI�v�f���K�w�I�ɒ�`����`���ł��B�e�v�f�� `<container>` �^�O���ɒ�`����A�T�C�Y��ʒu�A�p�f�B���O�A�}�[�W���A���C�A�E�g�����Ȃǂ̃J�X�^�}�C�Y�\�ȃv���p�e�B�������Ă��܂��BGUI�͐�������ѐ��������̎������C�A�E�g�ɑΉ����Ă���A���܂��܂ȉ�ʃT�C�Y��𑜓x�ɓK���ł��܂��B

## ���C�A�E�g�\��
���C�A�E�g�ݒ�̃��[�g�� `<root>` �^�O�Œ�`����A���̒��ɂ��ׂĂ�GUI�v�f���܂܂�܂��B�R���e�i��eGUI�R���|�[�l���g�͊K�w�I�Ƀl�X�g����A���G�ȃ��C�A�E�g���\�z�ł��܂��B�R���e�i�N���X�̎�v�ȑ����͈ȉ��̒ʂ�ł��B

- **pos**: �R���e�i�܂��͗v�f�̈ʒu���`���܂��i��F`{x, y}`�j�B
- **size**: �R���e�i�܂��͗v�f�̕��ƍ������w�肵�܂��B`auto`���g�p���邱�ƂŁA�R���e���c�Ɋ�Â��ăT�C�Y��������������܂��B
- **autolayout**: �������C�A�E�g��L���ɂ��܂��i`true`���w��j�B
- **direction**: ���C�A�E�g�̕������w�肵�܂��B�������C�A�E�g�i`direction="0"`�j�A�����������C�A�E�g�i`direction="1"`�j�B
- **padding**: �R���e�i�����̗v�f�Ԃ̃X�y�[�X���w�肵�܂��B
- **margin**: �R���e�i�̊O���ɐ݂�����X�y�[�X���w�肵�܂��B

### ���C�A�E�g�\���̗�F
```xml
<root>
    <container id="main" pos="{0,0}" autolayout="true">
        <container id="panel1" pos="{0,0}" size="auto" autolayout="true" direction="0" padding="25" margin="15">
            <!-- GUI�v�f�������ɔz�u����܂� -->
        </container>
    </container>
</root>
```

### ���ꃉ�x��
�ȉ��̃��x���͐��l�Ŏw�肷��K�v������܂��B
- **PositionType**: 
  - center: 0
  - topRight: 1
  - topLeft: 2
  - bottomRight: 3
  - bottomLeft: 4
  - rightCenter: 5
  - leftCenter: 6
  - topCenter: 7
  - bottomCenter: 8
- **GradationType**:
  - none: 0
  - top_bottom: 1
  - left_right: 2
  - topLeft_bottomRight: 3
  - topRight_bottomLeft: 4
- **Align**:
  - center: 0
  - left: 1
  - right: 2
  - top: 3
  - bottom: 4
- **Direction**:
  - vertical: 0
  - horizontal: 1
  
### �������ɃA�C�R����}������
iGUI�ł́A�\������镶���ɃA�C�R����}�����邱�Ƃ��ł��܂��B�g�p�ł���A�C�R����[������̃T�C�g](https://pictogrammers.com/library/mdi/)�ɕ\������Ă��܂��B�\������ɂ�`${ID}$`�Ƃ��܂��BID��[������̃T�C�g](https://pictogrammers.com/library/mdi/)�Ɏ�����Ă���A�C�R���ŗL��id�ł��B

---

## GUI�R���|�[�l���g
### 1. **�w�b�_�[ (Header)**
- **����**: �w�b�_�[�́A��ɉ�ʂ̏㕔�ɕ\������郉�x���t����GUI�v�f�ł��B`HeaderStyle` �\���̂Œ�`����Ă���A�T�C�Y�A�w�i�F�A�e�L�X�g�F�A�g���A�e�A���x���̈ʒu�Ȃǂ��J�X�^�}�C�Y�\�ł��B���x���̈ʒu�́A�z�u�̏ڍׂȒ������\�ŁA�O���f�[�V�������ʂ��T�|�[�g����Ă��܂��B
  
- **��ȑ���**:
  - `id`: �w�b�_�[�̈�ӂ̎��ʎq���w�肵�܂�
  - `size`: �w�b�_�[�̕��ƍ����� `SizeF` �^�Ŏw�肵�܂��B�f�t�H���g�� `{200, 50}`
  - `r`: �w�b�_�[�̊p���ۂ߂邽�߂̔��a�i�s�N�Z���P�ʁj�B�f�t�H���g�� `0`
  - `label`: �w�b�_�[�ɕ\������e�L�X�g�B�f�t�H���g�͋󕶎��� `U""` �ł�
  - `background_color`: �w�b�_�[�̔w�i�F���w�肵�܂��B�f�t�H���g�� `Palette::White`�B�O���f�[�V�������g�p����ꍇ�A`{color}-{color_to}`�Ƃ���`color_to`�ɔw�i�F�̏I�_�F���w�肵�܂�
  - `text_color`: �w�b�_�[��̃e�L�X�g�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Black`
  - `outline_thickness`: �w�b�_�[�̘g���̑������w�肵�܂��i�s�N�Z���P�ʁj�B�f�t�H���g�� `0.5`
  - `outline_color`: �w�b�_�[�̘g���̐F���w�肵�܂��B�f�t�H���g�� `Palette::Black`
  - `draw_shadow`: �w�b�_�[�ɉe��`�悷�邩�ǂ������w�肵�܂��B`true` �ŉe��`�悵�A`false` �ŕ`�悵�܂���B�f�t�H���g�� `false`
  - `shadow_offset`: �e�̃I�t�Z�b�g���w�肵�܂��B�f�t�H���g�� `{0, 0}`
  - `shadow_blur`: �e�̂ڂ�������w�肵�܂��B�f�t�H���g�� `5`
  - `position`: �w�b�_�[�̔z�u�ʒu�� `PositionType` �Ŏw�肵�܂��B�f�t�H���g�� `PositionType::topLeft`
  - `label_position`: �w�b�_�[���̃��x���̔z�u�ʒu�� `PositionType` �Ŏw�肵�܂��B�f�t�H���g�� `PositionType::center`
  - `gradation_type`: �O���f�[�V�����̃^�C�v�� `GradationType` �Ŏw�肵�܂��B�f�t�H���g�� `GradationType::none`

#### ��F
```xml
<header id="header1" size="{300,60}" r="15" background_color="{255,255,255}" background_color_to="{200,200,200}" text_color="{0,0,0}" outline_thickness="1.0" outline_color="{150,150,150}" position="topLeft" label_position="center" draw_shadow="true" shadow_offset="{3,3}" shadow_blur="8" gradation_type="linear">
    App Header
</header>
```

### 2. **�{�^�� (Button)**
- **����**: �{�^���́A�N���b�N����邱�ƂŃA�N�V�������g���K�[�����v��GUI�v�f�ł��B���̃{�^���X�^�C���� `ButtonStyle` �\���̂Œ�`����A�T�C�Y�⃉�x���A�w�i�F�A�e�L�X�g�F�A�g���A�e�ȂǁA���L���J�X�^�}�C�Y���\�ł��B�܂��A�{�^���ɂ� `GradationType` ���g�p�����O���f�[�V�������ʂ�A���x���̈ʒu�����I�v�V�������񋟂���Ă��܂��B
  
- **��ȑ���**:
  - `id`: �{�^���̈�ӂ̎��ʎq���w�肵�܂�
  - `size`: �{�^���̕��ƍ����� `SizeF` �^�Ŏw�肵�܂��B�f�t�H���g�� `{200, 50}`
  - `r`: �{�^���̊p���ۂ߂邽�߂̔��a�i�s�N�Z���P�ʁj�B�f�t�H���g�� `0`
  - `label`: �{�^���ɕ\������e�L�X�g�B�f�t�H���g�͋󕶎��� `U""` �ł�
  - `background_color`: �{�^���̔w�i�F�B�f�t�H���g�� `Palette::White`�O���f�[�V�������g�p����ꍇ�A`{color}-{color_to}`�Ƃ���`color_to`�ɔw�i�F�̏I�_�F���w�肵�܂�
  - `background_pressed_color`: �{�^���������ꂽ�Ƃ��̔w�i�F�B�f�t�H���g�� `Palette::Lightgray`�B�O���f�[�V�������g�p����ꍇ�A`{color}-{color_to}`�Ƃ���`color_to`�ɔw�i�F�̏I�_�F���w�肵�܂�
  - `text_color`: �{�^����̃e�L�X�g�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Black`
  - `outline_thickness`: �{�^���̘g���̑������w�肵�܂��i�s�N�Z���P�ʁj�B�f�t�H���g�� `0.5`
  - `outline_color`: �{�^���̘g���̐F���w�肵�܂��B�f�t�H���g�� `Palette::Black`
  - `draw_shadow`: �{�^���ɉe��`�悷�邩�ǂ������w�肵�܂��B`true` �ŉe��`�悵�A`false` �ŕ`�悵�܂���B�f�t�H���g�� `false`
  - `shadow_offset`: �e�̃I�t�Z�b�g���w�肵�܂��B�f�t�H���g�� `{0, 0}`
  - `shadow_blur`: �e�̂ڂ�������w�肵�܂��B�f�t�H���g�� `5`
  - `position`: �{�^���̔z�u�ʒu�� `PositionType` �Ŏw�肵�܂��B�f�t�H���g�� `PositionType::topLeft`
  - `label_position`: �{�^���̃��x���̔z�u�ʒu�� `PositionType` �Ŏw�肵�܂��B�f�t�H���g�� `PositionType::center`
  - `gradation_type`: �O���f�[�V�����̃^�C�v�� `GradationType` �Ŏw�肵�܂��B�f�t�H���g�� `GradationType::none`

#### ��F
```xml
<button id="button1" size="{200,50}" r="10" background_color="{240,240,240}-{200,200,200}" text_color="{50,50,50}" outline_thickness="1.0" outline_color="{100,100,100}" position="0" label_position="0" draw_shadow="true" shadow_offset="{2,2}" shadow_blur="10" gradation_type="2">
    OK
</button>
```

### 3. **�X���C�_�[ (Slider)**
- **����**: �X���C�_�[�́A����͈͓̔��Œl��I���ł���GUI�v�f�ł��B`SliderStyle` �\���̂��g�p���āA�T�C�Y��p�̊ۂ݁A�X���C�_�[�̃m�u�̑傫���A�w�i�F�A�z�o�[���̐F�A�e�̗L���ȂǁA���܂��܂ȃX�^�C�����J�X�^�}�C�Y���邱�Ƃ��ł��܂��B�X���C�_�[�͍ŏ��l�ƍő�l��ݒ�ł��A�X�e�b�v���݂̏ڍׂȐݒ���\�ł��B

- **��ȑ���**:
  - `id`: �X���C�_�[�̈�ӂ̎��ʎq���w�肵�܂�
  - `size`: �X���C�_�[�̕��ƍ����� `SizeF` �^�Ŏw�肵�܂��B�f�t�H���g�� `{200, 10}`
  - `r`: �X���C�_�[�̔w�i�����̊p���ۂ߂邽�߂̔��a�i�s�N�Z���P�ʁj�B�f�t�H���g�� `10.0`
  - `radius`: �X���C�_�[�̃m�u�i�ۂ��n���h���j�̃T�C�Y���w�肵�܂��B�f�t�H���g�� `10.0`
  - `initial_value`: �X���C�_�[�̏����l���w�肵�܂��B�f�t�H���g�� `0.0`
  - `min_value`: �X���C�_�[�̍ŏ��l���w�肵�܂��B�f�t�H���g�� `0.0`
  - `max_value`: �X���C�_�[�̍ő�l���w�肵�܂��B�f�t�H���g�� `100.0`
  - `step`: �X���C�_�[�̈ړ��X�e�b�v���w�肵�܂��B�f�t�H���g�� `5.0`
  - `step_detail`: �X���C�_�[�ׂ̍��Ȉړ��𐧌䂷��X�e�b�v�T�C�Y�B�f�t�H���g�� `1.0`
  - `background_color`: �X���C�_�[�̔w�i�F���w�肵�܂��B�f�t�H���g�� `Palette::Lightgray`�O���f�[�V�������g�p����ꍇ�A`{color}-{color_to}`�Ƃ���`color_to`�ɔw�i�F�̏I�_�F���w�肵�܂�
  - `background_range_color`: �X���C�_�[�͈͕̔����̐F���w�肵�܂��B�f�t�H���g�� `Palette::White`�O���f�[�V�������g�p����ꍇ�A`{color}-{color_to}`�Ƃ���`color_to`�ɔw�i�F�̏I�_�F���w�肵�܂�
  - `color`: �X���C�_�[�̃m�u�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Lightgray`
  - `hovor_color`: �X���C�_�[�Ƀz�o�[�����Ƃ��̃m�u�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Lightblue`
  - `outline_color`: �m�u�̘g���̐F���w�肵�܂��B�f�t�H���g�� `Palette::Black`
  - `hovor_outline_color`: �X���C�_�[�Ƀz�o�[�����Ƃ��̃m�u�̘g���F�B�f�t�H���g�� `Palette::Lightcyan`
  - `text_color`: �X���C�_�[�̃e�L�X�g�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Black`
  - `draw_shadow`: �X���C�_�[�ɉe��`�悷�邩���w�肵�܂��B�f�t�H���g�� `false`
  - `shadow_offset`: �e�̃I�t�Z�b�g���w�肵�܂��B�f�t�H���g�� `{0, 0}`
  - `shadow_blur`: �e�̂ڂ�������w�肵�܂��B�f�t�H���g�� `5`
  - `position`: �X���C�_�[�̔z�u�ʒu�� `PositionType` �Ŏw�肵�܂��B�f�t�H���g�� `PositionType::topLeft`
  - `gradation_type`: �O���f�[�V�����̎�ނ��w�肵�܂��B�f�t�H���g�� `GradationType::none`

#### ��F
```xml
<slider id="slider1" size="{250,15}" r="10" radius="12" initial_value="50" min_value="0" max_value="100" step="10" background_color="{230,230,230}" background_range_color="{255,255,255}" color="{200,200,200}" hovor_color="{100,149,237}" text_color="{0,0,0}" draw_shadow="true" shadow_offset="{2,2}" shadow_blur="6"/>
```

---

### 4. **�_�u���X���C�_�[ (DoubleSlider)**
- **����**: �_�u���X���C�_�[�́A2�̒l�i���[�ƉE�[�j�𓯎��ɑ���ł���X���C�_�[�ł��B`DoubleSliderStyle` �\���̂��g�p���āA�X���C�_�[�S�̂̃X�^�C���A���[�̃m�u�̐F�A�w�i�F�A�e�̐ݒ�Ȃǂ��ڍׂɃJ�X�^�}�C�Y�ł��܂��B����ɂ��A�͈͑I�����蕡�G�ȑ��삪�\�ł��B

- **��ȑ���**:
  - `id`: �_�u���X���C�_�[�̈�ӂ̎��ʎq���w�肵�܂�
  - `size`: �_�u���X���C�_�[�̕��ƍ����� `SizeF` �^�Ŏw�肵�܂��B�f�t�H���g�� `{200, 10}`
  - `r`: �X���C�_�[�̔w�i�����̊p���ۂ߂邽�߂̔��a�i�s�N�Z���P�ʁj�B�f�t�H���g�� `10.0`
  - `radius`: �X���C�_�[�̃m�u�̃T�C�Y���w�肵�܂��B�f�t�H���g�� `10.0`
  - `initial_left`: ���[�̃m�u�̏����l���w�肵�܂��B�f�t�H���g�� `0.0`
  - `initial_right`: �E�[�̃m�u�̏����l���w�肵�܂��B�f�t�H���g�� `100.0`
  - `min_value`: �X���C�_�[�̍ŏ��l���w�肵�܂��B�f�t�H���g�� `0.0`
  - `max_value`: �X���C�_�[�̍ő�l���w�肵�܂��B�f�t�H���g�� `100.0`
  - `step`: �X���C�_�[�̈ړ��X�e�b�v���w�肵�܂��B�f�t�H���g�� `5.0`
  - `step_detail`: �X���C�_�[�ׂ̍��Ȉړ��𐧌䂷��X�e�b�v�T�C�Y�B�f�t�H���g�� `1.0`
  - `label`: �_�u���X���C�_�[�̃��x�����w�肵�܂��B�f�t�H���g�͋󕶎��� `U""`
  - `background_color`: �X���C�_�[�̔w�i�F���w�肵�܂��B�f�t�H���g�� `Palette::Lightgray`�O���f�[�V�������g�p����ꍇ�A`{color}-{color_to}`�Ƃ���`color_to`�ɔw�i�F�̏I�_�F���w�肵�܂�
  - `background_range_color`: �X���C�_�[�̑I��͈͕����̐F���w�肵�܂��B�f�t�H���g�� `Palette::White`�O���f�[�V�������g�p����ꍇ�A`{color}-{color_to}`�Ƃ���`color_to`�ɔw�i�F�̏I�_�F���w�肵�܂�
  - `color`: �X���C�_�[�̃m�u�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Lightgray`
  - `hovor_color`: �X���C�_�[�Ƀz�o�[�����Ƃ��̃m�u�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Lightblue`
  - `outline_color`: �m�u�̘g���̐F���w�肵�܂��B�f�t�H���g�� `Palette::Black`
  - `hovor_outline_color`: �X���C�_�[�Ƀz�o�[�����Ƃ��̃m�u�̘g���F�B�f�t�H���g�� `Palette::Lightcyan`
  - `text_color`: �X���C�_�[�̃e�L�X�g�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Black`
  - `draw_shadow`: �X���C�_�[�ɉe��`�悷�邩���w�肵�܂��B�f�t�H���g�� `false`
  - `shadow_offset`: �e�̃I�t�Z�b�g���w�肵�܂��B�f�t�H���g�� `{0, 0}`
  - `shadow_blur`: �e�̂ڂ�������w�肵�܂��B�f�t�H���g�� `5`
  - `position`: �X���C�_�[�̔z�u�ʒu�� `PositionType` �Ŏw�肵�܂��B�f�t�H���g�� `PositionType::topLeft`
  - `gradation_type`: �O���f�[�V�����̎�ނ��w�肵�܂��B�f�t�H���g�� `GradationType::none`

#### ��F
```xml
<double_slider id="double_slider1" size="{300,15}" r="10" radius="12" initial_left="20" initial_right="80" min_value="0" max_value="100" step="10" background_color="{240,240,240}" background_range_color="{255,255,255}" color="{220,220,220}" hovor_color="{135,206,250}" text_color="{0,0,0}" draw_shadow="true" shadow_offset="{3,3}" shadow_blur="7"/>
```

---

### 5. **�v���O���X�o�[ (ProgressBar)**
- **����**: �v���O���X�o�[�́A�i���󋵂����o�I�ɕ\�����邽�߂�GUI�v�f�ł��B`ProgressBarStyle` �\���̂��g�p���āA�T�C�Y��p�̊ۂ݁A�w�i�F�A�i���o�[�̐F�A���x���̔z�u�Ȃǂ��J�X�^�}�C�Y���邱�Ƃ��ł��܂��B�i���̐F�ɂ̓O���f�[�V�������w��\�ŁA�e��g���̃X�^�C�����ݒ�ł��܂��B

- **��ȑ���**:
  - `id`: �v���O���X�o�[�̈�ӂ̎��ʎq���w�肵�܂�
  - `size`: �v���O���X�o�[�̕��ƍ����� `SizeF` �^�Ŏw�肵�܂��B�f�t�H���g�� `{200, 50}`
  - `r`: �v���O���X�o�[�̔w�i�����̊p���ۂ߂邽�߂̔��a�B�f�t�H���g�� `0.0`
  - `label`: �v���O���X�o�[�̃��x�����w�肵�܂��B�f�t�H���g�͋󕶎��� `U""`
  - `background_color`: �v���O���X�o�[�̔w�i�F���w�肵�܂��B�f�t�H���g�� `Palette::White`�O���f�[�V�������g�p����ꍇ�A`{color}-{color_to}`�Ƃ���`color_to`�ɔw�i�F�̏I�_�F���w�肵�܂�
  - `progress_color`: �i���o�[�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Lightgreen`�O���f�[�V�������g�p����ꍇ�A`{color}-{color_to}`�Ƃ���`color_to`�ɔw�i�F�̏I�_�F���w�肵�܂�
  - `text_color`: ���x���̃e�L�X�g�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Black`�O���f�[�V�������g�p����ꍇ�A`{color}-{color_to}`�Ƃ���`color_to`�ɔw�i�F�̏I�_�F���w�肵�܂�
  - `outline_thickness`: �v���O���X�o�[�̘g���̑������w�肵�܂��B�f�t�H���g�� `0.5`
  - `outline_color`: �g���̐F���w�肵�܂��B�f�t�H���g�� `Palette::Black`
  - `draw_shadow`: �v���O���X�o�[�ɉe��`�悷�邩���w�肵�܂��B�f�t�H���g�� `false`
  - `shadow_offset`: �e�̃I�t�Z�b�g���w�肵�܂��B�f�t�H���g�� `{0, 0}`
  - `shadow_blur`: �e�̂ڂ�������w�肵�܂��B�f�t�H���g�� `5`
  - `label_position`: ���x���̔z�u�ʒu�� `PositionType` �Ŏw�肵�܂��B�f�t�H���g�� `PositionType::center`
  - `position`: �v���O���X�o�[�̔z�u�ʒu���w�肵�܂��B�f�t�H���g�� `PositionType::topLeft`
  - `gradation_type`: �O���f�[�V�����̎�ނ��w�肵�܂��B�f�t�H���g�� `GradationType::none`

#### ��F
```xml
<progress_bar id="progress_bar1" size="{250,20}" r="5" label="Loading..." background_color="{245,245,245}" progress_color="{144,238,144}" text_color="{0,0,0}" outline_thickness="1.0" outline_color="{0,0,0}" draw_shadow="true" shadow_offset="{3,3}" shadow_blur="7"/>
```

---

### 6. **�v���O���X�o�[�{�^�� (ProgressBarButton)**
- **����**: �v���O���X�o�[�{�^���́A�{�^���̋@�\�������Ȃ���i����\�����邽�߂̗v�f�ł��B`ProgressBarButtonStyle` �\���̂��g�p���āA�ʏ�̃{�^���Ƃ͈قȂ�A�{�^�����������Ƃ��̔w�i�F��i���o�[�̃X�^�C���Ȃǂ��ݒ�ł��܂��B�i���\���ɉ����A�{�^���Ƃ��ẴC���^���N�V�������\�ł��B

- **��ȑ���**:
  - `id`: �v���O���X�o�[�{�^���̈�ӂ̎��ʎq���w�肵�܂�
  - `size`: �v���O���X�o�[�{�^���̕��ƍ����� `SizeF` �^�Ŏw�肵�܂��B�f�t�H���g�� `{200, 50}`
  - `r`: �v���O���X�o�[�{�^���̔w�i�����̊p���ۂ߂邽�߂̔��a�B�f�t�H���g�� `0.0`
  - `label`: �v���O���X�o�[�{�^���̃��x�����w�肵�܂��B�f�t�H���g�͋󕶎��� `U""`
  - `background_color`: �v���O���X�o�[�{�^���̒ʏ펞�̔w�i�F���w�肵�܂��B�f�t�H���g�� `Palette::White`
  - `background_pressed_color`: �{�^���������ꂽ�Ƃ��̔w�i�F���w�肵�܂��B�f�t�H���g�� `Palette::Lightgray`
  - `progress_color`: �i���o�[�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Lightgreen`
  - `text_color`: ���x���̃e�L�X�g�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Black`
  - `outline_thickness`: �v���O���X�o�[�{�^���̘g���̑������w�肵�܂��B�f�t�H���g�� `0.5`
  - `outline_color`: �g���̐F���w�肵�܂��B�f�t�H���g�� `Palette::Black`
  - `draw_shadow`: �v���O���X�o�[�{�^���ɉe��`�悷�邩���w�肵�܂��B�f�t�H���g�� `false`
  - `shadow_offset`: �e�̃I�t�Z�b�g���w�肵�܂��B�f�t�H���g�� `{0, 0}`
  - `shadow_blur`: �e�̂ڂ�������w�肵�܂��B�f�t�H���g�� `5`
  - `label_position`: ���x���̔z�u�ʒu�� `PositionType` �Ŏw�肵�܂��B�f�t�H���g�� `PositionType::center`
  - `position`: �v���O���X�o�[�{�^���̔z�u�ʒu���w�肵�܂��B�f�t�H���g�� `PositionType::topLeft`
  - `gradation_type`: �O���f�[�V�����̎�ނ��w�肵�܂��B�f�t�H���g�� `GradationType::none`

#### ��F
```xml
<progress_bar_button id="progress_bar_button1" size="{300,40}" r="10" label="Download" background_color="{245,245,245}" background_pressed_color="{211,211,211}" progress_color="{144,238,144}" text_color="{0,0,0}" outline_thickness="1.0" outline_color="{0,0,0}" draw_shadow="true" shadow_offset="{3,3}" shadow_blur="7"/>
```
---

### 7. **�v���_�E�����j���[ (Pulldown)**
- **����**: �v���_�E�����j���[�́A���[�U�[�����X�g����I������I�Ԃ��߂�GUI�R���|�[�l���g�ł��B`PulldownStyle` �\���̂��g���āA���j���[�S�̂̃T�C�Y�A�F�A�e�A�g���A�X�N���[���o�[�A�e�L�X�g�F�Ȃǂ��ׂ����J�X�^�}�C�Y�ł��܂��B�v���_�E�����j���[�ɂ� `item` �^�O���g���č��ڂ�ǉ����܂��B�e���ڂ� `<item label = "���x����"/>` �̌`���Ŏw��ł��܂��B

- **��ȑ���**:
  - `id`: �v���_�E�����j���[�̈�ӂ̎��ʎq���w�肵�܂��B
  - `size`: �v���_�E�����j���[�̃T�C�Y���w�肵�܂��B�f�t�H���g�� `{200, 50}`�B
  - `r`: ���j���[�̊p�̊ۂ݂��w�肵�܂��B�f�t�H���g�� `0`�B
  - `background_color`: ���j���[�̔w�i�F���w�肵�܂��B�f�t�H���g�� `Palette::White`�B�O���f�[�V�������g�p����ꍇ�A`{color}-{color_to}` �̌`���Ŕw�i�F�̏I�_���w�肵�܂��B
  - `selected_color`: �I�𒆂̍��ڂ̔w�i�F���w�肵�܂��B�f�t�H���g�� `Palette::Lightblue`�B�O���f�[�V�������g�p����ꍇ�A`{color}-{color_to}` �̌`���ŏI�_�F���w�肵�܂��B
  - `triangle_color`: �v���_�E�����j���[�̓W�J�������O�p�`�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Gray`�B
  - `scrollbar_color`: �X�N���[���o�[�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Lightgray`�B�O���f�[�V�����Ή��B
  - `scrollbar_pressed_color`: �X�N���[���o�[�������ꂽ�Ƃ��̐F���w�肵�܂��B�f�t�H���g�� `Palette::Gray`�B
  - `text_color`: �v���_�E�����j���[���̃e�L�X�g�̐F���w�肵�܂��B�f�t�H���g�� `Palette::Black`�B
  - `outline_thickness`: ���j���[�̘g���̑������w�肵�܂��B�f�t�H���g�� `0.5`�B
  - `outline_color`: ���j���[�̘g���̐F���w�肵�܂��B�f�t�H���g�� `Palette::Black`�B
  - `draw_shadow`: �e��`�悷�邩�ǂ������w�肵�܂��B`true` �ŉe��`�悵�A`false` �ŕ`�悵�܂���B�f�t�H���g�� `false`�B
  - `shadow_offset`: �e�̃I�t�Z�b�g���w�肵�܂��B�f�t�H���g�� `{0, 0}`�B
  - `shadow_blur`: �e�̂ڂ�������w�肵�܂��B�f�t�H���g�� `5`�B
  - `label_position`: �v���_�E�����j���[�̃��x���̈ʒu���w�肵�܂��B�f�t�H���g�� `PositionType::center`�B
  - `item_position`: ���ڂ̃��x���ʒu���w�肵�܂��B�f�t�H���g�� `PositionType::center`�B
  - `max_display_items`: �\������ő區�ڐ����w�肵�܂��B�f�t�H���g�� `3`�B����ȏ�̍��ڂ�����ꍇ�A�X�N���[���o�[���\������܂��B
  - `gradation_type`: �O���f�[�V�����̓K�p���@���w�肵�܂��B�f�t�H���g�� `GradationType::none`�B

#### ��F
```xml
<pulldown id = "pulldown1" pos = "{0,0}" size = "{200,100}">
    <item label = "item1"/>
    <item label = "item2"/>
    <item label = "item3"/>
</pulldown>
```



### 8. **GUI�R���e�i (GUIContainer)**
- **����**: `GUIContainerStyle` �\���̂́A������GUI�v�f�𐮗����Ĕz�u���邽�߂̃R���e�i�̃X�^�C�����`���܂��B�R���e�i�́A�v�f�𐂒��������͐��������ɕ��ׂ邱�Ƃ��ł��A�e�v�f�̔z�u��R���e�i�̃T�C�Y�A�}�[�W����p�f�B���O�Ȃǂ��J�X�^�}�C�Y�\�ł��B`Align` �� `Direction` ��g�ݍ��킹�āA���R�Ƀ��C�A�E�g�𒲐��ł��܂��B

- **��ȑ���**:
- `autolayout`: ���C�A�E�g���������߂��邩�ǂ�����ݒ肵�܂��B�f�t�H���g��`false`�B
- `size`: �R���e�i�̕��ƍ����� `SizeF` �^�Ŏw�肵�܂��B�f�t�H���g�� `Scene::Size()` �ŁA�V�[���S�̂̃T�C�Y�ɍ��킹�܂�
- `margin`: �R���e�i�̊O���̃X�y�[�X���w�肵�܂��i�s�N�Z���P�ʁj�B�f�t�H���g�� `0`
- `padding`: �R���e�i���̗v�f�ƃR���e�i�̋��E�Ƃ̊Ԋu���w�肵�܂��i�s�N�Z���P�ʁj�B�f�t�H���g�� `0`
- `position`: �R���e�i�̔z�u�ʒu�� `PositionType` �Ŏw�肵�܂��B�f�t�H���g�� `PositionType::center`
- `direction`: �v�f�𐂒� (`vertical`) �܂��͐��� (`horizontal`) �ɕ��ׂ邩�� `Direction` �Ŏw�肵�܂��B�f�t�H���g�� `Direction::horizontal`
- `align`: �R���e�i���̗v�f�̔z�u�� `Align` �Ŏw�肵�܂��B`center`, `left`, `right`, `top`, `bottom` ����I���\�ł��B�f�t�H���g�� `Align::center`

- **��**
```xml
<GUIContainer pos = "{0,0}" size = "auto" autolayout = "true" margin = "15" padding = "10">
    <!-- �v�f�͂����ɒ�` -->
</GUIContainer>
```
---

## ���ێ�I�ȃv���O�������������߂�
iGUI�Ŏg�p����XML�͎��̂悤�Ɋg������Ă��܂��B�w�肵��xml�t�@�C����compile����A`{filename}.compiled.xml`�ɕϊ�����܂��B

- �萔�̐錾 (C/C++�ł�`#define`)
- ���t�@�C������̒萔��import
- ���̌v�Z
  
### 1. �萔�̐錾
�萔��`def {name} {value}`�̂悤�ɐ錾���邱�Ƃ��ł��܂��������܂��萔���g�p����ۂɂ�`[{name}]`�̂悤�Ɏg�p���܂��B

#### ��:
```xml
def button_radius 10
<button r = [button_radius] ></button>
```

�܂�C/C++��`#define`�Ɠ��l�ɂ��̂܂ܒu�������邽�ߎ��̂悤�Ȏg�������ł��܂�

#### ��:
```xml
def button_color {255,255,0}
def button_label ����ɂ���
<button background_color = [button_color]>[button_label]</button>
```

### 2. import
`import {filepath}`��filepath�Ő錾���ꂽ�萔���ė��p���邱�Ƃ��ł��܂��B�Ȃ�filepath��Open Siv 3D�̃J�����g�f�B���N�g������Ƃ������΃p�X�������͐�΃p�X���L�q���܂��B
#### ��:
```xml
<!--window_pos.xml-->
def window_width 800
def window_height 600

def window_center_x :[window_width]/2:
def window_center_y :[window_height]/2:

def window_center :{[window_width],[window_height]}:
```

```xml
<!--button.xml-->
import window_pos.xml
<button pos = [window_center]>center</button>
```

### 3. ���̌v�Z
`::`�ň͂�ꂽ����OpenSiv3D����`Eval`�֐��ɓn����܂��B���̍ہA�錾����Ă����ϐ��͒u�������܂��B

#### ��:
```xml
def window_width 800
def window_height 600

def window_center_x :[window_width]/2:
def window_center_y :[window_height]/2:

def window_center :{[window_width],[window_height]}:

<button pos = [window_center]>center</button>
```




