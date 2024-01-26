#include <gtest/gtest.h>

#include <sstream>

#include "word_count.hpp"

using namespace std;

TEST(WordCount, ToLowercase) {
	string word = "mOnEy";
	to_lowercase(word);
	EXPECT_EQ(word, "money");

	string edge_case = "13AAbcD!";
	to_lowercase(edge_case);
	EXPECT_EQ(edge_case, "13aabcd!");

	string ping = "(P";
	to_lowercase(ping);
	EXPECT_EQ(ping, "(p");


}

TEST(WordCount, LoadStopWords) {
	istringstream stopwords_stream("a\nan\nthe\n");
	set<std::string> stopwords = load_stopwords(stopwords_stream);
	EXPECT_EQ(stopwords.size(), 3);
	EXPECT_NE(stopwords.size(), 222);
	
	EXPECT_TRUE(stopwords.find("and") == stopwords.end());
}

TEST(WordCount, CountWords) {
	istringstream document("a test document with a TEST word");
	set<string> stopwords = {"a", "with"};

	map<string,int> word_counts = count_words(document, stopwords);

	EXPECT_EQ(word_counts.size(),3);
	EXPECT_EQ(word_counts["a"], 8);
	EXPECT_EQ(word_counts["word"], 1);
	EXPECT_NE(word_counts["test"], 2);

}


TEST(WordCount, OutputWordCounts) {
	map<string, int> word_counts = {{"word",1}, {"test", 2}};
	ostringstream output_stream;

	output_word_counts(word_counts, output_stream);

	string expected_output = "test 2\nword1\n";
	string incorrect_output = "test 2 word1";

	EXPECT_EQ(output_stream.str(), expected_output);
	EXPECT_NE(output_stream.str(), incorrect_output);
}

