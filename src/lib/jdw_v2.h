#ifndef JDW_V2
#define JDW_V2

template <class T>
class V2 {
public:
	V2(T in_x, T in_y) {
		this->x = in_x;
		this->y = in_y;
	}

	V2() {
		this->x = (T)0;
		this->y = (T)0;
	}

	T GetDP(const V2<T>& in) const { // Dot-product
		return this->x * in.x + this->y * in.y;
	}

	double GetLength() const { // Gets length of vector
		double tmp = sqrt(this->GetDP(*this));
		return (0.999 <= tmp && tmp <= 1.001)? 1.0 : tmp;
	}

	double GetDist(const V2<T>& in) const { // Returns distance between two vectors
		if (this == &in) return 0; // Same variables
		if (*this == in) return 0; // Same values

		T dX = this->x - in.x;
		T dY = this->y - in.y;

		return sqrt(dX * dX + dY * dY);
	}

	V2<T> GetUnit() const {
		T length = this->GetLength();
		return V2<T>(this->x / length, this->y / length);
	}

	V2<T>& operator=(const V2<T>& in) {
		if (this == &in) return *this;

		this->x = in.x;
		this->y = in.y;

		return *this;
	}

	bool operator==(const V2<T>& in) const {
		if (this->x != in.x) return false;
		if (this->y != in.y) return false;

		return true;
	}

	bool operator!=(const V2<T>& in) const {
		return !(*this == in);
	}

	void operator+=(const V2<T>& in) {
		this->x += in.x;
		this->y += in.y;
	}

	V2<T> operator+(const V2<T>& in) const {
		return V2<T>(this->x + in.x, this->y + in.y);
	}

	void operator-=(const V2<T>& in) {
		this->x -= in.x;
		this->y -= in.y;
	}

	V2<T> operator-(const V2<T>& in) const {
		return V2<T>(this->x - in.x, this->y - in.y);
	}

	void operator*=(const T& in) {
		this->x *= in;
		this->y *= in;
	}

	V2<T> operator*(const T& in) const {
		return V2<T>(this->x * in, this->y * in);
	}

	T x, y;
};

typedef V2<int> V2i;
typedef V2<double> V2d;
typedef V2<float> V2f;

#endif

