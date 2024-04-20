#include "pt4taskmakerX.h"

#define alphabet "0123456789abcdefghijklmnopqrstuvwxyz"
#define ErrMes1 "Error: ������ �������� ����� 5 ����� �� ����� ��������� �������� ������."
#define ErrMes2 "Error: ��� ������� �������� ������ ������ �� ����� ��������� ����� 5 �����."
#define ErrMes3 "Error: ���������� �������� ������ ��������� 200."
#define ErrMes4 "Error: ���������� �������������� ������ ��������� 200."
#define ErrMes5 "Error: ��� ����������� ������� ������ ������ ���������� ��������� NewTask."
#define ErrMes6 "Error: ��� ����������� ������� �� ������� �������� ������."
#define ErrMes7 "Error: ��� ����������� ������� �� ������� �������������� ������."

char GroupName[100];
int yd, yr, ye, nd, nr, pr, wd;
bool nt, ut, fd, fr;
string fmt;
void (*tasks[100])();
int TaskCount = 0;

void pt4taskmakerX::RegisterTaskFunction(void (*task)()) {
	tasks[TaskCount++] = task;
}

void Show(const string& s) {
	MessageBox(nullptr, s.c_str(), "Error", MB_OK | MB_ICONERROR);
}

string ErrorMessage(const string& s) {
	return (s + string(100, ' ')).substr(0, 78);
}

void ErrorInfo(const string& s) {
	TaskText(("\B" + ErrorMessage(s) + "\b").c_str(), 0, ye);
	ye = ye + 1;
	if (ye > 5) {
		ye = 0;
	}
}

bool CheckTT() {
	if (!nt) {
		pt4taskmakerX::NewTask("");
		ErrorInfo(ErrMes5);
	}
	return ut;
}

int wreal(int w, double x) {
	//TODO ������ ������������� �����
	return 0;
}

int winteger(int w, int x) {
	int result = w;
	if (w == 0) {
		string x_str = to_string(x);
		result = x_str.length();
	}
	return result;
}


void pt4taskmakerX::NewTask(const char* topic, const char* tasktext) {
	if (nt)
		exit(-1);
	CreateTask(topic);
	TaskText(tasktext);
	nt = true;  // ������� ��������� NewTask
	ut = false; // ���� ���������� ������������ ������� (���������� UseTask)
	ye = 1;     // ������� ����� ������ ��� ������ ��������� �� ������
	yd = 0;     // ������� ����� ������ � ������� �������� ������
	yr = 0;     // ������� ����� ������ � ������� �����������
	nd = 0;     // ���������� ��������� �������� ������
	nr = 0;     // ���������� ��������� �������������� ������
	fd = false; // ������� �������� ������ � ������� �������� ������
	fr = false; // ������� �������� ������ � ������� �����������
	pr = 2;     // ������� �������� ������ ������������ ������
	fmt = "f2"; // ������� ������ ������ ������������ ������ //�������� "%.2f"
	wd = 0;     // ������� ������ ���� ������ ��� �����
}
void pt4taskmakerX::NewTask(const char* tasktext) {
	pt4taskmakerX::NewTask("", tasktext);
}

void DataInternal(const char* s, int a, int x, int y, int w) { //TODO ������ �������������� ������ ���� ������
	if ((y > 0) && fd) {
		ErrorInfo(ErrMes2);
		return;
	}
	++nd;
	if (nd > 200) {
		ErrorInfo(ErrMes3);
		return;
	}
	DataN(s, a, x, y, winteger(w, a));
}

void ResInternal(const char* s, int a, int x, int y, int w) { //TODO ������ �������������� ������ ���� ������
	if ((y > 0) && fr) {
		ErrorInfo(ErrMes2);
		return;
	}
	++nr;
	if (nr > 200) {
		ErrorInfo(ErrMes4);
		return;
	}
	ResultN(s, a, x, y, winteger(w, a));
}

void pt4taskmakerX::DataComm(const char* comm) {
	if (CheckTT()) return;
	++yd;
	DataComment(comm, 0, yd);
}
void pt4taskmakerX::Data(const char* comm, int a) {
	if (CheckTT()) return;
	++yd;
	DataInternal(comm, a, 0, yd, wd);
}
//void pt4taskmakerX::Data(const char* comm1, int a1, const char* comm2);
//void pt4taskmakerX::Data(const char* comm1, int a1, const char* comm2, int a2);
//void pt4taskmakerX::Data(const char* comm1, int a1, const char* comm2, int a2, const char* comm3);
//void pt4taskmakerX::Data(const char* comm1, int a1, const char* comm2, int a2, const char* comm3, int a3);
//void pt4taskmakerX::Data(const std::vector<bool>& seq);
//void pt4taskmakerX::Data(const std::vector<int>& seq);
//void pt4taskmakerX::Data(const std::vector<double>& seq);
//void pt4taskmakerX::Data(const std::vector<char>& seq);
//void pt4taskmakerX::Data(const std::vector<const char*>& seq);

