#ifndef JDW_V3
#define JDW_V3

template <class T>
class V3 {
public:
	V3(T in_x, T in_y, T in_z) {
		this->x = in_x;
		this->y = in_y;
		this->z = in_z;
	}

	V3() {
		this->x = (T)0;
		this->y = (T)0;
		this->z = (T)0;
	}

	T GetDP(const V3<T> in) const { // Dot-product
		return this->x * in.x + this->y * in.y + this->z * in.z;
	}

	V3<T> GetXP(const V3<T>& in) const { // Cross-prodcut
		// A x B -> A=this, B=in
		return V3<T>((this->y * in.z) - (this->z * in.y),
			           (this->z * in.x) - (this->x * in.z),
			           (this->x * in.y) - (this->y * in.x));
	}

	T GetLength() const { // Gets length of vector
		return sqrt(this->GetDP(*this));
	}

	T GetDist(const V3& in) const { // Returns distance between two vectors
		T dX = this->x - in.x;
		T dY = this->y - in.y;
		T dZ = this->z - in.z;
		return sqrt(dX * dX + dY * dY + dZ * dZ);
	}

	V3<T> GetUnit() const { // Returns a unit vector
		T length = this->GetLength();
		return V3<T>(this->x / length, this->y / length, this->z / length);
	}

	void operator=(const V3<T>& in) {
		this->x = in.x;
		this->y = in.y;
		this->z = in.z;
	}

	bool operator==(const V3<T>& in) const {
		if (this->x != in.x) return false;
		if (this->y != in.y) return false;
		if (this->z != in.z) return false;

		return true;
	}

	bool operator!=(const V3<T>& in) const {
		if (this->x == in.x) return false;
		if (this->y == in.y) return false;
		if (this->z == in.z) return false;

		return true;
	}

	void operator+=(const V3<T>& in) {
		this->x += in.x;
		this->y += in.y;
		this->z += in.z;
	}

	V3<T> operator+(const V3<T>& in) const {
		return V3<T>(this->x + in.x, this->y + in.y, this->z + in.z);
	}

	void operator-=(const V3<T>& in) {
		this->x -= in.x;
		this->y -= in.y;
		this->z -= in.z;
	}

	V3<T> operator-(const V3<T>& in) const {
		return V3<T>(this->x - in.x, this->y - in.y, this->z - in.z);
	}

	void operator*=(const T& in) {
		this->x *= in;
		this->y *= in;
		this->z *= in;
	}

	V3<T> operator*(const T& in) const {
		return V3<T>(this->x * in, this->y * in, this->z * in);
	}

	T x, y, z;
};

typedef V3<int> V3i;
typedef V3<double> V3d;
typedef V3<float> V3f;

#endif

