# 計算科学概論課題

[`geant4`](geant4) 配下のコードを完成させよ。現在、空気で満たされた 10m x 10m x 10m の World Volume が定義されているだけ。

## 必須課題

- [このリポジトリ](..) をフォークせよ <https://github.com/goiwai/introcs-2021/fork>
- フォークしたらば [`geant4`](geant4) および [`texdoc`](texdoc) 配下で以下を満たすよう作業せよ
- ビーム方向 (Z) に 1 cm 厚の水板 (40cm x 40cm) を100枚並べて配置するよう [`DetectorConstruction::Construct`](geant4/src/DetectorConstruction.cpp) を実装せよ
  - **セットアップ図がわかるように全体像を保存し、後述するレポートに貼り付けて提出すること**
- 上の水板を Active Volume (Sensitive Detector) として定義 (G4VSensitiveDetector 継承クラスの実装) し、登録せよ
  - 少なくとも Copy Number とそれに対応するエネルギー損失量を出力すること [`WaterPhantomSD.h`](geant4/include/WaterPhantomSD.h) [`WaterPhantomSD.cpp`](geant4/src/WaterPhantomSD.cpp)
  - 出力に対応する Hit クラスを作成せよ [`WaterPhantomHit.h`](geant4/include/WaterPhantomHit.h) [`WaterPhantomHit.cpp`](geant4/src/WaterPhantomHit.cpp)
- [`EventAction::EndOfEventAction`](geant4/src/EventAction.cpp) を実装し Hit 情報を元に Ntuple に Fill せよ
- [`PrimaryGeneratorAction::PrimaryGeneratorAction`](geant4/src/PrimaryGeneratorAction.cpp) では 100 MeV の Proton を Z 方向に一個だけ入射するように実装してある。1000 イベント生成後、保存された Ntuple データをオフラインで読み、深さ方向 (Z) のエネルギー分布をプロットせよ
  - **後述するレポートに貼り付けて提出すること**
- レポートは [`texdoc`](texdoc) 内に作成せよ
  - LaTeX で記述すること、提出物はソースのみで良い、PDF は不要
- Pull Request の発行をもって提出とする
  - 〆切: 8月29日(日) までに発行すること

## 選択課題

+2 以上で優とする。

- [`texdoc`](texdoc) に `CMakeLists.txt` を用意して提出せよ (+1)
- 水板 (40cm x 40cm x 1cm) は G4PVPlacement 以外で配置せよ (+1)
- Sensitive Detector からの出力は TTree オブジェクトとして `TFile` を使用して保存せよ、またそのように [`CMakeLists.txt`](geant4/CMakeLists.txt) を編集せよ。 (+2)
- その他、工夫点があればレポート内に記載せよ、評価に値するものであれば加点する。
