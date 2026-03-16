/*
 * meishi2 Binary Numpad - config.h
 * コンボ機能の設定
 */

#pragma once

// コンボの判定時間（ミリ秒）
// 同時押しと判定するまでの猶予時間。
// 短すぎると同時押しが認識されにくく、長すぎると単独キーの反応が遅くなる。
// デフォルトは50ms。慣れないうちは長めの100msに設定。
// 慣れてきたら50〜60msに下げると反応が速くなる。
#define COMBO_TERM 100

// コンボのバッファサイズ（4キー同時押しがあるので余裕を持たせる）
#define COMBO_KEY_BUFFER_LENGTH 8
#define COMBO_BUFFER_LENGTH 8
