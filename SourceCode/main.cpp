#include "maze.h"
#include <sstream>
#include <regex>
#include <string.h>



vector<string> parse(string  str, char delim)
{
    // construct a stream from the string
    std::stringstream ss(str);
    vector<string> out;
    std::string s;
    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
    return out; 
}


vector<vector<int>> parse_line(vector<string> line){


vector<string> newline, coordinates; 
string extract_string;
vector<vector<int>> returned;
vector<int> coornum; //num coordinates;;;;
for (int i=0; i< line.size();i++){
     newline= parse(line[i], ' ');
     for (int j=1;j<newline.size();j++){
         int length = newline[j].length();
         coordinates= parse(newline[j].substr(1,length-2), ','); 
         for (int m=0; m<coordinates.size();m++){
             int value; 
             stringstream ss(coordinates[m]);
             ss >> value;
             coornum.push_back(value);

         }
     }
     returned.push_back(coornum);   
     coornum.clear(); 

}

return returned; 

}



int main(){
ifstream infile; 
infile.open("test4.txt");
vector<string> inputfromfile; 
string temp;
while(getline(infile, temp)){ 
                
        inputfromfile.push_back(temp);
}
cout<<"size: "<<inputfromfile.size()<<endl;



vector <vector<int>> pointsfromfile, pointsupdated;
vector<int> realpos; 
pointsfromfile= parse_line(inputfromfile);
ofstream outmap; 
outmap.open("outmap.txt");


maze mine; 
mine.create_graph();
for (int i=0; i<pointsfromfile.size(); i++){

    pointsupdated=mine.Lee_Maze(pointsfromfile[i]);
    for (int i=0; i< pointsupdated.size();i++){
        for (int j=0 ; j< pointsupdated[i].size();j++)
            cout<< pointsupdated[i][j]<<"\t";
        cout<<endl;
    }

    outmap<<i<<".\n"; 
    for (int i=0; i< pointsupdated.size();i++){
        for (int j=0 ; j< pointsupdated[i].size();j++){
            
            realpos= mine.map_real_position(pointsupdated[i][j]);
            outmap<<"(";
            outmap<<realpos[0]<<","<<realpos[1]<<","<<realpos[2];
            outmap<<")\n";
            realpos.clear();
            
        }
    }
pointsupdated.clear();
}

return 0; 

}
