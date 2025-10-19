#include <iostream>
#include <string>
#include <vector>
#include <limits>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::vector;
using std::numeric_limits;
using std::streamsize;

void WriteSeparator(int count, char separator = '*')
{
	for (int i = 0; i < count; i++)
		cout << separator;
	cout << endl;
}

void OutputBlock(string &message, string &character = "")
{
	if (character == "")
	{
		cout << message << endl;
		WriteSeparator(50);
	}
	else 
	{
		cout << character << " :" << endl;
		cout << message << endl;
		WriteSeparator(50);
	}
}

int AskChoice(const string& question, const vector<string>& options)
{
	OutputBlock(question);
	for (size_t i = 0; i < options.size(); ++i)
	{
		cout << (i + 1) << ") " << options[i] << endl;
	}
	WriteSeparator(50);

	int choice = 0;
	while (true)
	{
		cout << "Выберите вариант (номер): ";
		if (cin >> choice && choice >= 1 && choice <= (int)options.size())
		{
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистить остаток строки
			return choice;
		}
		else
		{
			cout << "Неверный ввод. Попробуйте снова." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

void Episode1() 
{
	OutputBlock("Где-то в городе‑призраке, в одной пустой и полуразрушенной многоэтажке...");
	OutputBlock("Мда, сколько нам ещё здесь торчать?", "Панк");
	OutputBlock("Не ной, любуйся видами", "Вы");
	OutputBlock("Угараешь?! На что смотреть, на тараканов и серые полуразрухи?! Откуда здесь вообще живность?!", "Панк");
	OutputBlock("Оттуда же, откуда у тебя", "Вы");
	OutputBlock("Эй! Это необходимая мера! Не лыбысь ты так!", "Панк");
	OutputBlock("Ваши издевки над Панком прерывает молниеносный подзатыльник по вам и вашему горе‑напарнику");
	OutputBlock("Хватит шуметь, спугнете добычу", "Капитан Камэо");
	OutputBlock("Есть, капитан...", "Вы и Панк");
	OutputBlock("Перед вами стоит девушка среднего роста, облачённая в лёгкий вариант полевого снаряжения чёрного цвета с небольшими фиолетовыми отметинами на рукавах. Хоть вид и не внушает трепета, будьте уверены — она спуску никому не даст");
	OutputBlock("Не забыли о миссии? Кто скажет «забыл» — тому никакого обеда", "Капитан Камэо");

	vector options = { "Забыл", "Отряд саботажа не подведет?" };
	int sel = AskChoice("Что скажем?", options);

	if (sel == 1) {
		OutputBlock("Забыл. (Ехидная улыбка)", "Вы");
		OutputBlock("Сегодня голодаешь", "Капитан Камэо");
		OutputBlock("Да ну, кэп, вы же не серьёзно?", "Вы");
		OutputBlock("А как ты думаешь? (Небольшая ухмылка)", "Капитан Камэо");
		OutputBlock("Я...", "Вы");
	}
	else if (sel == 2) {
		OutputBlock("Отряд саботажа точно не подведёт? У меня дурное предчувствие...", "Вы");
		OutputBlock("Не знаю наверняка. Ожидание тяготит, а подобные сомнения только подкидывают уголь в котёл", "Капитан Камэо");
		OutputBlock("Надо было самим взять базуку, да как ****!", "Панк");
		OutputBlock("Знаешь, для снайпера очень странная фраза", "Вы");
		OutputBlock("А в чём я не прав?", "Панк");
	}

	OutputBlock("Ваши милые разговоры с товарищами прерывает гул металла — конвой приближается");
	OutputBlock("Многовато сопровождения, они бы всю армию сюда двинули", "Вы");
	OutputBlock("****! Я на такое не подписывался!", "Панк");
	OutputBlock("Вы зажимаете Панку рот рукой");
	OutputBlock("(Шёпотом) Свихнулся!? Дуралей ты штопанный", "Вы");
	OutputBlock("Некоторая часть конвоя останавливается совсем недалеко от вашей позиции");
	OutputBlock("(Шёпотом) Что делать-то будем?", "Вы");
	OutputBlock("Вы смотрите на капитана, все ещё прикрывая рот Панку, и, хоть она может показаться невозмутимой, вам кажется, что её одолевают какие‑то призраки прошлого");
	OutputBlock("Отряд саботажа хорошо сыграл свою роль, оправдав своё название", "Капитан Камэо");
	OutputBlock("Вы и Панк недоумённо смотрите на капитана");
	OutputBlock("Операция провалена, сваливаем", "Капитан Камэо");
	OutputBlock("Ч‑что?!", "Вы и Панк");
	OutputBlock("Шевел...", "Капитан Камэо");
	OutputBlock("Не дожидаясь команды капитана, непрошенные гости уже врываются в здание");
	OutputBlock("Бросайте оружие!", "Кто‑то из отряда врага");
	OutputBlock("В эту же секунду врывается высокий мужчина: солидный, в длинном полевом пальто с золотыми запонками, с белой бородой и усами, через один глаз у него проходит шрам — в общем, несомненно, это он отдаёт приказы этим воинам");
	OutputBlock("Рад встретиться с тобой, Камэо, или мне обращаться к тебе по званию?", "Грег");
}