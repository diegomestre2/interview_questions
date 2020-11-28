#pragma once

string reverseWords(string s) {
	string word = "";
	string rev = "";
	int lastword = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] != ' ') {
			lastword = i;
			break;
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			word += s[i];
		} else {
			if (word != "") {
				rev = word + rev;
				if (i != lastword + 1)
					rev = " " + rev;
			}
			word = "";
		}
	}
	if (word != "")
		rev = word + rev;
	return rev;
}