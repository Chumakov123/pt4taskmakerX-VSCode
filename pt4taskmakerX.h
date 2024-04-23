#ifndef _PT4TASKMAKERX
#define _PT4TASKMAKERX

#include <vector>
#include <string>

#include "pt4taskmaker.h"

// макрос дл€ добавлени€ задани€ в список всех заданий группы
#define DefineTask(name) \
    void name(); \
    struct name ## _Registrar { \
        name ## _Registrar() { RegisterTaskFunction(name); } \
    } name ## _registrar_instance; \
    void name()

// макрос дл€ получени€ названи€ группы заданий
#define DefineGroupName \
    struct _GroupName { \
        _GroupName() { GetGroupName(__FILE__); } \
    } _groupname_instance;

#define alphabet "0123456789abcdefghijklmnopqrstuvwxyz"
#define ErrMes1 "Error: –аздел размером более 5 строк не может содержать файловые данные."
#define ErrMes2 "Error: ѕри наличии файловых данных раздел не может содержать более 5 строк."
#define ErrMes3 "Error:  оличество исходных данных превысило 200."
#define ErrMes4 "Error:  оличество результирующих данных превысило 200."
#define ErrMes5 "Error: ѕри определении задани€ первой должна вызыватьс€ процедура NewTask."
#define ErrMes6 "Error: ѕри определении задани€ не указаны исходные данные."
#define ErrMes7 "Error: ѕри определении задани€ не указаны результирующие данные."

//TODO скрывать от составител€ заданий
extern int yd, yr, ye, nd, nr, pr, wd;
extern bool nt, ut, fd, fr;

bool CheckTT();
template<typename T>
void DataInternal(const char* s, T a, int x, int y, int w);
template<typename T>
void ResInternal(const char* s, T a, int x, int y, int w);
void ErrorInfo(const string& s);
int winteger(int w, int x);
int wreal(int w, double x);
//***********************

namespace pt4taskmakerX
{
	const int OptionAllLanguages = 1;       // группа доступна дл€ всех €зыков
	const int OptionPascalLanguages = 2;    // группа доступна дл€ всех реализаций ѕаскал€
	const int OptionNETLanguages = 4;       // группа доступна дл€ всех NET-€зыков
	const int OptionUseAddition = 8;        // группа доступна только при наличии файла дополнений
	const int OptionHideExamples = 16;      // не отображать раздел с примером верного решени€

	void RegisterTaskFunction(void (*task)());
	void GetGroupName(const char* FilePath);

	void NewTask(const char* topic, const char* tasktext);
	void NewTask(const char* tasktext);

//TODO скрывать от составител€ заданий
	void Data(const char* s, bool a, int x, int y, int w);
    void Data(const char* s, int a, int x, int y, int w);
    void Data(const char* s, double a, int x, int y, int w);
    void Data(const char* s, char a, int x, int y, int w);
    void Data(const char* s, const char* a, int x, int y, int w);
//***********************

	void DataComm(const char* comm);
	template<typename T>
	void Data(const char* comm, T a);
	template<typename T>
	void Data(const char* comm1, T a1, const char* comm2);
	template<typename T1, typename T2>
	void Data(const char* comm1, T1 a1, const char* comm2, T2 a2);
	template<typename T1, typename T2>
	void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3);
	template<typename T1, typename T2, typename T3>
	void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3);

	void Data(const std::vector<bool>& seq);
	void Data(const std::vector<int>& seq);
	void Data(const std::vector<double>& seq);
	void Data(const std::vector<char>& seq);
	void Data(const std::vector<const char*>& seq);

	void ResComm(const char* comm);
//TODO скрывать от составител€ заданий
	void Res(const char* s, bool a, int x, int y, int w);
    void Res(const char* s, int a, int x, int y, int w);
    void Res(const char* s, double a, int x, int y, int w);
    void Res(const char* s, char a, int x, int y, int w);
    void Res(const char* s, const char* a, int x, int y, int w);
