#include <typeinfo>
#include "pt4taskmakerX.h"

#define alphabet "0123456789abcdefghijklmnopqrstuvwxyz"
#define ErrMes1 "Error: Раздел размером более 5 строк не может содержать файловые данные."
#define ErrMes2 "Error: При наличии файловых данных раздел не может содержать более 5 строк."
#define ErrMes3 "Error: Количество исходных данных превысило 200."
#define ErrMes4 "Error: Количество результирующих данных превысило 200."
#define ErrMes5 "Error: При определении задания первой должна вызываться процедура NewTask."
#define ErrMes6 "Error: При определении задания не указаны исходные данные."
#define ErrMes7 "Error: При определении задания не указаны результирующие данные."

char GroupName[100];
int yd, yr, ye, nd, nr, pr, wd;
bool nt, ut, fd, fr;
string fmt;
void (*tasks[1000])();
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
	pt4taskmaker::TaskText(("\B" + ErrorMessage(s) + "\b").c_str(), 0, ye);
	ye = ye + 1;
	if (ye > 5) {
		ye = 0;
	}
}

bool CheckTT() {
	bool result = ut;
	if (!nt) {
		pt4taskmakerX::NewTask("");
		ErrorInfo(ErrMes5);
	}
	return result;
}

int wreal(int w, double x) {
	//TODO Ширина вещественного числа
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
		return;
	pt4taskmaker::CreateTask(topic);
	pt4taskmaker::TaskText(tasktext);
	nt = true;  // вызвана процедура NewTask
	ut = false; // было подключено существующее задание (процедурой UseTask)
	ye = 1;     // текущий номер строки для вывода сообщения об ошибке
	yd = 0;     // текущий номер строки в разделе исходных данных
	yr = 0;     // текущий номер строки в разделе результатов
	nd = 0;     // количество элементов исходных данных
	nr = 0;     // количество элементов результирующих данных
	fd = false; // наличие файловых данных в разделе исходных данных
	fr = false; // наличие файловых данных в разделе результатов
	pr = 2;     // текущая точность вывода вещественных данных
	fmt = "f2"; // текущий формат вывода вещественных данных //Возможно "%.2f"
	wd = 0;     // текущая ширина поля вывода для чисел
}
void pt4taskmakerX::NewTask(const char* tasktext) {
	pt4taskmakerX::NewTask("", tasktext);
}

void DataInternal(const char* s, int a, int x, int y, int w) { //TODO Должны поддерживаться разные типы данных
	if ((y > 0) && fd) {
		ErrorInfo(ErrMes2);
		return;
	}
	++nd;
	if (nd > 200) {
		ErrorInfo(ErrMes3);
		return;
	}
	pt4taskmaker::DataN(s, a, x, y, winteger(w, a));
}

void ResInternal(const char* s, int a, int x, int y, int w) { //TODO Должны поддерживаться разные типы данных
	if ((y > 0) && fr) {
		ErrorInfo(ErrMes2);
		return;
	}
	++nr;
	if (nr > 200) {
		ErrorInfo(ErrMes4);
		return;
	}
	pt4taskmaker::ResultN(s, a, x, y, winteger(w, a));
}

void pt4taskmakerX::DataComm(const char* comm) {
	if (CheckTT()) return;
	++yd;
	pt4taskmaker::DataComment(comm, 0, yd);
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
	pt4taskmaker::ResultComment(comm, 0, yr);
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
	pt4taskmaker::SetTestCount(n);
}
void pt4taskmakerX::SetRequiredDataCount(int n) {
	if (CheckTT()) return;
	pt4taskmaker::SetRequiredDataCount(n);
}

int pt4taskmakerX::CurrentTest() {
	if (CheckTT()) return 0;
	return pt4taskmaker::CurrentTest();
}
int pt4taskmakerX::Random(int M, int N) {
	return pt4taskmaker::RandomN(M, N);
}
//double pt4taskmakerX::Random(double A, double B);
//double pt4taskmakerX::Random1(double A, double B);
//double pt4taskmakerX::Random2(double A, double B);
//const char* pt4taskmakerX::RandomName(int len);

void pt4taskmakerX::GetGroupName(const char* FilePath) {

	// удаление пути и расширения
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

    // приведение префикса к верхнему регистру
    string prefix = result.substr(0, 3);
    for (size_t i = 0; i < prefix.size(); ++i) {
        if (prefix[i] >= 'a' && prefix[i] <= 'z') {
            prefix[i] -= ('a' - 'A'); 
        }
    }
    if (prefix == "PT4") {
        // удаление префикса PT4
        result.erase(0, 3);
	}

	// удаление суффикса, определяющего язык интерфейса
	size_t underscorePos = result.find('_');
	if (underscorePos != std::string::npos) {
		result.erase(underscorePos);
	}
	strcpy(GroupName, result.c_str());
}

bool AcceptedLanguage(int opt) {
	auto lang = pt4taskmaker::CurrentLanguage();
    return (lang == lgPascalABCNET) ||
           ((opt & pt4taskmakerX::OptionAllLanguages) == pt4taskmakerX::OptionAllLanguages) ||
           ((lang & lgNET) != 0 && (opt & pt4taskmakerX::OptionNETLanguages) == pt4taskmakerX::OptionNETLanguages) ||
           ((lang & lgPascal) == lgPascal && (opt & pt4taskmakerX::OptionPascalLanguages) == pt4taskmakerX::OptionPascalLanguages);
}

void __stdcall RunTask(int num) {
	bool ut0;
	try {
		if ((num > 0) && (num <= TaskCount)) {
			tasks[num - 1]();
		}
	} catch (const std::exception& e) {
        Show(e.what());
    }
	nt = false;
	ut0 = ut;
	ut = false;

	if (ut0) return;
	if (nd == 0 && !fd) {
        Show(ErrMes6);
    }
    if (nr == 0 && !fr) {
        Show(ErrMes7);
    }
}

void pt4taskmakerX::NewGroup(const char* GroupDescription, const char* GroupAuthor, int Options)
{
	if (!AcceptedLanguage(Options)) 
		return; // недопустимый текущий язык
	if (TaskCount == 0) {
		string name = GroupName;
		Show("Группа" + name + " не содержит заданий.");
		return;
	}
	if (TaskCount > 999) {
		string name = GroupName;
		Show("Группа" + name + " содержит более 999 заданий.");
		return;
	}
	string GroupKey = "GK123"; //TODO доделать создание ключа группы
	if ((Options & OptionUseAddition) == OptionUseAddition)
		GroupKey += "#UseAddition#";
	if ((Options & OptionHideExamples) == OptionHideExamples)
		GroupKey += "#HideExamples#";
	pt4taskmaker::CreateGroup(GroupName, GroupDescription, GroupAuthor,
		GroupKey.c_str(), TaskCount, RunTask);
}

void pt4taskmakerX::UseTask(const char* GroupName, int TaskNumber) {
	if (ut) return;
	pt4taskmaker::UseTask(GroupName, TaskNumber);
	ut = true;
}
void pt4taskmakerX::UseTask(const char* GroupName, int TaskNumber, const char* TopicDescription) {
	if (ut) return;
	pt4taskmaker::UseTask(GroupName, TaskNumber, TopicDescription);
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