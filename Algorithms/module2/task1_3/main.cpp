#include <iostream>
#include <vector>
#include <cmath>

/*
 *Аналогично 1.2, но ломаная должна быть замкнутая. Предполагается, что никакие три точки не лежат на одной прямой.
Указание: стройте ломаную от точки, имеющей наименьшую координату x. Если таких точек несколько, то используйте точку с наименьшей координатой y.
Точки на ломаной расположите в порядке убывания углов лучей от начальной точки до всех остальных точек.
 */
using namespace std;
struct Point {
    int x;
    int y;
    double angle;

    Point(int x, int y) : x(x), y(y) {}
};

bool isLessAngle(const Point &l, const Point &r) {
    return l.angle > r.angle;
}

template<class T>
void insertionSort(T *array, unsigned long l, unsigned long r, bool (*isLess)(const T &, const T &)) {
    int j = 0;
    T tmp=array[l];

    for (int i = l; i < r; i++) {
        tmp = array[i];
        for (j = i; j > l && isLess(tmp, array[j - 1]); j--)
            array[j] = array[j - 1];

        array[j] = tmp;
    }
}

void SearchStartPoint(std::vector<Point> &p_arr,int n) {
    int min_index = 0;
    for (int i = 1; i < n; i++)
        if (((p_arr[i].x == p_arr[min_index].x) && (p_arr[i].y < p_arr[min_index].y))||((p_arr[i].x < p_arr[min_index].x)))
            min_index = i;

    swap(p_arr[0], p_arr[min_index]);
}

void CountAngles(std::vector<Point> &p_arr, int n) {
    for (int i = 1; i < n; i++)
            p_arr[i].angle = atan2(p_arr[i].y - p_arr[0].y, p_arr[i].x - p_arr[0].x);
}


int main() {
    vector<Point> p_array;
    int n ,x,y;
    n=x=y=0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        p_array.push_back(Point(x, y));
    }

    SearchStartPoint(p_array,n);
    CountAngles(p_array, n);
    insertionSort(p_array.data(), 1, n, isLessAngle);


    for (int i = 0; i < p_array.size(); i++)
        cout << p_array[i].x << " " << p_array[i].y << endl;

    return 0;

}
