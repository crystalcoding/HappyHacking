#include <iostream>
#include <algorithm>

template <typename m_type>
bool binary_search(m_type m_array[], int length, m_type target)
{
  //sort(m_array, m_array+length);
  //for (int i=0;i<length;++i) cout << m_array[i] << endl;
  length = length/2; //integer division, so don't worry about length
  m_type mid = length; 
  if (target == m_array[mid]) return true; //hit the middle
  if (length == 0) return false; //does not hit the middle, and no else to check
  else if (target < m_array[mid] ) {
    return binary_search(m_array, length, target);
  }
  else {
    //remember length -1 , since mid+1
    return binary_search(&m_array[mid+1], length-1, target); 
  }
}

int main()
{
  int ary[] = {1,2,3,4,5,-1};
  //std::cout <<sizeof(ary)<<std::endl; //24
  //std::cout <<sizeof(int)<<std::endl; //4
  const int len = sizeof(ary) / sizeof(int); //6
  std::cout << len << std::endl;
  std::sort(ary, ary+len);
  bool ret = binary_search(ary,len, 4);
  std::cout << ret << std::endl;  //1
}
