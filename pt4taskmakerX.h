#ifndef _PT4TASKMAKERX
#define _PT4TASKMAKERX

#include <vector>
#include <string>
#include "pt4taskmaker.h"

using ShortString = char[256];

/// ������ ��� ���������� ������� � ������ ���� ������� ������
#define DefineTask(name) \
    void name(); \
    struct name ## _Registrar { \
        name ## _Registrar() { RegisterTaskFunction(name, #name); } \
    } name ## _registrar_instance; \
    void name()

/// ������ ��� ��������� �������� ������ �������
#define DefineGroupName \
    struct _GroupName { \
        _GroupName() { GetGroupName(__FILE__); } \
    } _groupname_instance;

#define alphabet "0123456789abcdefghijklmnoprstuvwxyz"
#define ErrMes1 "Error: ������ �������� ����� 5 ����� �� ����� ��������� �������� ������."
#define ErrMes2 "Error: ��� ������� �������� ������ ������ �� ����� ��������� ����� 5 �����."
#define ErrMes3 "Error: ���������� �������� ������ ��������� 200."
#define ErrMes4 "Error: ���������� �������������� ������ ��������� 200."
#define ErrMes5 "Error: ��� ����������� ������� ������ ������ ���������� ��������� NewTask."
#define ErrMes6 "Error: ��� ����������� ������� �� ������� �������� ������."
#define ErrMes7 "Error: ��� ����������� ������� �� ������� �������������� ������."

//������� � ���������� ��� ����������� �������������

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

//*********************************************

namespace pt4taskmakerX
{
	const int OptionAllLanguages = 1;       // ������ �������� ��� ���� ������
	const int OptionPascalLanguages = 2;    // ������ �������� ��� ���� ���������� �������
	const int OptionNETLanguages = 4;       // ������ �������� ��� ���� NET-������
	const int OptionUseAddition = 8;        // ������ �������� ������ ��� ������� ����� ����������
	const int OptionHideExamples = 16;      // �� ���������� ������ � �������� ������� �������

	/// ���������� ������� (��� ��������� �� �������) � ������ �������. ��� ����������� �������������.
	void RegisterTaskFunction(void (*task)(), const char* taskname);

	/// ��������� �������� ������ ������� �� �������� �����. ��� ����������� �������������.
	void GetGroupName(const char* FilePath);

	/// ���������, � ������� ������ ���������� ����������� ������ �������.
	/// ������ ���������� � ���������, ��������� �������� DefineTask(procedurename).
	/// �������� topic ���������� ��� ��������� � �������� ��������������.
	/// �������� tasktext �������� ������������ �������; ��������� ������
	/// ������������ ������ ����������� �������� \\n
	void NewTask(const char* topic, const char* tasktext);

	/// ���������, � ������� ������ ���������� ����������� ������ �������.
	/// ������ ���������� � ���������, ��������� �������� DefineTask(procedurename).
	/// �������� tasktext �������� ������������ �������; ��������� ������
	/// ������������ ������ ����������� �������� \\n
	void NewTask(const char* tasktext);

	void Data(const char* s, bool a, int x, int y, int w);
    void Data(const char* s, int a, int x, int y, int w);
    void Data(const char* s, double a, int x, int y, int w);
    void Data(const char* s, char a, int x, int y, int w);
    void Data(const char* s, const char* a, int x, int y, int w);

	/// ��������� ����������� � ����� ������ ������� �������� �������.
	void DataComm(const char* comm);

	/// ��������� ������ � ����������� � ����� ������ ������� �������� �������.
	template<typename T>
	void Data(const char* comm, T a);

	/// ��������� ������ � ����������� � ����� ������ ������� �������� �������.
	template<typename T>
	void Data(const char* comm1, T a1, const char* comm2);

	/// ��������� ������ � ����������� � ����� ������ ������� �������� �������.
	template<typename T1, typename T2>
	void Data(const char* comm1, T1 a1, const char* comm2, T2 a2);

