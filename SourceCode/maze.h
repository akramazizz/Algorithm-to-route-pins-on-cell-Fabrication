#pragma once 
#include <iostream>
#include <vector>
#include <fstream>
using namespace std; 

// #define m 20
#define n 20000
#define INFINITE  9999

struct cell{
int x,y;   //x and y coordinates
bool valid;  // determine whether it is blocked or not
bool layer; // determine which layer this cell belongs to 

};

struct node{
int weight; 
int index;
}; 



class maze{

private:

  //vector<vector<node>> maze_list;  
  vector<vector<int>> maze_matrix;
  void block_cell(int);
  vector<vector<int>> dijkpath(int startNode);
  
  

public:
    maze();
    vector<int> findthepath(vector<vector<int>> paths, int);
    void create_graph();
    void print_graph();
    int map_real_index(int,int,int);
    vector<int> map_real_position(int);
    vector<vector<int>> Lee_Maze(vector<int>);

}; 
