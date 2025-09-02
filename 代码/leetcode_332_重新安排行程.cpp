#include <bits/stdc++.h>
using namespace std;

class cmp {
public:
    bool operator()(const vector<string>& a, const vector<string>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
};

void listfindItinerary(vector<vector<string>>& tickets, vector<bool>& vis,
                       vector<string>& res) {
    for (auto& s : res) {
        cout << s << " ";
    }
    cout << endl;
    if (res.size() == tickets.size() + 1) {
        cout << "找到了" << endl;
        return;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if ((res.empty() && !vis[i] && tickets[i][0] == "JFK")) {
            vis[i] = 1;
            res.push_back(tickets[i][0]);
            res.push_back(tickets[i][1]);
            listfindItinerary(tickets, vis, res);
            if (res.size() == tickets.size() + 1) {
                return;
            }
            res.pop_back();
            res.pop_back();
            vis[i] = 0;
        } else if (!res.empty() && !vis[i] && tickets[i][0] == res.back()) {
            vis[i] = 1;
            res.push_back(tickets[i][1]);
            listfindItinerary(tickets, vis, res);
            if (res.size() == tickets.size() + 1) {
                return;
            }
            res.pop_back();
            vis[i] = 0;
        }
    }
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    sort(tickets.begin(), tickets.end(), cmp());
    vector<string> res;
    vector<bool> vis(tickets.size(), 0);
    listfindItinerary(tickets, vis, res);
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<vector<string>> tickets = {
        // {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
        {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "JFK"}, {"ATL", "AAA"},
        {"AAA", "ATL"}, {"ATL", "BBB"}, {"BBB", "ATL"}, {"ATL", "CCC"},
        {"CCC", "ATL"}, {"ATL", "DDD"}, {"DDD", "ATL"}, {"ATL", "EEE"},
        {"EEE", "ATL"}, {"ATL", "FFF"}, {"FFF", "ATL"}, {"ATL", "GGG"},
        {"GGG", "ATL"}, {"ATL", "HHH"}, {"HHH", "ATL"}, {"ATL", "III"},
        {"III", "ATL"}, {"ATL", "JJJ"}, {"JJJ", "ATL"}, {"ATL", "KKK"},
        {"KKK", "ATL"}, {"ATL", "LLL"}, {"LLL", "ATL"}, {"ATL", "MMM"},
        {"MMM", "ATL"}, {"ATL", "NNN"}, {"NNN", "ATL"}};
    vector<string> res;
    // string a, b;
    // while (cin >> a >> b) {
    // tickets_i.clear();
    // tickets_i.push_back(a);
    // tickets_i.push_back(b);
    // tickets.push_back(tickets_i);
    // }
    res = findItinerary(tickets);
    for (auto& s : res) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}