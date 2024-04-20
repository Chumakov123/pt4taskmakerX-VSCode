#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include "pt4taskmaker.h"

vector<int> vn;
vector<double> vr;
vector<string> vs;
vector<char> vc;

string abc("0123456789abcdefghijklmnopqrstuvwxyz");
string ABCext("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ");
string abcext("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

void MakeVN(int n, int a1, int b1)
{
  vn.clear();
  for (int i = 0; i < n; i++)
    vn.push_back(RandomN(a1,b1));
}

void MakeVR(int n, int a1, int b1)
{
  vr.clear();
  for (int i = 0; i < n; i++)
    vr.push_back(RandomN(a1,b1)/100.0);
}

void MakeVS(int n)
{
  vs.clear();
  int nw = EnWordCount()-1;
  for (int i = 0; i < n; i++)
    vs.push_back(EnWordSample(RandomN(0,nw)));
//  for (int i = 0; i <= nw; i++)
//    vs.push_back(EnWordSample(i));
}

void MakeVC(int n, string s)
{
  vc.clear();
  int nw = s.size()-1;
  for (int i = 0; i < n; i++)
    vc.push_back(s[RandomN(0,nw)]);
}

string RandomStr(int n)
{
        string res;
        for (int i = 0; i < n; i++)
                res += abc[RandomN(0, abc.size()-1)];
        return res;
}


void DataVN(const char* comm, int y)
{
  int p = 2;
  if (comm != "")
    DataComment(comm,p,y);
  p += 2;
  int n = vn.size();
  DataN("(",n,p,y,2);
  p += 3;
  DataComment("):",p,y);
  p += 2;
  int p0 = p;
  for (int i = 0; i < n; i++)
  {
      DataN("",vn[i],p,y,4);
          p += 4;
          if (p > 74)
          {
                  y++;
                  p = p0;
          }
  }
}

void ResultVN(const char* comm, int y)
{
  int p = 2;
  if (comm != "")
    ResultComment(comm,p,y);
  p += 2;
  int n = vn.size();
//  DataN("(",n,p,y,2);
  if (comm != "")
    ResultComment(":",p,y);
  p += 5;
  int p0 = p;
  for (int i = 0; i < n; i++)
  {
      ResultN("",vn[i],p,y,4);
          p += 4;
          if (p > 74)
          {
                  y++;
                  p = p0;
          }
  }
}

void DataVR(const char* comm, int y)
{
  int p = 2;
  if (comm != "")
    DataComment(comm,p,y);
  p += 2;
  int n = vr.size();
  DataN("(",n,p,y,2);
  p += 3;
  DataComment("):",p,y);
  p += 2;
  int p0 = p;
  for (int i = 0; i < n; i++)
  {
      DataR("",vr[i],p,y,6);
          p += 6;
          if (p > 74)
          {
                  y++;
                  p = p0;
          }
  }
}

void ResultVR(const char* comm, int y)
{
  int p = 2;
  if (comm != "")
    ResultComment(comm,p,y);
  p += 2;
  int n = vr.size();
//  DataN(" ",n,p,y,2);
  if (comm != "")
    ResultComment(":",p,y);
  p += 5;
  int p0 = p;
  for (int i = 0; i < n; i++)
  {
      ResultR("",vr[i],p,y,6);
          p += 6;
          if (p > 74)
          {
                  y++;
                  p = p0;
          }
  }
}


void DataVS(const char* comm, int y)
{
  int p = 2;
  if (comm != "")
    DataComment(comm,p,y);
  p += 2;
  int n = vs.size();
  DataN("(",n,p,y,2);
  p += 3;
  DataComment("):",p,y);
  p += 3;
  int p0 = p;
  int step = max_element(vs.begin(), vs.end(), [](string s1, string s2){return s1.size() < s2.size();})->size()+3;
  for (int i = 0; i < n; i++)
  {
      DataS("",vs[i].c_str(),p,y);
          p += step;
          if (p > 78 - step)
          {
                  y++;
                  p = p0;
          }
  }
}

void ResultVS(const char* comm, int y)
{
  int p = 2;
  if (comm != "")
    ResultComment(comm,p,y);
  p += 2;
  int n = vs.size();
//  DataN("(",n,p,y,2);
  if (comm != "")
    ResultComment(":",p,y);
  p += 6;
  int p0 = p;
  int step = max_element(vs.begin(), vs.end(), [](string s1, string s2){return s1.size() < s2.size();})->size()+3;
  for (int i = 0; i < n; i++)
  {
      ResultS("",vs[i].c_str(),p,y);
          p += step;
          if (p > 78 - step)
          {
                  y++;
                  p = p0;
          }
  }
}


void DataVC(const char* comm, int y)
{
  int p = 2;
  if (comm != "")
    DataComment(comm,p,y);
  p += 2;
  int n = vc.size();
  DataN("(",n,p,y,2);
  p += 3;
  DataComment("):",p,y);
  p += 3;
  int p0 = p;
  for (int i = 0; i < n; i++)
  {
      DataC("",vc[i],p,y);
          p += 4;
          if (p > 74)
          {
                  y++;
                  p = p0;
          }
  }
}

void ResultVC(const char* comm, int y)
{
  int p = 2;
  if (comm != "")
    ResultComment(comm,p,y);
  p += 2;
  int n = vc.size();
//  DataN("(",n,p,y,2);
  if (comm != "")
  ResultComment(":",p,y);
  p += 6;
  int p0 = p;
  for (int i = 0; i < n; i++)
  {
      ResultC("",vc[i],p,y);
          p += 4;
          if (p > 74)
          {
                  y++;
                  p = p0;
          }
  }
}


void DataFileVN(const char* name, int y1, int y2)
{
  ofstream f(name);
  int n = 0, l = RandomN(1,8);
  while (n < (int)vn.size())
  {
          f << vn[n++];
          l--;
          bool b = n < (int)vn.size();
          if (l == 0)
          {
                  f << endl;
                  l = RandomN(1,8);
          }
          else
                  if (b) 
                  f << " ";
  }
  f.close();
  DataFileT(name, y1, y2);
}

void DataFileVR(const char* name, int y1, int y2)
{
  ofstream f(name);
  int n = 0, l = RandomN(1,7);
  while (n < (int)vr.size())
  {
          f << vr[n++];
          l--;
          bool b = n < (int)vr.size();
          if (l == 0)
          {
                  f << endl;
                  l = RandomN(1,7);
          }
          else
                  if (b) 
                  f << " ";
  }
  f.close();
  DataFileT(name, y1, y2);
}

void DataFileVS(const char* name, int y1, int y2)
{
  ofstream f(name);
  int n = 0, l = RandomN(1,7), cnt = 0;
  while (n < (int)vs.size())
  {
          cnt += vs[n].size()+1;
          f << vs[n++];
          l--;
          bool b = n < (int)vs.size();
          if (l == 0 || b && cnt + vs[n].size() > 70)
          {
                  f << endl;
                  cnt = 0;
                  l = RandomN(1,7);
          }
          else
                  if (b)
                      f << " ";
  }
  f.close();
  DataFileT(name, y1, y2);
}


void ResultFileVN(const char* name, int y1, int y2)
{
  ofstream f(name);
  int n = 0;
  while (n < (int)vn.size())
  {
          f << vn[n++] << endl;
  }
  f.close();
  ResultFileT(name, y1, y2);
}

void ResultFileVN1(const char* name, int y1, int y2, const char* delim)
{
  ofstream f(name);
  int n = 0;
  while (n < (int)vn.size())
  {
          f << vn[n++] << delim;
  }
  f.close();
  ResultFileT(name, y1, y2);
}



void ResultFileVS(const char* name, int y1, int y2)
{
  ofstream f(name);
  int n = 0;
  while (n < (int)vs.size())
  {
          f << vs[n++] << endl;
  }
  f.close();
  ResultFileT(name, y1, y2);
}


void ResultFileVC(const char* name, int y1, int y2, const char* delim)
{
  ofstream f(name);
  int n = 0;
  while (n < (int)vc.size())
  {
          f << vc[n++] << delim;
  }
  f.close();
  ResultFileT(name, y1, y2);
}



//void ResultSeqN(const char* comm, int y)
//{
//  if (comm != "")
//    ResultComment(comm,0,y++);
//  int n = a.size();
//  for (int i = 0;  i < n; i++)
//    ResultN("",a[i],Center(i+1,n,3,1),y,3);
//}

void Stl1() 
{
  CreateTask();
  TaskText(
  "Дан набор целых чисел. Найти количество нулей в исходном наборе.\n"
  "Использовать итератор ptin\\_iterator и алгоритм count."
  );
  MakeVN(RandomN(10, 34), -5, 5);
  DataVN("", 3);
  ResultN(count(vn.begin(), vn.end(), 0), 0, 3, 2);
}

void Stl2()
{
  CreateTask();
  TaskText(
  "Дан текстовый файл с именем {name}, содержащий строковые представления\n"
  "вещественных чисел. Найти количество положительных чисел в исходном файле.\n"
  "Использовать итератор istream\\_iterator и алгоритм count\\_if."
  );
  MakeVR(RandomN(10, 33), -999, 999);
//  DataVR("", 3);
  string name = RandomStr(8) + ".tst";
  DataS("name = ", name.c_str(), 0, 1);
  DataFileVR(name.c_str(), 2, 5);
  ResultN(count_if(vr.begin(), vr.end(), [](double e){return e > 0;}), 0, 3, 2);
}

void Stl3()
{
  CreateTask();
  TaskText(
  "Дан текстовый файл с именем {name}, содержащий английские слова.\n"
  "Найти количество слов длины~6. Использовать итератор istream\\_iterator\n"
  "и алгоритм count\\_if."
  );
  MakeVS(RandomN(10, 34));
//  DataVS("", 3);
  string name = RandomStr(8) + ".tst";
  DataS("name = ", name.c_str(), 0, 1);
  DataFileVS(name.c_str(), 2, 5);

  ResultN(count_if(vs.begin(), vs.end(), [](string e){return e.size() == 6;}), 0, 3, 2);
}

void Stl4()
{
  CreateTask();
  TaskText(
  "Дан набор вещественных чисел. Вывести все элементы этого набора\n"
  "в том же порядке. Использовать итераторы ptin\\_iterator,\n"
  "ptout\\_iterator и алгоритм copy."
  );
  MakeVR(RandomN(10, 33), -999, 999);
  DataVR("", 3);
  ResultVR("", 3);
}

void Stl5()
{
  CreateTask();
  TaskText(
  "Дан текстовый файл с именем {name}, содержащий строковые представления\n"
  "целых чисел. Вывести все числа из файла в том же порядке. Использовать\n"
  "итераторы istream\\_iterator, ptout\\_iterator и алгоритм copy."
  );
  MakeVN(RandomN(10, 34), -99, 99);
//  DataVR("", 3);
  string name = RandomStr(8) + ".tst";
  DataS("name = ", name.c_str(), 0, 1);
  DataFileVN(name.c_str(), 2, 5);
  ResultVN("", 3);
}

void Stl6()
{
  CreateTask();
  TaskText(
  "Дана строка {name} и набор символов. Записать в текстовый файл\n"
  "с именем {name} исходный набор символов в том же порядке, добавляя\n"
  "после каждого символа пробел. Использовать итераторы ptin\\_iterator,\n"
  "ostream\\_iterator и алгоритм copy."
  );
  string name = RandomStr(8) + ".tst";
  DataS("name = ", name.c_str(), 0, 2);
  MakeVC(RandomN(10, 34), abcext);
  DataVC("", 3);
//  DataFileVN(name.c_str(), 2, 5);
  ResultFileVC(name.c_str(), 3, 3, " ");
}

void Stl7(int k)
{
  CreateTask();
  if (k == 0)
  TaskText(
  "Дан текстовый файл с именем {name1}, содержащий строковые представления\n"
  "целых чисел, и строка {name2}. Записать в текстовый файл с именем {name2}\n"
  "все ненулевые числа из исходного файла в том же порядке, располагая\n"
  "каждое число на новой строке. Использовать итераторы istream\\_iterator,\n"
  "ostream\\_iterator и алгоритм remove\\_copy."
  );
  else
  TaskText(
  "Решить задачу \\4, используя вместо алгоритма remove\\_copy\n"
  "цикл for с параметром-итератором."
  );
  string name1 = RandomStr(7) + "1.tst", name2 = RandomStr(7) + "2.tst";
  DataS("name1 = ", name1.c_str(), xLeft, 1);
  DataS("name2 = ", name2.c_str(), xRight, 1);
  MakeVN(RandomN(10, 34), -9, 9);
//  DataVC("", 3);
  DataFileVN(name1.c_str(), 2, 5);
  auto it = remove(vn.begin(), vn.end(), 0);
  vn.erase(it, vn.end());
  ResultFileVN(name2.c_str(), 1, 5);
}

void Stl8(int k)
{
  CreateTask();
  if (k == 0)
  TaskText(
  "Дано целое число {K} (>\\,0), текстовый файл с именем {name1}, содержащий английские\n"
  "слова, и строка {name2}. Записать в текстовый файл с именем {name2} все слова\n"
  "из исходного файла, длина которых не превосходит~{K}, сохранив исходный порядок\n"
  "их следования и располагая каждое слово на новой строке. Использовать\n"
  "итераторы istream\\_iterator, ostream\\_iterator и алгоритм remove\\_copy\\_if."
  );
  else
  TaskText(
  "Решить задачу \\4, используя вместо алгоритма remove\\_copy\\_if\n"
  "цикл for с параметром-итератором."
  );
  string name1 = RandomStr(7) + "1.tst", name2 = RandomStr(7) + "2.tst";
  size_t kk;
  do
  {
  kk = RandomN(5, 8);
  MakeVS(RandomN(10, 34));
  }
  while (count_if(vs.begin(), vs.end(), [kk](string e){return e.length() <= kk;}) <= 2);
  DataN("K = ", kk, 1, 1, 1);
  DataS("name1 = ", name1.c_str(), xLeft, 1);
  DataS("name2 = ", name2.c_str(), xRight, 1);
//  MakeVS(RandomN(10, 34));
//  DataVC("", 3);
  DataFileVS(name1.c_str(), 2, 5);
  auto it = remove_if(vs.begin(), vs.end(), [kk](string e){return e.length() > kk;});
  vs.erase(it, vs.end());
  ResultFileVS(name2.c_str(), 1, 5);
}

void Stl9(int k)
{
  CreateTask();
  if (k == 0)
  TaskText(
  "Дан текстовый файл с именем {name}, содержащий строковые представления\n"
  "целых чисел. Вывести числа из исходного файла с нечетными порядковыми\n"
  "номерами (т.\\,е. первое число, третье число и т.\\,д.). Использовать\n"
  "итераторы istream\\_iterator, ptout\\_iterator и алгоритм remove\\_copy\\_if."
  );
  else
  TaskText(
  "Решить задачу \\4, используя вместо алгоритма remove\\_copy\\_if\n"
  "цикл for с параметром-итератором."
  );
  string name = RandomStr(8) + ".tst";
  DataS("name = ", name.c_str(), 0, 1);
  MakeVN(RandomN(10, 34), -99, 99);
//  DataVC("", 3);
  DataFileVN(name.c_str(), 2, 5);
  bool c = true;
  auto it = remove_if(vn.begin(), vn.end(), [&c](int e){return c = !c;});
  vn.erase(it, vn.end());
  ResultVN("", 3);
}

void Stl10(int k)
{
  CreateTask();
  if (k == 0)
  TaskText(
  "Дан набор вещественных чисел, содержащий не менее двух элементов.\n"
  "Вывести числа из исходного набора с четными порядковыми номерами\n"
  "(т.\\,е. второе число, четвертое число и т.\\,д.). Использовать итераторы\n"
  "ptin\\_iterator, ptout\\_iterator и алгоритм remove\\_copy\\_if."
  );
  else
  TaskText(
  "Решить задачу \\4, используя вместо алгоритма remove\\_copy\\_if\n"
  "цикл for с параметром-итератором."
  );
  MakeVR(RandomN(10, 33), -999, 999);
//  DataVC("", 3);
  DataVR("", 3);
  bool c = false;
  auto it = remove_if(vr.begin(), vr.end(), [&c](int e){return c = !c;});
  vr.erase(it, vr.end());
  ResultVR("", 3);
}

void Stl15()
{
  CreateTask();
  TaskText(
  "Дана строка {name} и набор целых чисел. Записать в текстовый файл\n"
  "с именем {name} все числа из исходного набора в том же порядке, заменяя\n"
  "каждое число 0 на число 10 и добавляя после каждого числа два пробела.\n"
  "Использовать итераторы ptin\\_iterator, ostream\\_iterator\n"
  "и алгоритм replace\\_copy."
  );
  string name = RandomStr(8) + ".tst";
  DataS("name = ", name.c_str(), 0, 2);
  MakeVN(RandomN(10, 17), 0, 9);
  DataVN("", 3);
//  DataFileVN(name.c_str(), 2, 5);
  replace(vn.begin(), vn.end(), 0, 10);
  ResultFileVN1(name.c_str(), 3, 3, "  ");
}

void Stl16()
{
  CreateTask();
  TaskText(
  "Дан набор символов. Вывести все символы из исходного набора в том же\n"
  "порядке, заменяя цифровые символы на символ подчеркивания. Использовать\n"
  "итераторы ptin\\_iterator, ptout\\_iterator и алгоритм replace\\_copy\\_if."
  );
  MakeVC(RandomN(10, 34), abcext);
  DataVC("", 3);
//  DataFileVN(name.c_str(), 2, 5);
  replace_if(vc.begin(), vc.end(), [](char e){return e >= '0' && e <= '9';}, '_');
  ResultVC("", 3);
}

void Stl17()
{
  CreateTask();
  TaskText(
  "Дана строка {name} и набор символов. Записать в текстовый файл с именем {name}\n"
  "удвоенные кодовые значения всех символов из исходного набора в том же порядке,\n"
  "добавляя после каждого числа один пробел. Использовать итераторы\n"
  "ptin\\_iterator, ostream\\_iterator и алгоритм transform."
  );
  string name = RandomStr(8) + ".tst";
  DataS("name = ", name.c_str(), 0, 2);
  MakeVC(RandomN(10, 17), ABCext);
  DataVC("", 3);
//  DataFileVN(name.c_str(), 2, 5);
  vn.clear();
  transform(vc.begin(), vc.end(), back_inserter(vn), [](char e){return 2*(int)e;});
  ResultFileVN1(name.c_str(), 3, 3, " ");
}

void Stl18()
{
  CreateTask();
  TaskText(
  "Дана строка {name} и целое число {K} (>\\,0). Записать в текстовый файл\n"
  "с именем {name} {K} символов \\<*\\>. Использовать итератор ostream\\_iterator\n"
  "и алгоритм fill\\_n."
  );
  string name = RandomStr(8) + ".tst";
  DataS("name = ", name.c_str(), xLeft, 3);
//  MakeVC(RandomN(10, 23), ABCext);
  int k = RandomN(10,50);
  DataN("K = ", k, xRight, 3, 2);
//  DataVC("", 3);
//  DataFileVN(name.c_str(), 2, 5);
  vc.clear();
  fill_n(back_inserter(vc), k, '*');
  ResultFileVC(name.c_str(), 3, 3, "");
}

void Stl19()
{
  CreateTask();
  TaskText(
  "Даны вещественные числа {A}, {D} и целое число {N}. Вывести {N} первых членов\n"
  "арифметической прогрессии с первым элементом {A} и разностью {D}.\n"
  "Использовать итератор ptout\\_iterator и алгоритм generate\\_n."
  );
//  string name = RandomStr(8) + ".tst";
//  MakeVC(RandomN(10, 23), ABCext);
  double a = RandomN(100,999)/100.0;
  double d = RandomN(100,500)/100.0;
  int k = RandomN(10,20);
  DataR("A = ", a, xLeft, 3, 4);
  DataR("D = ", d, 0, 3, 4);
  DataN("N = ", k, xRight, 3, 2);
//  DataVC("", 3);
//  DataFileVN(name.c_str(), 2, 5);
  vr.clear();
  generate_n(back_inserter(vr), k, [&a, d]()->double{ a += d; return a-d;});
  ResultVR("", 3);
}

void Stl20()
{
  CreateTask();
  TaskText(
  "Дана строка {name} и целое число {N} (1~\\l~{N}~\\l~26). Записать в текстовый\n"
  "файл с именем {name} {N} начальных прописных букв латинского алфавита.\n"
  "Использовать итератор ostream\\_iterator и алгоритм generate\\_n."
  );
  string name = RandomStr(8) + ".tst";
//  MakeVC(RandomN(10, 23), ABCext);
  int k = RandomN(1,26);
  DataS("name = ", name.c_str(), xLeft, 3);
  DataN("N = ", k, xRight, 3, 1);
//  DataVC("", 3);
//  DataFileVN(name.c_str(), 2, 5);
  vc.clear();
  int c = (int)'A';
  generate_n(back_inserter(vc), k, [&c]()->char{ return (char)(c++);});
  ResultFileVC(name.c_str(), 3, 3, "");
}

void Stl21()
{
  CreateTask();
  TaskText(
  "Даны два текстовых файла с именами {name1} и {name2}, содержащие строковые\n"
  "представления целых чисел, причем в каждом файле числа располагаются\n"
  "по убыванию. Вывести все числа из исходных файлов в виде единой\n"
  "последовательности, упорядоченной по убыванию. Использовать\n"
  "итераторы istream\\_iterator, ptout\\_iterator и алгоритм merge\n"
  "с параметром \\= функциональным объектом."
  );
  string name1 = RandomStr(7) + "1.tst", name2 = RandomStr(7) + "2.tst";
  DataS("name1 = ", name1.c_str(), xLeft, 1);
  DataS("name2 = ", name2.c_str(), xRight, 1);
  MakeVN(RandomN(10, 34), -99, 99);
  sort(vn.begin(), vn.end(), greater<int>());
  DataFileVN(name1.c_str(), 2, 3);
//  DataVC("", 3);
//  DataFileVN(name.c_str(), 2, 5);
  vector<int> v1(vn);
  MakeVN(RandomN(10, 34), -99, 99);
  sort(vn.begin(), vn.end(), greater<int>());
  DataFileVN(name2.c_str(), 4, 5);
  vector<int> v2(vn);
  vn.clear();
  merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(vn), greater<int>());
  ResultVN("", 2);
}

