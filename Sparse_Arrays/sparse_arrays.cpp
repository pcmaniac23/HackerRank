#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries) {
	unordered_map<string, int> m;

	for (string s : strings) {
		unordered_map<string, int>::iterator itr = m.find(s);
		if (itr == m.end()) {
			m.insert(pair<string, int>(s, 1));
		}
		else {
			itr->second++;
		}
	}

	vector<int> res;
	for (string q : queries) {
		unordered_map<string, int>::iterator itr = m.find(q);
		if (itr == m.end()) {
			res.push_back(0);
		}
		else {
			res.push_back(itr->second);
		}
	}

	return res;
}