#ifndef __setfunc__
#define __setfunc__

#include <set>

std::set<int> parseSet(const std::string& str);
void printSet(const std::set<int>& s);
std::set<int> getIntersection(const std::set<int>& set0, const std::set<int>& set1);
std::set<int> getUnion(const std::set<int> set0, const std::set<int>& set1);
std::set<int> getDifference(const std::set<int>& set0, const std::set<int>& set1);
#endif