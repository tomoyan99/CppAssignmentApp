#pragma once
#include "../AllLib.hpp"
using namespace std;
struct StaticData{
    const Table explanation = {
            {"このゲームのコンセプトは"},
            {"ブラックジャック x バトルです。"},
            {"ブラックジャックのゲーム性を主軸に、HP制や特殊効果を追加することで"},
            {"よりアクティブなものに仕上げました。"}
    };
    const vector<Table> rule  = {
            {
                    {"[基本ルール]"},
                    {"ブラックジャックの要領で、カードを引いた出目が \"21\" に近づくようにします。"},
                    {"扱うカードは1~10がそれぞれ4枚ずつの52枚です。"},
                    {"自分と相手(AI)のそれぞれに100ポイントのHPが設定されており、引いたカードの出目の総和をダメージとし、"},
                    {"相手のHPを0にすることが勝利目標です。"},
                    {"このゲームはバトル要素を加えるために、4つのフェイズからなるターンを繰り返して行います。"}
            },
            {
                    {"[ドローフェイズ]"},
                    {"このフェーズではカードのドローを行います。"},
                    {"まず3枚のカードが配られ、プレイヤーは追加でドローするかを選択できます。"},
                    {"双方のプレイヤーが追加ドローを選択しなかった場合、お互いの手札は開示され、"},
                    {"次のフェーズに進みます。"}
            },
            {
                    {"[エフェクトフェイズ]"},
                    {"このゲームには、何らかの効果(エフェクト)を持つ数字カードがあります。"},
                    {"ドローフェイズで引いたカードの中にそれらのカードがあれば、"},
                    { "ここでその効果を発動します。" },
                    {"以下にカードと効果の表\を載せたので参考にしてください。"},
                    {"+-------+-----------------------------------+"},
                    {"|カード | 効果                              |"},
                    {"+-------+-----------------------------------+"},
                    {"| 1     | 攻撃力1.4倍                       |"},
                    {"| 2     | 攻撃力-10                         |"},
                    {"| 3     | なし                              |"},
                    {"| 4     | 攻撃力+10                         |"},
                    {"| 5     | 攻撃力0.8倍                       |"},
                    {"| 6     | なし                              |"},
                    {"| 7     | HP15回復                          |"},
                    {"| 8     | 自分の手札を一枚ランダムに捨てる  |"},
                    {"| 9     | 相手の手札を一枚ランダムに捨てる  |"},
                    {"| 10    | なし                              |"},
                    {"+-------+-----------------------------------+"},
                    {"※ カードの効果は重複します"},
                    {"例：7が2枚→HP15回復"}
            },
            {
                    {"[アタックフェイズ]"},
                    {"このフェイズでは攻撃を行います。"},
                    {"カードの出目の総和とカードエフェクトを考慮した値がダメージとなります。"},
                    {"この際、カードの出目が31を超えてしまっていた場合は攻撃が出来ません。"},
                    {"また、カードの出目が31ちょうどであった場合は、確殺チャンスが与えられます。"},
                    {"  『確殺チャンス』"},
                    {"  →確殺チャンスは、確率次第で相手のHPを一撃で削りきり、"},
                    {"   勝利を掴み取る千載一遇のチャンスです。"},
                    {"  →チャンスは手札枚数が少ないほど高いです。"},
                    {""},
            },
            {
                    {"[ジャッジフェイズ]"},
                    {"双方のHPを参照し、勝利者がいる場合はターンごとの双方のHPの変動をプロットしたグラフを表\示して、"},
                    {"ゲームを継続or終了します。"}
            }
    };
};