bool StrComp(string s1, string s2)
{
        return s1.size() < s2.size() ||
                s1.size() == s2.size() && s1 < s2;
}

void Stl22()
{
  CreateTask();
  TaskText(
  "Даны два текстовых файла с именами {name1} и {name2}, содержащие английские слова,\n"
  "причем в каждом файле слова располагаются по возрастанию длины, а слова равной\n"
  "длины \\= в лексикографическом порядке. Вывести все слова из исходных файлов\n"
  "в виде единой последовательности, упорядоченной таким же образом,\n"
  "как и исходные файлы. Использовать итераторы istream\\_iterator, ptout\\_iterator\n"
  "и алгоритм merge с параметром \\= функциональным объектом."
  );
  string name1 = RandomStr(7) + "1.tst", name2 = RandomStr(7) + "2.tst";
  DataS("name1 = ", name1.c_str(), xLeft, 1);
  DataS("name2 = ", name2.c_str(), xRight, 1);
  MakeVS(RandomN(4, 10));
  sort(vs.begin(), vs.end(), StrComp);
  DataFileVS(name1.c_str(), 2, 3);
  vector<string> v1(vs);
  MakeVS(RandomN(4, 10));
  sort(vs.begin(), vs.end(), StrComp);
  DataFileVS(name2.c_str(), 4, 5);
  vector<string> v2(vs);
  vs.clear();
  merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(vs), StrComp);
  ResultVS("", 1);
}

