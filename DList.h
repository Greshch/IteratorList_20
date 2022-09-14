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
		class IteratorImpl
		{
		public:
			IteratorImpl(Node* ihead, Node* itail):
				m_ihead(ihead),
				m_itail(itail)
			{}

			T& operator*() const
			{
				return m_ihead->val;
			}

			bool operator != (IteratorImpl const& obj)
			{
				return m_ihead != obj.m_ihead;
			}

			IteratorImpl& operator++()
			{
				if (m_ihead == m_itail)
				{
					m_ihead = nullptr;
				}
				else
				{
					m_ihead = m_ihead->next;
				}
				
				return *this;
			}

		private:
			Node* m_ihead = nullptr;
			Node* m_itail = nullptr;
		};

	private:
		Node* m_head = nullptr;
		Node* m_tail = nullptr;
		size_t m_size = 0;

	public:

		typedef IteratorImpl Iterator;

		List() = default;

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

		Iterator Begin() const
		{
			return IteratorImpl(m_head, m_tail);
		}

		Iterator End() const
		{
			return IteratorImpl(nullptr, m_tail);
		}
	};
}