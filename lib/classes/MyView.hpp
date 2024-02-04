#pragma once
#include "../AllLib.hpp"
#include <conio.h>
struct Status{
    HP hps={
            {"Human",100},
            {"AI",100}
    };
    Hand hands;
    Damage dmgs;
    Result result;
    int tern=0;
    bool is_continue = true;
};

class MyView{
private:
    Table comp_phase;
    Cards c_human;
    Cards c_AI;
    Table comp_cards_human;
    Table comp_cards_AI;
    Table comp_et_human;
    Table comp_et_AI;
    Table comp_log;
    Table comp_log_title={"[ ログ ]"};
    int c_p_hol;
    int c_c_h_hol;
    int c_c_A_hol;
    int c_e_h_hol;
    int c_e_A_hol;
    int comp_width_human;
    int comp_width_AI;

    int start_ver_human;
    int end_ver_human;
    int start_ver_AI;
    int end_ver_AI;

    int top;
    vector<int> start_hol_human;
    vector<int> start_hol_AI;
    Table line_v;
    Table line_h;
    int log_title_start;
    int log_ver_start;
    int log_hol_start;
    int log_ver_end;
    int log_hol_end;
    int log_size_limit = 9;
public:
    MyView(string phase,Status s,bool isEnemyHide=false){
        reloadData(phase,s,isEnemyHide);
        render();
    }
    void reloadData(string phase,Status s,bool isEnemyHide=false){
        EffectTable ET;
        comp_phase = {
                "ターン："+ to_string(s.tern)+"       [ "+phase+" ]"
        };
        c_human = s.hands["Human"];
        c_AI    = s.hands["AI"];
        string total_str = (phase == "ドローフェイズ")?"トータル":"攻撃力";
        map<string,int> total_num = {
                {"Human",sumMultiset(c_human)},
                {"AI",sumMultiset(c_AI)}
        };

        comp_cards_human = {
            "[ Player ]の手札   HP:"+ to_string(s.hps["Human"])+"/100",
            getPrintArray(c_human)+"  トータル:"+ to_string(total_num["Human"])+"  攻撃力:"+ to_string(s.dmgs["Human"]),
        };
        comp_et_human = ET.getTable(s.hands,"Human");

        if (isEnemyHide){
            comp_cards_AI = {
                    "[ AI ]の手札   HP:"+ to_string(s.hps["AI"])+"/100",
                    "[ * * * ]",
            };
            comp_et_AI = ET.getDummyTable();
        }else{
            comp_cards_AI = {
                    "[ AI ]の手札   HP:"+ to_string(s.hps["AI"])+"/100",
                    getPrintArray(c_AI)+"  トータル:"+ to_string(total_num["AI"])+"  攻撃力:"+ to_string(s.dmgs["AI"]),
            };
            comp_et_AI = ET.getTable(s.hands,"AI");
        }

        c_p_hol = comp_phase.size();
        c_c_h_hol = comp_cards_human.size();
        c_c_A_hol = comp_cards_AI.size();
        c_e_h_hol = comp_et_human.size();
        c_e_A_hol = comp_et_AI.size();
        comp_width_human = max(comp_cards_human[1].length(),comp_et_human[0].length());
        comp_width_AI = max(comp_cards_AI[1].length(),comp_et_AI[0].length());
        start_ver_human = 6;
        end_ver_human = start_ver_human + comp_width_human;
        start_ver_AI = end_ver_human + 8;
        end_ver_AI = start_ver_AI + comp_width_AI;
        top = 3;
        start_hol_human = {
                1,
                top+c_p_hol,
                top+c_p_hol+c_c_h_hol,
                top+c_p_hol+c_c_h_hol+c_e_h_hol,
        };
        start_hol_AI = {
                top,
                top+c_p_hol,
                top+c_p_hol+c_c_A_hol,
                top+c_p_hol+c_c_A_hol+c_e_A_hol
        };
        line_v={""};
        line_h={};
        for (int i = 0; i < end_ver_AI+5; ++i) {
            line_v[0]+="-";
        }
        for (int i = 0; i < max(start_hol_human[3],start_hol_AI[3]); ++i) {
            line_h.push_back("|");
        }
        log_ver_start = start_ver_human;
        log_title_start = line_h.size()+2;
        log_hol_start = log_title_start+1;
        log_ver_end = line_v[0].length();
        log_hol_end = line_h.size();
    }
    void addLog(string log){
        if (comp_log.size() == log_size_limit){comp_log.clear();}
        comp_log.push_back(log);
        logRender();
    }
    void addLog(Table log){
        if (comp_log.size() == log_size_limit){comp_log.clear();}
        for (string s:log) {
            comp_log.push_back(s);
        }
        logRender();
    }
    void logRender(){
        cout << "\x1b["<<to_string(log_hol_start)<<";"<<to_string(log_ver_start)<<"H"<<"\x1b[0J";
        showAnywhereTxt(line_v          ,1,log_title_start+line_h.size());
        showAnywhereTxt(line_h          ,1,log_title_start);
        showAnywhereTxt(line_h          ,log_ver_end,log_title_start);
        showAnywhereTxt(comp_log_title,start_ver_human,log_title_start);
        showAnywhereTxt(comp_log      ,start_ver_human,log_hol_start  );
    }
    bool logConfirm(string prompt){
        vector<char>keys = {'y','Y','n','N'};
        addLog(prompt+"[y/n]>>");
        int log_end_cursor = log_ver_start+comp_log[comp_log.size()-1].length();
        cout << "\x1b[1F\x1b["+ to_string(log_end_cursor)+"C";

        char yn = _getch();
        auto p = find(keys.begin(), keys.end(),yn);
        while(p == keys.end()){
            yn = _getch();
            p = find(keys.begin(), keys.end(),yn);
        }
        if(yn == 'y' ||yn == 'Y'){
            return true;
        }else{
            return false;
        }
    }
    void logPause(string prompt){
        char key = ' ';
        addLog(prompt+"[space]");
        int log_end_cursor = log_ver_start+comp_log[comp_log.size()-1].length();
        cout << "\x1b[1F\x1b["+ to_string(log_end_cursor)+"C";
        pause("");
    }
    void logClear(){
        comp_log.clear();
        logRender();
    }

    void interfaceRander(){
        showAnywhereTxt(comp_phase      ,start_ver_human    ,start_hol_human[0]);
        showAnywhereTxt(comp_cards_human,start_ver_human    ,start_hol_human[1]);
        showAnywhereTxt(comp_et_human   ,start_ver_human    ,start_hol_human[2]);
        showAnywhereTxt(comp_cards_AI   ,start_ver_AI       ,start_hol_AI[1]);
        showAnywhereTxt(comp_et_AI      ,start_ver_AI       ,start_hol_AI[2]);
        showAnywhereTxt(line_h          ,1,2);
        showAnywhereTxt(line_h          ,start_ver_AI+comp_width_AI+5 ,2);
        showAnywhereTxt(line_h          ,comp_width_human+10 ,2);
        showAnywhereTxt(line_v          ,1,line_h.size()+1);
        showAnywhereTxt(line_v          ,1,2);
    }
    void render(){
        system("cls");
        interfaceRander();
        logRender();
    }
};