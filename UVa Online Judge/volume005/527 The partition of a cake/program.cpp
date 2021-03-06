// The partition of a cake
// UVa ID: 527
// Verdict: Accepted
// Submission Date: 2017-05-08
// UVa Run Time: 0.330s
//
// 版权所有（C）2017，邱秋。metaphysis # yeah dot net

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1100;
const double EPSILON = 1e-7;

struct point
{
    double x, y;

    bool operator<(const point &p) const
    {
        if (fabs(x - p.x) > EPSILON)
            return x < p.x;
        else
            return y < p.y;
    }

    bool operator==(const point &p) const
    {
        return fabs(x - p.x) <= EPSILON && fabs(y - p.y) <= EPSILON;
    }
};

point lowerLeftPoint;

struct line
{
    point a, b;
    double angle;
};

struct polygon
{
    int number;
    point vertices[MAXN];
};

double crossProduct(point p1, point p2, point p3)
{
    return (p3.x - p1.x) * (p2.y - p1.y) - (p2.x - p1.x) * (p3.y - p1.y);
}

bool cw(point p1, point p2, point p3)
{
    return crossProduct(p1, p2, p3) > EPSILON;
}

bool cmpLine(line line1, line line2)
{
    if (fabs(line1.angle - line2.angle) <= EPSILON)
        return crossProduct(line2.a, line2.b, line1.a) < EPSILON;
    return line1.angle < line2.angle;
}

bool cmpAngle(line line1, line line2)
{
    return fabs(line1.angle - line2.angle) <= EPSILON;
}

bool paralle(line line1, line line2)
{
    return fabs((line1.a.x - line1.b.x) * (line2.a.y - line2.b.y) -
        (line2.a.x - line2.b.x) * (line1.a.y - line1.b.y)) <= EPSILON;
}

bool ccw(point a, point b, point c)
{
    return crossProduct(a, b, c) < -EPSILON;
}

bool collinear(point a, point b, point c)
{
    return fabs(crossProduct(a, b, c)) <= EPSILON;
}

bool ccwOrCollinear(point a, point b, point c)
{
    return ccw(a, b, c) || collinear(a, b, c);
}

double distanceToLowerLeftPoint(point p)
{
    return pow(lowerLeftPoint.x - p.x, 2) + pow(lowerLeftPoint.y - p.y, 2);
}

bool smallerAngle(point first, point second)
{
    if (collinear(lowerLeftPoint, first, second))
        return distanceToLowerLeftPoint(first) <= distanceToLowerLeftPoint(second);
    return ccw(lowerLeftPoint, first, second);
}

polygon grahamConvexHull(point vertices[], int number)
{
    polygon pg;
    pg.number = 0;

    if (number < 3)
    {
        for (int i = 0; i < number; i++)
            pg.vertices[i] = vertices[i];
        pg.number = number;
        return pg;
    }

    sort(vertices, vertices + number);
    number = unique(vertices, vertices + number) - vertices;

    lowerLeftPoint = vertices[0];
    sort(vertices + 1, vertices + number, smallerAngle);

    pg.vertices[0] = vertices[0];
    pg.vertices[1] = vertices[1];

    vertices[number] = lowerLeftPoint;

    int i = 2, top = 1;
    while (i <= number)
    {
        if (cw(pg.vertices[top - 1], pg.vertices[top], vertices[i]))
            top--;
        else if (collinear(pg.vertices[top - 1], pg.vertices[top], vertices[i]))
            pg.vertices[top] = vertices[i++];
        else
            pg.vertices[++top] = vertices[i++];
    }

    pg.number = top;

    return pg;
}

point intersection(line line1, line line2)
{
    point p = line1.a;
    double scale = ((line1.a.x - line2.a.x) * (line2.a.y - line2.b.y) -
        (line1.a.y - line2.a.y) * (line2.a.x - line2.b.x)) /
        ((line1.a.x - line1.b.x) * (line2.a.y - line2.b.y) -
        (line1.a.y - line1.b.y) * (line2.a.x - line2.b.x));
    p.x += (line1.b.x - line1.a.x) * scale;
    p.y += (line1.b.y - line1.a.y) * scale;
    return p;
}

