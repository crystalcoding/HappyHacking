//This program traverses a given directory and prints out the the files orderd by size//
//compile under FreeBSD:
//g++ large_files.cpp -I/usr/local/include -L/usr/local/lib/ -lboost_filesystem
//to compile a static executable (need to add libboost_system.a)
//g++ large_files.cpp -I/usr/local/include -L/usr/local/lib/ -lboost_filesystem -lboost_system -static

#include "boost/filesystem.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace  boost::filesystem;
using namespace std;

class Node {
public:
  Node(string p, int s):path(p), file_size(s) {}
  string path;
  int file_size;
};

class node_compare {
public:
  bool operator()(Node n1, Node n2) { return n1.file_size < n2.file_size; }
};

void traverse (string start_directory, vector<Node> &node_vector)
{
  directory_iterator end_iter;
  for (directory_iterator dir_itr((start_directory)); dir_itr != end_iter; ++dir_itr){
    if ( is_directory(dir_itr->status())) {
      cout << dir_itr->path().filename() << " (directory)" << endl;
      traverse(string(dir_itr->path().file_string()), node_vector);
      }
      else {

	int mFileSize;
	if (is_regular_file(dir_itr->status())){
        //try {
	  //mFileSize = file_size((dir_itr->path())) / 1000; // in KB
	  mFileSize = file_size(dir_itr->path().directory_string()) / 1000; // in KB
	  //}
	  //catch (...){
	  //  cout << "what is the exception" << endl;
	  //}
	  cout << dir_itr->path().filename() << " size:" << mFileSize << "KB" << endl;
	  node_vector.push_back(Node(dir_itr->path().directory_string(), mFileSize));
	  }
	else {
	  //need to take care of other cases, e.g. symbolic links
	}
      }
  }
}

int main(int argc, const char* argv[])
{
  //string start_directory = "/home/bps/Desktop/";
  string start_directory = argv[1];
  vector<Node> node_vector;
  traverse(start_directory, node_vector);
  cout << endl;

  sort(node_vector.begin(), node_vector.end(), node_compare());

  for (int i=0;i<node_vector.size();++i) {
    //cout << i ;
    cout << node_vector[i].path << ":";
    cout << node_vector[i].file_size << "KB" << endl;
  }
}
