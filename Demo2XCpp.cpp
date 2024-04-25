#include <algorithm>
#include "pt4taskmakerX.h"

using namespace pt4taskmakerX;

DefineGroupName;

void __stdcall inittaskgroup() {
	pt::NewGroup("Примеры различных задач (без fstream)", "М. Э. Абрамян, 2021", 1);
}

DefineTask(Task1) {
	pt::UseTask("Begin", 1);
}

DefineTask(Task2) {
	pt::UseTask("Begin", 2);
}

DefineTask(Task3) {
    pt::NewTask("Ввод и вывод данных, оператор присваивания",
        R"(Даны стороны прямоугольника~{a} и~{b}.\n
        Найти его площадь {S}~=~{a}\*{b} и периметр {P}~=~2\*({a}\;+\;{b}).)");
    double a = pt::Random(1, 99) / 10,
           b = pt::Random(1, 99) / 10;
    pt::SetWidth(5);
    pt::Data("a = ", a, "b = ", b);
    pt::Res("S = ", a * b, "P = ", 2 * (a + b));
    pt::SetTestCount(3);
}

DefineTask(Task4) {
    pt::NewTask("Двумерные массивы (матрицы): вывод элементов",
        R"(Дана матрица размера~{M}\;\x\;{N} и целое число~{K} (1~\l~{K}~\l~{M}).
        Вывести элементы {K}-й строки данной матрицы.)");
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
    pt::NewTask("Символы и строки: основные операции",
        R"(Дана непустая строка~{S}.
        Вывести ее первый и последний символ.)");
    string s = pt::RandomWord();
    if (pt::CurrentTest() == 3) {
        while (s[0] == s[s.length() - 1]) {
            s = pt::RandomWord();
        }
    }
    pt::Data("S = ", s.c_str());
    pt::Res("Первый символ: ", s[0], "Последний символ: ", s[s.length() - 1]);
    pt::SetTestCount(4);
}

DefineTask(Task6) {
    pt::NewTask("Символьные и строковые файлы",
        R"(Дано целое число~{K} (>\,0) и строковый файл.
        Создать два новых файла: строковый, содержащий первые {K}~символов
        каждой строки исходного файла, и символьный, содержащий {K}-й символ
        каждой строки (если длина строки меньше~{K}, то в строковый файл
        записывается вся строка, а в символьный файл записывается пробел).)");
    string s1 = "1" + pt::RandomName(5) + ".tst",
           s2 = "2" + pt::RandomName(5) + ".tst",
           s3 = "3" + pt::RandomName(5) + ".tst";
    FILE* fs1 = std::fopen(s1.c_str(), "wb");
    FILE* fs2 = std::fopen(s2.c_str(), "wb");
    FILE* fc3 = std::fopen(s3.c_str(), "wb");
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
        std::fwrite(buf, sizeof(char), 256, fs1);
        char c = ' ';
        if (j >= k)
        {
            c = s[k-1];
            buf[0] = (char)k;
        }
        std::fwrite(buf, sizeof(char), 256, fs2);
        std::fwrite(&c, sizeof(char), 1, fc3);
    }
    std::fclose(fs1);
    std::fclose(fs2);
    std::fclose(fc3);
    pt::Data("K = ", k);
    pt::Data("Имя исходного файла: ", s1.c_str(), "Содержимое исходного файла:");
    pt::DataFileString(s1.c_str());
    pt::Data("Имя результирующего строкового файла:  ", s2.c_str());
    pt::Data("Имя результирующего символьного файла: ", s3.c_str());
    pt::ResComm("Содержимое результирующего строкового файла:");
    pt::ResFileString(s2.c_str());
    pt::ResComm("Содержимое результирующего символьного файла:");
    pt::ResFileChar(s3.c_str());
}

DefineTask(Task7) {
    pt::NewTask("Текстовые файлы: основные операции",
        R"(Дан текстовый файл.
        Удалить из него все пустые строки.)");
    string s1 = pt::RandomName(6) + ".tst",
           s2 = pt::RandomName(6) + ".tst",
           s = pt::RandomText();
    FILE* t2 = std::fopen(s2.c_str(), "w");
    FILE* t1 = std::fopen(s1.c_str(), "w");
    std::fprintf(t2, "%s\n", s.c_str());
    std::fclose(t2);
    const char* s0 = "\r\n\r\n";
    size_t p = s.find(s0);
    while (p != string::npos)
    {
        s.erase(p, 2);
        p = s.find(s0);
    }
    std::fprintf(t1, "%s\n", s.c_str());
    std::fclose(t1);
    pt::ResText(s1.c_str());
    std::rename(s2.c_str(), s1.c_str());
    pt::Data("Имя файла", s1.c_str());
    pt::DataText(s1.c_str());
    pt::SetTestCount(3);
}
