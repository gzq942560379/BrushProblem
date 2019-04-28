//
// Created by guozhuoqiang on 2019-04-27.
//
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<iterator>

using namespace std;

// 字典树实现

class WordTree {
	class Node {
	public:
		bool isWord{ false };
		//也可以用数组 哈希表实现
		map<char, Node> children;
	};

public:
	void add(const string& word) {
		Node* cur = &root;
		for (const char ch : word) {
			auto it = cur->children.find(ch);
			if (it == cur->children.end()) {
				cur->children[ch] = Node();
			}
			cur = &cur->children[ch];
		}
		cur->isWord = true;
	}

	bool checkIsConcatenatedWordInDict(const string& word, const int startIndex,const int count) {
		if (startIndex == word.size())
			return count > 1;
		Node * cur = &root;
		for (int i = startIndex; i < word.size(); i++) {
			char ch = word[i];
			auto it = cur->children.find(ch);
			if (it == cur->children.end()) {
				return false;
			}
			if (it->second.isWord) {
				if (checkIsConcatenatedWordInDict(word, i + 1, count + 1)) {
					return true;
				}
			}
			cur = &it->second;
		}
		return false;
	}

private:
	Node root;
};

class Solution {
public:
	vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
		WordTree tree;
		for (const string& word : words) {
			tree.add(word);
		}
		vector<string> result;
		for (const string& word : words) {
			if (tree.checkIsConcatenatedWordInDict(word, 0, 0)) {
				result.push_back(word);
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<string> input{ "cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat" };
	vector<string> output = s.findAllConcatenatedWordsInADict(input);
	copy(output.begin(), output.end(), ostream_iterator<string>(cout, "\n"));
	return 0;

}