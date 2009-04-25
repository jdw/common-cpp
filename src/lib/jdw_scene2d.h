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
//#include "jdw_types.h"

class JDW_Scene2d: public JDW_Scene {
public:
	JDW_Scene2d(const SceneType::Enum in_type, const iV2& in_size)
	: JDW_Scene(in_type) {
		spScreen = boost::shared_ptr<JDW_Image<JDW_Pixel, JDW_Pixel> >(new JDW_Image<JDW_Pixel, JDW_Pixel>(in_size));
	}

	virtual ~JDW_Scene2d() {

	}

	JDW_Image<JDW_Pixel, JDW_Pixel>* GetScreen() const { return spScreen.get(); }

	virtual void Update() = 0;

protected:
	boost::shared_ptr<JDW_Image<JDW_Pixel, JDW_Pixel> > spScreen;

private:
};
#endif
