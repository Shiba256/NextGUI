# NextGUI
## 現在絶賛工事中
もともと**iGUI**として作成していましたがよりよい設計が思いついたため**NextGUI**として実装を進めています。
現時点でも大幅な変更予定があるので長いスパンをかけて作成しようと思います。

以下はiGUIのREADMEをそのままコピーした物です。

- ListBase
- EINIによる読み込み<br>

以上2項目は**NextGUI**で削除予定です

---
---
# iGUI
## 1. 特徴
- INIを拡張したEINIを使用
- EINIからGUIを読み込み編集可能
- GUIContainerを用いたグループ化
- AutoLayout対応

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
- (ListBase) ... 継承することでListを作成可能

## 3. サンプルプログラム
```C++
#include <Siv3D.hpp>
#include"iGUI.h"

void Main() {
	lib::EINI e_ini{ U"./layout/1.layout" };

	//変数を登録
	e_ini.setVars(U"center_x", Scene::Width() / 2);
	e_ini.setVars(U"center_y", Scene::Height() / 2);

	//背景色を設定
	Scene::SetBackground(e_ini.getOr(U"window", U"color", Color{ 240,240,255 }));

	//GUIのコンテナクラス
	iGUI::GUIContainer gui_container;

	//GUIを追加
	gui_container.append<iGUI::Header>(U"header", e_ini);
	gui_container.append<iGUI::Button>(U"button1", e_ini);
	gui_container.append<iGUI::Button>(U"button2", e_ini);
	gui_container.append<iGUI::TextBox>(U"textbox1", e_ini);
	gui_container.append<iGUI::ProgressBar>(U"progressbar", e_ini);
	gui_container.append<iGUI::Pulldown>(U"pulldown", e_ini);

	Stopwatch stopwatch{ StartImmediately::Yes };

	while (System::Update()) {
		//コンテナの更新
		gui_container.update();

		//プログレスバーの値を設定
		gui_container.get<iGUI::ProgressBar>(U"progressbar")->setProgress(stopwatch.sF() / 10.0);


		if (gui_container.get<iGUI::Button>(U"button1")->isClicked()) {
			Print << U"ボタンがおされたよ！";
		}

		if (gui_container.get<iGUI::Button>(U"button2")->isClicked()) {
			stopwatch.restart();
		}

		//プルダウンでアイテムが選択されたらGUIを再度読み込み
		if (gui_container.get<iGUI::Pulldown>(U"pulldown")->isClicked()) {

			//現在の index を取得
			auto index = gui_container.get<iGUI::Pulldown>(U"pulldown")->selectedIndex();

			//ファイルをリロード
			e_ini.reload(U"./layout/{}.layout"_fmt(1 + index));

			//背景色を設定
			Scene::SetBackground(e_ini.getOr(U"window", U"color", Color{ 240,240,255 }));

			//再登録
			gui_container.reappend<iGUI::Header>(U"header", iGUI::Header::make(e_ini, U"header"));
			gui_container.reappend<iGUI::Button>(U"button1", iGUI::Button::make(e_ini, U"button1"));
			gui_container.reappend<iGUI::Button>(U"button2", iGUI::Button::make(e_ini, U"button2"));
			gui_container.reappend<iGUI::TextBox>(U"textbox1", iGUI::TextBox::make(e_ini, U"textbox1"));
			gui_container.reappend<iGUI::ProgressBar>(U"progressbar", iGUI::ProgressBar::make(e_ini, U"progressbar"));
			gui_container.reappend<iGUI::Pulldown>(U"pulldown", iGUI::Pulldown::make(e_ini, U"pulldown"));
			gui_container.get<iGUI::Pulldown>(U"pulldown")->setIndex(index);
		}

		//コンテナの描画処理
		gui_container.draw();
	}
}
```
実行結果
![option1](./img/option1.png)
![option4](./img/option4.png)
![option5](./img/option5.png)


## 4. 対応している変数
![変数一覧](./img/vars.png)