void Stl23()
{
  CreateTask();
  TaskText(  
  "Даны два текстовых файла с именами {name1} и {name2}, содержащие одинаковое\n"
  "количество строковых представлений вещественных чисел. Вывести разности\n"
  "{B}_1~\\-~{A}_1, {B}_2~\\-~{A}_2, \\., {B}_N~\\-~{A}_N, где {N} \\= количество чисел\n"
  "в каждом файле, {A}_1, {A}_2, \\., {A}_N \\= числа из файла {name1},\n"
  "а {B}_1, {B}_2, \\., {B}_N \\= числа из файла {name2}. Использовать итераторы\n"
  "istream\\_iterator, ptout\\_iterator и алгоритм transform."
  );
  string name1 = RandomStr(7) + "1.tst", name2 = RandomStr(7) + "2.tst";
  DataS("name1 = ", name1.c_str(), xLeft, 1);
  DataS("name2 = ", name2.c_str(), xRight, 1);
  int k = RandomN(10, 22);
  MakeVR(k, -500, 500);
  DataFileVR(name1.c_str(), 2, 3);
  vector<double> v1(vr);
  MakeVR(k, -500, 500);
  DataFileVR(name2.c_str(), 4, 5);
  vector<double> v2(vr);
  vr.clear();
  transform(v1.begin(), v1.end(), v2.begin(), back_inserter(vr), 
          [](double e1, double e2){return e2-e1;});
  ResultVR("", 3);
}

