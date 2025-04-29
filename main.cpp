#include<iostream>
#include<vector>
#include<string>

using field = std::vector<std::vector<char>>;
using row = std::vector<char>;
using point = std::pair<int, int>;
using set_of_poits = std::set<point>;

const char start = 'A';
const char end = 'B';
const char wall = 'X';
const char corridor = ' ';

bool is_path_exist (const field& maze, const point& current, set_of_point& visited ) {
	
	char current_point = maze[current.first][current.second];

	
	if (current_point==end){
		return true;
	}

	if (visited.count(current)){
		return false;
	}

	if (current_point==wall){
		return false;
	}

	visited.insert(current);
	
	std::vector<point> neighbors = get_neighbors(maze, current);

	for (int i = 0; i<neighbors.size(); i++){
		if(is_path_exist(maze, neighbors[i], visited)){
			return true;
		}
	}

}

field read_maze () {
	
	char ch;
	field maze;
	row current_row;
	unsigned int width = 0, row_index = 0;
	bool met_a = false, met_b = false;
	

	while (std::cin.get (ch)){
		//std::cout << ch << std::endl;
		

		if(ch=='\n'){
			if (row_index==0)
				width = current_row.size();
			else {
				if(width != current_row.size()) 
					throw std::runtime_error("invalid width");
			}
			maze.push_back(current_row);
			current_row.clear();
			row_index++;
		}
		else if (ch=='X' || ch==' ' || ch=='A' || ch=='B') { 
			if(ch=='A' && met_a){throw std::runtime_error("duplicate A");}
			if(ch=='B' && met_b){throw std::runtime_error("duplicate B");}
			current_row.push_back(ch);
			if(ch=='A'){met_a=true;}
			if(ch=='B'){met_b=true;}
		}
		
		else {
			throw std::runtime_error(
				std::string("invalid symbol: ")
				+ch
				+std::string( "; at line: ")
				+std::to_string(row_index + 1));
		}
	}
	if (!(met_a && met_b)){throw std::runtime_error("A or B wasn't defined");}
	return maze;
}

int main () {
try
{
	int x=0;
	char ch;
	
	field maze = read_maze();
	
	for(int i = 0; i<maze.size(); i++){
		for(int j = 0; j < maze[i].size(); j++){
			std::cout<< maze[i][j];
		}
		std::cout<<std::endl;
	}

	return 0;
}
catch (const std::exception& e)
{
	std::cerr << e.what() << std::endl;

	return 1;
}
}