	/// ��������� ������ � ����������� � ����� ������ ������� �������� �������.
	template<typename T1, typename T2>
	void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3);

	/// ��������� ������ � ����������� � ����� ������ ������� �������� �������.
	template<typename T1, typename T2, typename T3>
	void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3);

	/// ��������� ������������������ ���������� ������ � ������ �������� ������.
	void Data(const std::vector<bool>& seq);

	/// ��������� ������������������ ����� ����� � ������ �������� ������.
	void Data(const std::vector<int>& seq);

	/// ��������� ������������������ ������������ ����� � ������ �������� ������.
	void Data(const std::vector<double>& seq);

	/// ��������� ������������������ �������� � ������ �������� ������.
	void Data(const std::vector<char>& seq);

	/// ��������� ������������������ ����� � ������ �������� ������.
	void Data(const std::vector<const char*>& seq);

	void Res(const char* s, bool a, int x, int y, int w);
    void Res(const char* s, int a, int x, int y, int w);
    void Res(const char* s, double a, int x, int y, int w);
    void Res(const char* s, char a, int x, int y, int w);
    void Res(const char* s, const char* a, int x, int y, int w);

	/// ��������� ����������� � ����� ������ ������� �����������.
	void ResComm(const char* comm);

	/// ��������� ������ � ����������� � ����� ������ ������� �����������.
	template<typename T>
	void Res(const char* comm, T a);

	/// ��������� ������ � ����������� � ����� ������ ������� �����������.
	template<typename T>
	void Res(const char* comm1, T a1, const char* comm2);

	/// ��������� ������ � ����������� � ����� ������ ������� �����������.
	template<typename T1, typename T2>
	void Res(const char* comm1, T1 a1, const char* comm2, T2 a2);

	/// ��������� ������ � ����������� � ����� ������ ������� �����������.
	template<typename T1, typename T2>
	void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3);

	/// ��������� ������ � ����������� � ����� ������ ������� �����������.
	template<typename T1, typename T2, typename T3>
	void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3);

	/// ��������� ������������������ ���������� ������ � ������ �����������.
	void Res(const std::vector<bool>& seq);

	/// ��������� ������������������ ����� ����� � ������ �����������.
	void Res(const std::vector<int>& seq);

	/// ��������� ������������������ ������������ ����� � ������ �����������.
	void Res(const std::vector<double>& seq);

	/// ��������� ������������������ �������� � ������ �����������.
	void Res(const std::vector<char>& seq);

	/// ��������� ������������������ ����� � ������ �����������.
	void Res(const std::vector<const char*>& seq);
	
	/// ������ ����������� ������ ���� ������ ��� �������� ������
	/// (����� ������������� �� ������� ���� ���� ������, 
	/// �.�. ��� ������������� ����������� ����� ���������).
	/// ���� n �� ����� � ��������� 0..10, �� ����� ��������� ������������.
	/// �� ��������� ����������� ������ ���� ������ ���������� ������ 0.
	void SetWidth(int n);

	/// ������ ������ ����������� ������������ �����: 
	/// � ������������� ������ � n �������� ������� ��� n > 0,
	/// � ��������� ������ � n �������� ������� ��� n < 0,
	/// � ��������� ������ � 6 �������� ������� ��� n = 0.
	/// ���� n �� ������ ����������� 10, �� ����� ��������� ������������.
	/// �� ��������� ��������������� ������ � ������������� ������
	/// � 2 �������� �������.
	void SetPrecision(int n);

	/// ������ ���������� �������� ��������, �����������
	/// ��� �������� ������������ ��������� (�� 2 �� 10). 
	/// �� ��������� ����� �������� �������� ���������� ������ 5.
	void SetTestCount(int n);

	/// ������ ���������� ����������� ���������� ��������� 
	/// �������� ������, ������� ��������� ������ ��� �����������
	/// ������� ������ � ������ �������� ������ �������� ������. 
	/// ��� ���������� ��������� ��������������,
	/// ��� ��� ����������� ������� ���� ������ ��� �������� ������.
	void SetRequiredDataCount(int n);

	/// ���������� ����� �������� ��������� ������� 
	/// (������� ���������� �� 1).
	int CurrentTest();

	/// ���������� ��������� ����� ����� � ��������� �� M �� N ������������.
	/// ���� M >= N, �� ���������� M.
	int Random(int M, int N);

	/// ��������� ��������� �������� � ��������� �� 0 (������������) �� 1 (�� ������������)
	double Random(); 

	/// ���������� ��������� ������������ ����� �� ���������� [A, B).
	/// ���� ���������� [A, B) ����, �� ���������� A.
	double Random(double A, double B);

	/// ���������� ��������� ������������ ����� �� ���������� [A, B)
	/// � ����� ������� ������ � ��������� �������� ������� 1e-7.
	/// ���� ���������� [A, B) ����, �� ���������� A, �����������
	/// �� ������ �������� ����� � ���������� �������� ������� 1e-7.
	double Random1(double A, double B);

	/// ���������� ��������� ������������ ����� �� ���������� [A, B)
	/// � ����� �������� ������� � ��������� �������� ������� 1e-7.
	/// ���� ���������� [A, B) ����, �� ���������� A, �����������
	/// �� ���� ������� ������ � ���������� �������� ������� 1e-7.
	double Random2(double A, double B);

	/// ���������� ��������� ������ ����� len, ���������
	/// �� ���� � �������� (�.�. ���������) ��������� ����.
	string RandomName(int len);

	/// ������� ����� ������ � ������� ��������� GroupDescription,
	/// ����������� �� ������ GroupAuthor � ������� �������������� �����, ������������ ��������� or.
	/// ��� ������ ������������ �� ����� ���������� (����� ������������ �������� PT4
	/// � ��������� ��������� _ru ��� _en). 
	/// � ������ ���������� �������, ������������ � ����������, ����� ������� ���������� � ������ Task.
	/// ��������� NewGroup ������ ���� ������� � ��������� inittaskgroup ��� ����������, �������
	/// ���������� ������� � ���������� � ������� ������� (��� ����� � ����� inittaskgroup - ��������).
	void NewGroup(const char* GroupDescription, const char* GroupAuthor, int Options = 0);
	
	/// ����������� � ����������� ������ ������������ �������
	/// �� ������ GroupName � ������� TaskNumber. ������ ����������
	/// � ��������� � ������, ������������ � ������ Task.
	void UseTask(const char* GroupName, int TaskNumber);

	/// ����������� � ����������� ������ ������������ �������
	/// �� ������ GroupName � ������� TaskNumber. ������ ����������
	/// � ��������� � ������, ������������ � ������ Task.
	void UseTask(const char* GroupName, int TaskNumber, const char* TopicDescription);

	/// ���������� ������ �� 116 ������� ����.
	vector<const char*> GetWords();
	/// ���������� ������ �� 116 ���������� ����.
	vector<const char*> GetEnWords();
	/// ���������� ������ �� 61 �������� �����������.
	vector<const char*> GetSentences();
	/// ���������� ������ �� 61 ����������� �����������.
	vector<const char*> GetEnSentences();
	/// ���������� ������ �� 85 ������� ������������� �������.
	/// ������ ������ ����������� �������� \\n.
	/// � ����� ������ ������ \\n �����������.
	vector<const char*> GetTexts();
	/// ���������� ������ �� 85 ���������� ������������� �������.
	/// ������ ������ ����������� �������� \\n.
	/// � ����� ������ ������ \\n �����������.
	vector<const char*> GetEnTexts();

	/// ���������� ��������� ������� ����� �� �������, 
	/// ��������� � ����������� ������� �������.
	const char* RandomWord();
	/// ���������� ��������� ���������� ����� �� �������, 
	/// ��������� � ����������� ������� �������.
	const char* RandomEnWord();
	/// ���������� ��������� ������� ����������� �� �������, 
	/// ��������� � ����������� ������� �������.
	const char* RandomSentence();
	/// ���������� ��������� ���������� ����������� �� �������, 
	/// ��������� � ����������� ������� �������.
	const char* RandomEnSentence();
	/// ���������� ��������� ������� ������������� ����� �� �������, 
	/// ��������� � ����������� ������� �������.
	/// ������ ������ ����������� �������� \\n.
	/// � ����� ������ ������ \\n �����������.
	const char* RandomText();
	/// ���������� ��������� ���������� ������������� ����� �� �������, 
	/// ��������� � ����������� ������� �������.
	/// ������ ������ ����������� �������� \\n.
	/// � ����� ������ ������ \\n �����������.
	const char* RandomEnText();

	/// ��������� � ������� �������� ���� ����� �����
	/// � ������ FileName � ���������� ��� ����������
	/// � ������� �������� ������.
	void DataFileInteger(const char* FileName);
	/// ��������� � ������� �������� ���� ������������ �����
	/// � ������ FileName � ���������� ��� ����������
	/// � ������� �������� ������.
	void DataFileReal(const char* FileName);
	/// ��������� � ������� �������� ���������� ����
	/// � ������ FileName � ���������� ��� ����������
	/// � ������� �������� ������. ������� ������
	/// ��������� � ����� � ����������� ���������.
	void DataFileChar(const char* FileName);
	/// ��������� � ������� �������� ��������� ����
	/// � ���������� ���� ShortString � ������ FileName 
	/// � ���������� ��� ���������� � ������� �������� ������.
	/// ����� ��������� ����� �� ������ ������������ 70 ��������.
	/// ������ ������ ��������� � ����� � ����������� ���������.
	void DataFileString(const char* FileName);
	/// ��������� � ������� �������� ��������� ����
	/// � ������ FileName � ���������� ��� ����������
	/// � ������� �������� ������. ����� ������ ������
	/// ���������� ����� �� ������ ������������ 70 ��������.
	/// ����� ������ ��������� � ����� � ����������� ���������.
	void DataText(const char* FileName, int LineCount = 5);

	/// ��������� � ������� �������������� ���� ����� �����
	/// � ������ FileName � ���������� ��� ���������� � ������� �����������.
	void ResFileInteger(const char* FileName);
	/// ��������� � ������� �������������� ���� ������������ �����
	/// � ������ FileName � ���������� ��� ���������� � ������� �����������.
	void ResFileReal(const char* FileName);
	/// ��������� � ������� �������������� ���������� ����
	/// � ������ FileName � ���������� ��� ���������� � ������� �����������.
	/// ������� ������ ��������� � ����� � ����������� ���������.
	void ResFileChar(const char* FileName);
	/// ��������� � ������� �������������� ��������� ����
	/// � ���������� ���� ShortString � ������ FileName 
	/// � ���������� ��� ���������� � ������� �����������.
	/// ����� ��������� ����� �� ������ ������������ 70 ��������.
	/// ������ ������ ��������� � ����� � ����������� ���������.
	void ResFileString(const char* FileName);
	/// ��������� � ������� �������������� ��������� ����
	/// � ������ FileName � ���������� ��� ���������� � ������� �����������. 
	/// ����� ������ ������ ���������� ����� �� ������ ������������ 70 ��������.
	/// ����� ������ ��������� � ����� � ����������� ���������.
	void ResText(const char* FileName, int LineCount = 5);

	/// ������������ ������� ������ � �������� (char[256])
	void ConvertToShortString(string s, ShortString buf);

	/// ���������, �������������� ����������� ������������ �������� ������
	/// � "��������� �����" ��� ���������� ������� � ����� PascalABC.NET
	/// (��� ������������� ������ ���� �� ��������� ������� ��������)
	void SetObjectStyle();

	/// ������������� ������� ������� ��� ����������� �������� ��� ������ 
	/// �������� ����� (��� ���������� ������� � ������������ ������)
	void SetProcess(int ProcessRank);

	class pt {
	public:
		/// �������������� ����� ��� ��������� NewGroup: 
		/// ������ �������� ��� ���� ������.  
		static int OptionAllLanguages() {
			return pt4taskmakerX::OptionAllLanguages;
		}
		/// �������������� ����� ��� ��������� NewGroup: 
		/// ������ �������� ��� ���� ���������� ����� Pascal
		static int OptionPascalLanguages() {
			return pt4taskmakerX::OptionPascalLanguages;
		}
		/// �������������� ����� ��� ��������� NewGroup: 
		/// ������ �������� ��� ���� NET-������.
		static int OptionUseAddition() {
			return pt4taskmakerX::OptionUseAddition;
		}
		/// �������������� ����� ��� ��������� NewGroup: 
		/// ������ �������� ������ ��� ������� ���������� � ��� ����� ����������.
		static int OptionNETLanguages() {
			return pt4taskmakerX::OptionNETLanguages;
		}
		/// �������������� ����� ��� ��������� NewGroup: 
		/// � �������� ������ ������ �� ����� ������������ ������ ������� �������.
		static int OptionHideExamples() {
			return pt4taskmakerX::OptionHideExamples;
		}

		/// ���������, � ������� ������ ���������� ����������� ������ �������.
		/// ������ ���������� � ���������, ��������� �������� DefineTask(procedurename).
		/// �������� topic ���������� ��� ��������� � �������� ��������������.
		/// �������� tasktext �������� ������������ �������; ��������� ������
		/// ������������ ������ ����������� �������� \\n
		static void NewTask(const char* topic, const char* tasktext) {
			pt4taskmakerX::NewTask(topic, tasktext);
		}

		/// ���������, � ������� ������ ���������� ����������� ������ �������.
		/// ������ ���������� � ���������, ��������� �������� DefineTask(procedurename).
		/// �������� tasktext �������� ������������ �������; ��������� ������
		/// ������������ ������ ����������� �������� \\n
		static void NewTask(const char* tasktext) {
			pt4taskmakerX::NewTask(tasktext);
		}

		/// ��������� ����������� � ����� ������ ������� �������� �������.
		static void DataComm(const char* comm) {
			pt4taskmakerX::DataComm(comm);
		}

		/// ��������� ������ � ����������� � ����� ������ ������� �������� �������.
		template<typename T>
		static void Data(const char* comm, T a) {
			pt4taskmakerX::Data(comm, a);
		}

		/// ��������� ������ � ����������� � ����� ������ ������� �������� �������.
		template<typename T>
		static void Data(const char* comm1, T a1, const char* comm2) {
			pt4taskmakerX::Data(comm1, a1, comm2);
		}

		/// ��������� ������ � ����������� � ����� ������ ������� �������� �������.
		template<typename T1, typename T2>
		static void Data(const char* comm1, T1 a1, const char* comm2, T2 a2) {
			pt4taskmakerX::Data(comm1, a1, comm2, a2);
		}

		/// ��������� ������ � ����������� � ����� ������ ������� �������� �������.
		template<typename T1, typename T2>
		static void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3) {
			pt4taskmakerX::Data(comm1, a1, comm2, a2, comm3);
		}

		/// ��������� ������ � ����������� � ����� ������ ������� �������� �������.
		template<typename T1, typename T2, typename T3>
		static void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3) {
			pt4taskmakerX::Data(comm1, a1, comm2, a2, comm3, a3);
		}

		/// ��������� ������������������ ���������� ������ � ������ �������� ������.
		static void Data(const std::vector<bool>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// ��������� ������������������ ����� ����� � ������ �������� ������.
		static void Data(const std::vector<int>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// ��������� ������������������ ������������ ����� � ������ �������� ������.
		static void Data(const std::vector<double>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// ��������� ������������������ �������� � ������ �������� ������.
		static void Data(const std::vector<char>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// ��������� ������������������ ����� � ������ �������� ������.
		static void Data(const std::vector<const char*>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// ��������� ����������� � ����� ������ ������� �����������.
		static void ResComm(const char* comm) {
			pt4taskmakerX::ResComm(comm);
		}

		/// ��������� ������ � ����������� � ����� ������ ������� �����������.
		template<typename T>
		static void Res(const char* comm, T a) {
			pt4taskmakerX::Res(comm, a);
		}

		/// ��������� ������ � ����������� � ����� ������ ������� �����������.
		template<typename T>
		static void Res(const char* comm1, T a1, const char* comm2) {
			pt4taskmakerX::Res(comm1, a1, comm2);
		}

		/// ��������� ������ � ����������� � ����� ������ ������� �����������.
		template<typename T1, typename T2>
		static void Res(const char* comm1, T1 a1, const char* comm2, T2 a2) {
			pt4taskmakerX::Res(comm1, a1, comm2, a2);
		}

		/// ��������� ������ � ����������� � ����� ������ ������� �����������.
		template<typename T1, typename T2>
		static void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3) {
			pt4taskmakerX::Res(comm1, a1, comm2, a2, comm3);
		}

		/// ��������� ������ � ����������� � ����� ������ ������� �����������.
		template<typename T1, typename T2, typename T3>
		static void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3) {
			pt4taskmakerX::Res(comm1, a1, comm2, a2, comm3, a3);
		}

		/// ��������� ������������������ ���������� ������ � ������ �����������.
		static void Res(const std::vector<bool>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// ��������� ������������������ ����� ����� � ������ �����������.
		static void Res(const std::vector<int>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// ��������� ������������������ ������������ ����� � ������ �����������.
		static void Res(const std::vector<double>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// ��������� ������������������ �������� � ������ �����������.
		static void Res(const std::vector<char>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// ��������� ������������������ ����� � ������ �����������.
		static void Res(const std::vector<const char*>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// ������ ����������� ������ ���� ������ ��� �������� ������
		/// (����� ������������� �� ������� ���� ���� ������, 
		/// �.�. ��� ������������� ����������� ����� ���������).
		/// ���� n �� ����� � ��������� 0..10, �� ����� ��������� ������������.
		/// �� ��������� ����������� ������ ���� ������ ���������� ������ 0.
		static void SetWidth(int n) {
			pt4taskmakerX::SetWidth(n);
		}

		/// ������ ������ ����������� ������������ �����: 
		/// � ������������� ������ � n �������� ������� ��� n > 0,
		/// � ��������� ������ � n �������� ������� ��� n < 0,
		/// � ��������� ������ � 6 �������� ������� ��� n = 0.
		/// ���� n �� ������ ����������� 10, �� ����� ��������� ������������.
		/// �� ��������� ��������������� ������ � ������������� ������
		/// � 2 �������� �������.
		static void SetPrecision(int n) {
			pt4taskmakerX::SetPrecision(n);
		}

		/// ������ ���������� �������� ��������, �����������
		/// ��� �������� ������������ ��������� (�� 2 �� 10). 
		/// �� ��������� ����� �������� �������� ���������� ������ 5.
		static void SetTestCount(int n) {
			pt4taskmakerX::SetTestCount(n);
		}

		/// ������ ���������� ����������� ���������� ��������� 
		/// �������� ������, ������� ��������� ������ ��� �����������
		/// ������� ������ � ������ �������� ������ �������� ������. 
		/// ��� ���������� ��������� ��������������,
		/// ��� ��� ����������� ������� ���� ������ ��� �������� ������.
		static void SetRequiredDataCount(int n) {
			pt4taskmakerX::SetRequiredDataCount(n);
		}

		/// ���������� ����� �������� ��������� ������� 
		/// (������� ���������� �� 1).
		static int CurrentTest() {
			return pt4taskmakerX::CurrentTest();
		}

		/// ���������� ��������� ����� ����� � ��������� �� M �� N ������������.
		/// ���� M >= N, �� ���������� M.
		static int Random(int M, int N) {
			return pt4taskmakerX::Random(M, N);
		}

		/// ��������� ��������� �������� � ��������� �� 0 (������������) �� 1 (�� ������������)
		static double Random() {
			return pt4taskmakerX::Random();
		}

		/// ���������� ��������� ������������ ����� �� ���������� [A, B).
		/// ���� ���������� [A, B) ����, �� ���������� A.
		static double Random(double A, double B) {
			return pt4taskmakerX::Random(A, B);
		}

		/// ���������� ��������� ������������ ����� �� ���������� [A, B)
		/// � ����� ������� ������ � ��������� �������� ������� 1e-7.
		/// ���� ���������� [A, B) ����, �� ���������� A, �����������
		/// �� ������ �������� ����� � ���������� �������� ������� 1e-7.
		static double Random1(double A, double B) {
			return pt4taskmakerX::Random1(A, B);
		}

		/// ���������� ��������� ������������ ����� �� ���������� [A, B)
		/// � ����� �������� ������� � ��������� �������� ������� 1e-7.
		/// ���� ���������� [A, B) ����, �� ���������� A, �����������
		/// �� ���� ������� ������ � ���������� �������� ������� 1e-7.
		static double Random2(double A, double B) {
			return pt4taskmakerX::Random2(A, B);
		}

		/// ���������� ��������� ������ ����� len, ���������
		/// �� ���� � �������� (�.�. ���������) ��������� ����.
		static string RandomName(int len) {
			return pt4taskmakerX::RandomName(len);
		}

		/// ������� ����� ������ � ������� ��������� GroupDescription,
		/// ����������� �� ������ GroupAuthor � ������� �������������� �����, ������������ ��������� or.
		/// ��� ������ ������������ �� ����� ���������� (����� ������������ �������� PT4
		/// � ��������� ��������� _ru ��� _en). 
		/// � ������ ���������� �������, ������������ � ����������, ����� ������� ���������� � ������ Task.
		/// ��������� NewGroup ������ ���� ������� � ��������� inittaskgroup ��� ����������, �������
		/// ���������� ������� � ���������� � ������� ������� (��� ����� � ����� inittaskgroup - ��������).
		static void NewGroup(const char* GroupDescription, const char* GroupAuthor, int Options = 0) {
			pt4taskmakerX::NewGroup(GroupDescription, GroupAuthor, Options);
		}

		/// ����������� � ����������� ������ ������������ �������
		/// �� ������ GroupName � ������� TaskNumber. ������ ����������
		/// � ��������� � ������, ������������ � ������ Task.
		static void UseTask(const char* GroupName, int TaskNumber) {
			pt4taskmakerX::UseTask(GroupName, TaskNumber);
		}

		/// ����������� � ����������� ������ ������������ �������
		/// �� ������ GroupName � ������� TaskNumber. ������ ����������
		/// � ��������� � ������, ������������ � ������ Task.
		static void UseTask(const char* GroupName, int TaskNumber, const char* TopicDescription) {
			pt4taskmakerX::UseTask(GroupName, TaskNumber, TopicDescription);
		}

		/// ���������� ������ �� 116 ������� ����.
		static vector<const char*> GetWords() {
			return pt4taskmakerX::GetWords();
		}
		/// ���������� ������ �� 116 ���������� ����.
		static vector<const char*> GetEnWords() {
			return pt4taskmakerX::GetEnWords();
		}
		/// ���������� ������ �� 61 �������� �����������.
		static vector<const char*> GetSentences() {
			return pt4taskmakerX::GetSentences();
		}
		/// ���������� ������ �� 61 ����������� �����������.
		static vector<const char*> GetEnSentences() {
			return pt4taskmakerX::GetEnSentences();
		}
		/// ���������� ������ �� 85 ������� ������������� �������.
		/// ������ ������ ����������� �������� \\n.
		/// � ����� ������ ������ \\n �����������.
		static vector<const char*> GetTexts() {
			return pt4taskmakerX::GetTexts();
		}
		/// ���������� ������ �� 85 ���������� ������������� �������.
		/// ������ ������ ����������� �������� \\n.
		/// � ����� ������ ������ \\n �����������.
		static vector<const char*> GetEnTexts() {
			return pt4taskmakerX::GetEnTexts();
		}

		/// ���������� ��������� ������� ����� �� �������, 
		/// ��������� � ����������� ������� �������.
		static const char* RandomWord() {
			return pt4taskmakerX::RandomWord();
		}
		/// ���������� ��������� ���������� ����� �� �������, 
		/// ��������� � ����������� ������� �������.
		static const char* RandomEnWord() {
			return pt4taskmakerX::RandomEnWord();
		}
		/// ���������� ��������� ������� ����������� �� �������, 
		/// ��������� � ����������� ������� �������.
		static const char* RandomSentence() {
			return pt4taskmakerX::RandomSentence();
		}
		/// ���������� ��������� ���������� ����������� �� �������, 
		/// ��������� � ����������� ������� �������.
		static const char* RandomEnSentence() {
			return pt4taskmakerX::RandomEnSentence();
		}
		/// ���������� ��������� ������� ������������� ����� �� �������, 
		/// ��������� � ����������� ������� �������.
		/// ������ ������ ����������� �������� \\n.
		/// � ����� ������ ������ \\n �����������.
		static const char* RandomText() {
			return pt4taskmakerX::RandomText();
		}
		/// ���������� ��������� ���������� ������������� ����� �� �������, 
		/// ��������� � ����������� ������� �������.
		/// ������ ������ ����������� �������� \\n.
		/// � ����� ������ ������ \\n �����������.
		static const char* RandomEnText() {
			return pt4taskmakerX::RandomEnText();
		}

		/// ��������� � ������� �������� ���� ����� �����
		/// � ������ FileName � ���������� ��� ����������
		/// � ������� �������� ������.
		static void DataFileInteger(const char* FileName) {
			pt4taskmakerX::DataFileInteger(FileName);
		}
		/// ��������� � ������� �������� ���� ������������ �����
		/// � ������ FileName � ���������� ��� ����������
		/// � ������� �������� ������.
		static void DataFileReal(const char* FileName) {
			pt4taskmakerX::DataFileReal(FileName);
		}
		/// ��������� � ������� �������� ���������� ����
		/// � ������ FileName � ���������� ��� ����������
		/// � ������� �������� ������. ������� ������
		/// ��������� � ����� � ����������� ���������.
		static void DataFileChar(const char* FileName) {
			pt4taskmakerX::DataFileChar(FileName);
		}
		/// ��������� � ������� �������� ��������� ����
		/// � ���������� ���� ShortString � ������ FileName 
		/// � ���������� ��� ���������� � ������� �������� ������.
		/// ����� ��������� ����� �� ������ ������������ 70 ��������.
		/// ������ ������ ��������� � ����� � ����������� ���������.
		static void DataFileString(const char* FileName) {
			pt4taskmakerX::DataFileString(FileName);
		}
		/// ��������� � ������� �������� ��������� ����
		/// � ������ FileName � ���������� ��� ����������
		/// � ������� �������� ������. ����� ������ ������
		/// ���������� ����� �� ������ ������������ 70 ��������.
		/// ����� ������ ��������� � ����� � ����������� ���������.
		static void DataText(const char* FileName, int LineCount = 5) {
			pt4taskmakerX::DataText(FileName, LineCount);
		}

		/// ��������� � ������� �������������� ���� ����� �����
		/// � ������ FileName � ���������� ��� ���������� � ������� �����������.
		static void ResFileInteger(const char* FileName) {
			pt4taskmakerX::ResFileInteger(FileName);
		}
		/// ��������� � ������� �������������� ���� ������������ �����
		/// � ������ FileName � ���������� ��� ���������� � ������� �����������.
		static void ResFileReal(const char* FileName) {
			pt4taskmakerX::ResFileReal(FileName);
		}
		/// ��������� � ������� �������������� ���������� ����
		/// � ������ FileName � ���������� ��� ���������� � ������� �����������.
		/// ������� ������ ��������� � ����� � ����������� ���������.
		static void ResFileChar(const char* FileName) {
			pt4taskmakerX::ResFileChar(FileName);
		}
		/// ��������� � ������� �������������� ��������� ����
		/// � ���������� ���� ShortString � ������ FileName 
		/// � ���������� ��� ���������� � ������� �����������.
		/// ����� ��������� ����� �� ������ ������������ 70 ��������.
		/// ������ ������ ��������� � ����� � ����������� ���������.
		static void ResFileString(const char* FileName) {
			pt4taskmakerX::ResFileString(FileName);
		}
		/// ��������� � ������� �������������� ��������� ����
		/// � ������ FileName � ���������� ��� ���������� � ������� �����������. 
		/// ����� ������ ������ ���������� ����� �� ������ ������������ 70 ��������.
		/// ����� ������ ��������� � ����� � ����������� ���������.
		static void ResText(const char* FileName, int LineCount = 5) {
			pt4taskmakerX::ResText(FileName, LineCount);
		}
		
		/// ������������ ������� ������ � �������� (char[256])
		static void ConvertToShortString(string s, ShortString buf) {
			pt4taskmakerX::ConvertToShortString(s, buf);
		}

		/// ���������, �������������� ����������� ������������ �������� ������
		/// � "��������� �����" ��� ���������� ������� � ����� PascalABC.NET
		/// (��� ������������� ������ ���� �� ��������� ������� ��������)
		static void SetObjectStyle() {
			pt4taskmakerX::SetObjectStyle();
		}

		/// ������������� ������� ������� ��� ����������� �������� ��� ������ 
		/// �������� ����� (��� ���������� ������� � ������������ ������)
		void SetProcess(int ProcessRank) {
			pt4taskmakerX::SetProcess(ProcessRank);
		}
	};
}
#include "pt4taskmakerX.tpp"
#endif // _PT4TASKMAKERX
