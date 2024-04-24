#ifndef _PT4TASKMAKERX
#define _PT4TASKMAKERX

#include <vector>
#include <string>
#include "pt4taskmaker.h"

using ShortString = char[256];

/// макрос для добавления задания в список всех заданий группы
#define DefineTask(name) \
    void name(); \
    struct name ## _Registrar { \
        name ## _Registrar() { RegisterTaskFunction(name, #name); } \
    } name ## _registrar_instance; \
    void name()

/// макрос для получения названия группы заданий
#define DefineGroupName \
    struct _GroupName { \
        _GroupName() { GetGroupName(__FILE__); } \
    } _groupname_instance;

#define alphabet "0123456789abcdefghijklmnoprstuvwxyz"
#define ErrMes1 "Error: Раздел размером более 5 строк не может содержать файловые данные."
#define ErrMes2 "Error: При наличии файловых данных раздел не может содержать более 5 строк."
#define ErrMes3 "Error: Количество исходных данных превысило 200."
#define ErrMes4 "Error: Количество результирующих данных превысило 200."
#define ErrMes5 "Error: При определении задания первой должна вызываться процедура NewTask."
#define ErrMes6 "Error: При определении задания не указаны исходные данные."
#define ErrMes7 "Error: При определении задания не указаны результирующие данные."

