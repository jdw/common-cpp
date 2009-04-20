/*
 * jdw_actor.h
 *
 *  Created on: Apr 20, 2009
 *      Author: jdw
 */

#ifndef JDW_ACTOR
#define JDW_ACTOR

#include "jdw_object.h"

namespace JDW_ActorType {
	enum Enum {
		CIRCLE = 0,
		CUBE,

		MAX // Faulty
	};
}

template <class T>
class JDW_Actor: public JDW_Object {
public:
	JDW_Actor(const JDW_ActorType::Enum& in_type)
	: JDW_Object(JDW_ObjectType::ACTOR), actorType(in_type) {
		pos = T();
	}

	JDW_Actor(const JDW_ActorType::Enum& in_type, const T& in_pos)
	: JDW_Object(JDW_ObjectType::ACTOR), actorType(in_type) {
		pos = in_pos;
	}

	virtual ~JDW_Actor() {

	}

	void SetPos(const T& in_pos) { pos = in_pos; }
	const T& GetPos() { return pos; }
	const JDW_ActorType::Enum& GetActorType() const { return actorType; }

private:
	T pos;
	const JDW_ActorType::Enum actorType;
};

#endif
