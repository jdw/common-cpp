/*
 * jdw_scene2d.h
 *
 *  Created on: Apr 19, 2009
 *      Author: jdw
 */

#ifndef JDW_SCENE2D
#define JDW_SCENE2D

#include "jdw_scene.h"
#include "jdw_vector2d.h"
#include "jdw_image.h"

class JDW_Scene2d: public JDW_Scene {
public:
	JDW_Scene2d(const SceneType::Enum in_type, const iV2& in_size)
	: JDW_Scene(in_type) {
		pScreen = new Image(in_size);
		pScreen->GetPixels();
	}

	virtual ~JDW_Scene2d() {

	}

	Image* GetImage() { return pScreen; }

	virtual void Update() = 0;

protected:
	Image* pScreen;

private:
};
#endif