//***********************

	void ResComm(const char* comm);
	template<typename T>
	void Res(const char* comm, T a);
	template<typename T>
	void Res(const char* comm1, T a1, const char* comm2);
	template<typename T1, typename T2>
	void Res(const char* comm1, T1 a1, const char* comm2, T2 a2);
	template<typename T1, typename T2>
	void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3);
	template<typename T1, typename T2, typename T3>
	void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3);

	void Res(const std::vector<bool>& seq);
	void Res(const std::vector<int>& seq);
	void Res(const std::vector<double>& seq);
	void Res(const std::vector<char>& seq);
	void Res(const std::vector<const char*>& seq);

	void SetWidth(int n);
	//void SetPrecision(int n);
	void SetTestCount(int n);
	void SetRequiredDataCount(int n);

	int CurrentTest();
	int Random(int M, int N);
	double Random(); //¬озращает случайное значение в диапазоне от 0 (включительно) до 1 (не включительно)
	double Random(double A, double B);
	double Random1(double A, double B);
	double Random2(double A, double B);
	const char* RandomName(int len);

	void NewGroup(const char* GroupDescription, const char* GroupAuthor, int Options = 0);
	void UseTask(const char* GroupName, int TaskNumber);
	void UseTask(const char* GroupName, int TaskNumber, const char* TopicDescription);

	vector<const char*> GetWords();
	vector<const char*> GetEnWords();
	vector<const char*> GetSentences();
	vector<const char*> GetEnSentences();
	vector<const char*> GetTexts();
	vector<const char*> GetEnTexts();

	const char* RandomWord();
	const char* RandomEnWord();
	const char* RandomSentence();
	const char* RandomEnSentence();
	const char* RandomText();
	const char* RandomEnText();

	void DataFileInteger(const char* FileName);
	void DataFileReal(const char* FileName);
	void DataFileChar(const char* FileName);
	void DataFileString(const char* FileName);
	void DataText(const char* FileName, int LineCount);

	void ResFileInteger(const char* FileName);
	void ResFileReal(const char* FileName);
	void ResFileChar(const char* FileName);
	void ResFileString(const char* FileName);
	void ResText(const char* FileName, int LineCount);

	class pt {
	public:
		static int OptionAllLanguages() {
			return pt4taskmakerX::OptionAllLanguages;
		}
		static int OptionPascalLanguages() {
			return pt4taskmakerX::OptionPascalLanguages;
		}
		static int OptionUseAddition() {
			return pt4taskmakerX::OptionUseAddition;
		}
		static int OptionNETLanguages() {
			return pt4taskmakerX::OptionNETLanguages;
		}
		static int OptionHideExamples() {
			return pt4taskmakerX::OptionHideExamples;
		}

		static void NewTask(const char* topic, const char* tasktext) {
			pt4taskmakerX::NewTask(topic, tasktext);
		}
		static void NewTask(const char* tasktext) {
			pt4taskmakerX::NewTask(tasktext);
		}

		static void DataComm(const char* comm) {
			pt4taskmakerX::DataComm(comm);
		}
		template<typename T>
		static void Data(const char* comm, T a) {
			pt4taskmakerX::Data(comm, a);
		}
		template<typename T>
		static void Data(const char* comm1, T a1, const char* comm2) {
			pt4taskmakerX::Data(comm1, a1, comm2);
		}
		template<typename T1, typename T2>
		static void Data(const char* comm1, T1 a1, const char* comm2, T2 a2) {
			pt4taskmakerX::Data(comm1, a1, comm2, a2);
		}
		template<typename T1, typename T2>
		static void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3) {
			pt4taskmakerX::Data(comm1, a1, comm2, a2, comm3);
		}
		template<typename T1, typename T2, typename T3>
		static void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3) {
			pt4taskmakerX::Data(comm1, a1, comm2, a2, comm3, a3);
		}
		static void Data(const std::vector<bool>& seq) {
			pt4taskmakerX::Data(seq);
		}
		static void Data(const std::vector<int>& seq) {
			pt4taskmakerX::Data(seq);
		}
		static void Data(const std::vector<double>& seq) {
			pt4taskmakerX::Data(seq);
		}
		static void Data(const std::vector<char>& seq) {
			pt4taskmakerX::Data(seq);
		}
		static void Data(const std::vector<const char*>& seq) {
			pt4taskmakerX::Data(seq);
		}

		static void ResComm(const char* comm) {
			pt4taskmakerX::ResComm(comm);
		}
		template<typename T>
		static void Res(const char* comm, T a) {
			pt4taskmakerX::Res(comm, a);
		}
		template<typename T>
		static void Res(const char* comm1, T a1, const char* comm2) {
			pt4taskmakerX::Res(comm1, a1, comm2);
		}
		template<typename T1, typename T2>
		static void Res(const char* comm1, T1 a1, const char* comm2, T2 a2) {
			pt4taskmakerX::Res(comm1, a1, comm2, a2);
		}
		template<typename T1, typename T2>
		static void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3) {
			pt4taskmakerX::Res(comm1, a1, comm2, a2, comm3);
		}
		template<typename T1, typename T2, typename T3>
		static void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3) {
			pt4taskmakerX::Res(comm1, a1, comm2, a2, comm3, a3);
		}

		static void Res(const std::vector<bool>& seq) {
			pt4taskmakerX::Res(seq);
		}
		static void Res(const std::vector<int>& seq) {
			pt4taskmakerX::Res(seq);
		}
		static void Res(const std::vector<double>& seq) {
			pt4taskmakerX::Res(seq);
		}
		static void Res(const std::vector<char>& seq) {
			pt4taskmakerX::Res(seq);
		}
		static void Res(const std::vector<const char*>& seq) {
			pt4taskmakerX::Res(seq);
		}

		static void SetWidth(int n) {
			pt4taskmakerX::SetWidth(n);
		}
		//static void SetPrecision(int n);
		static void SetTestCount(int n) {
			pt4taskmakerX::SetTestCount(n);
		}
		static void SetRequiredDataCount(int n) {
			pt4taskmakerX::SetRequiredDataCount(n);
		}

		static int CurrentTest() {
			return pt4taskmakerX::CurrentTest();
		}
		static int Random(int M, int N) {
			return pt4taskmakerX::Random(M, N);
		}
		static double Random() {
			return pt4taskmakerX::Random();
		}
		static double Random(double A, double B) {
			return pt4taskmakerX::Random(A, B);
		}
		static double Random1(double A, double B) {
			return pt4taskmakerX::Random1(A, B);
		}
		static double Random2(double A, double B) {
			return pt4taskmakerX::Random2(A, B);
		}
		static const char* RandomName(int len) {
			return pt4taskmakerX::RandomName(len);
		}

		static void NewGroup(const char* GroupDescription, const char* GroupAuthor, int Options = 0) {
			pt4taskmakerX::NewGroup(GroupDescription, GroupAuthor, Options);
		}
		static void UseTask(const char* GroupName, int TaskNumber) {
			pt4taskmakerX::UseTask(GroupName, TaskNumber);
		}
		static void UseTask(const char* GroupName, int TaskNumber, const char* TopicDescription) {
			pt4taskmakerX::UseTask(GroupName, TaskNumber, TopicDescription);
		}

		static vector<const char*> GetWords() {
			return pt4taskmakerX::GetWords();
		}
		static vector<const char*> GetEnWords() {
			return pt4taskmakerX::GetEnWords();
		}
		static vector<const char*> GetSentences() {
			return pt4taskmakerX::GetSentences();
		}
		static vector<const char*> GetEnSentences() {
			return pt4taskmakerX::GetEnSentences();
		}
		static vector<const char*> GetTexts() {
			return pt4taskmakerX::GetTexts();
		}
		static vector<const char*> GetEnTexts() {
			return pt4taskmakerX::GetEnTexts();
		}

		static const char* RandomWord() {
			return pt4taskmakerX::RandomWord();
		}
		static const char* RandomEnWord() {
			return pt4taskmakerX::RandomEnWord();
		}
		static const char* RandomSentence() {
			return pt4taskmakerX::RandomSentence();
		}
		static const char* RandomEnSentence() {
			return pt4taskmakerX::RandomEnSentence();
		}
		static const char* RandomText() {
			return pt4taskmakerX::RandomText();
		}
		static const char* RandomEnText() {
			return pt4taskmakerX::RandomEnText();
		}

		static void DataFileInteger(const char* FileName) {
			pt4taskmakerX::DataFileInteger(FileName);
		}
		static void DataFileReal(const char* FileName) {
			pt4taskmakerX::DataFileReal(FileName);
		}
		static void DataFileChar(const char* FileName) {
			pt4taskmakerX::DataFileChar(FileName);
		}
		static void DataFileString(const char* FileName) {
			pt4taskmakerX::DataFileString(FileName);
		}
		static void DataText(const char* FileName, int LineCount) {
			pt4taskmakerX::DataText(FileName, LineCount);
		}

		static void ResFileInteger(const char* FileName) {
			pt4taskmakerX::ResFileInteger(FileName);
		}
		static void ResFileReal(const char* FileName) {
			pt4taskmakerX::ResFileReal(FileName);
		}
		static void ResFileChar(const char* FileName) {
			pt4taskmakerX::ResFileChar(FileName);
		}
		static void ResFileString(const char* FileName) {
			pt4taskmakerX::ResFileString(FileName);
		}
		static void ResText(const char* FileName, int LineCount) {
			pt4taskmakerX::ResText(FileName, LineCount);
		}
	};
}
#include "pt4taskmakerX.tpp"
#endif // _PT4TASKMAKERX
