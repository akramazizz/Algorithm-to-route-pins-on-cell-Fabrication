#include "maze.h"

maze::maze(){
    // maze_list.resize(n);
    maze_matrix.resize(n);
    for (int i=0; i<maze_matrix.size(); i++){
        maze_matrix[i].resize(n);
        maze_matrix[i].assign(n,0);
    }
}




void maze :: create_graph(){

for (int i=0; i<maze_matrix.size(); i++){
    
    if (i<n/2){
    //layer 1  horizontal; 

        if (i%100==99){
            //last column
            if(i==99){        
            maze_matrix[i][i-1]=1; 
            maze_matrix[i][i+100]= 10; 
            maze_matrix[i][i+n/2]= 15;        
            }
            else if(i==(n/2)-1){        
            maze_matrix[i][i-1]=1; 
            maze_matrix[i][i-100]= 10; 
            maze_matrix[i][i+n/2]= 15;        
            }
            else {
            maze_matrix[i][i-1]=1; 
            maze_matrix[i][i-100]= 10; 
            maze_matrix[i][i+100]= 10; 
            maze_matrix[i][i+n/2]= 15;

            }
            
        }

        else if (i%100==0){
            //first column
            if(i==0){        
            maze_matrix[i][i+1]=1; 
            maze_matrix[i][i+100]= 10; 
            maze_matrix[i][i+n/2]= 15;        
            }
            else if(i==(n/2)-100){        
            maze_matrix[i][i+1]=1; 
            maze_matrix[i][i-100]= 10; 
            maze_matrix[i][i+n/2]= 15;        
            }
            else {
            maze_matrix[i][i+1]=1; 
            maze_matrix[i][i-100]= 10; 
            maze_matrix[i][i+100]= 10; 
            maze_matrix[i][i+n/2]= 15;

            }
            
        }

        else if (i<99){
            //first row
            if(i==0){        
            maze_matrix[i][i+1]=1; 
            maze_matrix[i][i+100]= 10; 
            maze_matrix[i][i+n/2]= 15;        
            }
            
            else {
            maze_matrix[i][i+1]=1; 
            maze_matrix[i][i-1]=1; 
            maze_matrix[i][i+100]= 10; 
            maze_matrix[i][i+n/2]= 15;
            }
            
        }

        else if (i> (n/2)-100){
            //last row
            
            maze_matrix[i][i+1]=1; 
            maze_matrix[i][i-1]=1; 
            maze_matrix[i][i-100]= 10; 
            maze_matrix[i][i+n/2]= 15;
            
            
        }

        else {
            // intermediate nodes..
            maze_matrix[i][i+1]=1; 
            maze_matrix[i][i-1]=1; 
            maze_matrix[i][i-100]= 10; 
            maze_matrix[i][i+100]= 10; 
            maze_matrix[i][i+n/2]= 15;
        }


    }

    else {

        //layer2  veriical 

         if (i%100==99){
            //last column
            if(i==(n/2+99)){        
            maze_matrix[i][i-1]=10; 
            maze_matrix[i][i+100]= 1; 
            maze_matrix[i][i-n/2]= 15;        
            }
            else if(i==n-1){        
            maze_matrix[i][i-1]=10; 
            maze_matrix[i][i-100]= 1; 
            maze_matrix[i][i-n/2]= 15;        
            }
            else {
            maze_matrix[i][i-1]=10; 
            maze_matrix[i][i-100]= 1; 
            maze_matrix[i][i+100]= 1; 
            maze_matrix[i][i-n/2]= 15;

            }
            
        }

        else if (i%100==0){
            //first column
            if(i==n/2){        
            maze_matrix[i][i+1]=10; 
            maze_matrix[i][i+100]= 1; 
            maze_matrix[i][i-n/2]= 15;        
            }
            else if(i==n-100){        
            maze_matrix[i][i+1]=10; 
            maze_matrix[i][i-100]= 1; 
            maze_matrix[i][i-n/2]= 15;        
            }
            else {
            maze_matrix[i][i+1]=10; 
            maze_matrix[i][i-100]= 1; 
            maze_matrix[i][i+100]= 1; 
            maze_matrix[i][i-n/2]= 15;

            }
            
        }

        else if (i<((n/2)+99)){
            //first row
            if(i==n/2){        
            maze_matrix[i][i+1]=10; 
            maze_matrix[i][i+100]= 1; 
            maze_matrix[i][i-n/2]= 15;        
            }
            
            else {
            maze_matrix[i][i+1]=10; 
            maze_matrix[i][i-1]=10; 
            maze_matrix[i][i+100]= 1; 
            maze_matrix[i][i-n/2]= 15;
            }
            
        }

        else if (i> n-100){
            //last row
            
            maze_matrix[i][i+1]=10; 
            maze_matrix[i][i-1]=10; 
            maze_matrix[i][i-100]= 1; 
            maze_matrix[i][i-n/2]= 15;
            
            
        }

        else {
            // intermediate nodes..
            maze_matrix[i][i+1]=10; 
            maze_matrix[i][i-1]=10; 
            maze_matrix[i][i-100]= 1; 
            maze_matrix[i][i+100]= 1; 
            maze_matrix[i][i-n/2]= 15;
        }



    }

}

    cout<<endl;
}




