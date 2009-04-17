#ifndef JDW_CUBE
#define JDW_CUBE

template <class T>
class JDW_Cube {
public:
	JDW_Cube(const JDW_Vector3d<T> in_o, const T in_sides/*, const U in_clr*/) {
		this->o = in_o;
		this->sides = in_sides;
		//this->clr = in_clr;
		this->pVertexList = (JDW_Vertex<T>*)0;
		float halfSide = this->sides / 2.0f;

		this->pPolys[0] = new JDW_Polygon<T>( // Front plane
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y - halfSide,  o.z + halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y - halfSide,  o.z + halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y + halfSide,  o.z + halfSide)));
		this->pPolys[1] = new JDW_Polygon<T>(
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y + halfSide,  o.z + halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y + halfSide,  o.z + halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y - halfSide,  o.z + halfSide)));

		this->pPolys[2] = new JDW_Polygon<T>( // Back plane
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y - halfSide,  o.z - halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y - halfSide,  o.z - halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y + halfSide,  o.z - halfSide)));
		this->pPolys[3] = new JDW_Polygon<T>(
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y + halfSide,  o.z - halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y + halfSide,  o.z - halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y - halfSide,  o.z - halfSide)));

		this->pPolys[4] = new JDW_Polygon<T>( // Right plane
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y - halfSide,  o.z + halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y - halfSide,  o.z - halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y + halfSide,  o.z - halfSide)));
		this->pPolys[5] = new JDW_Polygon<T>(
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y + halfSide,  o.z - halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y + halfSide,  o.z + halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y - halfSide,  o.z + halfSide)));

		this->pPolys[6] = new JDW_Polygon<T>( // Left plane
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y - halfSide,  o.z + halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y + halfSide,  o.z + halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y + halfSide,  o.z - halfSide)));
		this->pPolys[7] = new JDW_Polygon<T>(
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y + halfSide,  o.z - halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y - halfSide,  o.z - halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y - halfSide,  o.z + halfSide)));

		this->pPolys[8] = new JDW_Polygon<T>( // Upper plane
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y + halfSide,  o.z + halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y + halfSide,  o.z - halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y + halfSide,  o.z - halfSide)));
		this->pPolys[9] = new JDW_Polygon<T>(
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y + halfSide,  o.z - halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y + halfSide,  o.z + halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y + halfSide,  o.z + halfSide)));

		this->pPolys[10] = new JDW_Polygon<T>( // Lower plane
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y - halfSide,  o.z + halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y - halfSide,  o.z + halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y - halfSide,  o.z - halfSide)));
		this->pPolys[11] = new JDW_Polygon<T>(
			AddVertex(JDW_Vector3d<T>(o.x - halfSide, o.y - halfSide,  o.z - halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y - halfSide,  o.z - halfSide)),
			AddVertex(JDW_Vector3d<T>(o.x + halfSide, o.y - halfSide,  o.z + halfSide)));
	}

	~JDW_Cube() {
		for(int i = 0; i < 12; ++i) {
			//delete pPolys[i];
		}
	}

	const JDW_Vector3d<T>& GetOrigo() { return o; }
	T GetSide() { return sides; }
	T GetSize() { return sides * sides * sides; }
	//const U& GetColor() { return clr; }
	JDW_Polygon<T>** const GetPolys() { return pPolys; }
	JDW_Polygon<T>* const GetPoly(int i) { return pPolys[i]; }
	int GetVertexCount() { return sizeof((*pVertexList)) / sizeof(JDW_Vertex<T>); }
	int GetPolyCount() { return sizeof((pPolys)) / sizeof(JDW_Polygon<T>*); }
	JDW_Vertex<T>* GetVertexList() { return pVertexList; }
	// get polycount?

private:
	JDW_Vertex<T>* AddVertex(JDW_Vector3d<T> in_v) {
		JDW_Vertex<T>* pTmp = pVertexList;

		if (pTmp == (JDW_Vertex<T>*)0) { // First time
			pTmp = new JDW_Vertex<T>();
			pTmp->pos.x = in_v.x;
			pTmp->pos.y = in_v.y;
			pTmp->pos.z = in_v.z;

			pVertexList = pTmp;

			return pTmp;
		}

		while (pTmp->pNext != (JDW_Vertex<T>*)0) {
			if ((pTmp->pos.x == in_v.x) &&
				  (pTmp->pos.y == in_v.y) &&
				  (pTmp->pos.z == in_v.z))
				return pTmp;

			pTmp = pTmp->pNext;
		}

		if ((pTmp->pos.x == in_v.x) &&
				(pTmp->pos.y == in_v.y) &&
				(pTmp->pos.z == in_v.z))
			return pTmp;

		pTmp->pNext = new JDW_Vertex<T>();
		pTmp = pTmp->pNext;

		pTmp->pos.x = in_v.x;
		pTmp->pos.y = in_v.y;
		pTmp->pos.z = in_v.z;

		return pTmp;
	}

	JDW_Vector3d<T> o;
	T sides;
	//U clr; // (SiC) Replace with "material", FFS
	JDW_Polygon<T>* pPolys[12];
	JDW_Vertex<T>* pVertexList;
};

typedef JDW_Cube<int> iCube;
typedef JDW_Cube<float> fCube;
typedef JDW_Cube<double> dCube;

#endif
