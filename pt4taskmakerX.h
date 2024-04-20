#ifndef _PT4TASKMAKERX
#define _PT4TASKMAKERX

#include <vector>
#include <string>

#include "pt4taskmaker.h"

// макрос для добавления задания в список всех заданий группы
#define DefineTask(name) \
    void name(); \
    struct name ## _Registrar { \
        name ## _Registrar() { RegisterTaskFunction(name); } \
    } name ## _registrar_instance; \
    void name()

// макрос для получения названия группы заданий
#define DefineGroupName \
    struct _GroupName { \
        _GroupName() { GetGroupName(__FILE__); } \
    } _groupname_instance;

namespace pt4taskmakerX
{
	const int OptionAllLanguages = 1;       // группа доступна для всех языков
	const int OptionPascalLanguages = 2;    // группа доступна для всех реализаций Паскаля
	const int OptionNETLanguages = 4;       // группа доступна для всех NET-языков
	const int OptionUseAddition = 8;        // группа доступна только при наличии файла дополнений
	const int OptionHideExamples = 16;      // не отображать раздел с примером верного решения

	void RegisterTaskFunction(void (*task)());
	void GetGroupName(const char* FilePath);

	void NewTask(const char* topic, const char* tasktext);
	void NewTask(const char* tasktext);

	void DataComm(const char* comm);
	void Data(const char* comm, int a); //TODO здесь тип должен быть произвольным, а не только int
	//void Data(const char* comm1, int a1, const char* comm2);
	//void Data(const char* comm1, int a1, const char* comm2, int a2);
	//void Data(const char* comm1, int a1, const char* comm2, int a2, const char* comm3);
	//void Data(const char* comm1, int a1, const char* comm2, int a2, const char* comm3, int a3);
	//void Data(const std::vector<bool>& seq);
	//void Data(const std::vector<int>& seq);
	//void Data(const std::vector<double>& seq);
	//void Data(const std::vector<char>& seq);
	//void Data(const std::vector<const char*>& seq);

	void ResComm(const char* comm);
	void Res(const char* comm, int a); //TODO здесь тип должен быть произвольным, а не только int
	//void Res(const char* comm1, int a1, const char* comm2);
	//void Res(const char* comm1, int a1, const char* comm2, int a2);
	//void Res(const char* comm1, int a1, const char* comm2, int a2, const char* comm3);
	//void Res(const char* comm1, int a1, const char* comm2, int a2, const char* comm3, int a3);
	//void Res(const std::vector<bool>& seq);
	//void Res(const std::vector<int>& seq);
	//void Res(const std::vector<double>& seq);
	//void Res(const std::vector<char>& seq);
	//void Res(const std::vector<const char*>& seq);

	void SetWidth(int n);
	//void SetPrecision(int n);
	void SetTestCount(int n);
	void SetRequiredDataCount(int n);

	int CurrentTest();
	int Random(int M, int N);
	//double Random(double A, double B);
	//double Random1(double A, double B);
	//double Random2(double A, double B);
	//const char* RandomName(int len);

	void NewGroup(const char* GroupDescription, const char* GroupAuthor, int Options = 0);
	void ActivateNET(const char* S);
	void UseTask(const char* GroupName, const char* TaskNumber);
	void UseTask(const char* GroupName, const char* TaskNumber, const char* TopicDescription);

	//vector<const char*>& GetWords();
	//vector<const char*>& GetEnWords();
	//vector<const char*>& GetSentences();
	//vector<const char*>& GetEnSentences();
	//vector<const char*>& GetTexts();
	//vector<const char*>& GetEnTexts();

	//const char* RandomWord();
	//const char* RandomEnWord();
	//const char* RandomSentence();
	//const char* RandomEnSentence();
	//const char* RandomText();
	//const char* RandomEnText();

	//void DataFileInteger(const char* FileName);
	//void DataFileReal(const char* FileName);
	//void DataFileChar(const char* FileName);
	//void DataFileString(const char* FileName);
	//void DataText(const char* FileName);

	//void ResFileInteger(const char* FileName);
	//void ResFileReal(const char* FileName);
	//void ResFileChar(const char* FileName);
	//void ResFileString(const char* FileName);
	//void ResText(const char* FileName);

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
		static void Data(const char* comm, int a) {
			pt4taskmakerX::Data(comm, a);
		}
		//static void Data(const char* comm1, int a1, const char* comm2);
		//static void Data(const char* comm1, int a1, const char* comm2, int a2);
		//static void Data(const char* comm1, int a1, const char* comm2, int a2, const char* comm3);
		//static void Data(const char* comm1, int a1, const char* comm2, int a2, const char* comm3, int a3);
		//static void Data(const std::vector<bool>& seq);
		//static void Data(const std::vector<int>& seq);
		//static void Data(const std::vector<double>& seq);
		//static void Data(const std::vector<char>& seq);
		//static void Data(const std::vector<const char*>& seq);

		static void ResComm(const char* comm) {
			pt4taskmakerX::ResComm(comm);
		}
		static void Res(const char* comm, int a) {
			pt4taskmakerX::Res(comm, a);
		}
		//static void Res(const char* comm1, int a1, const char* comm2);
		//static void Res(const char* comm1, int a1, const char* comm2, int a2);
		//static void Res(const char* comm1, int a1, const char* comm2, int a2, const char* comm3);
		//static void Res(const char* comm1, int a1, const char* comm2, int a2, const char* comm3, int a3);
		//static void Res(const std::vector<bool>& seq);
		//static void Res(const std::vector<int>& seq);
		//static void Res(const std::vector<double>& seq);
		//static void Res(const std::vector<char>& seq);
		//static void Res(const std::vector<const char*>& seq);

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
		//static double Random(double A, double B);
		//static double Random1(double A, double B);
		//static double Random2(double A, double B);
		//static const char* RandomName(int len);

		static void NewGroup(const char* GroupDescription, const char* GroupAuthor, int Options = 0) {
			pt4taskmakerX::NewGroup(GroupDescription, GroupAuthor, Options);
		}
		static void ActivateNET(const char* S) {
			pt4taskmakerX::ActivateNET(S);
		}
		static void UseTask(const char* GroupName, const char* TaskNumber) {
			pt4taskmakerX::UseTask(GroupName, TaskNumber);
		}
		static void UseTask(const char* GroupName, const char* TaskNumber, const char* TopicDescription) {
			pt4taskmakerX::UseTask(GroupName, TaskNumber, TopicDescription);
		}

		//static vector<const char*>& GetWords();
		//static vector<const char*>& GetEnWords();
		//static vector<const char*>& GetSentences();
		//static vector<const char*>& GetEnSentences();
		//static vector<const char*>& GetTexts();
		//static vector<const char*>& GetEnTexts();

		//static const char* RandomWord();
		//static const char* RandomEnWord();
		//static const char* RandomSentence();
		//static const char* RandomEnSentence();
		//static const char* RandomText();
		//static const char* RandomEnText();

		//static void DataFileInteger(const char* FileName);
		//static void DataFileReal(const char* FileName);
		//static void DataFileChar(const char* FileName);
		//static void DataFileString(const char* FileName);
		//static void DataText(const char* FileName);

		//static void ResFileInteger(const char* FileName);
		//static void ResFileReal(const char* FileName);
		//static void ResFileChar(const char* FileName);
		//static void ResFileString(const char* FileName);
		//static void ResText(const char* FileName);
	};
}

#endif // _PT4TASKMAKERX
