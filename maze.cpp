#include<iostream>
#include<vector>
#include<string>
#include<set>

using field = std::vector<std::vector<char>>;
using row = std::vector<char>;
using point = std::pair<int, int>;
using set_of_points = std::set<point>;

const char start = 'A';
const char end = 'B';
const char wall = 'X';
const char corridor = ' ';

point search (const field& maze, char symbol){

	for(int x = 0; x<maze.size(); x++){
		for(int y = 0; y<maze[x].size(); y++){
			if(maze[x][y]==symbol){
				return {x, y};
			}
		}
	}
	throw std::runtime_error("symbol not found");
}

std::vector<point> get_neighbors(const field& maze, const point& p){

	std::vector<point> ret_val;
	
	if(p.first > 0){
		ret_val.push_back({p.first - 1, p.second});
	}
	if(p.second < maze[0].size() - 1){
                ret_val.push_back({p.first, p.second + 1});
        }
	if(p.first < maze.size() - 1){
                ret_val.push_back({p.first + 1, p.second});
        }
	if(p.second > 0){
                ret_val.push_back({p.first, p.second - 1});
        }

	
	return ret_val;
}

bool is_path_exist (const field& maze, const point& current, set_of_points& visited ) {
	
	char current_point = maze[current.first][current.second];
	//std::cout << '(' << current.first << ", " << current.second << ") " << current_point << std::endl;
	
	if (current_point==end){return true;}

	if (visited.count(current)){return false;}

	if (current_point==wall){return false;}


	visited.insert(current);
	
	std::vector<point> neighbors = get_neighbors(maze, current);

	for (int i = 0; i<neighbors.size(); i++){
		if(is_path_exist(maze, neighbors[i], visited)){
			return true;
		}
	}
	return false;
}

field read_maze () {
	
	char ch;
	field maze;
	row current_row;
	unsigned int width = 0, row_index = 0;
	bool met_a = false, met_b = false;
	

	while (std::cin.get (ch)){

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
	set_of_points visited;
	
	field maze = read_maze();
	
	for(int i = 0; i<maze.size(); i++){
		for(int j = 0; j < maze[i].size(); j++){
			std::cout << maze[i][j];
		}
		std::cout << std::endl;
	}
	point A = search(maze, 'A');
	
	std::cout << (
		is_path_exist(maze, A, visited) ? "path exist" : "path is not exist" 		
	) << std::endl;
	return 0;
}
catch (const std::exception& e)
{
	std::cerr << e.what() << std::endl;

	return 1;
}
}
