#pragma once
template <typename T>
class CLinkedListNode
{

	template <typename T>
	friend class CLinkedList;
	template <typename T>
	friend class CLinkedListIterator;


private:
	CLinkedListNode()
	{
		m_pNext = nullptr;
		m_pPrev = nullptr;
	}
	~CLinkedListNode()
	{

	}
private:
	CLinkedListNode<T>* m_pNext;
	CLinkedListNode<T>* m_pPrev;
	T m_Data;
};

template <typename T>
class CLinkedListIterator
{
	template <typename T>
	friend class CLinkedList;
public:
	CLinkedListIterator()
	{
		m_pNode = nullptr;
	}
	~CLinkedListIterator()
	{

	}
	void operator ++(void)
	{
		m_pNode = m_pNode->m_pNext;
	}
	void operator ++(int)
	{
		m_pNode = m_pNode->m_pNext;
	}
	void operator --(void)
	{
		m_pNode = m_pNode->m_pPrev;
	}
	void operator --(int)
	{
		m_pNode = m_pNode->m_pPrev;
	}
	T& operator *(void)
	{
		return m_pNode->m_Data;
	}
	bool operator !=(const CLinkedListIterator<T>& iter)
	{
		return m_pNode != iter.m_pNode;
	}
	bool operator ==(const CLinkedListIterator<T>& iter)
	{
		return m_pNode == iter.m_pNode;
	}
private:
	typedef CLinkedListNode<T>* PNODE;
	typedef CLinkedListNode<T>* NODE;

private:
	PNODE m_pNode;
};
template <typename T>
class CLinkedList
{


public:
	CLinkedList()
	{
		//더미노드 초기화
		m_iSize = 0;
		m_Begin = new NODE;
		m_End = new NODE; 
		m_Begin->m_pNext = m_End;
		m_End->m_pPrev = m_Begin;
	}
	~CLinkedList()
	{
		clear();
		delete m_Begin;
		delete m_End;
	}
public:
	typedef CLinkedListIterator<T> iterator;

public:

	void push_front(const T& data)
	{
		PNODE pNewNode = new NODE;
		pNewNode->m_Data = data;

		PNODE pNext = m_Begin->m_pNext;

		pNewNode->m_pNext = pNext;
		pNext->m_pPrev = pNewNode;

		m_Begin->m_pNext = pNewNode;
		pNewNode->m_pPrev = m_Begin;
		++m_iSize;
	}
	void push_back(const T& data)
	{
		PNODE pNewNode = new NODE;
		pNewNode->m_Data = data;

		PNODE pPrev = m_End->m_pPrev;
		pPrev->m_pNext = pNewNode;
		pNewNode->m_pPrev = pPrev;

		pNewNode->m_pNext = m_End;
		m_End->m_pPrev = pNewNode;
		++m_iSize;
	}
	
	iterator erase(iterator& iter)
	{
		PNODE pPrev = iter.m_pNode->m_pPrev;
		PNODE pNext = iter.m_pNode->m_pNext;

		delete iter.m_pNode;

		pPrev->m_pNext = pNext;
		pNext->m_pPrev = pPrev;
		m_iSize--;

		iterator rtniter;
		rtniter.m_pNode = pNext;

		return rtniter;
	}
	iterator erase(const T& data)
	{
		iterator iter;
		iterator iter_end;
		iter_end = end();

		for (iter = begin(); iter != iter_end; ++iter)
		{
			if (*iter == data)
			{
				return erase(iter);
			}
		}
		return m_End();
	}
	
	void clear(void)
	{
		PNODE pNode = m_Begin->m_pNext;
		PNODE pNext;
		while (pNode != m_End)
		{
			pNext = pNode->m_pNext;
			delete pNode;
			pNode = pNext;
		}
		m_iSize = 0;
		m_Begin->m_pNext = m_End;
		m_End->m_pPrev = m_Begin;

	}
	bool isEmpty(void)const
	{
		return m_iSize == 0;
	}
	iterator begin()const
	{
		iterator iter;
		iter.m_pNode = m_Begin->m_pNext;
		return iter;
	}
	iterator end()const 
	{
		iterator iter;
		iter.m_pNode = m_End;
		return iter;
	}

private:
	typedef CLinkedListNode<T>* PNODE;
	typedef CLinkedListNode<T> NODE;

private:
	PNODE m_Begin;
	PNODE m_End;
	int m_iSize;


};

