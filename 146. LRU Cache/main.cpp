#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
using namespace std;

class LRUCache{	
private:
	struct DListNode
	{
	public:
		int key;
		int val;
		DListNode* pre;
		DListNode* next;

		DListNode(int iKey, int iVal) :key(iKey), val(iVal), pre(NULL), next(NULL)
		{

		}
	};
	int mCapacity;
	unordered_map<int, DListNode*> mMap;
	DListNode head;
	DListNode* tail;
public:
	LRUCache(int capacity) :head(0, 0), mCapacity(capacity), mMap()
	{
		tail = &head;
	}

	int get(int key) {
		if (mMap.find(key) != mMap.end())
		{
			DListNode* cur = mMap[key];
			if (cur->pre != &head)
			{
				if (tail == cur)
				{
					tail = cur->pre;
					tail->next = NULL;
				}
				else
					cur->next->pre = cur->pre;
					
				cur->pre->next = cur->next;				
				cur->pre = &head;
				cur->next = head.next;
				if (head.next != NULL)
					head.next->pre = cur;
				head.next = cur;
			}

			return cur->val;
		}
		return -1;
	}

	void set(int key, int value) {
		if (mCapacity <= 0)
			return;

		bool hadKey = get(key) != -1;

		if (mMap.size() == mCapacity && !hadKey)
		{
			mMap.erase(tail->key);
			tail = tail->pre;			
			delete tail->next;
			tail->next = NULL;
		}

		if (!hadKey)
		{
			DListNode* newNode = new DListNode(key, value);
			newNode->pre = &head;
			newNode->next = head.next;
			if (head.next != NULL)
				head.next->pre = newNode;
			else
				tail = newNode;
			head.next = newNode;
			mMap[key] = newNode;
		}
		else
		{		
			mMap[key]->val = value;
		}			
	}
};

int main()
{
	int count = 1000;
	LRUCache lru(10);
	for (int i = 1; i <= count; i++)
	{
		if (rand() % 2 == 0)
		{
			int r = rand() % 15;
			cout << "set " << r << " ";
			lru.set(r, r);
		}
		else
		{
			int r = rand() % 10;
			cout << "get " <<r << " :"<< lru.get(r) << " ";
		}
	}
		
	LRUCache lur(10);
	lur.set(10, 13); lur.set(3, 17); lur.set(6, 11); lur.set(10, 5); lur.set(9, 10), cout << lur.get(13); lur.set(2, 19), cout << lur.get(2), cout << lur.get(3); lur.set(5, 25), cout << lur.get(8); lur.set(9, 22); lur.set(5, 5); lur.set(1, 30), cout << lur.get(11); lur.set(9, 12), cout << lur.get(7), cout << lur.get(5), cout << lur.get(8), cout << lur.get(9); lur.set(4, 30); lur.set(9, 3), cout << lur.get(9), cout << lur.get(10), cout << lur.get(10); lur.set(6, 14); lur.set(3, 1), cout << lur.get(3); lur.set(10, 11), cout << lur.get(8); lur.set(2, 14), cout << lur.get(1), cout << lur.get(5), cout << lur.get(4); lur.set(11, 4); lur.set(12, 24); lur.set(5, 18), cout << lur.get(13); lur.set(7, 23), cout << lur.get(8), cout << lur.get(12); lur.set(3, 27); lur.set(2, 12), cout << lur.get(5); lur.set(2, 9); lur.set(13, 4); lur.set(8, 18); lur.set(1, 7), cout << lur.get(6); lur.set(9, 29); lur.set(8, 21), cout << lur.get(5); lur.set(6, 30); lur.set(1, 12), cout << lur.get(10); lur.set(4, 15); lur.set(7, 22); lur.set(11, 26); lur.set(8, 17); lur.set(9, 29), cout << lur.get(5); lur.set(3, 4); lur.set(11, 30), cout << lur.get(12); lur.set(4, 29), cout << lur.get(3), cout << lur.get(9), cout << lur.get(6); lur.set(3, 4), cout << lur.get(1), cout << lur.get(10); lur.set(3, 29); lur.set(10, 28); lur.set(1, 20); lur.set(11, 13), cout << lur.get(3); lur.set(3, 12); lur.set(3, 8); lur.set(10, 9); lur.set(3, 26), cout << lur.get(8), cout << lur.get(7), cout << lur.get(5); lur.set(13, 17); lur.set(2, 27); lur.set(11, 15), cout << lur.get(12); lur.set(9, 19); lur.set(2, 15); lur.set(3, 16), cout << lur.get(1); lur.set(12, 17); lur.set(9, 1); lur.set(6, 19), cout << lur.get(4), cout << lur.get(5), cout << lur.get(5); lur.set(8, 1); lur.set(11, 7); lur.set(5, 2); lur.set(9, 28), cout << lur.get(1); lur.set(2, 2); lur.set(7, 4); lur.set(4, 22); lur.set(7, 24); lur.set(9, 26); lur.set(13, 28); lur.set(11, 26);

	getchar();
	return 0;
}