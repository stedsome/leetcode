#include <stdio.h>
#include <iostream>
#include <string.h>
int countLetters(std::string s) {
	    int ret = 0;
	if (s.size() == 0) {
		return 0;
	}
	char prev = s[0];
	int currLen = 0;
	for (int i = 0; i < s.size(); i++) {
		char curr = s[i];
		if (prev == curr) {
			currLen++;
		} else {
			while (currLen > 0) {
				ret += currLen;
				currLen--; 
			}
			currLen = 1;
			prev = s[i];
		}
	}

	if (currLen != 0) {
		while (currLen > 0) {
			ret += currLen;
			currLen--; 
		}
	}
	return ret;
}

int main (int argc, char** argv) {
	std::string s = "aaaba";
	std::cout << "string " << s << " : "<< countLetters(s) << std::endl;
	s = "aaaaaaaaaa";
	std::cout << "string " << s << " : "<< countLetters(s) << std::endl;
	s = "";
	std::cout << "string " << s << " : "<< countLetters(s) << std::endl;
	s = "abcdefghieeeee";
	std::cout << "string " << s << " : "<< countLetters(s) << std::endl;
}