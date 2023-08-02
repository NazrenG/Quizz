#include<iostream>
#include<cassert>
#include<string>
#include<list>
#include<vector>
#include<conio.h>
#include<sstream>
#include<windows.h>
#include<fstream>
#include<algorithm>
using namespace std;



#include"class.h"
int  _count = 1;
#include"menu.h"

void submit(list<Answer>& answers, list<Quiz>& quizz,int question_count,string name,string surname, string choose_quiz_name,bool& check, bool& checkMap, bool& checkQUIZ) {
	int true_answer = 0, false_answer = 0;
	auto it1 = answers.begin();
	auto it2 = quizz.begin();

	while (it1 != answers.end() && it2 != quizz.end()) {
		if (it1->getAnswer() == it2->getCorrect()) {
			true_answer++;
		}
		else false_answer++;
		++it1;
		++it2;
	}

	ofstream fileLeader("FinalFile/quiz_leaderList.txt", ios::app);
	float success_degree = (true_answer * 100) /( question_count+1);
	fileLeader << "\n  " << name << ":" << surname << ":" << choose_quiz_name << ":" << question_count << " " << true_answer << " " << false_answer << " " << success_degree;
	fileLeader.flush();
	fileLeader.close();

	cout << "\n\t\t  PLAYER   : " << name << " " << surname << endl;
	cout << "\n\t\t | TOTAL | TRUE | FALSE |" << endl;
	cout << "\n\t\t ------------------------" << endl;
	cout << "\n\t\t |   " << question_count+1 << "  |  " << true_answer << "   |   " << false_answer << "   | ";
	Sleep(5000);

	check = false;
	checkMap = false;
	checkQUIZ = false;//proq bitti
	
}

