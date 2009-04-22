/*
 * jdw_rectangle.h
 *
 *  Created on: Apr 21, 2009
 *      Author: jdw
 */

#ifndef JDW_RECTANGLE
#define JDW_RECTANGLE

#include "jdw_actor.h"

template <class T, class U> // T = JDW_VectorXd<Q>, U = Q
class JDW_Rectangle: public JDW_Actor<T> {
public:
	JDW_Rectangle()
	: JDW_Actor<T>(JDW_ActorType::RECTANGLE) {
		size = T();
	}

	JDW_Rectangle(const T& in_pos, const T& in_size)
	: JDW_Actor<T>(JDW_ActorType::RECTANGLE, in_pos) {
		size = in_size;
	}
	virtual ~JDW_Rectangle() {

	}

	void SetSize(const T& in_size) { size = in_size; }
	const T& GetSize() const { return size; }
	U GetArea() const { return size.x * size.y; }

	bool IsInside(const T& in_pos) {
		if (!(((JDW_Actor<T>*)this)->GetPos().x <= in_pos.x && in_pos.x <= ((JDW_Actor<T>*)this)->GetPos().x + size.x)) return FALSE;
		if (!(((JDW_Actor<T>*)this)->GetPos().y <= in_pos.y && in_pos.y <= ((JDW_Actor<T>*)this)->GetPos().y + size.y)) return FALSE;

		return TRUE;
	}
private:
	JDW_Vector2d<U> size;
};

typedef JDW_Rectangle<JDW_Vector2d<double>, double> dRect;
typedef JDW_Rectangle<JDW_Vector2d<float>, float> fRect;
typedef JDW_Rectangle<JDW_Vector2d<int>, int> iRect;

#endif
