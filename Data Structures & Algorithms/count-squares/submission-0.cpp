
class CountSquares {
public:
    map<pair<int, int>, int> mp;

    CountSquares() {
        
    }

    void add(vector<int> point) {
        mp[{point[0], point[1]}]++;
    }

    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ans = 0;

        for (auto &p : mp) {
            int x1 = p.first.first;
            int y1 = p.first.second;

            // Check diagonal point
            if (abs(x - x1) != abs(y - y1) || x == x1)
                continue;

            // Check remaining two corners
            int side = abs(x - x1);

            ans += p.second *
                   mp[{x, y1}] *
                   mp[{x1, y}];
        }

        return ans;
    }
};
