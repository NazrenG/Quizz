#pragma once



int count = 1;
void map_1(int select) {
	system("cls");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\t\tWELCOME TO QUIZ\n\n";
	if (select == 1) {
		cout << "\t\t\t\t\t\t=> Player" << endl;
		cout << "\t\t\t\t\t\t Admin" << endl;
	}
	else if (select == 2) {
		cout << "\t\t\t\t\t\t Player" << endl;
		cout << "\t\t\t\t\t\t=> Admin" << endl;
	}
}
void map_2(int select_2) {
	system("cls");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\t\tGUEST TABLE\n\n";
	if (select_2 == 1) {
		cout << "\t\t\t\t\t\t=> Start to quiz" << endl;
		cout << "\t\t\t\t\t\t Leader board " << endl;
		cout << "\t\t\t\t\t\t Exit " << endl;
	}
	else if (select_2 == 2) {
		cout << "\t\t\t\t\t\t Start to quiz" << endl;
		cout << "\t\t\t\t\t\t=> Leader board" << endl;
		cout << "\t\t\t\t\t\t Exit " << endl;
	}
	else if (select_2 == 3) {
		cout << "\t\t\t\t\t\t Start to quiz" << endl;
		cout << "\t\t\t\t\t\t Leader board" << endl;
		cout << "\t\t\t\t\t\t=> Exit " << endl;
	}
}
void map_3(int select_2) {
	system("cls");
	cout << "\n\n\n\n";
	cout << "\t\t\t\t\t\tADMIN TABLE\n\n";
	if (select_2 == 1) {
		cout << "\t\t\t\t\t\t=> Create quiz" << endl;
		cout << "\t\t\t\t\t\t Start to quiz" << endl;
		cout << "\t\t\t\t\t\t Leader board " << endl;
		cout << "\t\t\t\t\t\t Exit " << endl;
	}
	else if (select_2 == 2) {
		cout << "\t\t\t\t\t\t Create quiz" << endl;
		cout << "\t\t\t\t\t\t=> Start to quiz" << endl;
		cout << "\t\t\t\t\t\t Leader board" << endl;
		cout << "\t\t\t\t\t\t Exit " << endl;
	}
	else if (select_2 == 3) {
		cout << "\t\t\t\t\t\t Create quiz" << endl;
		cout << "\t\t\t\t\t\t Start to quiz" << endl;
		cout << "\t\t\t\t\t\t=> Leader board" << endl;
		cout << "\t\t\t\t\t\t Exit " << endl;
	}
	else if (select_2 == 4) {
		cout << "\t\t\t\t\t\t Create quiz" << endl;
		cout << "\t\t\t\t\t\t Start to quiz" << endl;
		cout << "\t\t\t\t\t\t Leader board" << endl;
		cout << "\t\t\t\t\t\t=> Exit " << endl;
	}
}
void map_save_back_new(int selectt, string file_name, string question, string answer1, string answer2, string answer3, string answer4, string correct_answer) {
	cout << "\n\n";
	system("cls");
	cout << "\t\t\t\t\t\t" << file_name << "\n\n";
	cout << "\t\t\tEnter question: " << question;
	cout << "\n\n\t\t\tEnter answer 1: " << answer1;
	cout << "\n\n\t\t\tEnter answer 2: " << answer2;
	cout << "\n\n\t\t\tEnter answer 3: " << answer3;
	cout << "\n\n\t\t\tEnter answer 4: " << answer4;
	cout << "\n\n\t\t\tEnter correct answer: " << correct_answer;
	if (selectt == 1) {

		cout << "\n\n\t\t=>[1]NEW\n\n\t\t[2]SAVE\n\n\t\t[3]BACK" << endl;
	}
	else if (selectt == 2) {

		cout << "\n\n\t\t[1]NEW\n\n\t\t=>[2]SAVE\n\n\t\t[3]BACK" << endl;
	}
	else if (selectt == 3) {

		cout << "\n\n\t\t[1]NEW\n\n\t\t[2]SAVE\n\n\t\t=>[3]BACK" << endl;
	}

}
void map_select_variant(string select, list<Quiz>::iterator& item) {
	system("cls");
	cout << "Question " << _count << ": " << item->getQuestion() << endl;
	if (select == "a") {
		cout << "~~ a) " << item->getAnswer_1() << " ~~" << endl;
		cout << "b) " << item->getAnswer_2() << endl;
		cout << "c) " << item->getAnswer_3() << endl;
		cout << "d) " << item->getAnswer_4() << endl;
		cout << "\n------------------------------" << endl;
		cout << "\n[1]NEXT";
		cout << "\n[2]SUBMIT";
		_count++;
		*item++;
		
		cout << "\n\tYour select variant A);" << endl;
		cout << "\nNext question is loading....";
		Sleep(1500);

	}
	else if (select == "b") {
		cout << "a) " << item->getAnswer_1() << endl;
		cout << "~~ b) " << item->getAnswer_2() << " ~~" << endl;
		cout << "c) " << item->getAnswer_3() << endl;
		cout << "d) " << item->getAnswer_4() << endl;
		cout << "\n------------------------------" << endl;
		cout << "\n[1]NEXT";
		cout << "\n[2]SUBMIT";
		_count++;
		*item++;
		
		cout << "\n\tYour select variant B);" << endl;
		cout << "\nNext question is loading....";
		Sleep(1500);
	}
	else if (select == "c") {//c-ni secerse
		cout << "a) " << item->getAnswer_1() << endl;
		cout << "b) " << item->getAnswer_2() << endl;
		cout << "~~ c) " << item->getAnswer_3() << " ~~" << endl;
		cout << "d) " << item->getAnswer_4() << endl;
		cout << "\n------------------------------" << endl;
		cout << "\n[1]NEXT";
		cout << "\n[2]SUBMIT";
		_count++;
		*item++;
		
		cout << "\n\tYour select variant C);" << endl;
		cout << "\nNext question is loading....";
		Sleep(1500);
	}
	else if (select == "d") {//d-ni secerse
		cout << "a) " << item->getAnswer_1() << endl;
		cout << "b) " << item->getAnswer_2() << endl;
		cout << "c) " << item->getAnswer_3() << endl;
		cout << "~~ d) " << item->getAnswer_4() << " ~~" << endl;
		cout << "\n------------------------------" << endl;
		cout << "\n[1]NEXT";
		cout << "\n[2]SUBMIT";
		_count++;
		*item++;
		
		cout << "\n\tYour select variant D);" << endl;
		cout << "\nNext question is loading....";
		Sleep(1500);
	}
	else if (select == "next") {//next
		cout << "a) " << item->getAnswer_1() << endl;
		cout << "b) " << item->getAnswer_2() << endl;
		cout << "c) " << item->getAnswer_3() << endl;
		cout << "d) " << item->getAnswer_4() << endl;
		cout << "\n------------------------------" << endl;
		cout << "\n~~ [1]NEXT" << " ~~";
		cout << "\n[2]SUBMIT";
		_count++;
		*item++;
		
		cout << "\n\tYour select  NEXT ;" << endl;
		cout << "\nNext question is loading....";
		Sleep(1500);

	}
	else if (select == "submit") {//submit
		cout << "a) " << item->getAnswer_1() << endl;
		cout << "b) " << item->getAnswer_2() << endl;
		cout << "c) " << item->getAnswer_3() << endl;
		cout << "d) " << item->getAnswer_4() << endl;
		cout << "\n------------------------------" << endl;
		cout << "\n[1]NEXT";
		cout << "\n~~ [2]SUBMIT" << " ~~";

		cout << "\n\nQuiz is FINISH....";
		Sleep(1500);
	}

}

