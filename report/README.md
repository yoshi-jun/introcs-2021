# 計算科学概論課題

[`geant4`](geant4) 配下のコードを完成させよ。現在、空気で満たされた 10m x 10m x 10m の World Volume が定義されているだけ。

## 必須課題

- このリポジトリをフォークせよ
- ビーム方向 (Z) に 1 cm 厚の水板 (40cm x 40cm) を100枚並べて配置せよ
  - セットアップ図がわかるように全体像を保存し、後述するレポートに貼り付けて提出すること
- 水板を Active Volume (Sensitive Detector) として定義し、登録せよ
  - 少なくとも Copy Number とそれに対応するエネルギー損失量を出力すること
  - 出力に対応する Hit クラスを作成せよ
- EventAction::EndOfEventAction を実装し Hit 情報を元に Ntuple に Fill せよ
- PrimaryGeneratorAction::PrimaryGeneratorAction では 100 MeV の Proton を Z 方向に入射するように実装してある。1000 イベント生成し、保存された Ntuple データを読んで 深さ方向 (Z) のエネルギー分布をプロットせよ
  - 後述するレポートに貼り付けて提出すること
- レポートは [`texdoc`](texdoc) 内に作成せよ
  - LaTeX で記述すること、提出物はソースのみで良い、PDF は不要
- Pull Request の発行をもって提出とする
- 〆切: 8月29日(日)

## 選択課題

+2点以上で優とする。

- [`texdoc`](texdoc) に `CMakeLists.txt` を用意して提出せよ (+1)
- 水板 (40cm x 40cm x 1cm) は G4PVPlacement 以外で配置せよ (+1)
- Sensitive Detector からの出力は TTree オブジェクトとして `TFile` を使用して保存せよ、またそのように [`CMakeLists.txt`](geant4/CMakeLists.txt) を編集せよ。 (+2)
- その他、工夫点があればレポート内に記載せよ、評価に値するものであれば加点する。