int maze::map_real_index(int layer,int x,int y){

    if (layer==1){
    return (y)*100 +x; 
    }

    else if (layer==2){

    return 10000+(y)*100 +x;

    }

    else{
    return -1; 
    }

}



vector<int> maze::map_real_position(int index){
    
    vector <int> coor;  // coordinates
    int x; 
    int y; 
    if (index<n/2){
        coor.push_back(1);
        x= index%100;
        y= (index-x)/100;  
        coor.push_back(x);
        coor.push_back(y);


    }
    else{ 
        coor.push_back(2);
        x= index%100;
        y= (index-x-10000)/100;  
        coor.push_back(x);
        coor.push_back(y);
    }

    return coor; 


}


vector<vector<int>> maze :: Lee_Maze(vector<int> points){

vector<vector<int>> nodes; //holds number of nodes needing to be connected; 
vector<vector<int>> returned; //holds a sequence of the indices representing the path from the source to the target 
vector <int> temp; 

for (int i=0 ;i<points.size();i++)
    cout<<points[i]<<"\t";
cout<<endl;

for (int i=0; i< points.size()/3; i++){
temp.push_back(points[i*3]);
temp.push_back(points[i*3+1]);
temp.push_back(points[i*3+2]);
nodes.push_back(temp);
temp.clear();
}

vector<int> indices;
for (int i=0; i<nodes.size();i++){
    int tempindex= map_real_index(nodes[i][0], nodes[i][1],nodes[i][2]);
    indices.push_back(tempindex); 
}

vector<vector<int>> paths;
vector<int> desired_path; 
for (int i=0;i < indices.size()-1; i++){

paths= dijkpath(indices[i]);



desired_path= findthepath(paths, indices[i+1]);
returned.push_back(desired_path);




desired_path.clear();
}
for (int i=0; i<returned.size(); i++){
    for (int j=0; j<returned[i].size();j++){
    block_cell(returned[i][j]);
    }
}





return returned; 




}










void maze:: print_graph(){

ofstream outfile; 
outfile.open("output.txt");
for (int i=0; i<n; i++)
    outfile<< i<<"\t"; 

outfile <<endl; 
for (int i=0; i<maze_matrix.size(); i++){
    
    for (int j=0; j<maze_matrix[i].size();j++){        
        outfile <<maze_matrix[i][j]<<"\t";
    }

    outfile<<endl;
}
    outfile<< endl; 



}

void maze::block_cell(int index){
    for (int i=0; i<n; i++)
        maze_matrix[index][i]=0; 
    
    for (int i=0; i<n; i++)
        maze_matrix[i][index]=0;

}


vector<vector<int>> maze::dijkpath(int startNode) {
    vector<int> one(n,0);
    vector<vector<int>> temp(n,one);
	int costs[n], previous[n];
	bool visited[n];
	//temp
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (maze_matrix[i][j] == 0)
				temp[i][j] = INFINITE;
			else
				temp[i][j] = maze_matrix[i][j];
	 //costs, previous, and visited
	for (int i = 0; i < n; i++)
	{
		costs[i] = temp[startNode][i];
		previous[i] = startNode;
		visited[i] = false;
	}
	 //startNode
	costs[startNode] = 0;
	visited[startNode] = true;

	int count = 1, nextNode, minimumCost;
	while (count < n)
	{
		 //Find the minimum cost in order to visit a node.
		minimumCost = INFINITE;
		for (int i = 0; i < n; i++)
			if ((costs[i] < minimumCost) && (visited[i] == false))
			{
				minimumCost = costs[i];
				nextNode = i;
			}
		 //Visit the node.
		visited[nextNode] = true;
		 //Update the costs of the children of the visited node.
		for (int i = 0; i < n; i++)
			if ((minimumCost + temp[nextNode][i] < costs[i]) && (visited[i] == false))
			{
				costs[i] = minimumCost + temp[nextNode][i];
				previous[i] = nextNode;
			}
		count++;
	}
	 //Fill the paths.
	int j;
	vector<vector<int>> paths;
	paths.resize(n);
	for (int i = 0; i < n; i++)
	{
		paths[i].push_back(i);
		if (i != startNode)
		{
			j = i;
			do
			{
				j = previous[j];
				paths[i].insert(paths[i].begin(), j);
			} while (j != startNode);
		}
	}
	return paths;

}



vector<int> maze::findthepath(vector<vector<int>> paths, int target) {
	
	for (int i = 0; i < paths.size(); i++){

		int size = paths[i].size();
		if (paths[i][size - 1] == target)
			return paths[i];

	}
	
	return paths[1];

}