void map_start_quiz( int& select, list<Quiz>::iterator& item) {
	system("cls");

	cout << "Question " << _count << ": " << item->getQuestion() << endl;

	if (select == 1) {
		cout << "=>a) " << item->getAnswer_1() << endl;
		cout << "b) " << item->getAnswer_2() << endl;
		cout << "c) " << item->getAnswer_3() << endl;
		cout << "d) " << item->getAnswer_4() << endl;
		cout << "\n------------------------------" << endl;
		cout << "\n[1]NEXT";
		cout << "\n[2]SUBMIT";
	}
	else if (select == 2) {
		cout << "a) " << item->getAnswer_1() << endl;
		cout << "=>b) " << item->getAnswer_2() << endl;
		cout << "c) " << item->getAnswer_3() << endl;
		cout << "d) " << item->getAnswer_4() << endl;
		cout << "\n------------------------------" << endl;
		cout << "\n[1]NEXT";
		cout << "\n[2]SUBMIT";
	}
	else if (select == 3) {
		cout << "a) " << item->getAnswer_1() << endl;
		cout << "b) " << item->getAnswer_2() << endl;
		cout << "=>c) " << item->getAnswer_3() << endl;
		cout << "d) " << item->getAnswer_4() << endl;
		cout << "\n------------------------------" << endl;
		cout << "\n[1]NEXT";
		cout << "\n[2]SUBMIT";
	}
	else if (select == 4) {
		cout << "a) " << item->getAnswer_1() << endl;
		cout << "b) " << item->getAnswer_2() << endl;
		cout << "c) " << item->getAnswer_3() << endl;
		cout << "=>d) " << item->getAnswer_4() << endl;
		cout << "\n------------------------------" << endl;
		cout << "\n[1]NEXT";
		cout << "\n[2]SUBMIT";
	}
	else if (select == 5) {
		cout << "a) " << item->getAnswer_1() << endl;
		cout << "b) " << item->getAnswer_2() << endl;
		cout << "c) " << item->getAnswer_3() << endl;
		cout << "d) " << item->getAnswer_4() << endl;
		cout << "\n------------------------------" << endl;
		cout << "\n=>[1]NEXT";
		cout << "\n[2]SUBMIT";
	}
	else if (select == 6) {
		cout << "a) " << item->getAnswer_1() << endl;
		cout << "b) " << item->getAnswer_2() << endl;
		cout << "c) " << item->getAnswer_3() << endl;
		cout << "d) " << item->getAnswer_4() << endl;
		cout << "\n------------------------------" << endl;
		cout << "\n[1]NEXT";
		cout << "\n=>[2]SUBMIT";
	}
	

}
