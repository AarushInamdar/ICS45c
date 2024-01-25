#include <fstream>

#include "word_count.hpp"
#include "word_count.cpp"


int main(){
	std::ifstream stopwords_file("stopwords.txt");
	const auto stopwords = load_stopwords(stopwords_file);

	std::ifstream document("sample_doc.txt");
	const auto word_counts= count_words(document, stopwords);

	std::ofstream output("frequency.txt");
	output_word_counts(word_counts,output);
}
