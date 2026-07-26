class Solution {
	public:
	string findOrder(vector<string> &words) {
		// code here
		int n = words.size();
		vector<pair<char, char>> vec;
		for (int i = 0; i<n - 1; i++) {
			string a = words[i];
			string b = words[i + 1];
			int x = 0, y = 0;
			while (x<a.length() and y<b.length()) {
				if (a[x] != b[y]) {
					vec.push_back({a[x], b[y]});
					break;
				}
				x++; y++;
				if (x == b.length() && a.length() > b.length())
					return "";
			}
		}
		unordered_set<char>s;
		unordered_map<char, unordered_set<char>> adj;
		for (auto i:vec) {
			adj[i.first].insert(i.second);
		}
		for (auto i:words) {
			for (auto j:i)s.insert(j);
		}
		const int len = s.size();
		
		unordered_map<char, int>indeg;
		for (auto i:adj) {
			for (auto j:i.second)
				indeg[j]++;
		}
		
		queue<char>q;
		for (auto i:s) {
			if (indeg[i] == 0)q.push(i);
		}
		string ans = "";
		while (!q.empty()) {
			char ch = q.front();
			ans += ch;
			q.pop();
			for (auto c:adj[ch]) {
				indeg[c]--;
				if (indeg[c] == 0)q.push(c);
			}
		}
		if (ans.length() == len)return ans;
		return "";
	}
};
