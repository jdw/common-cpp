#ifndef JDW_CUBE
#define JDW_CUBE

template <class T>
class Cube {
public:
	Cube(const V3<T> in_o, const T in_sides/*, const U in_clr*/) {
		this->o = in_o;
		this->sides = in_sides;
		//this->clr = in_clr;
		this->pVertexList = (Vertex<T>*)0;
		float halfSide = this->sides / 2.0f;
	
		this->pPolys[0] = new Poly<T>( // Front plane
			AddVertex(V3<T>(o.x - halfSide, o.y - halfSide,  o.z + halfSide)),
			AddVertex(V3<T>(o.x + halfSide, o.y - halfSide,  o.z + halfSide)),
			AddVertex(V3<T>(o.x + halfSide, o.y + halfSide,  o.z + halfSide)));
		this->pPolys[1] = new Poly<T>(
			AddVertex(V3<T>(o.x + halfSide, o.y + halfSide,  o.z + halfSide)),
			AddVertex(V3<T>(o.x - halfSide, o.y + halfSide,  o.z + halfSide)),
			AddVertex(V3<T>(o.x - halfSide, o.y - halfSide,  o.z + halfSide)));
	
		this->pPolys[2] = new Poly<T>( // Back plane
			AddVertex(V3<T>(o.x + halfSide, o.y - halfSide,  o.z - halfSide)),
			AddVertex(V3<T>(o.x - halfSide, o.y - halfSide,  o.z - halfSide)),
			AddVertex(V3<T>(o.x - halfSide, o.y + halfSide,  o.z - halfSide)));
		this->pPolys[3] = new Poly<T>(
			AddVertex(V3<T>(o.x - halfSide, o.y + halfSide,  o.z - halfSide)),
			AddVertex(V3<T>(o.x + halfSide, o.y + halfSide,  o.z - halfSide)),
			AddVertex(V3<T>(o.x + halfSide, o.y - halfSide,  o.z - halfSide)));
	
		this->pPolys[4] = new Poly<T>( // Right plane
			AddVertex(V3<T>(o.x + halfSide, o.y - halfSide,  o.z + halfSide)),
			AddVertex(V3<T>(o.x + halfSide, o.y - halfSide,  o.z - halfSide)),
			AddVertex(V3<T>(o.x + halfSide, o.y + halfSide,  o.z - halfSide)));
		this->pPolys[5] = new Poly<T>(
			AddVertex(V3<T>(o.x + halfSide, o.y + halfSide,  o.z - halfSide)),
			AddVertex(V3<T>(o.x + halfSide, o.y + halfSide,  o.z + halfSide)),
			AddVertex(V3<T>(o.x + halfSide, o.y - halfSide,  o.z + halfSide)));

		this->pPolys[6] = new Poly<T>( // Left plane
			AddVertex(V3<T>(o.x - halfSide, o.y - halfSide,  o.z + halfSide)),
			AddVertex(V3<T>(o.x - halfSide, o.y + halfSide,  o.z + halfSide)),
			AddVertex(V3<T>(o.x - halfSide, o.y + halfSide,  o.z - halfSide)));
		this->pPolys[7] = new Poly<T>(
			AddVertex(V3<T>(o.x - halfSide, o.y + halfSide,  o.z - halfSide)),
			AddVertex(V3<T>(o.x - halfSide, o.y - halfSide,  o.z - halfSide)),
			AddVertex(V3<T>(o.x - halfSide, o.y - halfSide,  o.z + halfSide)));

		this->pPolys[8] = new Poly<T>( // Upper plane
			AddVertex(V3<T>(o.x + halfSide, o.y + halfSide,  o.z + halfSide)),
			AddVertex(V3<T>(o.x + halfSide, o.y + halfSide,  o.z - halfSide)),
			AddVertex(V3<T>(o.x - halfSide, o.y + halfSide,  o.z - halfSide)));
		this->pPolys[9] = new Poly<T>(
			AddVertex(V3<T>(o.x - halfSide, o.y + halfSide,  o.z - halfSide)),
			AddVertex(V3<T>(o.x - halfSide, o.y + halfSide,  o.z + halfSide)),
			AddVertex(V3<T>(o.x + halfSide, o.y + halfSide,  o.z + halfSide)));
		
		this->pPolys[10] = new Poly<T>( // Lower plane
			AddVertex(V3<T>(o.x + halfSide, o.y - halfSide,  o.z + halfSide)),
			AddVertex(V3<T>(o.x - halfSide, o.y - halfSide,  o.z + halfSide)),
			AddVertex(V3<T>(o.x - halfSide, o.y - halfSide,  o.z - halfSide)));
		this->pPolys[11] = new Poly<T>(
			AddVertex(V3<T>(o.x - halfSide, o.y - halfSide,  o.z - halfSide)),
			AddVertex(V3<T>(o.x + halfSide, o.y - halfSide,  o.z - halfSide)),
			AddVertex(V3<T>(o.x + halfSide, o.y - halfSide,  o.z + halfSide)));

	}

	~Cube() {
		for(int i = 0; i < 12; ++i) {
			delete pPolys[i];
		}	
	}

	const V3<T>& GetOrigo() { return o; }
  T GetSide() { return sides; }
  T GetSize() { return sides * sides * sides; }
  //const U& GetColor() { return clr; }
  Poly<T>** const GetPolys() { return pPolys; }
  Poly<T>* const GetPoly(int i) { return pPolys[i]; }
  int GetVertexCount() { return sizeof((*pVertexList)) / sizeof(Vertex<T>); }
  int GetPolyCount() { return sizeof((pPolys)) / sizeof(Poly<T>*); }
  Vertex<T>* GetVertexList() { return pVertexList; }
  // get polycount?
  
private:
	Vertex<T>* AddVertex(V3<T> in_v) {
		Vertex<T>* pTmp = pVertexList;
	
		if (pTmp == (Vertex<T>*)0) { // First time
			pTmp = new Vertex<T>();
			pTmp->pos.x = in_v.x;
			pTmp->pos.y = in_v.y;
			pTmp->pos.z = in_v.z;
		
			pVertexList = pTmp;
		
			return pTmp;
		}
		
		while (pTmp->pNext != (Vertex<T>*)0) {
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
	
		pTmp->pNext = new Vertex<T>();
		pTmp = pTmp->pNext;
	
		pTmp->pos.x = in_v.x;
		pTmp->pos.y = in_v.y;
		pTmp->pos.z = in_v.z;
	
		return pTmp;
	}
	
	V3<T> o;
	T sides;
	//U clr; // Replace with "material", FFS
	Poly<T>* pPolys[12];
	Vertex<T>* pVertexList;
};

#endif