//Функции и переменные для внутреннего использования

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
	const int OptionAllLanguages = 1;       // группа доступна для всех языков
	const int OptionPascalLanguages = 2;    // группа доступна для всех реализаций Паскаля
	const int OptionNETLanguages = 4;       // группа доступна для всех NET-языков
	const int OptionUseAddition = 8;        // группа доступна только при наличии файла дополнений
	const int OptionHideExamples = 16;      // не отображать раздел с примером верного решения

	/// Добавление задания (как указатель на функцию) в список заданий. Для внутреннего использования.
	void RegisterTaskFunction(void (*task)(), const char* taskname);

	/// Получение названия группы заданий из названия файла. Для внутреннего использования.
	void GetGroupName(const char* FilePath);

	/// Процедура, с которой должно начинаться определение нового задания.
	/// Должна вызываться в процедуре, созданной макросом DefineTask(procedurename).
	/// Параметр topic определяет имя подгруппы и является необязательным.
	/// Параметр tasktext содержит формулировку задания; отдельные строки
	/// формулировки должны разделяться символом \\n
	void NewTask(const char* topic, const char* tasktext);

	/// Процедура, с которой должно начинаться определение нового задания.
	/// Должна вызываться в процедуре, созданной макросом DefineTask(procedurename).
	/// Параметр tasktext содержит формулировку задания; отдельные строки
	/// формулировки должны разделяться символом \\n
	void NewTask(const char* tasktext);

	void Data(const char* s, bool a, int x, int y, int w);
    void Data(const char* s, int a, int x, int y, int w);
    void Data(const char* s, double a, int x, int y, int w);
    void Data(const char* s, char a, int x, int y, int w);
    void Data(const char* s, const char* a, int x, int y, int w);

	/// Добавляет комментарий в новой строке раздела исходных даннных.
	void DataComm(const char* comm);

	/// Добавляет данные и комментарии в новой строке раздела исходных даннных.
	template<typename T>
	void Data(const char* comm, T a);

	/// Добавляет данные и комментарии в новой строке раздела исходных даннных.
	template<typename T>
	void Data(const char* comm1, T a1, const char* comm2);

	/// Добавляет данные и комментарии в новой строке раздела исходных даннных.
	template<typename T1, typename T2>
	void Data(const char* comm1, T1 a1, const char* comm2, T2 a2);

	/// Добавляет данные и комментарии в новой строке раздела исходных даннных.
	template<typename T1, typename T2>
	void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3);

	/// Добавляет данные и комментарии в новой строке раздела исходных даннных.
	template<typename T1, typename T2, typename T3>
	void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3);

	/// Добавляет последовательность логических данных в раздел исходных данных.
	void Data(const std::vector<bool>& seq);

	/// Добавляет последовательность целых чисел в раздел исходных данных.
	void Data(const std::vector<int>& seq);

	/// Добавляет последовательность вещественных чисел в раздел исходных данных.
	void Data(const std::vector<double>& seq);

	/// Добавляет последовательность символов в раздел исходных данных.
	void Data(const std::vector<char>& seq);

	/// Добавляет последовательность строк в раздел исходных данных.
	void Data(const std::vector<const char*>& seq);

	void Res(const char* s, bool a, int x, int y, int w);
    void Res(const char* s, int a, int x, int y, int w);
    void Res(const char* s, double a, int x, int y, int w);
    void Res(const char* s, char a, int x, int y, int w);
    void Res(const char* s, const char* a, int x, int y, int w);

	/// Добавляет комментарий в новой строке раздела результатов.
	void ResComm(const char* comm);

	/// Добавляет данные и комментарии в новой строке раздела результатов.
	template<typename T>
	void Res(const char* comm, T a);

	/// Добавляет данные и комментарии в новой строке раздела результатов.
	template<typename T>
	void Res(const char* comm1, T a1, const char* comm2);

	/// Добавляет данные и комментарии в новой строке раздела результатов.
	template<typename T1, typename T2>
	void Res(const char* comm1, T1 a1, const char* comm2, T2 a2);

	/// Добавляет данные и комментарии в новой строке раздела результатов.
	template<typename T1, typename T2>
	void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3);

	/// Добавляет данные и комментарии в новой строке раздела результатов.
	template<typename T1, typename T2, typename T3>
	void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3);

	/// Добавляет последовательность логических данных в раздел результатов.
	void Res(const std::vector<bool>& seq);

	/// Добавляет последовательность целых чисел в раздел результатов.
	void Res(const std::vector<int>& seq);

	/// Добавляет последовательность вещественных чисел в раздел результатов.
	void Res(const std::vector<double>& seq);

	/// Добавляет последовательность символов в раздел результатов.
	void Res(const std::vector<char>& seq);

	/// Добавляет последовательность строк в раздел результатов.
	void Res(const std::vector<const char*>& seq);
	
	/// Задает минимальную ширину поля вывода для числовых данных
	/// (числа выравниваются по правому краю поля вывода, 
	/// т.е. при необходимости дополняются слева пробелами).
	/// Если n не лежит в диапазоне 0..10, то вызов процедуры игнорируется.
	/// По умолчанию минимальная ширина поля вывода полагается равной 0.
	void SetWidth(int n);

	/// Задает формат отображения вещественных чисел: 
	/// с фиксированной точкой и n дробными знаками при n > 0,
	/// с плавающей точкой и n дробными знаками при n < 0,
	/// с плавающей точкой и 6 дробными знаками при n = 0.
	/// Если n по модулю превосходит 10, то вызов процедуры игнорируется.
	/// По умолчанию устанавливается формат с фиксированной точкой
	/// и 2 дробными знаками.
	void SetPrecision(int n);

	/// Задает количество тестовых запусков, выполняемых
	/// для проверки правильности программы (от 2 до 10). 
	/// По умолчанию число тестовых запусков полагается равным 5.
	void SetTestCount(int n);

	/// Задает минимально необходимое количество элементов 
	/// исходных данных, которое требуется ввести для правильного
	/// решения задачи в случае текущего набора исходных данных. 
	/// При отсутствии процедуры предполагается,
	/// что для правильного решения надо ввести все исходные данные.
	void SetRequiredDataCount(int n);

	/// Возвращает номер текущего тестового запуска 
	/// (запуски нумеруются от 1).
	int CurrentTest();

	/// Генерирует случайное целое число в диапазоне от M до N включительно.
	/// Если M >= N, то возвращает M.
	int Random(int M, int N);

	/// Возращает случайное значение в диапазоне от 0 (включительно) до 1 (не включительно)
	double Random(); 

	/// Генерирует случайное вещественное число на промежутке [A, B).
	/// Если промежуток [A, B) пуст, то возвращает A.
	double Random(double A, double B);

	/// Генерирует случайное вещественное число на промежутке [A, B)
	/// с одним дробным знаком и случайной добавкой порядка 1e-7.
	/// Если промежуток [A, B) пуст, то возвращает A, округленное
	/// до одного дробного знака и снабженное добавкой порядка 1e-7.
	double Random1(double A, double B);

	/// Генерирует случайное вещественное число на промежутке [A, B)
	/// с двумя дробными знаками и случайной добавкой порядка 1e-7.
	/// Если промежуток [A, B) пуст, то возвращает A, округленное
	/// до двух дробных знаков и снабженное добавкой порядка 1e-7.
	double Random2(double A, double B);

	/// Генерирует случайную строку длины len, состоящую
	/// из цифр и строчных (т.е. маленьких) латинских букв.
	string RandomName(int len);

	/// Создает новую группу с кратким описанием GroupDescription,
	/// информацией об авторе GroupAuthor и набором необязательных опций, объединяемых операцией or.
	/// Имя группы определяется по имени библиотеки (путем отбрасывания префикса PT4
	/// и возможных суффиксов _ru или _en). 
	/// В группу включаются задания, определенные в процедурах, имена которых начинаются с текста Task.
	/// Процедура NewGroup должна быть вызвана в процедуре inittaskgroup без параметров, которую
	/// необходимо описать в библиотеке с группой заданий (все буквы в имени inittaskgroup - строчные).
	void NewGroup(const char* GroupDescription, const char* GroupAuthor, int Options = 0);
	
	/// Импортирует в создаваемую группу существующее задание
	/// из группы GroupName с номером TaskNumber. Должна вызываться
	/// в процедуре с именем, начинающемся с текста Task.
	void UseTask(const char* GroupName, int TaskNumber);

	/// Импортирует в создаваемую группу существующее задание
	/// из группы GroupName с номером TaskNumber. Должна вызываться
	/// в процедуре с именем, начинающемся с текста Task.
	void UseTask(const char* GroupName, int TaskNumber, const char* TopicDescription);

	/// Возвращает массив из 116 русских слов.
	vector<const char*> GetWords();
	/// Возвращает массив из 116 английских слов.
	vector<const char*> GetEnWords();
	/// Возвращает массив из 61 русского предложения.
	vector<const char*> GetSentences();
	/// Возвращает массив из 61 английского предложения.
	vector<const char*> GetEnSentences();
	/// Возвращает массив из 85 русских многострочных текстов.
	/// Строки текста разделяются символом \\n.
	/// В конце текста символ \\n отсутствует.
	vector<const char*> GetTexts();
	/// Возвращает массив из 85 английских многострочных текстов.
	/// Строки текста разделяются символом \\n.
	/// В конце текста символ \\n отсутствует.
	vector<const char*> GetEnTexts();

	/// Возвращает случайное русское слово из массива, 
	/// входящего в конструктор учебных заданий.
	const char* RandomWord();
	/// Возвращает случайное английское слово из массива, 
	/// входящего в конструктор учебных заданий.
	const char* RandomEnWord();
	/// Возвращает случайное русское предложение из массива, 
	/// входящего в конструктор учебных заданий.
	const char* RandomSentence();
	/// Возвращает случайное английское предложение из массива, 
	/// входящего в конструктор учебных заданий.
	const char* RandomEnSentence();
	/// Возвращает случайный русский многострочный текст из массива, 
	/// входящего в конструктор учебных заданий.
	/// Строки текста разделяются символом \\n.
	/// В конце текста символ \\n отсутствует.
	const char* RandomText();
	/// Возвращает случайный английский многострочный текст из массива, 
	/// входящего в конструктор учебных заданий.
	/// Строки текста разделяются символом \\n.
	/// В конце текста символ \\n отсутствует.
	const char* RandomEnText();

	/// Добавляет в задание исходный файл целых чисел
	/// с именем FileName и отображает его содержимое
	/// в разделе исходных данных.
	void DataFileInteger(const char* FileName);
	/// Добавляет в задание исходный файл вещественных чисел
	/// с именем FileName и отображает его содержимое
	/// в разделе исходных данных.
	void DataFileReal(const char* FileName);
	/// Добавляет в задание исходный символьный файл
	/// с именем FileName и отображает его содержимое
	/// в разделе исходных данных. Символы должны
	/// храниться в файле в однобайтной кодировке.
	void DataFileChar(const char* FileName);
	/// Добавляет в задание исходный строковый файл
	/// с элементами типа ShortString и именем FileName 
	/// и отображает его содержимое в разделе исходных данных.
	/// Длина элементов файла не должна превосходить 70 символов.
	/// Строки должны храниться в файле в однобайтной кодировке.
	void DataFileString(const char* FileName);
	/// Добавляет в задание исходный текстовый файл
	/// с именем FileName и отображает его содержимое
	/// в разделе исходных данных. Длина каждой строки
	/// текстового файла не должна превосходить 70 символов.
	/// Текст должен храниться в файле в однобайтной кодировке.
	void DataText(const char* FileName, int LineCount = 5);

	/// Добавляет в задание результирующий файл целых чисел
	/// с именем FileName и отображает его содержимое в разделе результатов.
	void ResFileInteger(const char* FileName);
	/// Добавляет в задание результирующий файл вещественных чисел
	/// с именем FileName и отображает его содержимое в разделе результатов.
	void ResFileReal(const char* FileName);
	/// Добавляет в задание результирующий символьный файл
	/// с именем FileName и отображает его содержимое в разделе результатов.
	/// Символы должны храниться в файле в однобайтной кодировке.
	void ResFileChar(const char* FileName);
	/// Добавляет в задание результирующий строковый файл
	/// с элементами типа ShortString и именем FileName 
	/// и отображает его содержимое в разделе результатов.
	/// Длина элементов файла не должна превосходить 70 символов.
	/// Строки должны храниться в файле в однобайтной кодировке.
	void ResFileString(const char* FileName);
	/// Добавляет в задание результирующий текстовый файл
	/// с именем FileName и отображает его содержимое в разделе результатов. 
	/// Длина каждой строки текстового файла не должна превосходить 70 символов.
	/// Текст должен храниться в файле в однобайтной кодировке.
	void ResText(const char* FileName, int LineCount = 5);

	/// Конвертирует обычную строку в короткую (char[256])
	void ConvertToShortString(string s, ShortString buf);

	/// Процедура, обеспечивающая отображение динамических структур данных
	/// в "объектном стиле" при выполнении заданий в среде PascalABC.NET
	/// (при использовании других сред не выполняет никаких действий)
	void SetObjectStyle();

	/// Устанавливает текущий процесс для последующей передачи ему данных 
	/// числовых типов (при выполнении задания в параллельном режиме)
	void SetProcess(int ProcessRank);

	class pt {
	public:
		/// Дополнительная опция для процедуры NewGroup: 
		/// группа доступна для всех языков.  
		static int OptionAllLanguages() {
			return pt4taskmakerX::OptionAllLanguages;
		}
		/// Дополнительная опция для процедуры NewGroup: 
		/// группа доступна для всех реализаций языка Pascal
		static int OptionPascalLanguages() {
			return pt4taskmakerX::OptionPascalLanguages;
		}
		/// Дополнительная опция для процедуры NewGroup: 
		/// группа доступна для всех NET-языков.
		static int OptionUseAddition() {
			return pt4taskmakerX::OptionUseAddition;
		}
		/// Дополнительная опция для процедуры NewGroup: 
		/// группа доступна только при наличии связанного с ней файла дополнений.
		static int OptionNETLanguages() {
			return pt4taskmakerX::OptionNETLanguages;
		}
		/// Дополнительная опция для процедуры NewGroup: 
		/// в заданиях данной группы не будет отображаться пример верного решения.
		static int OptionHideExamples() {
			return pt4taskmakerX::OptionHideExamples;
		}

		/// Процедура, с которой должно начинаться определение нового задания.
		/// Должна вызываться в процедуре, созданной макросом DefineTask(procedurename).
		/// Параметр topic определяет имя подгруппы и является необязательным.
		/// Параметр tasktext содержит формулировку задания; отдельные строки
		/// формулировки должны разделяться символом \\n
		static void NewTask(const char* topic, const char* tasktext) {
			pt4taskmakerX::NewTask(topic, tasktext);
		}

		/// Процедура, с которой должно начинаться определение нового задания.
		/// Должна вызываться в процедуре, созданной макросом DefineTask(procedurename).
		/// Параметр tasktext содержит формулировку задания; отдельные строки
		/// формулировки должны разделяться символом \\n
		static void NewTask(const char* tasktext) {
			pt4taskmakerX::NewTask(tasktext);
		}

		/// Добавляет комментарий в новой строке раздела исходных даннных.
		static void DataComm(const char* comm) {
			pt4taskmakerX::DataComm(comm);
		}

		/// Добавляет данные и комментарии в новой строке раздела исходных даннных.
		template<typename T>
		static void Data(const char* comm, T a) {
			pt4taskmakerX::Data(comm, a);
		}

		/// Добавляет данные и комментарии в новой строке раздела исходных даннных.
		template<typename T>
		static void Data(const char* comm1, T a1, const char* comm2) {
			pt4taskmakerX::Data(comm1, a1, comm2);
		}

		/// Добавляет данные и комментарии в новой строке раздела исходных даннных.
		template<typename T1, typename T2>
		static void Data(const char* comm1, T1 a1, const char* comm2, T2 a2) {
			pt4taskmakerX::Data(comm1, a1, comm2, a2);
		}

		/// Добавляет данные и комментарии в новой строке раздела исходных даннных.
		template<typename T1, typename T2>
		static void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3) {
			pt4taskmakerX::Data(comm1, a1, comm2, a2, comm3);
		}

		/// Добавляет данные и комментарии в новой строке раздела исходных даннных.
		template<typename T1, typename T2, typename T3>
		static void Data(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3) {
			pt4taskmakerX::Data(comm1, a1, comm2, a2, comm3, a3);
		}

		/// Добавляет последовательность логических данных в раздел исходных данных.
		static void Data(const std::vector<bool>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// Добавляет последовательность целых чисел в раздел исходных данных.
		static void Data(const std::vector<int>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// Добавляет последовательность вещественных чисел в раздел исходных данных.
		static void Data(const std::vector<double>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// Добавляет последовательность символов в раздел исходных данных.
		static void Data(const std::vector<char>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// Добавляет последовательность строк в раздел исходных данных.
		static void Data(const std::vector<const char*>& seq) {
			pt4taskmakerX::Data(seq);
		}

		/// Добавляет комментарий в новой строке раздела результатов.
		static void ResComm(const char* comm) {
			pt4taskmakerX::ResComm(comm);
		}

		/// Добавляет данные и комментарии в новой строке раздела результатов.
		template<typename T>
		static void Res(const char* comm, T a) {
			pt4taskmakerX::Res(comm, a);
		}

		/// Добавляет данные и комментарии в новой строке раздела результатов.
		template<typename T>
		static void Res(const char* comm1, T a1, const char* comm2) {
			pt4taskmakerX::Res(comm1, a1, comm2);
		}

		/// Добавляет данные и комментарии в новой строке раздела результатов.
		template<typename T1, typename T2>
		static void Res(const char* comm1, T1 a1, const char* comm2, T2 a2) {
			pt4taskmakerX::Res(comm1, a1, comm2, a2);
		}

		/// Добавляет данные и комментарии в новой строке раздела результатов.
		template<typename T1, typename T2>
		static void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3) {
			pt4taskmakerX::Res(comm1, a1, comm2, a2, comm3);
		}

		/// Добавляет данные и комментарии в новой строке раздела результатов.
		template<typename T1, typename T2, typename T3>
		static void Res(const char* comm1, T1 a1, const char* comm2, T2 a2, const char* comm3, T3 a3) {
			pt4taskmakerX::Res(comm1, a1, comm2, a2, comm3, a3);
		}

		/// Добавляет последовательность логических данных в раздел результатов.
		static void Res(const std::vector<bool>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// Добавляет последовательность целых чисел в раздел результатов.
		static void Res(const std::vector<int>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// Добавляет последовательность вещественных чисел в раздел результатов.
		static void Res(const std::vector<double>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// Добавляет последовательность символов в раздел результатов.
		static void Res(const std::vector<char>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// Добавляет последовательность строк в раздел результатов.
		static void Res(const std::vector<const char*>& seq) {
			pt4taskmakerX::Res(seq);
		}

		/// Задает минимальную ширину поля вывода для числовых данных
		/// (числа выравниваются по правому краю поля вывода, 
		/// т.е. при необходимости дополняются слева пробелами).
		/// Если n не лежит в диапазоне 0..10, то вызов процедуры игнорируется.
		/// По умолчанию минимальная ширина поля вывода полагается равной 0.
		static void SetWidth(int n) {
			pt4taskmakerX::SetWidth(n);
		}

		/// Задает формат отображения вещественных чисел: 
		/// с фиксированной точкой и n дробными знаками при n > 0,
		/// с плавающей точкой и n дробными знаками при n < 0,
		/// с плавающей точкой и 6 дробными знаками при n = 0.
		/// Если n по модулю превосходит 10, то вызов процедуры игнорируется.
		/// По умолчанию устанавливается формат с фиксированной точкой
		/// и 2 дробными знаками.
		static void SetPrecision(int n) {
			pt4taskmakerX::SetPrecision(n);
		}

		/// Задает количество тестовых запусков, выполняемых
		/// для проверки правильности программы (от 2 до 10). 
		/// По умолчанию число тестовых запусков полагается равным 5.
		static void SetTestCount(int n) {
			pt4taskmakerX::SetTestCount(n);
		}

		/// Задает минимально необходимое количество элементов 
		/// исходных данных, которое требуется ввести для правильного
		/// решения задачи в случае текущего набора исходных данных. 
		/// При отсутствии процедуры предполагается,
		/// что для правильного решения надо ввести все исходные данные.
		static void SetRequiredDataCount(int n) {
			pt4taskmakerX::SetRequiredDataCount(n);
		}

		/// Возвращает номер текущего тестового запуска 
		/// (запуски нумеруются от 1).
		static int CurrentTest() {
			return pt4taskmakerX::CurrentTest();
		}

		/// Генерирует случайное целое число в диапазоне от M до N включительно.
		/// Если M >= N, то возвращает M.
		static int Random(int M, int N) {
			return pt4taskmakerX::Random(M, N);
		}

		/// Возращает случайное значение в диапазоне от 0 (включительно) до 1 (не включительно)
		static double Random() {
			return pt4taskmakerX::Random();
		}

		/// Генерирует случайное вещественное число на промежутке [A, B).
		/// Если промежуток [A, B) пуст, то возвращает A.
		static double Random(double A, double B) {
			return pt4taskmakerX::Random(A, B);
		}

		/// Генерирует случайное вещественное число на промежутке [A, B)
		/// с одним дробным знаком и случайной добавкой порядка 1e-7.
		/// Если промежуток [A, B) пуст, то возвращает A, округленное
		/// до одного дробного знака и снабженное добавкой порядка 1e-7.
		static double Random1(double A, double B) {
			return pt4taskmakerX::Random1(A, B);
		}

		/// Генерирует случайное вещественное число на промежутке [A, B)
		/// с двумя дробными знаками и случайной добавкой порядка 1e-7.
		/// Если промежуток [A, B) пуст, то возвращает A, округленное
		/// до двух дробных знаков и снабженное добавкой порядка 1e-7.
		static double Random2(double A, double B) {
			return pt4taskmakerX::Random2(A, B);
		}

		/// Генерирует случайную строку длины len, состоящую
		/// из цифр и строчных (т.е. маленьких) латинских букв.
		static string RandomName(int len) {
			return pt4taskmakerX::RandomName(len);
		}

		/// Создает новую группу с кратким описанием GroupDescription,
		/// информацией об авторе GroupAuthor и набором необязательных опций, объединяемых операцией or.
		/// Имя группы определяется по имени библиотеки (путем отбрасывания префикса PT4
		/// и возможных суффиксов _ru или _en). 
		/// В группу включаются задания, определенные в процедурах, имена которых начинаются с текста Task.
		/// Процедура NewGroup должна быть вызвана в процедуре inittaskgroup без параметров, которую
		/// необходимо описать в библиотеке с группой заданий (все буквы в имени inittaskgroup - строчные).
		static void NewGroup(const char* GroupDescription, const char* GroupAuthor, int Options = 0) {
			pt4taskmakerX::NewGroup(GroupDescription, GroupAuthor, Options);
		}

		/// Импортирует в создаваемую группу существующее задание
		/// из группы GroupName с номером TaskNumber. Должна вызываться
		/// в процедуре с именем, начинающемся с текста Task.
		static void UseTask(const char* GroupName, int TaskNumber) {
			pt4taskmakerX::UseTask(GroupName, TaskNumber);
		}

		/// Импортирует в создаваемую группу существующее задание
		/// из группы GroupName с номером TaskNumber. Должна вызываться
		/// в процедуре с именем, начинающемся с текста Task.
		static void UseTask(const char* GroupName, int TaskNumber, const char* TopicDescription) {
			pt4taskmakerX::UseTask(GroupName, TaskNumber, TopicDescription);
		}

		/// Возвращает массив из 116 русских слов.
		static vector<const char*> GetWords() {
			return pt4taskmakerX::GetWords();
		}
		/// Возвращает массив из 116 английских слов.
		static vector<const char*> GetEnWords() {
			return pt4taskmakerX::GetEnWords();
		}
		/// Возвращает массив из 61 русского предложения.
		static vector<const char*> GetSentences() {
			return pt4taskmakerX::GetSentences();
		}
		/// Возвращает массив из 61 английского предложения.
		static vector<const char*> GetEnSentences() {
			return pt4taskmakerX::GetEnSentences();
		}
		/// Возвращает массив из 85 русских многострочных текстов.
		/// Строки текста разделяются символом \\n.
		/// В конце текста символ \\n отсутствует.
		static vector<const char*> GetTexts() {
			return pt4taskmakerX::GetTexts();
		}
		/// Возвращает массив из 85 английских многострочных текстов.
		/// Строки текста разделяются символом \\n.
		/// В конце текста символ \\n отсутствует.
		static vector<const char*> GetEnTexts() {
			return pt4taskmakerX::GetEnTexts();
		}

		/// Возвращает случайное русское слово из массива, 
		/// входящего в конструктор учебных заданий.
		static const char* RandomWord() {
			return pt4taskmakerX::RandomWord();
		}
		/// Возвращает случайное английское слово из массива, 
		/// входящего в конструктор учебных заданий.
		static const char* RandomEnWord() {
			return pt4taskmakerX::RandomEnWord();
		}
		/// Возвращает случайное русское предложение из массива, 
		/// входящего в конструктор учебных заданий.
		static const char* RandomSentence() {
			return pt4taskmakerX::RandomSentence();
		}
		/// Возвращает случайное английское предложение из массива, 
		/// входящего в конструктор учебных заданий.
		static const char* RandomEnSentence() {
			return pt4taskmakerX::RandomEnSentence();
		}
		/// Возвращает случайный русский многострочный текст из массива, 
		/// входящего в конструктор учебных заданий.
		/// Строки текста разделяются символом \\n.
		/// В конце текста символ \\n отсутствует.
		static const char* RandomText() {
			return pt4taskmakerX::RandomText();
		}
		/// Возвращает случайный английский многострочный текст из массива, 
		/// входящего в конструктор учебных заданий.
		/// Строки текста разделяются символом \\n.
		/// В конце текста символ \\n отсутствует.
		static const char* RandomEnText() {
			return pt4taskmakerX::RandomEnText();
		}

		/// Добавляет в задание исходный файл целых чисел
		/// с именем FileName и отображает его содержимое
		/// в разделе исходных данных.
		static void DataFileInteger(const char* FileName) {
			pt4taskmakerX::DataFileInteger(FileName);
		}
		/// Добавляет в задание исходный файл вещественных чисел
		/// с именем FileName и отображает его содержимое
		/// в разделе исходных данных.
		static void DataFileReal(const char* FileName) {
			pt4taskmakerX::DataFileReal(FileName);
		}
		/// Добавляет в задание исходный символьный файл
		/// с именем FileName и отображает его содержимое
		/// в разделе исходных данных. Символы должны
		/// храниться в файле в однобайтной кодировке.
		static void DataFileChar(const char* FileName) {
			pt4taskmakerX::DataFileChar(FileName);
		}
		/// Добавляет в задание исходный строковый файл
		/// с элементами типа ShortString и именем FileName 
		/// и отображает его содержимое в разделе исходных данных.
		/// Длина элементов файла не должна превосходить 70 символов.
		/// Строки должны храниться в файле в однобайтной кодировке.
		static void DataFileString(const char* FileName) {
			pt4taskmakerX::DataFileString(FileName);
		}
		/// Добавляет в задание исходный текстовый файл
		/// с именем FileName и отображает его содержимое
		/// в разделе исходных данных. Длина каждой строки
		/// текстового файла не должна превосходить 70 символов.
		/// Текст должен храниться в файле в однобайтной кодировке.
		static void DataText(const char* FileName, int LineCount = 5) {
			pt4taskmakerX::DataText(FileName, LineCount);
		}

		/// Добавляет в задание результирующий файл целых чисел
		/// с именем FileName и отображает его содержимое в разделе результатов.
		static void ResFileInteger(const char* FileName) {
			pt4taskmakerX::ResFileInteger(FileName);
		}
		/// Добавляет в задание результирующий файл вещественных чисел
		/// с именем FileName и отображает его содержимое в разделе результатов.
		static void ResFileReal(const char* FileName) {
			pt4taskmakerX::ResFileReal(FileName);
		}
		/// Добавляет в задание результирующий символьный файл
		/// с именем FileName и отображает его содержимое в разделе результатов.
		/// Символы должны храниться в файле в однобайтной кодировке.
		static void ResFileChar(const char* FileName) {
			pt4taskmakerX::ResFileChar(FileName);
		}
		/// Добавляет в задание результирующий строковый файл
		/// с элементами типа ShortString и именем FileName 
		/// и отображает его содержимое в разделе результатов.
		/// Длина элементов файла не должна превосходить 70 символов.
		/// Строки должны храниться в файле в однобайтной кодировке.
		static void ResFileString(const char* FileName) {
			pt4taskmakerX::ResFileString(FileName);
		}
		/// Добавляет в задание результирующий текстовый файл
		/// с именем FileName и отображает его содержимое в разделе результатов. 
		/// Длина каждой строки текстового файла не должна превосходить 70 символов.
		/// Текст должен храниться в файле в однобайтной кодировке.
		static void ResText(const char* FileName, int LineCount = 5) {
			pt4taskmakerX::ResText(FileName, LineCount);
		}
		
		/// Конвертирует обычную строку в короткую (char[256])
		static void ConvertToShortString(string s, ShortString buf) {
			pt4taskmakerX::ConvertToShortString(s, buf);
		}

		/// Процедура, обеспечивающая отображение динамических структур данных
		/// в "объектном стиле" при выполнении заданий в среде PascalABC.NET
		/// (при использовании других сред не выполняет никаких действий)
		static void SetObjectStyle() {
			pt4taskmakerX::SetObjectStyle();
		}

		/// Устанавливает текущий процесс для последующей передачи ему данных 
		/// числовых типов (при выполнении задания в параллельном режиме)
		void SetProcess(int ProcessRank) {
			pt4taskmakerX::SetProcess(ProcessRank);
		}
	};
}
#include "pt4taskmakerX.tpp"
#endif // _PT4TASKMAKERX
