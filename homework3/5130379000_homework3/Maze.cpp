/*
 * Use standard I/O to read test file and output answer.
 * There are three test file: testmap_1.txt, testmap_2.txt, testmap_3.txt,
 * and your output should like:
 * testmap_1: (1,1) (1,2) (1,3) (2,3) ...
 * More detail on course websit
 */

/*
 *Name:YeXiaoRain
 *ID:5130379000
 */

/*
 * ' '=empty 
 * 'S'=start
 * 'E'=end
 * other is wall
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int derx[]={1,-1,0,0};
int dery[]={0,0,1,-1};
struct my_point{
	int x,y;
};
void print_ans(string filename,vector <my_point> & m_path)
{
	int i,pathlen=m_path.size();
	cout<<filename<<":";
	for(i=0;i<pathlen;i++){
		cout<<" ("<<m_path[i].x<<","<<m_path[i].y<<")";
	}
	cout<<endl;
}
bool digui(int nowx,int nowy,vector<vector<int> > & m_maze,vector <my_point> & m_path)
{
	m_maze[nowy][nowx]=-1;//visited
	//find way
	int j,newx,newy;
	for(j=0;j<4;j++){//four direction
		//create new point
		newx=nowx+derx[j];
		newy=nowy+dery[j];
		if(!m_maze[newy][newx] ||m_maze[newy][newx]==2 )//empty or distance
		{
			my_point newp={newx-1,newy-1};
			m_path.push_back(newp); 
			if(m_maze[newy][newx]==2)//find End
				return true;
			if(digui(newx,newy,m_maze,m_path))
				return true;
			m_path.pop_back();
		}
	}
	m_maze[nowy][nowx]=0;
	return false;
}
void solve_maze(string filein){
	vector<vector<int> > vv_maze;
	vector<int> v_line;
	vector<my_point> path;
	stringstream firstline;
	string line_info;
	int max_x,max_y;
	ifstream fin((filein+".txt").c_str());
	getline(fin,line_info);
	firstline<<line_info;
	firstline>>max_x>>max_y;
	//-1(can't reach),0(empty),1(start), 2(end);
	vector<int>firlast_line(max_x+2,-1);//bian jie
	vv_maze.push_back(firlast_line);
	while(getline(fin,line_info)){//getline
		//translate letter to -1(can't reach),0(empty),1(start), 2(end)
		v_line.clear();
		v_line.push_back(-1);//bian jie
		int i,strlen=line_info.length();
		for(i=0;i<strlen;i++){
			switch(line_info[i]){
				case ' ':
					v_line.push_back(0);
					break;
				case 'S':
					v_line.push_back(1);
					break;
				case 'E':
					v_line.push_back(2);
					break;
				default:
					v_line.push_back(-1);
			}
		}
		v_line.push_back(-1);//bian jie
		vv_maze.push_back(v_line);
	}
	vv_maze.push_back(firlast_line);
	fin.close();
	int i,j;
	int stx=0,sty=0;
	for(i=1;i<=max_x;i++)
		for(j=1;j<=max_y;j++)
			if(vv_maze[j][i]==1)
			{
				stx=i;
				sty=j;
			}
	if(digui(stx,sty,vv_maze,path))
		print_ans(filein,path);
	else
		cout<<"no ans"<<endl;
	return ;
}
int main()
{
	solve_maze("testmap_1");
	solve_maze("testmap_2");
	solve_maze("testmap_3");
	return 0;
}