line pointsToLine(point a, point b)
{
    line l;
    l.a = a;
    l.b = b;
    l.angle = atan2(b.y - a.y, b.x - a.x);
    return l;
}

polygon halfPlaneIntersection(line * edges, int n)
{
    polygon pg;
    line deques[MAXN];

    pg.number = 0;

    sort(edges, edges + n, cmpLine);
    n = unique(edges, edges + n, cmpAngle) - edges;

    int bottom = 0, top = 1;
    deques[0] = edges[0], deques[1] = edges[1];

    for (int i = 2; i < n; i++)
    {
        if (paralle(deques[top], deques[top - 1]) || paralle(deques[bottom], deques[bottom + 1]))
            return pg;

        while (bottom < top && cw(edges[i].a, edges[i].b,
                intersection(deques[top], deques[top - 1])))
            top--;

        while (bottom < top && cw(edges[i].a, edges[i].b,
                intersection(deques[bottom], deques[bottom + 1])))
            bottom++;

        deques[++top] = edges[i];
    }

    while (bottom < top && cw(deques[bottom].a, deques[bottom].b,
            intersection(deques[top], deques[top - 1])))
        top--;

    while (bottom < top && cw(deques[top].a, deques[top].b,
            intersection(deques[bottom], deques[bottom + 1])))
        bottom++;

    if (top <= (bottom + 1))
        return pg;

    for (int i = bottom; i < top; i++)
        pg.vertices[pg.number++] = intersection(deques[i], deques[i + 1]);

    if (bottom < (top + 1))
        pg.vertices[pg.number++] = intersection(deques[bottom], deques[top]);

    return pg;
}

int main(int argc, char *argv[])
{
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);

    int cases = 0;
    cin >> cases;

    for (int c = 1; c <= cases; c++)
    {
        if (c > 1)
            cout << '\n';

        int cuts;
        cin >> cuts;

        vector<polygon> pgs, next;

        polygon pg;
        pg.number = 4;
        pg.vertices[0] = point{0, 0};
        pg.vertices[1] = point{1000, 0};
        pg.vertices[2] = point{1000, 1000};
        pg.vertices[3] = point{0, 1000};
        pgs.push_back(pg);

        line edges1[MAXN], edges2[MAXN];

        double x1, y1, x2, y2;
        for (int i = 1; i <= cuts; i++)
        {
            cin >> x1 >> y1 >> x2 >> y2;

            point cutpoint1 = point{x1, y1}, cutpoint2 = point{x2, y2};

            for (int j = 0; j < pgs.size(); j++)
            {
                polygon somePg = pgs[j];

                int lines = 0;
                for (int k = 0; k < somePg.number; k++)
                {
                    point start = somePg.vertices[k];
                    point end = somePg.vertices[(k + 1) % somePg.number];

                    edges1[lines] = pointsToLine(start, end);
                    edges2[lines] = pointsToLine(start, end);

                    lines++;
                }

                edges1[lines] = pointsToLine(cutpoint1, cutpoint2);
                polygon pg1 = halfPlaneIntersection(edges1, lines + 1);

                edges2[lines] = pointsToLine(cutpoint2, cutpoint1);
                polygon pg2 = halfPlaneIntersection(edges2, lines + 1);

                polygon pg3 = grahamConvexHull(pg1.vertices, pg1.number);
                polygon pg4 = grahamConvexHull(pg2.vertices, pg2.number);

                if (pg3.number < 3 || pg4.number < 3)
                    next.push_back(somePg);
                else
                    next.push_back(pg3), next.push_back(pg4);
            }

            pgs.swap(next);
            next.clear();
        }

        cout << pgs.size() << '\n';
    }

    return 0;
}
