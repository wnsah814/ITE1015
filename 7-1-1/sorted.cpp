#include "sorted.h"
#include <vector>
#include <algorithm>
#include <functional>

SortedArray::SortedArray() {
    
}

SortedArray::~SortedArray() {

}

void SortedArray::AddNumber(int num) {
    numbers_.push_back(num);
}

std::vector<int> SortedArray::GetSortedAscending() {
    std::vector<int> copy = numbers_;
    std::sort(copy.begin(), copy.end());
    return copy;
}

std::vector<int> SortedArray::GetSortedDescending() {
    std::vector<int> copy = numbers_;
    std::sort(copy.begin(), copy.end(), std::greater<int>());
    return copy;
}

int SortedArray::GetMax() {
    int max = *max_element(numbers_.begin(), numbers_.end());
    return max;
}

int SortedArray::GetMin() {
    int min = *min_element(numbers_.begin(), numbers_.end());
    return min;
}