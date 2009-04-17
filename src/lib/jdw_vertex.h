#ifndef JDW_VERTEX
#define JDW_VERTEX

template <class T>
class Vertex {
public:
	Vertex() {
		this->pos.x = (T)0;
		this->pos.y = (T)0;
		this->pos.z = (T)0;
		this->scr.x = 0;
		this->scr.y = 0;
	
		calculated = false;
		pNext = (Vertex<T>*)0;
	}

	Vertex(V3<T> in_pos, V2<T> in_scr) {
		this->pos = in_pos;
		this->scr = in_scr;
	
		calculated = false;
		pNext = (Vertex<T>*)0;
	}

	void Rotate(const T e){
		V3<T> tmp = pos;
		float tmp_cosE = cos(e);
		float tmp_sinE = sin(e);

		/// Rotation (http://www.siggraph.org/education/materials/HyperGraph/modeling/mod_tran/3drota.htm)
		// Round the x-axis
		pos.y = tmp_cosE * tmp.y - tmp_sinE * tmp.z;
		pos.z = tmp_sinE * tmp.y + tmp_cosE * tmp.z;

		// Round the y-axis
		tmp = pos;
		//in_v.pos.x = tmp_sinE * tmp.z + tmp_cosE * tmp.x;
		//in_v.pos.z = tmp_cosE * tmp.z - tmp_sinE * tmp.x;

		// Round the z-axis
		tmp = pos;
		//in_v.pos.x = tmp_cosE * tmp.x - tmp_sinE * tmp.y;
		//in_v.pos.y = tmp_sinE * tmp.x + tmp_cosE * tmp.y;
	
		pos = tmp;
	}

	V3<T> pos;
	V2<T> scr;
	bool calculated;
	Vertex* pNext;
};
#endif

