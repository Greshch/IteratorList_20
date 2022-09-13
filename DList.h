#pragma once

namespace util
{
	
	template<class T>
	class List
	{
	private:
		struct Node
		{
			T val = {};
			Node* prev = nullptr;
			Node* next = nullptr;
		};

	private:
		Node* m_head = nullptr;
		Node* m_tail = nullptr;
		size_t m_size = 0;

	public:
		List();
		List(size_t size, int val);
		List(List const& list);
		size_t Size() const;
		void PushBack(int data);
		int PopBack();
		void Clear();
		~List();
	};
}