#pragma once

vector<int> findAnagrams(string s, string p) {
	if (s.empty() || s.size() < p.size())
		return {};
	vector<int> res, asc_s(256, 0), asc_p(256, 0);
	for (auto i = 0; i < p.size(); i++) {
		asc_s[s[i]]++;
		asc_p[p[i]]++;
	}
	if (asc_s == asc_p)
		res.push_back(0);
	for (auto i = p.size(); i != s.size(); ++i) {
		asc_s[s[i - p.size()]]--;
		asc_s[s[i]]++;
		if (asc_s == asc_p) {
			res.push_back(i - p.size() + 1);
		}
	}
	return res;
}