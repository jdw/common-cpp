#ifndef JDW_POLYGON
#define JDW_POLYGON

template <class T>
class JDW_Polygon {
public:
	JDW_Polygon(JDW_Vertex<T>* in_o, JDW_Vertex<T>* in_a, JDW_Vertex<T>* in_b) {
		this->o = in_o; // Keep 'em counterclockwise!
		this->a = in_a;
		this->b = in_b;
	}

	JDW_Polygon(JDW_Vertex<T> in_o, JDW_Vertex<T> in_a, JDW_Vertex<T> in_b) {
		this->o = new JDW_Vertex<T>(in_o); // Keep 'em counterclockwise!
		this->a = new JDW_Vertex<T>(in_a);
		this->b = new JDW_Vertex<T>(in_b);
	}

	~JDW_Polygon() {
		delete o;
		delete a;
		delete b;
	}

	JDW_Vector3d<T> GetNormal() {
		//normal = (p1-p2) x (p3-p2) dvs,
		//normal = (a - o) x (b - o)
		//return (V3<T>(a->pos.x - o->pos.x, a->pos.y - o->pos.y, a->pos.z - o->pos.z).GetXP(
		//        V3<T>(b->pos.x - o->pos.x, b->pos.y - o->pos.y, b->pos.z - o->pos.z))).GetUnit();

		// http://easyweb.easynet.co.uk/~mrmeanie/plane/planes.htm
		JDW_Vector3d<T> N((T)0, (T)0, (T)0), U((T)0, (T)0, (T)0), V((T)0, (T)0, (T)0);
		U.x = a->pos.x - o->pos.x;
		U.y = a->pos.y - o->pos.y;
		U.z = a->pos.z - o->pos.z;

		V.x = b->pos.x - o->pos.x;
		V.y = b->pos.y - o->pos.y;
		V.z = b->pos.z - o->pos.z;

		N.x = (U.y * V.z) - (U.z * V.y);
		N.y = (U.z * V.x) - (U.x * V.z);
		N.z = (U.x * V.y) - (U.y * V.x);

		return N.GetUnit();
	}

	T GetK(const JDW_Vector3d<T>& p) {
		return this->GetNormal().DP(p);
	}

	JDW_Vertex<T>* o;
	JDW_Vertex<T>* a;
	JDW_Vertex<T>* b;
};

typedef JDW_Polygon<int> iPoly;
typedef JDW_Polygon<float> fPoly;
typedef JDW_Polygon<double> dPoly;

#endif
