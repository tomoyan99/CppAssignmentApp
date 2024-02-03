#pragma once
#include <bits/stdc++.h>

using namespace std;

class MultiPlotter {
private:
    ofstream script_file;
    string title;
    struct DataSet {
        vector<double> x_data;
        vector<double> y_data;
        string legend;
    };
    vector<DataSet> data;
public:
    //コンストラクタ
    MultiPlotter(const string& x_label, const string& y_label,const string& title) {
        this->title =title;
        // x軸とy軸のラベルを設定
        script_file.open("plot_script.gnu");
        script_file << "set xlabel '" << x_label << "'\n";
        script_file << "set ylabel '" << y_label << "'\n";
        script_file << "set title '"  << title   << "'\n";
        script_file << "set xtics 1\n";
    }
    //デストラクタ
    ~MultiPlotter() {
        script_file.close();
    }

    // データを追加してプロットするメソッド
    void addData(const vector<double>& x_data, const vector<double>& y_data, const string& legend) {
        // データセットを保存
        data.push_back({x_data, y_data, legend});
    }

    // グラフを表示するメソッド
    void plot() {
        // 新しいプロットを開始
        script_file << "unset key\n";
        script_file << "set multiplot layout " << data.size() << ",1\n";

        // 各データセットをプロット
        for (const auto& dataset : data) {
            script_file << "plot '-' with lines title '" << dataset.legend << "'\n";
            for (size_t i = 0; i < dataset.x_data.size(); ++i) {
                script_file << dataset.x_data[i] << " " << dataset.y_data[i] << "\n";
            }
            script_file << "e\n";
        }
        script_file << "unset multiplot\n";
        //グラフの即座に表示
        script_file << "replot\n";

        //画像ファイルとして保存
        script_file << "set terminal pngcairo enhanced font 'arial,12'\n"; //出力形式をPNGに設定
        script_file << "set output " << "'"<< title << ".png" << "'\n";//保存先のファイル名を指定
        script_file << "replot\n";

        //グラフィックデバイスを元に戻す
        script_file << "set output";
        // ファイルを閉じる
        script_file.close();

        // Gnuplotコマンドを呼び出してスクリプトを実行
        system("gnuplot -persist plot_script.gnu");
        return;
    }
};