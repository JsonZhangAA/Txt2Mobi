#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void productHtml(string str_name,string str_text,int no)
{
    string fileName="./chapter"+to_string(no)+".html";
    fstream fout(fileName,ios::out);
    fout<<"<html>"<<endl<<"<head>"<<endl<<"<meta http-equiv=\"content-type\" content=\"text/html; charset=utf-8\">"
        <<endl<<"<link rel=\"stylesheet\" type=\"text/css\" href=\"online.css\">"
        <<endl<<"</head>"<<endl<<"<body>";
    fout<<"<title>"<<str_name<<"</title>"<<endl<<str_text;
    fout<<" </body>"<<endl<<"</html>";

    fout.close();
}

void productNcx(vector<string> & menu_name)
{

    fstream fout("./menu.ncx",ios::out);
    fout<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"<<endl<<"<!DOCTYPE ncx PUBLIC \"-//NISO//DTD ncx 2005-1//EN\" \"http://www.daisy.org/z3986/2005/ncx-2005-1.dtd\">"
<<endl<<"<ncx xmlns=\"http://www.daisy.org/z3986/2005/ncx/\" version=\"2005-1\" xml:lang=\"en-US\">"<<endl<<"<head>"<<endl<<
"<meta name=\"dtb:uid\" content=\"BookId\"/>"<<endl<<
"<meta name=\"dtb:depth\" content=\"2\"/>"<<endl<<
"<meta name=\"dtb:totalPageCount\" content=\"0\"/>"<<endl<<
"<meta name=\"dtb:maxPageNumber\" content=\"0\"/>"<<endl<<
"</head>"<<endl<<
"<docTitle><text>藏地密码</text></docTitle>"<<endl<<
"<docAuthor><text>何马</text></docAuthor>"<<endl<<
    "<navMap>";
fout<<"<navPoint class=\"toc\" id=qianyan playOrder=\"1\">"<<endl<<
                "<navLabel>"<<endl<<
                        "<text>前言</text>"<<endl<<
                "</navLabel>"<<endl<<
                "<content src=\"chapter0.html\"/>"<<endl<<
        "</navPoint>";
    for(int i=0;i<menu_name.size();i++)
    {
        fout<<"<navPoint class=\"toc\" id=\""+menu_name[i]+"\" playOrder=\"1\">"<<endl<<
                    "<navLabel>"<<endl<<
                            "<text>"+menu_name[i]+"</text>"<<endl<<
                    "</navLabel>"<<endl<<
                    "<content src=\"chapter"+to_string(i+1)+".html\"/>"<<endl<<
            "</navPoint>";
    }
    fout<<" </navMap>"<<endl<<"</ncx>";
    fout.close();
    cout<<"finished ncx"<<endl;
}

void productOpf(vector<string> & menuName)
{
    fstream fout("./test.opf",fstream::out);
    fout<<"<package xmlns=\"http://www.idpf.org/2007/opf\" version=\"2.0\" unique-identifier=\"BookId\">"<<endl<<
    "<metadata xmlns:dc=\"http://purl.org/dc/elements/1.1/\" xmlns:opf=\"http://www.idpf.org/2007/opf\">"<<endl<<
    "<dc:title>电子书标题</dc:title>"<<endl<<
    "<dc:language>en-us</dc:language>"<<endl<<
    "</metadata>"<<endl<<
    "<manifest>";
    fout<<"<item id=\"My_Table_of_Contents\" media-type=\"application/x-dtbncx+xml\" href=\"menu.ncx\"/>"<<endl;
    for(int i=0;i<menuName.size()+1;i++)
    {
        fout<<"<item id=\"item"+to_string(i)+"\" media-type=\"application/xhtml+xml\" href=\"chapter"+to_string(i)+".html\"/>"<<endl;
    }
    fout<<"</manifest>"<<endl<<"<spine toc=\"My_Table_of_Contents\">";
    for(int i=0;i<menuName.size()+1;i++)
    {
        fout<<"<itemref idref=\"item"+to_string(i)+"\"/>"<<endl;
    }
    fout<<" </spine>"<<endl<<"</package>";
    fout.close();
    cout<<"finished opf"<<endl;
}