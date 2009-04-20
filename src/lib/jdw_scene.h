#ifndef JDW_SCENE
#define JDW_SCENE

#include "jdw_misc.h"
#include "jdw_object.h"
#include "jdw_list.h"

namespace SceneStatus {
	enum Enum {
		PAUSED	= 1 << 0,
		DONE	= 1 << 1
	};
}

namespace SceneType {
	enum Enum {
		TWOD = 0,
		THREED,
		RAYTRACED,

		MAX // Faulty
	};
}

class JDW_Scene {
public:
	virtual ~JDW_Scene() {

	}

	int GetObjCount() const { return pObj->Size(); }
	//void AddObj(JDW_Object* in) { pObj->Add(in); }
	const bool Paused() const { return status & SceneStatus::PAUSED; }
	const bool Done() const { return status & SceneStatus::DONE; }
	void SetPaused() { status |= SceneStatus::PAUSED; }
	void SetDeltaTime(const double& in_dT) { deltaTime = in_dT; }
	const double& GetDeltaTime() { return deltaTime; }
	const double& GetTotalTime() { return totalTime; }
	void UpdateTotalTime() { totalTime += deltaTime; }

	virtual void Update() = 0;

protected:
	JDW_Scene(const SceneType::Enum in_type)
	: type(in_type) {
		deltaTime = 0.0;
		totalTime = 0.0;
	}

	JDW_List<JDW_Object*>* pObj;

private:
	int status;
	const SceneType::Enum type;
	double deltaTime; // Time since last update
	double totalTime; // Total time running
};

#endif


