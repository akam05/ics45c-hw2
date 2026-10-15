#include "word_count.hpp"
#include <cctype>
#include <iostream>

using namespace std;

void to_lowercase(string& str)
{
    for (char& c : str)
    {
        c = tolower(static_cast<unsigned char>(c));
    }
}

set<string> load_stopwords(istream& stopwords)
{
    set<string> words;
    string word;

    while (stopwords >> word)
    {
        to_lowercase(word);
        words.insert(word);
    }
    return words;
}

map<string, int> count_words(istream& document, const set<string>& stopwords)
{
    map<string, int> word_counts;
    string word;

    while (document >> word)
    {
        to_lowercase(word);

        if (stopwords.find(word) == stopwords.end())
        {
            ++word_counts[word];
        }
    }
    return word_counts;
}

void output_word_counts(const map<string, int>& word_counts, ostream& output)
{
	for (auto E: word_counts)
	{
		output << E.first << ' ' << E.second << endl;
	}
}
