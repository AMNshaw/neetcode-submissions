class Point {
public:
    int x_, y_;
    double d_;

    Point(int x, int y) : x_(x), y_(y) {
        d_ = sqrt(x_ * x_ + y_ * y_);
    }
};

class Solution {
public:
    static bool compare(const Point* a, const Point* b) { 
        return a->d_ > b->d_; // Min-heap: smallest distance has highest priority
    }

    priority_queue<Point*, vector<Point*>, function<bool(const Point*, const Point*)>> minHeap_;

    Solution() : minHeap_(compare) {}

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (auto &point : points) {
            minHeap_.push(new Point(point[0], point[1])); // Store pointers
        }

        vector<vector<int>> arr;
        for (int i = 0; i < k; i++) {
            Point* topPoint = minHeap_.top();
            arr.push_back({topPoint->x_, topPoint->y_});
            minHeap_.pop();
            delete topPoint; // Free memory
        }

        return arr;
    }
};