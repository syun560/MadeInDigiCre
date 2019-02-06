# MadeInDegiCre
## 概要
デジクリの企画です。
DxライブラリとC++を利用して、某簡単操作のゲームを真似たミニゲームを作っていきます。

気が向いた時に更新していきます。

## 主なファイルの説明
- Source.cpp

プログラムのエントリポイントです。DXライブラリの初期化処理やループ処理を行っています。

- MyDx.cpp

Dxライブラリのラップ関数や、プログラム全体でグローバルに扱いたい変数を記述します。基本的にほとんどのファイルはMyDx.hをincludeします。

- Game.cpp

ゲームの一番根幹の部分です。シーン遷移などを記述します。

- Input.cpp

Dxライブラリ標準のマウスやキーボードの入出力の取扱いをすこしだけ簡単にします。すべてstatic関数なので、#include "Input.h"でどこからでも呼び出せます（それがデザイン的に良いのかどうかは置いといて）
