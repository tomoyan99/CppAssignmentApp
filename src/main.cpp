#include "../lib/AllLib.hpp"

int main(void) {
    srand(time(NULL));
    Title T;
    GameMain G;
    Plot P = G.getPlotData();
    Status S = G.getStatus();
    MultiPlotter MP("Tern","HP","Result");
    MP.addData(P["x"],P["y_Human"],"Player");
    MP.addData(P["x"],P["y_AI"],"AI");
    MyView MV("プロットフェーズ",S);
    MV.logPause("ターンとHPの遷移グラフをプロットします ");
    MP.plot();
    MV.logPause("スペースキーを押して終了します ");
    return 0;
}