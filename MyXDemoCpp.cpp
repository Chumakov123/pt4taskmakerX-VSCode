#include "pt4taskmakerX.h"

using namespace pt4taskmakerX;

DefineGroupName;

void __stdcall inittaskgroup() {
	pt::NewGroup("������ ��� ������������", "�. �. �������", 1);
}

DefineTask(Task1) {
	pt::UseTask("Begin",1);
}

DefineTask(Task2) {
	pt::NewTask("�������� ����� �����",
		"����� �������� ��������� ~{a} +~{b}");
	int a = pt::Random(1, 99);
	int b = pt::Random(1, 99);
	pt::SetWidth(5);
	pt::Data("a = ", a);
	pt::Data("b = ", b);
	pt::Res("S = ", a + b);
	pt::SetTestCount(5);
}

DefineTask(Task3) {
	pt::NewTask("��������� � �������� ����� �����",
		"����� �������� ���������~{a} -~{b} �~{a} +~{b}");
	int a = pt::Random(1, 99);
	int b = pt::Random(1, 99);
	auto w = pt::RandomText();
	pt::SetPrecision(0);
	vector<double> v;
	for (int i = 0; i < 30; ++i) {
		v.push_back(pt::Random(1.0, 20.0));
	}
	const char* s = "������";
	pt::Data("",w);
	pt::Data("a = ", a, "b = ", b, "s = ", s);
	pt::Data(v);
	pt::Res("D = ", a - b, "S = ", a + b);
	pt::SetTestCount(5);
}