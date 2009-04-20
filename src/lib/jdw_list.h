/*
 * jdw_slist.h
 *
 *  Created on: Apr 19, 2009
 *      Author: jdw
 *      About: Single linked list
 */

#ifndef JDW_LIST
#define JDW_LIST

template <class T>
class JDW_List {
public:
	JDW_List(T* in_pObj) {
		TEST_PTR(in_pObj);
		pObj = in_pObj;
		pNext = NULL;
	}

	~JDW_List() {
		if (pNext != NULL) delete pNext;
		//delete pObj;
	}

	//! Returns size from this element
	int Size() {
		if (pNext != NULL) return 1 + pNext->Size();
		else return 1;
	}

	//! Adds element to end of list
	void Add(T* in_pObj) {
		if (pNext == NULL) // At end of list, add new element
			pNext = new JDW_List<T>(in_pObj);
		else // Not at end, continue to next element
			pNext->Add(in_pObj);
	}

	void DelObj() {
		delete pObj;
		pObj = NULL;
	}

	void DelAllObj() {
		if (pObj != NULL) DelObj();
		if (pNext != NULL) pNext->DelAllObj();
	}

	JDW_List<T>* Del(T in_pObj) {
		if (pObj == in_pObj) { // This is the one to remove
			// tjallallalala
		}
	}

	T* pObj;
	JDW_List<T>* pNext;
};

typedef JDW_List<int> iList;
typedef JDW_List<float> fList;
typedef JDW_List<double> dList;

#endif
