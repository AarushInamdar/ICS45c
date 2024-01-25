#include <fstream>
#include "word_count.hpp"
#include <set>

int main(){
	std::ifstream stopwords_file("stopwords.txt");
	const std::set<std::string> stopwords = load_stopwords(stopwords_file);

	std::ifstream document("sample_doc.txt");
	const auto word_counts= count_words(document, stopwords);

	std::ofstream output("frequency.txt");
	output_word_counts(word_counts,output);
}
