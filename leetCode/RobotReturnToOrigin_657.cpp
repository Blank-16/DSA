class Solution {
public:
    bool judgeCircle(string moves) {
        vector<int> l, r, u, d;
        for (char c : moves) {
            switch (c) {
            case 'L':
                l.push_back(1);
                if (r.size() != 0) {
                    r.pop_back();
                    l.pop_back();
                }
                break;
            case 'R':
                r.push_back(1);
                if (l.size() != 0) {
                    l.pop_back();
                    r.pop_back();
                }
                break;
            case 'U':
                u.push_back(1);
                if (d.size() != 0) {
                    u.pop_back();
                    d.pop_back();
                }
                break;
            case 'D':
                d.push_back(1);
                if (u.size() != 0) {
                    d.pop_back();
                    u.pop_back();
                }
                break;
            }
        }

        return l.size() == 0 && r.size() == 0 && u.size() == 0 && d.size() == 0;
    }
};

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char& c : moves) {
            if (c == 'L')
                x--;
            if (c == 'R')
                x++;
            if (c == 'U')
                y--;
            if (c == 'D')
                y++;
        }
        return x == 0 && y == 0;
    }
};
