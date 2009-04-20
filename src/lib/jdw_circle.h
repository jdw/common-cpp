/*
 * jdw_circle.h
 *
 *  Created on: Apr 20, 2009
 *      Author: jdw
 */

#ifndef JDW_CIRCLE
#define JDW_CIRCLE

#include "jdw_actor.h"

template <class T>
class JDW_Circle: public JDW_Actor<T> {
public:
	JDW_Circle()
	: JDW_Actor<T>(JDW_ActorType::CIRCLE) {
		radius = 0;
	}

	virtual ~JDW_Circle() {

	}

	void SetRadius(const double& in_radius) { radius = in_radius; }
	const double& GetRadius() const { return radius; }

private:
	double radius;
};

#endif
