/*
 * jdw_slist.h
 *
 *  Created on: Apr 19, 2009
 *      Author: jdw
 *      About: Single linked list
 */

#ifndef JDW_SLIST
#define JDW_SLIST

template <class T>
class JDW_List {
public:
	JDW_List(T* in_pObj) {
		TEST_PTR(in_pObj);
		pNext = NULL;
	}

	~JDW_List() {
		if (pNext != NULL) delete pNext;
		//delete pObj;
	}

	//! Adds element to end of list
	void Add(T* in_pObj) {
		TEST_PTR(in_pObj);

		if (pNext == NULL) // At end of list, add new element
			pNext = new JDW_List<T*>(in_pObj);
		else // Not at end, continue to next element
			pNext->Add(in_pObj);
	}

	JDW_List* Del(T* in_pObj) {
		TEST_PTR(in_pObj);

		if (pObj == in_pObj) { // This is the one to remove
			// tjallallalala
		}
	}

	T* pObj;
	JDW_List<T>* pNext;
};

#endif /* JDW_SLIST_H_ */
