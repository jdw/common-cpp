/*
 * jdw_object.h
 *
 *  Created on: Apr 19, 2009
 *      Author: jdw
 */

#ifndef JDW_OBJECT
#define JDW_OBJECT

namespace JDW_ObjectType {
	enum Enum {
		OBJECT = 0, // Sick?
		ACTOR,

		MAX // Faulty
	};
}

class JDW_Object {
public:
	const JDW_ObjectType::Enum& GetObjectType() { return objectType; }

protected:
	JDW_Object(const JDW_ObjectType::Enum in_type)
	: objectType(in_type) {

	}

	virtual ~JDW_Object() {

	}

private:
	const JDW_ObjectType::Enum objectType;
};

#endif
