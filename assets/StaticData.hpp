#pragma once
#include <bits/stdc++.h>
using namespace std;
struct StaticData{
   const string title = "HIGH・ジャック";
   const string explanation = "このゲームのコンセプトは\n"
                              "ブラックジャック x バトルです。\n"
                              "ブラックジャックのゲーム性を主軸に、HP制や特殊効果を追加することで\n"
                              "よりアクティブなものに仕上げました。";
   const vector<string> rule  = {
           {"[基本ルール]\n"
            "基本はブラックジャックと同じく、カードを引いた出目が21に近づくようにします。\n"
            "ただし、扱うカードは1~13がそれぞれ4枚ずつの52枚です。\n"
            "自分と相手(AI)のそれぞれに100ポイントのHPが設定されており、引いたカードの出目の総和をダメージとし、\n"
            "相手のHPを0にすることが勝利目標です。\n"
            "このゲームはバトル要素を加えるために、4つのフェイズからなるターンを繰り返して行います。\n\n"
            "[ドローフェイズ]\n"
            "このフェーズではカードのドローを行います。\n"
            "まず3枚のカードが配られ、プレイヤーは追加でドローするかを選択できます。\n"
            "双方のプレイヤーが追加ドローを選択しなかった場合、お互いの手札は開示され、\n"
            "次のフェーズに進みます。\n"},
           {"[エフェクトフェイズ]\n"
            "このゲームには、何らかの効果(エフェクト)を持つ数字カードがあります。\n"
            "ドローフェイズで引いたカードの中にそれらのカードがあれば、\n"
            "ここでその効果を発動します。\n"
            "以下にカードと効果の表\を載せたので参考にしてください。\n"
            "+-------+-----------------------------------+\n"
            "|カード\t|効果\t\t\t\t    |\n"
            "+-------+-----------------------------------+\n"
            "| 1\t| 与ダメージ1.4倍\t            |\n"
            "| 2\t| なし\t\t\t\t    |\n"
            "| 3\t| なし\t\t\t\t    |\n"
            "| 4\t| 相手の手札を一枚ランダムに捨てる  |\n"
            "| 5\t| なし\t\t\t\t    |\n"
            "| 6\t| なし\t\t\t\t    |\n"
            "| 7\t| HP15回復\t\t\t    |\n"
            "| 8\t| なし\t\t\t\t    |\n"
            "| 9\t| 被ダメージ+10\t\t\t    |\n"
            "| 10\t| 被ダメージ-10\t\t\t    |\n"
            "| 11\t| 自分の手札を一枚ランダムに捨てる  |\n"
            "| 12\t| なし\t\t\t\t    |\n"
            "| 13\t| 与ダメージ+5\t\t\t    |\n"
            "+-------+-----------------------------------+\n"
            "※ カードの効果は重複します\n"
            "例：7が2枚→HP15回復\n"},
           {"[アタックフェイズ]\n"
            "このフェイズでは攻撃を行います。\n"
            "カードの出目の総和とカードエフェクトを考慮した値がダメージとなります。\n"
            "この際、カードの出目が21を超えてしまっていた場合は攻撃が出来ません。\n"
            "また、カードの出目が21ちょうどであった場合は、確殺チャンスが与えられます。\n"
            "  『確殺チャンス』\n"
            "  →確殺チャンスは、確率次第で相手のHPを一撃で削りきり、\n"
            "   勝利を掴み取る千載一遇のチャンスです。\n"
            "  →チャンスは手札枚数が少ないほど高いです。\n"
            "\n"
            "[ジャッジフェイズ]\n"
            "双方のHPを参照し、勝利者がいる場合はターンごとの双方のHPの変動をプロットしたグラフを表\示して、\n"
            "ゲームを継続or終了します。\n"}
   };
};