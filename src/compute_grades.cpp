#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <stdexcept>
#include <iomanip>
#include <numeric>
#include "compute_grades.hpp"

void Student::validate() const {
	std::for_each(this->quiz.begin(), this->quiz.end(), [](int q) {
		if(q <0 || q >100){
			throw std::domain_error("Error: invalid percentage " + std::to_string(q));
		}
	});
	

	std::for_each(this->hw.begin(), this->hw.end(), [](int q){
		if(q <0 || q >100){
			throw std::domain_error("Error: invalid percentage " + std::to_string(q));
		}
	});

	if(this->final_score < 0 || this->final_score > 100){
		throw std::domain_error("Error: invalid percentage " + std::to_string(this->final_score));
	}

}

std::strong_ordering Student operator<=>(Student const&) const {
	
}

bool Student::operator==(const Student& other) const {
	return (this->course_score == other.course_score) ? true : false;
}

std::istream& operator>>(std::istream& in, Student& s) {
	std::string line;
	std::vector<std::string> lines;

	while (std::getline(in, line) && !line.empty()) {
		lines.push_back(line);
	}

	std::for_each(lines.begin(), lines.end(), [&s](const std::string& line) {
		std::istringstream iss(line);
		std::string key;
		iss >> key;
		if (key=="Name") {
			iss >> s.first_name >> std::ws;
			std::getline(iss,s.last_name);
		} else if (key == "Quiz") {
			s.quiz = std::vector<int>(std::istream_iterator<int>(iss), std::istream_iterator<int>());
			} else if (key == "HW") {
				s.hw = std::vector<int>{std::istream_iterator<int>(iss), std::istream_iterator<int>()};
				} else if (key == "Final") {
				iss >> s.final_score;
			}
		});
	s.compute_grade();
	return in;
	
}

std::ostream& operator<<(std::ostream& out, const Student& s) {
	out << std::left << std::setw(8) << "Name:" << s.first_name << " " << s.last_name << "\n"<< std::setw(8) <<"HW Ave:" << std::fixed << std::setprecision(2) << s.hw_avg << "\n" <<std::setw(8) << "QZ Ave: " << std::fixed << std::setprecision(2) <<s.quiz_avg << "\n" <<std::setw(8) << "Final:" << s.final_score << "\n" << std::setw(8) <<"Total:" << s.course_score << "\n" << std::setw(8) << "Grade:" << s.course_grade << "\n" << "\n";
	std::cout << "Operator << is logged for Student class\n";
	return out;
}

void Student::compute_quiz_avg() {
	if(this->quiz.empty()) {
		return;
	}
	bool pluralScores = this->quiz.size() >=2;

	int minEl = -1;

	if (pluralScores) {
		minEl = this->quiz[0];
		std::for_each(this->quiz.begin(),this->quiz.end(), [&] (int q) {if (minEl >= q) {
			minEl = q;
		}
		});
	}
	int currSum = 0;

	std::for_each(this->quiz.begin(), this->quiz.end(), [&] (int q) {
		if(minEl != q){
			currSum += q;
		}
	});

	if(pluralScores){
		this->quiz_avg = currSum/(this->quiz.size() - 1);
	}else{
		this->quiz_avg = currSum/this->quiz.size();
	}
}

void Student::compute_hw_avg() {
	int currSum = 0;
	std::for_each(this->hw.begin(), this->hw.end(), [&](int q) {
		currSum += q;
	});
	this->hw_avg = currSum/this->hw.size();
}

void Student::compute_course_score() {
	this->compute_hw_avg();
	this->compute_quiz_avg();
	this->course_score = (int) (0.4 * this->quiz_avg + 0.3 * this->hw_avg + 0.3*this->final_score + 0.5);
}

void Student::compute_grade() {
	this->compute_course_score();
	std::string grade;
	int cs = this->course_score;
	if(cs >= 97){
		grade = "A+";
	}else if(cs >= 93){
		grade = "A";
	}else if(cs >= 90){
		grade = "A-";
	}else if(cs >= 87){
		grade = "B+";
	}else if(cs >= 83){
		grade = "B";
	}else if(cs >= 80){
		grade = "B-";
	}else if(cs >= 77){
		grade = "C+";
	}else if(cs >= 73){
		grade = "C";
	}else if(cs >= 70){
		grade = "C-";
	}else if(cs >= 67){
		grade = "D+";
	}else if(cs >= 63){
		grade = "D";
	}else if(cs >= 60){
		grade = "D-";
	}else{
		grade = "F";
	}

	this->course_grade = grade;

}


void Gradebook::compute_grades(){

}

void Gradebook::sort(){

}

void Gradebook::validate() const{

}

std::istream& operator>>(std::istream& in, Gradebook& g ) {
	while (in.peek() !=EOF) {
		Student student;
		in >> student;
		if (in) {
			g.students.push_back(student);
		}
	}
	return in;
}

std::ostream& operator<<(std::ostream& out, const Gradebook& g) {
	for (const Student& s : g.students) {
		std::cout << "logging for student " << std::endl;
		out << s;
	}
	;
	return out;
}