## 5. EINI形式
```INI
;他のファイルで定義した変数を読み込める
import = hoge.eini

;定数の定義
def <window_size_x> = 1920
def <window_size_y> = 1080

;":"で囲われた部分は計算式として扱われる
def <scale> = :80/100:

[window]
width = :<window_size_x>*<scale>:
height = :<window_size_y>*<scale>:
```

## 6. XML形式
EINIの機能を引き継いだまま構造化が可能なXML形式を追加しました。XML形式ではautolayoutの読み込みに対応しています。

### iGUIのXML書き方
## 概要
iGUIの設定は、コンテナとGUI要素を階層的に定義する形式です。各要素は `<container>` タグ内に定義され、サイズや位置、パディング、マージン、レイアウト方向などのカスタマイズ可能なプロパティを持っています。GUIは垂直および水平方向の自動レイアウトに対応しており、さまざまな画面サイズや解像度に適応できます。

## レイアウト構造
レイアウト設定のルートは `<root>` タグで定義され、その中にすべてのGUI要素が含まれます。コンテナや各GUIコンポーネントは階層的にネストされ、複雑なレイアウトを構築できます。コンテナクラスの主要な属性は以下の通りです。

- **pos**: コンテナまたは要素の位置を定義します（例：`{x, y}`）。
- **size**: コンテナまたは要素の幅と高さを指定します。`auto`を使用することで、コンテンツに基づいてサイズが自動調整されます。
- **autolayout**: 自動レイアウトを有効にします（`true`を指定）。
- **direction**: レイアウトの方向を指定します。垂直レイアウト（`direction="0"`）、水平方向レイアウト（`direction="1"`）。
- **padding**: コンテナ内部の要素間のスペースを指定します。
- **margin**: コンテナの外側に設けられるスペースを指定します。

### レイアウト構造の例：
```xml
<root>
    <container id="main" pos="{0,0}" autolayout="true">
        <container id="panel1" pos="{0,0}" size="auto" autolayout="true" direction="0" padding="25" margin="15">
            <!-- GUI要素がここに配置されます -->
        </container>
    </container>
</root>
```

### 特殊ラベル
以下のラベルは数値で指定する必要があります。
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
  
