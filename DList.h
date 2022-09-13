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
		List()
		{

		}

		
		List(List const& list)
		{
			Node* cur = list.m_head;
			for (size_t i = 0; i < list.m_size; i++, cur = cur->next)
			{
				T val = cur->val;
				PushBack(val);
			}
		}

		size_t Size() const
		{
			return m_size;
		}

		void PushBack(T data)
		{
			Node* newNode = new Node;
			newNode->val = data;

			if (m_size == 0)
			{
				m_head = m_tail = newNode;
			}
			else
			{
				m_tail->next = newNode;
				newNode->prev = m_tail;
				m_tail = newNode;
			}

			++m_size;
		}

		T PopBack()
		{
			if (m_size == 0) // empty!!
			{
				throw std::runtime_error("Unexpected operation - pop... ERROR.. list is empty!!");
			}

			T res = m_tail->val;

			Node* prevTail = m_tail->prev;
			if (prevTail != nullptr) // size != 1
			{
				prevTail->next = nullptr;
			}

			delete m_tail;
			m_tail = nullptr;
			m_tail = prevTail;
			--m_size;
			return res;
		}

		void Clear()
		{
			Node* cur = m_head;
			Node* prev = nullptr;
			for (size_t i = 0; i < m_size; i++, cur = cur->next)
			{
				if (prev != nullptr)
				{
					delete prev;
					prev = nullptr;
				}
				prev = cur;
			}
			if (prev != nullptr)
			{
				delete prev;
				prev = nullptr;
			}
			m_size = 0;
		}

		~List()
		{
			Clear();
		}
	};
}