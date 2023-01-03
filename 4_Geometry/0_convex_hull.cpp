#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <stack>
#include <vector>

struct Point2D
{
    double x;
    double y;

    static int ccw(const Point2D& a, const Point2D& b, const Point2D& c)
    {
        /*                      ------>   ------> 
        Area(a, b, c) = | 1/2 * (b - a) * (c - a)
        */
        double area2 = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        if (area2 < 0)
            return -1;  // clockwise
        if (area2 > 0)
            return 1;   // counter-clockwise
        return 0;       // collinear
    }
    
    double polar_angle() const
    {
        return std::atan2(y, x);
    }
};

std::stack<Point2D> GrahamScan(std::vector<Point2D>& points)
{
    std::stack<Point2D> hull;

    // prepare points set: 
    // 1. sort by y
    // 2. sort by angle between every point and point with the lowest y
    std::sort(points.begin(), points.end(), 
        [](const Point2D& lhs, const Point2D& rhs){
            return lhs.y < rhs.y;
        });
    auto& point_with_lowest_y = points[0];
    std::sort(points.begin(), points.end(), 
        [first_point_angle = point_with_lowest_y.polar_angle()]
        (const Point2D& lhs, const Point2D& rhs){
            return std::abs(lhs.polar_angle() - first_point_angle) < std::abs(rhs.polar_angle() - first_point_angle);
        });

    // push first two points,
    // because they are deffinitely on hull
    hull.push(points[0]);
    hull.push(points[1]);

    for (size_t i = 2; i < points.size(); ++i)
    {
        auto top = hull.top(); hull.pop();
        // disccard all points that would create clockwise turn
        while (Point2D::ccw(hull.top(), top, points[i]) <= 0)
        {
            top = hull.top(); hull.pop();
        }
        hull.push(top); // guaranteed on hull
        hull.push(points[i]); // potentially on hull
    }

    return hull;
}

std::vector<Point2D> ScanInput()
{
    uint32_t n;
    std::cin >> n;
    assert(n >= 3);

    std::vector<Point2D> out;
    out.reserve(n);
    for (uint32_t i = 0; i < n; ++i)
    {
        double a, b;
        std::cin >> a >> b;
        out.push_back({a, b});
    }

    return out;
}

void PrintOutput(std::stack<Point2D>&& hull)
{
    while (hull.size())
    {
        auto point = hull.top(); hull.pop();
        std::cout << "(" << point.x << "; " << point.y << ") ";
    }
    std::cout << std::endl;
}

int main()
{
    auto points = ScanInput();
    auto hull = GrahamScan(points);
    PrintOutput(std::move(hull));
    return 0;
}