void Stl24()
{
  CreateTask();
  TaskText(
  "Дан текстовый файл с именем {name1}, содержащий английские слова,\n"
  "строка {name2} и набор английских слов, размер которого не превосходит\n"
  "количество слов, содержащихся в файле {name1}. Записать в текстовый файл\n"
  "с именем {name2} все слова из исходного набора, дополнив каждое слово\n"
  "символом \\<-\\> (дефис) и словом из файла {name1} с тем же порядковым номером\n"
  "(если файл {name1} содержит больше слов, чем исходный набор, то лишние слова\n"
  "в файле игнорируются). Каждое дополненное слово записывать в файл\n"
  "с новой строки. Использовать итераторы ptin\\_iterator, istream\\_iterator,\n"
  "\\Mostream\\_iterator\\m и алгоритм transform."
  );
  string name1 = RandomStr(7) + "1.tst", name2 = RandomStr(7) + "2.tst";
  DataS("name1 = ", name1.c_str(), xLeft, 1);
  DataS("name2 = ", name2.c_str(), xRight, 1);
  int k = RandomN(10, 12);
  MakeVS(k + RandomN(0, 6));
  DataFileVS(name1.c_str(), 2, 2);
  vector<string> v1(vs);
  MakeVS(k);
  DataVS("", 3);
  vector<string> v2(vs);
  vs.clear();
  transform(v2.begin(), v2.end(), v1.begin(), back_inserter(vs), 
          [](string e1, string e2){return e1+"-"+e2;});
  ResultFileVS(name2.c_str(), 1, 5);
}

