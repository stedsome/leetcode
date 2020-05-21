#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>

std::string customSortString(std::string S, std::string T) {
	std::map<char, size_t> map;

	for (int i = 0; i < T.size(); i++) {
		if (map.find(T[i]) == map.end()) {
			map[T[i]] = 1;
		} else {
			map[T[i]]++;
		}
	}

	std::string ret = "";
	for (int i = 0; i <= S.size(); i++) {
		if (map.find(S[i]) != map.end()) {
			ret.append(map[S[i]], S[i]);
			map.erase(S[i]);
		}
	}

	for (auto it = map.begin(); it != map.end(); it++) {
		ret.append(it->second, it->first);
	}
	return ret;
}

int main (int argc, char** argv) {
	std::cout << customSortString("cba", "abcd") << std::endl;
	std::cout << customSortString("", "happy feb") << std::endl;
}