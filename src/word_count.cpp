#include "word_count.hpp"

#include <algorithm>
#include <cctype>
#include <sstream>
#include <set>
#include <map>




void to_lowercase(std::string& str) {
	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::tolower(c); });

}

std::set<std::string> load_stopwords(std::istream& stopwords_stream) {

	std::set<std::string> stopwords;
	std::string word;

	while (stopwords_stream >> word){
		to_lowercase(word);
		stopwords.insert(word);
	}
	return stopwords;
}

std::map<std::string, int> count_words(std::istream& document, const std::set<std::string>&stopwords) {
	std::map<std::string, int> word_counts;
	std::string word;
	while (document >>word) {
		to_lowercase(word);
		if (stopwords.find(word) == stopwords.end()) {
			++word_counts[word];
		}
	}
	return word_counts;
}

void output_word_counts(const std::map<std::string, int>& word_counts, std::ostream& output) {
	for (const auto& pair : word_counts) {
		output << pair.first << " " << pair.second << "\n";
	}
}
