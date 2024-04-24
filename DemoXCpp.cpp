#include <algorithm>
#include <fstream>
#include "pt4taskmakerX.h"

using namespace pt4taskmakerX;

DefineGroupName;

void __stdcall inittaskgroup() {
	pt::NewGroup("������� ��������� �����", "�. �. �������, 2021", 1);
}

DefineTask(Task1) {
	pt::UseTask("Begin", 1);
}

DefineTask(Task2) {
	pt::UseTask("Begin", 2);
}

DefineTask(Task3) {
    pt::NewTask("���� � ����� ������, �������� ������������",
        R"(���� ������� ��������������~{a} �~{b}.\n
        ����� ��� ������� {S}~=~{a}\*{b} � �������� {P}~=~2\*({a}\;+\;{b}).)");
    double a = pt::Random(1, 99) / 10,
           b = pt::Random(1, 99) / 10;
    pt::SetWidth(5);
    pt::Data("a = ", a, "b = ", b);
    pt::Res("S = ", a * b, "P = ", 2 * (a + b));
    pt::SetTestCount(3);
}

DefineTask(Task4) {
    pt::NewTask("��������� ������� (�������): ����� ���������",
        R"(���� ������� �������~{M}\;\x\;{N} � ����� �����~{K} (1~\l~{K}~\l~{M}).
        ������� �������� {K}-� ������ ������ �������.)");
    int m = pt::Random(4, 8),
        n = pt::Random(4, 8),
        k = pt::Random(1, m);
    pt::Data("M = ", m, "N = ", n);
    pt::SetWidth(5);
    for ( int i = 0; i < m; ++i) {
        vector<double> a(n);
        generate(a.begin(), a.end(), [&]() { return pt::Random(-9.99, 9.99); });
        pt::Data(a);
        if (i == k - 1) {
            pt::Res(a);
        }
    }
    pt::SetWidth(0);
    pt::Data("K = ", k);
    pt::SetTestCount(5);
}

DefineTask(Task5) {
    pt::NewTask("������� � ������: �������� ��������",
        R"(���� �������� ������~{S}.
        ������� �� ������ � ��������� ������.)");
    string s = pt::RandomWord();
    if (pt::CurrentTest() == 3) {
        while (s[0] == s[s.length() - 1]) {
            s = pt::RandomWord();
        }
    }
    pt::Data("S = ", s.c_str());
    pt::Res("������ ������: ", s[0], "��������� ������: ", s[s.length() - 1]);
    pt::SetTestCount(4);
}

DefineTask(Task6) {
    pt::NewTask("���������� � ��������� �����",
        R"(���� ����� �����~{K} (>\,0) � ��������� ����.
        ������� ��� ����� �����: ���������, ���������� ������ {K}~��������
        ������ ������ ��������� �����, � ����������, ���������� {K}-� ������
        ������ ������ (���� ����� ������ ������~{K}, �� � ��������� ����
        ������������ ��� ������, � � ���������� ���� ������������ ������).)");
    string s1 = "1" + pt::RandomName(5) + ".tst",
           s2 = "2" + pt::RandomName(5) + ".tst",
           s3 = "3" + pt::RandomName(5) + ".tst";
    ofstream fs1(s1, ios::binary | ios_base::out),
             fs2(s2, ios::binary | ios_base::out),
             fc3(s3, ios::binary | ios_base::out);
    int k = pt::Random(2, 11),
        n = pt::Random(10, 20),
        jmax = 0;
    for (int i = 1; i < n; ++i) {
        ShortString buf;
        int j = pt::Random(2, 16);
        if (jmax < j)
            jmax = j;
        string s = pt::RandomName(pt::Random(2, 16));
        pt::ConvertToShortString(s, buf);
        fs1.write(buf, 256);
        char c = ' ';
        if (j >= k)
        {
            c = s[k-1];
            buf[0] = (char)k;
        }
        fs2.write(buf, 256);
        fc3.write((char*) &c, 1);
        // char ch = (s.length() >= k) ? s[k - 1] : ' ';
        // fc3.write(&ch, sizeof(char));
        // fs2 << s.substr(0, k) << endl; 
    }
    fs1.close();
    fs2.close();
    fc3.close();
    pt::Data("K = ", k);
    pt::Data("��� ��������� �����: ", s1.c_str(), "���������� ��������� �����:");
    //pt4taskmaker::DataFileS(s1.c_str(), 3, jmax + 3);
    pt::DataFileString(s1.c_str());
    pt::Data("��� ��������������� ���������� �����:  ", s2.c_str());
    pt::Data("��� ��������������� ����������� �����: ", s3.c_str());
    pt::ResComm("���������� ��������������� ���������� �����:");
    pt::ResFileString(s2.c_str());
    pt::ResComm("���������� ��������������� ����������� �����:");
    pt::ResFileChar(s3.c_str());
}