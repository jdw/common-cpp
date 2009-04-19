#ifndef JDW_VECTOR3D
#define JDW_VECTOR3D

template <class T>
class JDW_Vector3d {
public:
	JDW_Vector3d(T in_x, T in_y, T in_z) {
		this->x = in_x;
		this->y = in_y;
		this->z = in_z;
	}

	JDW_Vector3d() {
		this->x = (T)0;
		this->y = (T)0;
		this->z = (T)0;
	}

	T GetDP(const JDW_Vector3d<T>& in) const { // Dot-product
		return this->x * in.x + this->y * in.y + this->z * in.z;
	}

	JDW_Vector3d<T> GetXP(const JDW_Vector3d<T>& in) const { // Cross-prodcut
		// A x B -> A=this, B=in
		return JDW_Vector3d<T>((this->y * in.z) - (this->z * in.y),
			         (this->z * in.x) - (this->x * in.z),
			         (this->x * in.y) - (this->y * in.x));
	}

	T GetLength() const { // Gets length of vector
		double tmp = sqrt(this->GetDP(*this));
		return (0.999 <= tmp && tmp <= 1.001)? 1.0 : tmp; // SiC...
	}

	double GetDist(const JDW_Vector3d<T>& in) const { // Returns distance between two vectors
		if (this == &in) return 0; // Same variables
		if (*this == in) return 0; // Same values

		T dX = this->x - in.x;
		T dY = this->y - in.y;
		T dZ = this->z - in.z;

		return sqrt(dX * dX + dY * dY + dZ * dZ);
	}

	JDW_Vector3d<double> GetUnit() const { // Returns a unit vector
		double length = this->GetLength();
		return JDW_Vector3d<double>(this->x / length, this->y / length, this->z / length);
	}

	JDW_Vector3d<T>& operator=(const JDW_Vector3d<T>& in) {
		if (this == &in) return *this;

		this->x = in.x;
		this->y = in.y;
		this->z = in.z;

		return *this;
	}

	bool operator==(const JDW_Vector3d<T>& in) const {
		if (this->x != in.x) return false;
		if (this->y != in.y) return false;
		if (this->z != in.z) return false;

		return true;
	}

	bool operator!=(const JDW_Vector3d<T>& in) const {
		return !(*this == in);
	}

	void operator+=(const JDW_Vector3d<T>& in) {
		this->x += in.x;
		this->y += in.y;
		this->z += in.z;
	}

	JDW_Vector3d<T> operator+(const JDW_Vector3d<T>& in) const {
		return JDW_Vector3d<T>(this->x + in.x, this->y + in.y, this->z + in.z);
	}

	void operator-=(const JDW_Vector3d<T>& in) {
		this->x -= in.x;
		this->y -= in.y;
		this->z -= in.z;
	}

	JDW_Vector3d<T> operator-(const JDW_Vector3d<T>& in) const {
		return JDW_Vector3d<T>(this->x - in.x, this->y - in.y, this->z - in.z);
	}

	void operator*=(const T& in) {
		this->x *= in;
		this->y *= in;
		this->z *= in;
	}

	JDW_Vector3d<T> operator*(const T& in) const {
		return JDW_Vector3d<T>(this->x * in, this->y * in, this->z * in);
	}

	T x, y, z;
};

typedef JDW_Vector3d<int> iV3;
typedef JDW_Vector3d<double> dV3;
typedef JDW_Vector3d<float> fV3;
typedef JDW_Vector3d<unsigned long> ulV3;
#endif

