#pragma once
class Person {
	string name = "";
	string surname = "";
public:
	Person() = default;
	Person(string name, string surname) {
		setName(name);
		setSurname(surname);
	}
	void setName(string name) {
		if (name.size() >= 3) {
			this->name = name;
			return;
		}
		else throw exception("name is wrong!!");
	}
	void setSurname(string surname) {
		if (surname.size() >= 3) {
			this->surname = surname;
			return;
		}
		else throw exception("surname is wrong!!");
	}

	string getName() { return name; }
	string getSurname() { return surname; }

};
class Guest :public Person {
	float point = 0;
public:
	Guest() = default;
	Guest(string name, string surname, float point) :Person(name, surname) {
		setPoint(point);
	}
	void setPoint(float point) {
		this->point = point;
	}
	float getPoint() { return point; }
};

class Quiz {
	string question = "";
	string answer1 = "";
	string answer2 = "";
	string answer3 = "";
	string answer4 = "";
	string correct_answer = "";
public:
	Quiz() = default;
	Quiz(string questn, string ans_1, string ans_2, string ans_3, string ans_4, string correct) {
		setQuestion(questn);
		setAnswer_1(ans_1);
		setAnswer_2(ans_2);
		setAnswer_3(ans_3);
		setAnswer_4(ans_4);
		setCorrect(correct);
	}
	void setQuestion(string questn) {
		if (!questn.empty()) {
			this->question = questn;
			return;
		}
	}
	void setAnswer_1(string ans_1) {
		if (!ans_1.empty()) {
			this->answer1 = ans_1;
			return;
		}
	}
	void setAnswer_2(string ans_2) {
		if (!ans_2.empty()) {
			this->answer2 = ans_2;
			return;
		}
	}
	void setAnswer_3(string ans_3) {
		if (!ans_3.empty()) {
			this->answer3 = ans_3;
			return;
		}
	}
	void setAnswer_4(string ans_4) {
		if (!ans_4.empty()) {
			this->answer4 = ans_4;
			return;
		}
	}
	void setCorrect(string correct) {
		if (!correct.empty()) {
			this->correct_answer = correct;
			return;
		}
	}


	string getQuestion() { return question; };
	string getAnswer_1() { return answer1; };
	string getAnswer_2() { return answer2; };
	string getAnswer_3() { return answer3; };
	string getAnswer_4() { return answer4; };
	string getCorrect() { return correct_answer; };

};
class Quiz_name {
	string quiz_name = "";
public:
	Quiz_name() = default;
	Quiz_name(string name) {
		setName(name);
	}
	void setName(string name) {
		if (!name.empty()) {
			this->quiz_name = name;
			return;
		}
		else throw exception("Quiz name was wrong!");
	}
	string getQuiz_name() { return quiz_name; }

};
class Answer {
	string answer = "-";
public:
	Answer() = default;
	Answer(string answer) {
		setAnswer(answer);
	}
	void setAnswer(string answer) {
		if (!answer.empty()) {
			this->answer = answer;
			return;
		}
	}

	string getAnswer() { return answer; }

};
class Leader :public Guest, public Quiz_name {
	int total_count = 0;
	int true_count = 0;
	int false_count = 0;
public:
	Leader() = default;
	Leader(string name, string surname, string quiz_name, int total, int true_count, int false_count, float point)
		:Guest(name, surname, point), Quiz_name(quiz_name) {

		this->total_count = total;
		this->true_count = true_count;
		this->false_count = false_count;
	}
	int getTotal() { return total_count; }
	int getTrue() { return true_count; }
	int getFalse() { return false_count; }

	friend ostream& operator<<(ostream& print, Leader& leader) {
		print << "  " << leader.getName() << " " << leader.getSurname() << endl;
		print << "Quiz Name: " << leader.getQuiz_name() << endl;
		print << "Total Questions: " << leader.getTotal() << endl;
		print << "Correct Answers: " << leader.getTrue() << endl;
		print << "False Answers: " << leader.getFalse() << endl;
		print << "Success Degree: " << leader.getPoint() << "%" << endl;
		return print;
	}
};