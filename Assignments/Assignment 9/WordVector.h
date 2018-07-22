/*************************************************************************************
 * Name        : WordVector.h
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to Vector functionality
 *************************************************************************************/

#ifndef WORDVECTOR_H_
#define WORDVECTOR_H_

#include <vector>
#include "TimedContainer.h"
#include "Word.h"

using namespace std;

/**
 * A sorted vector implementation for the concordance
 * that inherits a timer.
 */
class WordVector : public vector<Word>, public TimedContainer
{
public:
    /**
     * Default constructor.
     */
    WordVector();

    /**
     * Destructor.
     */
    virtual ~WordVector();

    /**
     * Insert a new word into the sorted vector,
     * or increment the count of an existing word.
     * Time this operation.
     * @param text the text of the word to insert or increment.
     */
    void insert(const string text);

    /**
     * Search the vector for a word entry with the given text.
     * Time this operation.
     * @param text the text of the word to find.
     * @return an iterator pointing to the word entry if found,
     *         or data.end() if not.
     */
    vector<Word>::iterator search(const string text);

    /**
     * Overloaded [] operator that returns
     * a reference to a Word element.
     * @param index the index of the element to return.
     * @return a reference to the element.
     */
    Word& operator[](const int index);

    int size();

private:
    /**
     * Helper function that performs a binary search of the sorted vector.
     * @param text the text of the target word.
     * @param low the lower index of the subrange to search.
     * @param high the upper index of the subrange to search.
     */
    int find(const string text, int low, int high) const;

    vector<Word> wordVector;
};

#endif /* WORDVECTOR_H_ */
