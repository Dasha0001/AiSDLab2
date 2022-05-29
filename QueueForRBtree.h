#ifndef QUEUEFORRBTREE
#pragma once
#include "RBTreeRealisation.h"
template<typename T>



template <typename T>
class Queue : public Node_List<T>
{
public:
	Node_List<T>::Clear;

	Node_List<T>::GetSize;

	void PushFront(T element) override
	{
		throw logic_error("Queue structure has no access to execute PushFront");
	}

	Node_List<T>::PushBack;

	void PushIndex(int index, T element) override
	{
		if (index == GetSize()) PushBack(element);
		else throw logic_error("In queue structure pushing index can only be the last one");
		return;
	}

	void Push(T element) override
	{
		PushBack(element);
		return;
	}

	Node_List<T>::PopFront;

	void PopBack() override
	{
		throw logic_error("Queue structure has no access to execute PopBack");
	}

	void PopIndex(int index) override
	{
		if (index == 0) PopFront();
		else throw logic_error("In queue structure popping index can only be zero");
		return;
	}

	void Pop() override
	{
		PopFront();
		return;
	}

	Node_List<T>::GetData;

	Node_List<T>::PrintData;
};

static void quickSortForQueue(int* weight, char* elem, size_t size) {
	if (size > 0) {
		int start = 0; 
		int end = size - 1;
		int val = weight[rand() % size]; 
		do {
			while (weight[start] > val) { start++; }
			while (weight[end] < val){ end--; }
			if (start <= end) {swap(weight[start], weight[end]);
				swap(elem[start], elem[end]);
				start++;
				end--;
			}
		} while (start <= end);

		if (start < size) 
			quickSortForQueue(weight + start, elem + start, size - start);
		if (end > 0) 
			quickSortForQueue(weight, elem, ++end);
	}
}

#endif // !QUEUEFORRBTREE
