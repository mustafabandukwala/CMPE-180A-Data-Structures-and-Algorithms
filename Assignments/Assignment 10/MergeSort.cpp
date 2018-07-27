/**************************************************************************
 * Name        : MergeSort.cpp
 * Author      : Mustafa Bandukwala
 * Version     : 1.0
 * Description : File which contains various functions related to MergeSort
 **************************************************************************/

#include <string>
#include "MergeSort.h"
#include "LinkedList.h"

MergeSort::MergeSort() : ListSorter("Mergesort") {}

MergeSort::~MergeSort() {}

void MergeSort::run_sort_algorithm() throw(string)
		{
	// Defensive programming: Make sure we end up
	// with the same size list after sorting.
	int size_before = data.get_size();

	mergesort(data);

	// Check sizes.
	int size_after = data.get_size();
	if (size_before != size_after)
	{
		string message = "***** Size mismatch: before " +
				to_string(size_before) + ", size after " +
				to_string(size_after);
		throw message;
	}
		}

void MergeSort::mergesort(LinkedList& list)
{
	LinkedList subList1;
	LinkedList subList2;
	while(list.get_head()!=list.get_tail()){
		list.split(subList1,subList2);
	}
	if(subList1.get_size()!=0)
		mergesort(subList1);

	if(subList2.get_size()!=0)
		mergesort(subList2);

	merge(list, subList1, subList2);
}

void MergeSort::merge(LinkedList& list,
		LinkedList& sublist1, LinkedList& sublist2)
{
	if(sublist1.get_head()!=nullptr && sublist2.get_head()!=nullptr){
		while(sublist1.get_head()!=nullptr && sublist2.get_head()!=nullptr){
			if(sublist1.get_head()->element < sublist2.get_head()->element){
				list.add(sublist1.remove_head());
			}else{
				list.add(sublist2.remove_head());
			}
			Sorter::compare_count++;
		}
	}else if(sublist1.get_head()==nullptr && sublist2.get_head()!=nullptr){
		list.concatenate(sublist2);
	}else if(sublist1.get_head()!=nullptr && sublist2.get_head()==nullptr){
		list.concatenate(sublist1);
	}

	if(sublist1.get_head()==nullptr && sublist2.get_head()!=nullptr){
		list.concatenate(sublist2);
	}else if(sublist1.get_head()!=nullptr && sublist2.get_head()==nullptr){
		list.concatenate(sublist1);
	}
}

void MergeSort::clear()
{
	data.clear();
}
