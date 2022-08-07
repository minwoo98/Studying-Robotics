#include <iostream>
#include <stdio.h>
#include <stdlib.h> //난수 생성을 위한 헤더 
#include <math.h> 
#include <time.h>
#include <cstring>
#include <vector>
#include <algorithm>

#define RND_SIZE 10
#define ITERATION 40

using namespace std;

char map[16][16];
int start_x = 0, start_y = 0;
int goal_x = 8, goal_y = 8;

typedef pair<int,int> p;
vector<p> tree;
vector<pair<double,p>> dist_temp;


int main(void)
{
	srand(time(NULL));
	memset(map,'0',sizeof(map));
	
	map[start_y][start_x] = 'S';
	map[goal_y][goal_x] = 'G';
	
	cout << "obstacle_num : ";
	int obs_num;
	cin >> obs_num;
	
	for(int i=0; i<obs_num; i++)
	{
		cout << "[" << i+1 << "]" <<"obstacle (y,x): ";
		int obs_y, obs_x;
		cin >> obs_y >> obs_x;
		
		map[obs_y][obs_x] = 'X'; //0: walkable, 1: non-walkable
	}
	
	tree.push_back({start_y,start_x});
	
	//나중에 WHILE문으로 바꿔야할듯? 
	for(int itr = 1; itr <=100; itr++)
	{
		//generate random sampling
		int rdm_y = rand()%15;
		int rdm_x = rand()%15;
		
		cout << "Random (y,x): " << rdm_y << ' ' << rdm_x << '\n';
		
		if(rdm_y == 0 && rdm_x == 0)	itr -= 1;		
	    //cout << rdm_y << ' ' << rdm_x << '\n';
	    //select the nearest to random samples in tree

		for(int i=0; i<tree.size(); i++)
		{
			double dist_y = (tree[i].first - rdm_y);
			double dist_x = (tree[i].second - rdm_x);
			
			double dist = sqrt(pow(dist_y,2) + pow(dist_x,2));
			
			dist_temp.push_back({dist,{tree[i].first, tree[i].second}});
			//cout << dist << ' ';
		}
		cout << '\n';
		//select the nearest node
		sort(dist_temp.begin(), dist_temp.end());

		int nearest_y = dist_temp[0].second.first;
		int nearest_x = dist_temp[0].second.second;
		
		//cout << nearest_y << ' ' << nearest_x << '\n';
		//nearest -> rdm 방향으로 delta만큼 떨어진 new정하기(일단 중점으로) 
		//장애물 없이
		
		int new_y = (nearest_y + rdm_y) / 2;
		int new_x = (nearest_x + rdm_x) / 2;
		
		if(map[new_y][new_x] != '*')
		{
			tree.push_back({new_y,new_x}); 
		}
		
		if(new_y == goal_y && new_x == goal_x)
		{
			cout << "Arrive at the goal point!!" << '\n';
			break;
		}
		else
		{
			map[new_y][new_x] = '*';
		}			
	}
	
	for(int i=0; i<16; i++)
	{
		for(int j=0; j<16; j++)
		{
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "------------------------" << '\n';
	
	for(int i=0; i<tree.size(); i++)
	{
		cout << tree[i].first << "," << tree[i].second << '\n';
	}
	
	
/*	
	for(int i=0; i<10; i++)
	{
	   	 double rnd = rand()%10; 

	}
*/		
	return 0;	
}
