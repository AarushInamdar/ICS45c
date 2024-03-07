#include<iostream>
#include <iosfwd>
#include <map>
#include <set>
#include <string>
#include <iterator>
#include <vector>

std::string to_lowercase(const std::string& str) {
	std::string newstr(str);
	std::transform(newstr.begin(), newstr.end(), newstr.begin(), [](char c) {return std::tolower(static_cast<unsigned char>(c));});
	return newstr;
}

std::set<std::string> load_stopwords(std::istream& stopwords) {
	
	std::set<std::string> stopwordsSet;
	
	std::for_each(std::istream_iterator<std::string>(stopwords), std::istream_iterator<std::string>(), [&stopwordsSet](const std::string& word) {stopwordsSet.insert(to_lowercase(word));});
	
	return stopwordsSet;

}

std::map<std::string, int> count_words(std::istream& document, const std::set<std::string>& stopwords) {
	std::map<std::string, int> myMap;

	std::vector<std::string> allWords;
	std::string word;


	std::for_each(std::istream_iterator<std::string>(document), std::istream_iterator<std::string>(), [&allWords](const std::string& word) {allWords.push_back(to_lowercase(word));});
	
	std::sort(allWords.begin(), allWords.end());

	for (auto& word : allWords) {
		if (stopwords.find(to_lowercase(word)) == stopwords.end()) {//fix so that it doesnt include stopwords (its doing the opposite)
			myMap[word]++;
		}
	}
	return myMap;
}

void output_word_counts(const std::map<std::string, int>& word_counts, std::ostream& output) {
	for (const auto& [word, count] : word_counts) {
		output << word << ' ' << count << std::endl;
	}
}
