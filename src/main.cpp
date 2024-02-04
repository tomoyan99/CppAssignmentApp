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
    MyView MV("�v���b�g�t�F�[�Y",S);
    MV.logPause("�^�[����HP�̑J�ڃO���t���v���b�g���܂� ");
    MP.plot();
    MV.logPause("�X�y�[�X�L�[�������ďI�����܂� ");
    return 0;
}