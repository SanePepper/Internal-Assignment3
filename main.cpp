#include <iostream>
#include <cmath>
using namespace std;

template <typename T = uint16_t>
class Coord{
public:
	T x, y;
	Coord(){
		x = 0;
		y = 0;
	}
	Coord(T x_cor, T y_cor){
		x = x_cor;
		y = y_cor;
	}

	/**
	 * @brief Gives the absolute value of the variable
	 * @param x Numeric variable e.g. integer, floating point number
	 * @return The absolute value of the variable
	 */
	static T absolute(T x){
		return (x >= 0)?x:-x;
	}

	/**
	 * @brief Checks whether the two coordinates are the same
	 * @param A First coordinate
	 * @param B Second coordinate
	 * @return bool whether coordinates A and B are the same
	 */
	static bool check(const Coord<T>& A, const Coord<T>& B){
		return (A.x == B.x) && (A.y == B.y);
	}

	/**
	 * @brief Calculate the distance between 2 coordinates
	 * @param A First coordinate
	 * @param B Second coordinate
	 * @return double The distance
	 */
	static double Dist(const Coord<T>& A, const Coord<T>& B){
		T dx = (A-B).x;
		T dy = (A-B).y;
		return sqrt(dx*dx + dy*dy);
	}

	/**
	 * @brief Calculate the Manhattan distance between 2 coordinates
	 * @param A First coordinate
	 * @param B Second coordinate
	 * @return double The Manhattan distance
	 */
	static double Man_Dist(const Coord<T>& A, const Coord<T>& B){
		return absolute((A-B).x)+absolute((A-B).y);
	}


	/**
	 * @brief Calculate the slope of the line segment AB
	 * @param A First coordinate
	 * @param B Second coordinate
	 * @return double The slope
	 */
	static double Slope(const Coord<T>& A, const Coord<T>& B){
		T dx = (A-B).x;
		T dy = (A-B).y;
		if (dx == 0){
			cout << "Undefined slope for vertical line." << endl;
			return 0;
		}
		else{
			return (dy/dx);
		}
	}

	/**
	 * @brief Calculate the triangle area enclosed by 3 points
	 * @param A First coordinate
	 * @param B Second coordinate
	 * @param C Third coordinate
	 * @return double Area of triangle ABC
	 */
	static double Tri_Area(const Coord<T>& A, const Coord<T>& B, const Coord<T>& C){
		if  (check(A,B) || check(A,C) || check(B,C)){
			return 0;
		}
		else{
			return absolute((A.x*((B-C).y)+B.x*((C-A).y)+C.x*((A-B).y))/2);
		}
	}

	/**
	 * @brief Calculate the radius of the circle that can pass through the 3 coordinates
	 * @param A First coordinate
	 * @param B Second coordinate
	 * @param C Third coordinate
	 * @return double Radius of the circle
	 */
	static double Radius(const Coord<T>& A, const Coord<T>& B, const Coord<T>& C){
		double tri_area = Tri_Area(A,B,C);
		if (tri_area == 0){
			cout << "Area of the triangle is 0. Unable to find the radius." << endl;
			return 0;
		}
		else{
			return Dist(A,B)*Dist(B,C)*Dist(C,A)/4/tri_area;
		}
	}
};

/**
 * @brief Sum the 2 given coordinates
 * @param A First coordinate
 * @param B Second coordinate
 * @return Coord Resulting values
 */
template <typename T = uint16_t>
Coord<T> operator+(const Coord<T>& A,const Coord<T>& B){
	Coord<T> coord;
	coord.x = A.x + B.x;
	coord.y = A.y + B.y;
	return coord;
}

/**
 * @brief Subtract one coordinate from another
 * @param A First coordinate
 * @param B Second coordinate
 * @return Coord Resulting values
 */
template <typename T = uint16_t>
Coord<T> operator-(const Coord<T>& A,const Coord<T>& B){
	Coord<T> coord;
	coord.x = A.x - B.x;
	coord.y = A.y - B.y;
	return coord;
}

/**
 * @brief Sum the 2 given coordinates and store the value in the first coordinate
 * @param A First coordinate
 * @param B Second coordinate
 * @return Coord Resulting values
 */
template <typename T = uint16_t>
Coord<T>& operator+=(Coord<T>& A,const Coord<T>& B){
	A.x = A.x + B.x;
	A.y = A.y + B.y;
	return A;
}

/**
 * @brief Subtract the one coordinate from another and store the value in the first coordinate
 * @param A First coordinate
 * @param B Second coordinate
 * @return Coord Resulting values
 */
template <typename T = uint16_t>
Coord<T>& operator-=(Coord<T>& A,const Coord<T>& B){
	A.x = A.x - B.x;
	A.y = A.y - B.y;
	return A;
}

/**
 * @brief Convert the coordinate into an output sequence
 * @param os The output sequence
 * @param A The coordinate need to be output
 * @return ostream The processed output sequence of the coordinate
 * In format of:
 * (<x-coordinate> , <y-coordinate>)
 */
template <typename T = uint16_t>
ostream& operator<<(ostream& os, const Coord<T>& A){
	os << "(" << A.x <<", " << A.y << ")";
	return os;
}

int main(){
	return 0;
}
