#include <iostream>
#include <queue>
#include <string>
#include <map>
#include <vector>
#include <climits>
#include <set>
using namespace std;

struct par {
	string word;
	int pos;
	par(string w, int p) {
		word = w;
		pos = p;
	}
};

bool operator <(par x, par y) {
	return x.pos > y.pos;
}

vector<string> words;
priority_queue<par> q;
map<string, int> rightmost;
map<string, bool> repeated;

int main() {
	freopen("11860.inp", "r", stdin);
	freopen("11860.out", "w", stdin);
	int docs;
	cin >> docs;
	for (int doc = 1; doc <= docs; doc++) {
		words.clear();
		string line;
		repeated.clear();
		int m = 0;
		while (getline(cin, line) && line != "END") {
			string word = "";
			for (int i = 0; i < line.length(); i++)
				if (line[i] >= 'a' && line[i] <= 'z')
					word += line[i];
				else if (word.length() > 0) {
					words.push_back(word);
					if (!repeated[word]) {
						m++;
						repeated[word] = true;
					}
					word = "";
				}
			if (word.length() > 0) {
				words.push_back(word);
				if (!repeated[word]) {
					m++;
					repeated[word] = true;
				}
				word = "";
			}
		}

		int p = 0, sol = INT_MAX, seen = 0, n = words.size();
		rightmost.clear();
		q = priority_queue<par>();
		for (int i = 1; i <= n; i++) {
			string word = words[i - 1];
			if (rightmost[word] == 0)
				seen++;
			rightmost[word] = i;
			q.push(par(word, i));
			while (!q.empty() && q.top().pos != rightmost[q.top().word])
				q.pop();
			if (seen == m && i - q.top().pos < sol) {
				sol = i - q.top().pos;
				p = q.top().pos;
			}
		}

		cout << "Document " << doc << ": " << p << " " << p + sol << endl;

	}

}