void start_quiz(bool& check,bool& checkQUIZ,list<Answer>& answers, list<Quiz>& quizz, list<Person>& person) {
	_count = 1;
	system("cls");
	string name, surname;
	cout << "\t\t\t\t\t\t" << "Start to quiz" << "\n\n";
	cout << "\t\t\tEnter your name: ";
	getline(cin, name);
	cout << "\n\t\t\tEnter your surname: ";
	getline(cin, surname);
	try {
		person.push_back(Person(name, surname));
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
	ofstream file("FinalFile/quiz_guest.txt", ios::app);
	file << name << " " << surname << "\n";
	file.flush();
	file.close();

	ifstream file_2("FinalFile/quiz_name.txt", ios::in);
	if (!file_2) { assert(!"File was not found!"); }
	if (!file_2.is_open()) { assert(!"File was not opened!"); }
	string data, copy;

	while (!file_2.eof()) {
		getline(file_2, data);
		copy += data + "\n";

	}
	file_2.close();

	string choose_quiz_name;
	cout << "\n\n\t\t\t\t\t\t" << "All quiz name:" << "\n\n";
	cout << copy;

	cout << "\n\n\t\t\t\t\t\t" << "Write the quiz name:";
	getline(cin, choose_quiz_name);
	cout << "\n Press Enter...";

	ifstream file_3(choose_quiz_name, ios::in);
	if (!file_3) { assert(!"File was not found!"); }
	if (!file_3.is_open()) { assert(!"File was not opened!"); }

	int getch = _getch();
	int question_count = -1;
	if (getch == 13) {
		system("cls");
		string question, ans_1, ans_2, ans_3, ans_4, correct;
		while (!file_3.eof()) {
			getline(file_3, question, ':');
			getline(file_3, ans_1, ':');
			getline(file_3, ans_2, ':');
			getline(file_3, ans_3, ':');
			getline(file_3, ans_4, ':');
			getline(file_3, correct);

			quizz.push_back(Quiz(question, ans_1, ans_2, ans_3, ans_4, correct));
			question_count++;

		}
	}
	file_3.close();

	int select_map = 1, choose_get;

	bool checkMap = true;
	auto item = quizz.begin();
	map_start_quiz(select_map, item);
	while (checkMap) {

		choose_get = _getch();
		if (choose_get == 224) {
			choose_get = _getch();
			if (choose_get == 72) {
				if (select_map == 1) select_map = 6;
				else select_map--;
			}
			else if (choose_get == 80) {
				if (select_map == 6) select_map = 1;
				else select_map++;
			}

		}
		else if (choose_get == 13) {
			string select;
			if (select_map == 1) {
				select = "a";//a-ni secerse
				answers.push_back(item->getAnswer_1());

			}
			else if (select_map == 2) {
				select = "b";//b-ni secerse
				answers.push_back(item->getAnswer_2());

			}
			else if (select_map == 3) {
				select = "c";//c-ni secerse
				answers.push_back(item->getAnswer_3());

			}
			else if (select_map == 4) {
				select = "d";//d-ni secerse
				answers.push_back(item->getAnswer_4());

			}
			else if (select_map == 5) {//next
				select = "next";
				answers.push_back(Answer("-"));

			}
			else if (select_map == 6) {//submit
				select = "submit";
				
				if (_count <= question_count) {
					for (auto i = item; i != quizz.end(); i++)
					{
						answers.push_back(Answer("-"));
					}
				}
				submit(answers, quizz, question_count, name, surname, choose_quiz_name, check, checkMap, checkQUIZ);
				break;
			}
			if (_count > question_count) {
				submit(answers, quizz, question_count, name, surname, choose_quiz_name, check, checkMap, checkQUIZ);
				break;
			}
			map_select_variant(select, item);
		}
		map_start_quiz(select_map, item);
	}
}
bool compareDegree(Leader& l1, Leader& l2);
void leader_table(vector<Leader>& leaders,bool check) {
	system("cls");
	ifstream file_6("FinalFile/quiz_leaderList.txt", ios::in);
	if (!file_6) { assert(!"File was not found!"); }
	if (!file_6.is_open()) { assert(!"File was not opened!"); }

	string _name, _surname, _fileName;
	int _total, _true, _false;
	float _degree;
	while (!file_6.eof()) {
		getline(file_6, _name, ':');
		getline(file_6, _surname, ':');
		getline(file_6, _fileName, ':');
		file_6 >> _total;
		file_6 >> _true;
		file_6 >> _false;
		file_6 >> _degree;
		leaders.push_back(Leader(_name, _surname, _fileName, _total, _true, _false, _degree));
	}

	file_6.close();
	sort(leaders.begin(), leaders.end(), compareDegree);
	for (auto& i : leaders) {
		cout << i << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
	}

	cout << "\nPress ENTER...";
	

}
void createQuiz(list<Quiz_name>& quiz_names, int selectt, string& file_name, string& question, string& answer1, string& answer2, string& answer3, string& answer4, string& correct_answer) {

	system("cls");
	cout << "\t\t\t\t\t\tPlease enter quiz name: ";
	getline(cin, file_name);

	try {
		quiz_names.push_back(Quiz_name(file_name));
	}
	catch (exception& ex) {
		cout << ex.what();
	}

	bool check = true;//eyni adli fayli quiz_name-e yazmasin
	string fileNames;

	ifstream file("FinalFile/quiz_name.txt", ios::in);
	while (!file.eof()) {
		getline(file, fileNames);
		if (fileNames == file_name) check = false;
	}
	file.close();
	if (check) {
		ofstream file_1("FinalFile/quiz_name.txt", ios::app);
		file_1 << file_name << "\n";
		file_1.flush();
		file_1.close();
	}

	system("cls");

	cout << "\t\t\t\t\t\t" << file_name << "\n\n";
	cout << "\t\t\tEnter question: ";
	getline(cin, question);
	cout << "\n\t\t\tEnter answer 1: ";
	getline(cin, answer1);
	cout << "\n\t\t\tEnter answer 2: ";
	getline(cin, answer2);
	cout << "\n\t\t\tEnter answer 3: ";
	getline(cin, answer3);
	cout << "\n\t\t\tEnter answer 4: ";
	getline(cin, answer4);
	cout << "\n\t\t\tEnter correct answer: ";
	getline(cin, correct_answer);

	map_save_back_new(selectt, file_name, question, answer1, answer2, answer3, answer4, correct_answer);
}
bool compareDegree(Leader& l1, Leader& l2) {
	return l1.getPoint() > l2.getPoint();
}


int main() {
	list<Person> person;
	list<Quiz_name> quiz_names;
	list<Quiz> quizz;
	list<Answer> answers;
	vector<Leader> leaders;

	int choose, select = 1;
	bool checkQUIZ = true;
	map_1(select);
	while (checkQUIZ) {
		choose = _getch();
		if (choose == 224) {
			choose = _getch();
			if (choose == 72) {//player
				if (select == 1) select = 2;
				else select--;
			}
			else if (choose == 80) {//admin
				if (select == 2) select = 1;
				else select++;
			}
			map_1(select);
		}
		else if (choose == 13) {
			if (select == 1) {
				int select_2 = 1;
				map_2(select_2);
				bool check = true;
				// guest table=>start quiz, leader board,exit
				while (check) {
					choose = _getch();
					if (choose == 224) {
						choose = _getch();
						if (choose == 72) {
							if (select_2 == 1) select_2 = 3;
							else select_2--;
						}
						else if (choose == 80) {
							if (select_2 == 3) select_2 = 1;
							else select_2++;
						}
						map_2(select_2);
					}
					else if (choose == 13) {
						if (select_2 == 1) {//start quiz
							start_quiz(check, checkQUIZ, answers, quizz, person);

						}
						else if (select_2 == 2) {//leader board
							leader_table(leaders, check);
							int chose;
							chose = _getch();

							if (chose == 13) {
								map_2(select_2);//girise qayit
								check = false;
							}

						}
						else if (select_2 == 3) {//exit
							map_1(select);
							check = false;
						}
					}
				}
			}
			else if (select == 2) {
				int select_2 = 1;
				map_3(select_2);
				bool check = true;
				// admin table=>create quiz,start quiz, leader table,exit
				while (check) {
					choose = _getch();
					if (choose == 224) {
						choose = _getch();
						if (choose == 72) {
							if (select_2 == 1) select_2 = 4;
							else select_2--;
						}
						else if (choose == 80) {
							if (select_2 == 4) select_2 = 1;
							else select_2++;
						}
						map_3(select_2);
					}
					else if (choose == 13) {
						if (select_2 == 1) {//create quiz
							string question, answer1, answer2, answer3, answer4, correct_answer, file_name;

							system("cls");
							cout << "\t\t\t\t\t\tPlease enter quiz name: ";
							getline(cin, file_name);

							try {
								quiz_names.push_back(Quiz_name(file_name));
							}
							catch (exception& ex) {
								cout << ex.what();
							}

							bool check = true;//eyni adli fayli quiz_name-e yazmasin
							string fileNames;
							ifstream file_4("FinalFile/quiz_name.txt", ios::in);
							while (!file_4.eof()) {
								getline(file_4, fileNames);
								if (fileNames == file_name) check = false;
							}
							file_4.close();
							if (check) {
								ofstream file_5("FinalFile/quiz_name.txt", ios::app);
								file_5 << file_name << "\n";
								file_5.flush();
								file_5.close();
							}

							system("cls");

							cout << "\t\t\t\t\t\t" << file_name << "\n\n";
							cout << "\t\t\tEnter question: ";
							getline(cin, question);
							cout << "\n\t\t\tEnter answer 1: ";
							getline(cin, answer1);
							cout << "\n\t\t\tEnter answer 2: ";
							getline(cin, answer2);
							cout << "\n\t\t\tEnter answer 3: ";
							getline(cin, answer3);
							cout << "\n\t\t\tEnter answer 4: ";
							getline(cin, answer4);
							cout << "\n\t\t\tEnter correct answer(full name): ";
							getline(cin, correct_answer);

							int selectt = 1, choosee;
							bool check_1 = true;
							map_save_back_new(selectt, file_name, question, answer1, answer2, answer3, answer4, correct_answer);
							while (check_1) {// new save  back
								choosee = _getch();
								if (choosee == 224) {
									choosee = _getch();
									if (choosee == 72) {
										if (selectt == 1) selectt = 3;
										else selectt--;
									}
									else if (choosee == 80) {
										if (selectt == 3) selectt = 1;
										else selectt++;
									}
									map_save_back_new(selectt, file_name, question, answer1, answer2, answer3, answer4, correct_answer);
								}
								else if (choosee == 13) {
									if (selectt == 2) {//save

										ofstream file(file_name, ios::app);
										file << question << ":" << answer1 << ":" << answer2 << ":" << answer3 << ":" << answer4 << ":" << correct_answer << "\n";
										file.flush();
										file.close();
										cout << "\n QUIZ WAS SAVED!!!";
										Sleep(3100);
										check_1 = false;
										map_3(select_2);//admin table-a qayit
									}
									else if (selectt == 3) {//back

										cout << "\n QUIZ WAS NOT SAVED!!!";
										Sleep(3100);
										check_1 = false;
										map_3(select_2);//admin table-a qayit
									}
									else if (selectt == 1) {//new
										ofstream file(file_name, ios::app);
										file << question << ":" << answer1 << ":" << answer2 << ":" << answer3 << ":" << answer4 << ":" << correct_answer << "\n";
										file.flush();
										file.close();
										cout << "\n QUIZ WAS SAVED AND CREATE ANOTHER ONE!!!";
										Sleep(3100);
										createQuiz(quiz_names, selectt, file_name, question, answer1, answer2, answer3, answer4, correct_answer);

									}
								}
							}

						}
						else if (select_2 == 2) {//start quiz
							start_quiz(check, checkQUIZ, answers, quizz, person);


						}
						else if (select_2 == 3) {//leader board
						leader_table(leaders, check);
							int chose;
							chose = _getch();

							if (chose == 13) {
								map_1(select);//girise qayit
								check = false;
							}

						}
						else if (select_2 == 4) {//exit
							map_1(select);//girise qayit
							check = false;
						}
					}
				}
			}
		}
	}

}

