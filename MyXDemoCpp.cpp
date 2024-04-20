#include "pt4taskmakerX.h"

using namespace pt4taskmakerX;

DefineGroupName;

void __stdcall inittaskgroup() {
	pt::NewGroup("������ ��� ������������", "�. �. �������", 1);
}

DefineTask(Task1) {
	pt::UseTask("Begin","1");
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
	pt::NewTask("��������� ����� �����",
		"����� �������� ��������� ~{a} -~{b}");
	int a = pt::Random(1, 99);
	int b = pt::Random(1, 99);
	pt::SetWidth(5);
	pt::Data("a = ", a);
	pt::Data("b = ", b);
	pt::Res("S = ", a - b);
	pt::SetTestCount(5);
}