void __stdcall InitTask(int num)
{
  switch (num)  
  {
    case 1:      Stl1(); break;
    case 2:      Stl2(); break;
    case 3:      Stl3(); break;
    case 4:      Stl4(); break;
    case 5:      Stl5(); break;
    case 6:      Stl6(); break;
    case 7:      Stl7(0); break;
    case 8:      Stl8(0); break;
    case 9:      Stl9(0); break;
    case 10:      Stl10(0); break;
    case 11:      Stl7(1); break;
    case 12:      Stl8(1); break;
    case 13:      Stl9(1); break;
    case 14:      Stl10(1); break;
    case 15:      Stl15(); break;
    case 16:      Stl16(); break;
    case 17:      Stl17(); break;
    case 18:      Stl18(); break;
    case 19:      Stl19(); break;
    case 20:      Stl20(); break;
    case 21:      Stl21(); break;
    case 22:      Stl22(); break;
    case 23:      Stl23(); break;
    case 24:      Stl24(); break;
  }
}

void __stdcall inittaskgroup()
{
  if ((CurrentLanguage() & lgCPP) == 0) return;
  CreateGroup("STL1Iter", "Знакомство с итераторами и алгоритмами", 
    "М. Э. Абрамян, 2015, 2021" , "qwq233#EnTopic<Introduction to iterators and algorithms>#4sd255335hfgd5ttd", 24, InitTask); 

  CommentText("Для всех исходных наборов данных вначале указывается их размер (т.\\,е. количество элементов),");
  CommentText("а затем значения элементов.");
}
 