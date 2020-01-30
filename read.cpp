#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>
#include <windows.h>
#include "productHtml.h"

using namespace std;

int main(int argc,char * * argv)
{
    fstream fin(argv[1],fstream::in);
    string test="";
    vector<string> vec_menu;
    vector<string> vec_text;
    string rs="^[0-9]";
    regex expression(rs);
    smatch wm;
    string str_text="<p>";

    while(getline(fin,test))
    {
        if (regex_search (test,wm,expression)) {
            vec_menu.push_back(test);
            //cout<<str_text<<endl;
            str_text+="</p>";
            vec_text.push_back(str_text);
            str_text="<p>";
        }
        else
        {
            str_text+=test;
            str_text+="<br/>";
        }
    }
    vec_text.push_back(str_text);
    cout<<vec_menu.size()<<" "<<vec_text.size()<<endl;
    for(int i=0;i<vec_text.size();i++)
    {
        /*
        cout<<vec_menu[i]<<endl;
        cout<<vec_text[i+1]<<endl;
        */
        string str=vec_text[i];
        string str_name=i==0?"前言":vec_menu[i-1];
        productHtml(str_name,str,i);
    }
    productNcx(vec_menu);
    productOpf(vec_menu);
    cout<<"finished"<<endl;
    fin.close();

    int ret=(int)ShellExecute(NULL,"open","kindlegen.exe","test.opf",NULL,SW_SHOWNORMAL);
    cout<<"ret: "<<ret<<endl;
    return 0;
}