### 文字中にアイコンを挿入する
iGUIでは、表示される文字にアイコンを挿入することができます。使用できるアイコンは[こちらのサイト](https://pictogrammers.com/library/mdi/)に表示されています。表示するには`${ID}$`とします。IDは[こちらのサイト](https://pictogrammers.com/library/mdi/)に示されているアイコン固有のidです。

---

## GUIコンポーネント
### 1. **ヘッダー (Header)**
- **説明**: ヘッダーは、主に画面の上部に表示されるラベル付きのGUI要素です。`HeaderStyle` 構造体で定義されており、サイズ、背景色、テキスト色、枠線、影、ラベルの位置などをカスタマイズ可能です。ラベルの位置は、配置の詳細な調整が可能で、グラデーション効果もサポートされています。
  
- **主な属性**:
  - `id`: ヘッダーの一意の識別子を指定します
  - `size`: ヘッダーの幅と高さを `SizeF` 型で指定します。デフォルトは `{200, 50}`
  - `r`: ヘッダーの角を丸めるための半径（ピクセル単位）。デフォルトは `0`
  - `label`: ヘッダーに表示するテキスト。デフォルトは空文字列 `U""` です
  - `background_color`: ヘッダーの背景色を指定します。デフォルトは `Palette::White`。グラデーションを使用する場合、`{color}-{color_to}`として`color_to`に背景色の終点色を指定します
  - `text_color`: ヘッダー上のテキストの色を指定します。デフォルトは `Palette::Black`
  - `outline_thickness`: ヘッダーの枠線の太さを指定します（ピクセル単位）。デフォルトは `0.5`
  - `outline_color`: ヘッダーの枠線の色を指定します。デフォルトは `Palette::Black`
  - `draw_shadow`: ヘッダーに影を描画するかどうかを指定します。`true` で影を描画し、`false` で描画しません。デフォルトは `false`
  - `shadow_offset`: 影のオフセットを指定します。デフォルトは `{0, 0}`
  - `shadow_blur`: 影のぼかし具合を指定します。デフォルトは `5`
  - `position`: ヘッダーの配置位置を `PositionType` で指定します。デフォルトは `PositionType::topLeft`
  - `label_position`: ヘッダー内のラベルの配置位置を `PositionType` で指定します。デフォルトは `PositionType::center`
  - `gradation_type`: グラデーションのタイプを `GradationType` で指定します。デフォルトは `GradationType::none`

#### 例：
```xml
<header id="header1" size="{300,60}" r="15" background_color="{255,255,255}" background_color_to="{200,200,200}" text_color="{0,0,0}" outline_thickness="1.0" outline_color="{150,150,150}" position="topLeft" label_position="center" draw_shadow="true" shadow_offset="{3,3}" shadow_blur="8" gradation_type="linear">
    App Header
</header>
```

### 2. **ボタン (Button)**
- **説明**: ボタンは、クリックされることでアクションをトリガーする主要なGUI要素です。このボタンスタイルは `ButtonStyle` 構造体で定義され、サイズやラベル、背景色、テキスト色、枠線、影など、幅広いカスタマイズが可能です。また、ボタンには `GradationType` を使用したグラデーション効果や、ラベルの位置調整オプションが提供されています。
  
- **主な属性**:
  - `id`: ボタンの一意の識別子を指定します
  - `size`: ボタンの幅と高さを `SizeF` 型で指定します。デフォルトは `{200, 50}`
  - `r`: ボタンの角を丸めるための半径（ピクセル単位）。デフォルトは `0`
  - `label`: ボタンに表示するテキスト。デフォルトは空文字列 `U""` です
  - `background_color`: ボタンの背景色。デフォルトは `Palette::White`グラデーションを使用する場合、`{color}-{color_to}`として`color_to`に背景色の終点色を指定します
  - `background_pressed_color`: ボタンが押されたときの背景色。デフォルトは `Palette::Lightgray`。グラデーションを使用する場合、`{color}-{color_to}`として`color_to`に背景色の終点色を指定します
  - `text_color`: ボタン上のテキストの色を指定します。デフォルトは `Palette::Black`
  - `outline_thickness`: ボタンの枠線の太さを指定します（ピクセル単位）。デフォルトは `0.5`
  - `outline_color`: ボタンの枠線の色を指定します。デフォルトは `Palette::Black`
  - `draw_shadow`: ボタンに影を描画するかどうかを指定します。`true` で影を描画し、`false` で描画しません。デフォルトは `false`
  - `shadow_offset`: 影のオフセットを指定します。デフォルトは `{0, 0}`
  - `shadow_blur`: 影のぼかし具合を指定します。デフォルトは `5`
  - `position`: ボタンの配置位置を `PositionType` で指定します。デフォルトは `PositionType::topLeft`
  - `label_position`: ボタンのラベルの配置位置を `PositionType` で指定します。デフォルトは `PositionType::center`
  - `gradation_type`: グラデーションのタイプを `GradationType` で指定します。デフォルトは `GradationType::none`

#### 例：
```xml
<button id="button1" size="{200,50}" r="10" background_color="{240,240,240}-{200,200,200}" text_color="{50,50,50}" outline_thickness="1.0" outline_color="{100,100,100}" position="0" label_position="0" draw_shadow="true" shadow_offset="{2,2}" shadow_blur="10" gradation_type="2">
    OK
</button>
```

### 3. **スライダー (Slider)**
- **説明**: スライダーは、特定の範囲内で値を選択できるGUI要素です。`SliderStyle` 構造体を使用して、サイズや角の丸み、スライダーのノブの大きさ、背景色、ホバー時の色、影の有無など、さまざまなスタイルをカスタマイズすることができます。スライダーは最小値と最大値を設定でき、ステップ刻みの詳細な設定も可能です。

- **主な属性**:
  - `id`: スライダーの一意の識別子を指定します
  - `size`: スライダーの幅と高さを `SizeF` 型で指定します。デフォルトは `{200, 10}`
  - `r`: スライダーの背景部分の角を丸めるための半径（ピクセル単位）。デフォルトは `10.0`
  - `radius`: スライダーのノブ（丸いハンドル）のサイズを指定します。デフォルトは `10.0`
  - `initial_value`: スライダーの初期値を指定します。デフォルトは `0.0`
  - `min_value`: スライダーの最小値を指定します。デフォルトは `0.0`
  - `max_value`: スライダーの最大値を指定します。デフォルトは `100.0`
  - `step`: スライダーの移動ステップを指定します。デフォルトは `5.0`
  - `step_detail`: スライダーの細かな移動を制御するステップサイズ。デフォルトは `1.0`
  - `background_color`: スライダーの背景色を指定します。デフォルトは `Palette::Lightgray`グラデーションを使用する場合、`{color}-{color_to}`として`color_to`に背景色の終点色を指定します
  - `background_range_color`: スライダーの範囲部分の色を指定します。デフォルトは `Palette::White`グラデーションを使用する場合、`{color}-{color_to}`として`color_to`に背景色の終点色を指定します
  - `color`: スライダーのノブの色を指定します。デフォルトは `Palette::Lightgray`
  - `hovor_color`: スライダーにホバーしたときのノブの色を指定します。デフォルトは `Palette::Lightblue`
  - `outline_color`: ノブの枠線の色を指定します。デフォルトは `Palette::Black`
  - `hovor_outline_color`: スライダーにホバーしたときのノブの枠線色。デフォルトは `Palette::Lightcyan`
  - `text_color`: スライダーのテキストの色を指定します。デフォルトは `Palette::Black`
  - `draw_shadow`: スライダーに影を描画するかを指定します。デフォルトは `false`
  - `shadow_offset`: 影のオフセットを指定します。デフォルトは `{0, 0}`
  - `shadow_blur`: 影のぼかし具合を指定します。デフォルトは `5`
  - `position`: スライダーの配置位置を `PositionType` で指定します。デフォルトは `PositionType::topLeft`
  - `gradation_type`: グラデーションの種類を指定します。デフォルトは `GradationType::none`

#### 例：
```xml
<slider id="slider1" size="{250,15}" r="10" radius="12" initial_value="50" min_value="0" max_value="100" step="10" background_color="{230,230,230}" background_range_color="{255,255,255}" color="{200,200,200}" hovor_color="{100,149,237}" text_color="{0,0,0}" draw_shadow="true" shadow_offset="{2,2}" shadow_blur="6"/>
```

---

### 4. **ダブルスライダー (DoubleSlider)**
- **説明**: ダブルスライダーは、2つの値（左端と右端）を同時に操作できるスライダーです。`DoubleSliderStyle` 構造体を使用して、スライダー全体のスタイル、両端のノブの色、背景色、影の設定などを詳細にカスタマイズできます。これにより、範囲選択やより複雑な操作が可能です。

- **主な属性**:
  - `id`: ダブルスライダーの一意の識別子を指定します
  - `size`: ダブルスライダーの幅と高さを `SizeF` 型で指定します。デフォルトは `{200, 10}`
  - `r`: スライダーの背景部分の角を丸めるための半径（ピクセル単位）。デフォルトは `10.0`
  - `radius`: スライダーのノブのサイズを指定します。デフォルトは `10.0`
  - `initial_left`: 左端のノブの初期値を指定します。デフォルトは `0.0`
  - `initial_right`: 右端のノブの初期値を指定します。デフォルトは `100.0`
  - `min_value`: スライダーの最小値を指定します。デフォルトは `0.0`
  - `max_value`: スライダーの最大値を指定します。デフォルトは `100.0`
  - `step`: スライダーの移動ステップを指定します。デフォルトは `5.0`
  - `step_detail`: スライダーの細かな移動を制御するステップサイズ。デフォルトは `1.0`
  - `label`: ダブルスライダーのラベルを指定します。デフォルトは空文字列 `U""`
  - `background_color`: スライダーの背景色を指定します。デフォルトは `Palette::Lightgray`グラデーションを使用する場合、`{color}-{color_to}`として`color_to`に背景色の終点色を指定します
  - `background_range_color`: スライダーの選択範囲部分の色を指定します。デフォルトは `Palette::White`グラデーションを使用する場合、`{color}-{color_to}`として`color_to`に背景色の終点色を指定します
  - `color`: スライダーのノブの色を指定します。デフォルトは `Palette::Lightgray`
  - `hovor_color`: スライダーにホバーしたときのノブの色を指定します。デフォルトは `Palette::Lightblue`
  - `outline_color`: ノブの枠線の色を指定します。デフォルトは `Palette::Black`
  - `hovor_outline_color`: スライダーにホバーしたときのノブの枠線色。デフォルトは `Palette::Lightcyan`
  - `text_color`: スライダーのテキストの色を指定します。デフォルトは `Palette::Black`
  - `draw_shadow`: スライダーに影を描画するかを指定します。デフォルトは `false`
  - `shadow_offset`: 影のオフセットを指定します。デフォルトは `{0, 0}`
  - `shadow_blur`: 影のぼかし具合を指定します。デフォルトは `5`
  - `position`: スライダーの配置位置を `PositionType` で指定します。デフォルトは `PositionType::topLeft`
  - `gradation_type`: グラデーションの種類を指定します。デフォルトは `GradationType::none`

#### 例：
```xml
<double_slider id="double_slider1" size="{300,15}" r="10" radius="12" initial_left="20" initial_right="80" min_value="0" max_value="100" step="10" background_color="{240,240,240}" background_range_color="{255,255,255}" color="{220,220,220}" hovor_color="{135,206,250}" text_color="{0,0,0}" draw_shadow="true" shadow_offset="{3,3}" shadow_blur="7"/>
```

---

### 5. **プログレスバー (ProgressBar)**
- **説明**: プログレスバーは、進捗状況を視覚的に表示するためのGUI要素です。`ProgressBarStyle` 構造体を使用して、サイズや角の丸み、背景色、進捗バーの色、ラベルの配置などをカスタマイズすることができます。進捗の色にはグラデーションも指定可能で、影や枠線のスタイルも設定できます。

- **主な属性**:
  - `id`: プログレスバーの一意の識別子を指定します
  - `size`: プログレスバーの幅と高さを `SizeF` 型で指定します。デフォルトは `{200, 50}`
  - `r`: プログレスバーの背景部分の角を丸めるための半径。デフォルトは `0.0`
  - `label`: プログレスバーのラベルを指定します。デフォルトは空文字列 `U""`
  - `background_color`: プログレスバーの背景色を指定します。デフォルトは `Palette::White`グラデーションを使用する場合、`{color}-{color_to}`として`color_to`に背景色の終点色を指定します
  - `progress_color`: 進捗バーの色を指定します。デフォルトは `Palette::Lightgreen`グラデーションを使用する場合、`{color}-{color_to}`として`color_to`に背景色の終点色を指定します
  - `text_color`: ラベルのテキストの色を指定します。デフォルトは `Palette::Black`グラデーションを使用する場合、`{color}-{color_to}`として`color_to`に背景色の終点色を指定します
  - `outline_thickness`: プログレスバーの枠線の太さを指定します。デフォルトは `0.5`
  - `outline_color`: 枠線の色を指定します。デフォルトは `Palette::Black`
  - `draw_shadow`: プログレスバーに影を描画するかを指定します。デフォルトは `false`
  - `shadow_offset`: 影のオフセットを指定します。デフォルトは `{0, 0}`
  - `shadow_blur`: 影のぼかし具合を指定します。デフォルトは `5`
  - `label_position`: ラベルの配置位置を `PositionType` で指定します。デフォルトは `PositionType::center`
  - `position`: プログレスバーの配置位置を指定します。デフォルトは `PositionType::topLeft`
  - `gradation_type`: グラデーションの種類を指定します。デフォルトは `GradationType::none`

#### 例：
```xml
<progress_bar id="progress_bar1" size="{250,20}" r="5" label="Loading..." background_color="{245,245,245}" progress_color="{144,238,144}" text_color="{0,0,0}" outline_thickness="1.0" outline_color="{0,0,0}" draw_shadow="true" shadow_offset="{3,3}" shadow_blur="7"/>
```

---

### 6. **プログレスバーボタン (ProgressBarButton)**
- **説明**: プログレスバーボタンは、ボタンの機能を持ちながら進捗を表示するための要素です。`ProgressBarButtonStyle` 構造体を使用して、通常のボタンとは異なり、ボタンが押されるときの背景色や進捗バーのスタイルなども設定できます。進捗表示に加え、ボタンとしてのインタラクションが可能です。

- **主な属性**:
  - `id`: プログレスバーボタンの一意の識別子を指定します
  - `size`: プログレスバーボタンの幅と高さを `SizeF` 型で指定します。デフォルトは `{200, 50}`
  - `r`: プログレスバーボタンの背景部分の角を丸めるための半径。デフォルトは `0.0`
  - `label`: プログレスバーボタンのラベルを指定します。デフォルトは空文字列 `U""`
  - `background_color`: プログレスバーボタンの通常時の背景色を指定します。デフォルトは `Palette::White`
  - `background_pressed_color`: ボタンが押されたときの背景色を指定します。デフォルトは `Palette::Lightgray`
  - `progress_color`: 進捗バーの色を指定します。デフォルトは `Palette::Lightgreen`
  - `text_color`: ラベルのテキストの色を指定します。デフォルトは `Palette::Black`
  - `outline_thickness`: プログレスバーボタンの枠線の太さを指定します。デフォルトは `0.5`
  - `outline_color`: 枠線の色を指定します。デフォルトは `Palette::Black`
  - `draw_shadow`: プログレスバーボタンに影を描画するかを指定します。デフォルトは `false`
  - `shadow_offset`: 影のオフセットを指定します。デフォルトは `{0, 0}`
  - `shadow_blur`: 影のぼかし具合を指定します。デフォルトは `5`
  - `label_position`: ラベルの配置位置を `PositionType` で指定します。デフォルトは `PositionType::center`
  - `position`: プログレスバーボタンの配置位置を指定します。デフォルトは `PositionType::topLeft`
  - `gradation_type`: グラデーションの種類を指定します。デフォルトは `GradationType::none`

#### 例：
```xml
<progress_bar_button id="progress_bar_button1" size="{300,40}" r="10" label="Download" background_color="{245,245,245}" background_pressed_color="{211,211,211}" progress_color="{144,238,144}" text_color="{0,0,0}" outline_thickness="1.0" outline_color="{0,0,0}" draw_shadow="true" shadow_offset="{3,3}" shadow_blur="7"/>
```
---

### 7. **プルダウンメニュー (Pulldown)**
- **説明**: プルダウンメニューは、ユーザーがリストから選択肢を選ぶためのGUIコンポーネントです。`PulldownStyle` 構造体を使って、メニュー全体のサイズ、色、影、枠線、スクロールバー、テキスト色などを細かくカスタマイズできます。プルダウンメニューには `item` タグを使って項目を追加します。各項目は `<item label = "ラベル名"/>` の形式で指定できます。

- **主な属性**:
  - `id`: プルダウンメニューの一意の識別子を指定します。
  - `size`: プルダウンメニューのサイズを指定します。デフォルトは `{200, 50}`。
  - `r`: メニューの角の丸みを指定します。デフォルトは `0`。
  - `background_color`: メニューの背景色を指定します。デフォルトは `Palette::White`。グラデーションを使用する場合、`{color}-{color_to}` の形式で背景色の終点を指定します。
  - `selected_color`: 選択中の項目の背景色を指定します。デフォルトは `Palette::Lightblue`。グラデーションを使用する場合、`{color}-{color_to}` の形式で終点色を指定します。
  - `triangle_color`: プルダウンメニューの展開を示す三角形の色を指定します。デフォルトは `Palette::Gray`。
  - `scrollbar_color`: スクロールバーの色を指定します。デフォルトは `Palette::Lightgray`。グラデーション対応。
  - `scrollbar_pressed_color`: スクロールバーが押されたときの色を指定します。デフォルトは `Palette::Gray`。
  - `text_color`: プルダウンメニュー内のテキストの色を指定します。デフォルトは `Palette::Black`。
  - `outline_thickness`: メニューの枠線の太さを指定します。デフォルトは `0.5`。
  - `outline_color`: メニューの枠線の色を指定します。デフォルトは `Palette::Black`。
  - `draw_shadow`: 影を描画するかどうかを指定します。`true` で影を描画し、`false` で描画しません。デフォルトは `false`。
  - `shadow_offset`: 影のオフセットを指定します。デフォルトは `{0, 0}`。
  - `shadow_blur`: 影のぼかし具合を指定します。デフォルトは `5`。
  - `label_position`: プルダウンメニューのラベルの位置を指定します。デフォルトは `PositionType::center`。
  - `item_position`: 項目のラベル位置を指定します。デフォルトは `PositionType::center`。
  - `max_display_items`: 表示する最大項目数を指定します。デフォルトは `3`。それ以上の項目がある場合、スクロールバーが表示されます。
  - `gradation_type`: グラデーションの適用方法を指定します。デフォルトは `GradationType::none`。

#### 例：
```xml
<pulldown id = "pulldown1" pos = "{0,0}" size = "{200,100}">
    <item label = "item1"/>
    <item label = "item2"/>
    <item label = "item3"/>
</pulldown>
```



### 8. **GUIコンテナ (GUIContainer)**
- **説明**: `GUIContainerStyle` 構造体は、複数のGUI要素を整理して配置するためのコンテナのスタイルを定義します。コンテナは、要素を垂直もしくは水平方向に並べることができ、各要素の配置やコンテナのサイズ、マージンやパディングなどもカスタマイズ可能です。`Align` と `Direction` を組み合わせて、自由にレイアウトを調整できます。

- **主な属性**:
- `autolayout`: レイアウトを自動調節するかどうかを設定します。デフォルトは`false`。
- `size`: コンテナの幅と高さを `SizeF` 型で指定します。デフォルトは `Scene::Size()` で、シーン全体のサイズに合わせます
- `margin`: コンテナの外側のスペースを指定します（ピクセル単位）。デフォルトは `0`
- `padding`: コンテナ内の要素とコンテナの境界との間隔を指定します（ピクセル単位）。デフォルトは `0`
- `position`: コンテナの配置位置を `PositionType` で指定します。デフォルトは `PositionType::center`
- `direction`: 要素を垂直 (`vertical`) または水平 (`horizontal`) に並べるかを `Direction` で指定します。デフォルトは `Direction::horizontal`
- `align`: コンテナ内の要素の配置を `Align` で指定します。`center`, `left`, `right`, `top`, `bottom` から選択可能です。デフォルトは `Align::center`

- **例**
```xml
<GUIContainer pos = "{0,0}" size = "auto" autolayout = "true" margin = "15" padding = "10">
    <!-- 要素はここに定義 -->
</GUIContainer>
```
---

## より保守的なプログラムを書くために
iGUIで使用するXMLは次のように拡張されています。指定したxmlファイルはcompileされ、`{filename}.compiled.xml`に変換されます。

- 定数の宣言 (C/C++での`#define`)
- 他ファイルからの定数のimport
- 式の計算
  
### 1. 定数の宣言
定数は`def {name} {value}`のように宣言することができますおきかまた定数を使用する際には`[{name}]`のように使用します。

#### 例:
```xml
def button_radius 10
<button r = [button_radius] ></button>
```

またC/C++の`#define`と同様にそのまま置き換えるため次のような使い方もできます

#### 例:
```xml
def button_color {255,255,0}
def button_label こんにちは
<button background_color = [button_color]>[button_label]</button>
```

### 2. import
`import {filepath}`でfilepathで宣言された定数を再利用することができます。なおfilepathはOpen Siv 3Dのカレントディレクトリを基準とした相対パスもしくは絶対パスを記述します。
#### 例:
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

### 3. 式の計算
`::`で囲われた式はOpenSiv3D内の`Eval`関数に渡されます。この際、宣言されていた変数は置き換わります。

#### 例:
```xml
def window_width 800
def window_height 600

def window_center_x :[window_width]/2:
def window_center_y :[window_height]/2:

def window_center :{[window_width],[window_height]}:

<button pos = [window_center]>center</button>
```




