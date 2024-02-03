#pragma once
#include <bits/stdc++.h>

using namespace std;

class MultiPlotter {
private:
    ofstream script_file;
    ofstream data_file;
    string title;
    struct DataSet {
        vector<int> x_data;
        vector<int> y_data;
        string legend;
    };
    vector<DataSet> data;
public:
    //コンストラクタ
    MultiPlotter(const string& x_label, const string& y_label,const string& title) {
        this->title =title;
        // x軸とy軸のラベルを設定
        script_file.open("plot_script.gnu");
        data_file.open("plot_data.dat");
        script_file << "set xlabel '" << x_label << "'\n";
        script_file << "set ylabel '" << y_label << "'\n";
        script_file << "set title '"  << title   << "'\n";
        script_file << "set xtics 1\n";
    }
    //デストラクタ
    ~MultiPlotter() {
        script_file.close();
        data_file.close();
    }
    // データを追加してプロットするメソッド
    void addData(const vector<int>& x_data, const vector<int>& y_data, const string& legend) {
        // データセットを保存
        data.push_back({x_data, y_data, legend});
    }

    // グラフを表示するメソッド
    void plot() {
        //凡例の表示
        script_file << "set key top right\n";
        //multiplotモードの開始
        script_file << "set multiplot layout " << data.size() << ",1\n";
        // 各データセットをplot_data.datに保存
        for (size_t i = 0; i < data[0].x_data.size(); ++i) {
            data_file << data[0].x_data[i];
            for (const auto& dataset : data) {
                data_file << "\t" << dataset.y_data[i];
            }
                data_file << "\n";
        }
        //plot_data.datを読み込んでプロットするという処理を記述
        script_file << "plot ";
        for (int i = 0; i < data.size(); ++i) {
            script_file << "'plot_data.dat' using 1:"<< i+2 <<" with lines lw 2 title '"
                        << data[i].legend <<"'";
            if(i<data.size()-1){
                script_file << ",\\";
            }
            script_file << "\n";
        }
        //multiplotモードを解除？
        script_file << "unset multiplot\n";
        //グラフを即座に表示
        script_file << "replot\n";
        //画像ファイルとして保存
        script_file << "set terminal pngcairo enhanced font 'arial,12'\n"; //出力形式をPNGに設定
        script_file << "set output " << "'"<< title << ".png" << "'\n";//保存先のファイル名を指定
        //再プロット
        script_file << "replot\n";
        script_file << "set output\n";
        //ファイルを閉じる(これがないとplot出来ない)
        data_file.close();
        script_file.close();
        // Gnuplotコマンドを呼び出してスクリプトを実行
        system("gnuplot -persist plot_script.gnu");
        return;
    }
};