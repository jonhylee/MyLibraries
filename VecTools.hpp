/*********************************************
  *Copyright(C)		zhiqli					 
  *FileName:		VecTools.h			     
  *Author:			zhiqli
  *Version:			v1.0
  *Date:			2014-8-11
  *Description:		vector工具类
  *Platform:		windows 7

  *Others:		
  *History:  
     1.Date:		2014-8-11
       Author:		zhiqli
       Modification:创建文件
***********************************************/
#ifndef __VECTOOLS_HH__
#define __VECTOOLS_HH__

#include <ostream>
#include <iostream>
#include <vector>
#include <sstream>

template<class T>
void write(std::vector<T> t, std::ostream& out) {
    for (auto it = t.begin(); it != t.end(); it++)
        out << *it << std::endl;
}

template<class Iterator>
void write(Iterator begin, Iterator end, std::ostream& out) {
    for (auto it = begin; it != end; it++)
        out << *it << std::endl;
}

template<class Iterator>
void print(Iterator begin, Iterator end) {
    write(begin, end, std::cout);
}

template<class T>
void print(std::vector<T> t) {
    write(t, std::cout);
}

/** Find the index of the nth occurence of char "to_find"
  * If "to_find" appears "how_many" times return the index of the last occurence
  * Else return -1;
  *
  * @param vec       The vector to search
  * @param to_find   The character to find in the vector
  * @param how_many  The number of times the character should appear
  * @return The index of the last appearance of "to_find" if "to_find"
  *         appeared "how_may" times, -1 otherwise
  */
template<class T>
int find_nth_in(std::vector<T> vec, T to_find, unsigned int how_many) {
    unsigned int i = 0, found = 0;
    for (; i < vec.size() && found < how_many; i++)
        if (vec[i] == to_find) ++found;

    if (found == how_many) 
		return --i;
    else 
		return -1;
}

template<class T>
void AppendArray(std::vector<T> &vec, T* arr, unsigned int size) {
    vec.reserve(vec.size() + size);
    for (unsigned int i = 0; i < size; i++)
        vec.push_back(arr[i]);
}

template<class T>
bool compare(std::vector<T> &vec1, std::vector<T> &vec2) {
    if (vec1.size() != vec2.size()) return false;

    auto it1 = vec1.begin(), it2 = vec2.begin();

    for (; it1 != vec1.end(); it1++, it2++)
        if ((*it1) != (*it2)) return false;

    return true;
}

template<class T>
std::string concat(std::vector<T> in, char sep = ' ') {
    std::stringstream ss;
    for (auto it = in.begin(); it != in.end(); it++)
        ss << *it << sep;

    std::string str = ss.str();
    if (str.length() > 0)
        str.erase(str.length() - 1);

    return str;
}

#endif 
