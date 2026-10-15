// ------------------------- Your tests - student_gtests.cpp ----------------------------- //
// Your own GoogleTest suite for the word_count module. It is graded: the autograder runs it
// against a correct implementation and against several with one bug each. A test is worth
// something only when it passes on the correct implementation and fails on a broken one, so a
// test that always fails (or that tests nothing) earns nothing.
//
// Two examples are given. Add tests of your own for to_lowercase, load_stopwords, count_words
// and output_word_counts, and for the edges: an empty document, a document that is all stop
// words, stop words written in mixed case, and the same word in several cases.
// --------------------------------------------------------------------------------------- //

#include <gtest/gtest.h>
#include <sstream>
#include "word_count.hpp"

using namespace std;

TEST(WordCountTests, StopwordsAreLoadedCaseInsensitively) {
    stringstream stopwords{"The OVER\n"};
    const auto loaded = load_stopwords(stopwords);
    EXPECT_TRUE(loaded.contains("the"));
    EXPECT_TRUE(loaded.contains("over"));
}

TEST(WordCountTests, WordsAreCountedCaseInsensitively) {
    stringstream document{"Apple apple APPLE pear"};
    const auto counts = count_words(document, {});
    EXPECT_EQ(counts.at("apple"), 3);
    EXPECT_EQ(counts.at("pear"), 1);
}

// ADD YOUR TESTS HERE:
TEST(WordCountTests, ToLowercase)
{
	string text = "TEst";
	to_lowercase(text);

	EXPECT_EQ(text, "test");
}

TEST(WordCountTests, StopWords)
{
	stringstream document{"testing the testing document way too late"};
	set<string> stopwords{"the", "way", "too"};
	const auto counts = count_words(document, stopwords);

	EXPECT_EQ(counts.at("testing"), 2);
	EXPECT_EQ(counts.at("late"), 1);
	EXPECT_EQ(counts.at("document"), 1);
	EXPECT_FALSE(counts.contains("the"));
	EXPECT_FALSE(counts.contains("way"));
	EXPECT_FALSE(counts.contains("too"));
}

TEST(WordCountTests, EmptyDocument)
{
	stringstream document{""};
	const auto counts = count_words(document, {});

	EXPECT_TRUE(counts.empty());
}

TEST(WordCountTests, AllWordsAreStopWords)
{
	stringstream document{"TEST test testing"};
	set<string> stopwords{"test", "testing"};

	const auto counts = count_words(document, stopwords);
	
	EXPECT_TRUE(counts.empty());
}