void pt4taskmakerX::ResComm(const char* comm)
{
	if (CheckTT()) return;
	++yr;
	ResultComment(comm, 0, yr);
}
void pt4taskmakerX::Res(const char* comm, int a)
{
	if (CheckTT()) return;
	++yr;
	ResInternal(comm, a, 0, yr, wd);
}
//void pt4taskmakerX::Res(const char* comm1, int a1, const char* comm2);
//void pt4taskmakerX::Res(const char* comm1, int a1, const char* comm2, int a2);
//void pt4taskmakerX::Res(const char* comm1, int a1, const char* comm2, int a2, const char* comm3);
//void pt4taskmakerX::Res(const char* comm1, int a1, const char* comm2, int a2, const char* comm3, int a3);
//void pt4taskmakerX::Res(const std::vector<bool>& seq);
//void pt4taskmakerX::Res(const std::vector<int>& seq);
//void pt4taskmakerX::Res(const std::vector<double>& seq);
//void pt4taskmakerX::Res(const std::vector<char>& seq);
//void pt4taskmakerX::Res(const std::vector<const char*>& seq);

void pt4taskmakerX::SetWidth(int n) {
	if ((n >= 0) && (n <= 20)) {
		wd = n;
	}
}
//void pt4taskmakerX::SetPrecision(int n);
void pt4taskmakerX::SetTestCount(int n) {
	if (CheckTT()) return;
	SetTestCount(n);
}
void pt4taskmakerX::SetRequiredDataCount(int n) {
	if (CheckTT()) return;
	SetRequiredDataCount(n);
}

int pt4taskmakerX::CurrentTest() {
	if (CheckTT()) return 0;
	return CurrentTest();
}
int pt4taskmakerX::Random(int M, int N) {
	return RandomN(M, N);
}
//double pt4taskmakerX::Random(double A, double B);
//double pt4taskmakerX::Random1(double A, double B);
//double pt4taskmakerX::Random2(double A, double B);
//const char* pt4taskmakerX::RandomName(int len);

void pt4taskmakerX::GetGroupName(const char* FilePath) {

	// �������� ���� � ����������
	string str(FilePath);
	size_t lastSlash = str.find_last_of("/\\");
	size_t lastDot = str.find_last_of('.');
	string result;

	if (lastDot != std::string::npos && (lastSlash == std::string::npos || lastDot > lastSlash)) {
		result = str.substr(lastSlash + 1, lastDot - lastSlash - 1);
	}
	else {
		result = str.substr(lastSlash + 1);
	}

	// �������� �������� PT4
	//result.erase(0, 3);

	// �������� ��������, ������������� ���� ����������
	size_t underscorePos = result.find('_');
	if (underscorePos != std::string::npos) {
		result.erase(underscorePos);
	}
	strcpy(GroupName, result.c_str());
}

bool AcceptedLanguage(int opt) {
	return true; //TODO �������� ����� ����������������
}

void __stdcall RunTask(int num) {
	//TODO �������� RunTask(int num)
	bool ut0;
	if ((num > 0) && (num <= TaskCount)) {
		tasks[num - 1]();
	}
	
	nt = false;
	ut0 = ut;
	ut = false;

	if (ut0) exit(-1);
}

void pt4taskmakerX::NewGroup(const char* GroupDescription, const char* GroupAuthor, int Options)
{
	if (!AcceptedLanguage(Options)) 
		exit(-1); // ������������ ������� ����
	string GroupKey = "GK123"; //TODO �������� �������� ����� ������
	//TODO �������� NewGroup
	CreateGroup(GroupName, GroupDescription, GroupAuthor,
		GroupKey.c_str(), TaskCount, RunTask);
}
void pt4taskmakerX::ActivateNET(const char* S)
{
	ActivateNET(S);
}

void pt4taskmakerX::UseTask(const char* GroupName, const char* TaskNumber) {
	if (ut) exit(-1);
	UseTask(GroupName, TaskNumber);
	ut = true;
}
void pt4taskmakerX::UseTask(const char* GroupName, const char* TaskNumber, const char* TopicDescription) {
	if (ut) exit(-1);
	UseTask(GroupName, TaskNumber, TopicDescription);
	ut = true;
}

//vector<const char*>& pt4taskmakerX::GetWords();
//vector<const char*>& pt4taskmakerX::GetEnWords();
//vector<const char*>& pt4taskmakerX::GetSentences();
//vector<const char*>& pt4taskmakerX::GetEnSentences();
//vector<const char*>& pt4taskmakerX::GetTexts();
//vector<const char*>& pt4taskmakerX::GetEnTexts();

//const char* pt4taskmakerX::RandomWord();
//const char* pt4taskmakerX::RandomEnWord();
//const char* pt4taskmakerX::RandomSentence();
//const char* pt4taskmakerX::RandomEnSentence();
//const char* pt4taskmakerX::RandomText();
//const char* pt4taskmakerX::RandomEnText();

//void pt4taskmakerX::DataFileInteger(const char* FileName);
//void pt4taskmakerX::DataFileReal(const char* FileName);
//void pt4taskmakerX::DataFileChar(const char* FileName);
//void pt4taskmakerX::DataFileString(const char* FileName);
//void pt4taskmakerX::DataText(const char* FileName);

//void pt4taskmakerX::ResFileInteger(const char* FileName);
//void pt4taskmakerX::ResFileReal(const char* FileName);
//void pt4taskmakerX::ResFileChar(const char* FileName);
//void pt4taskmakerX::ResFileString(const char* FileName);
//void pt4taskmakerX::ResText(const char* FileName);