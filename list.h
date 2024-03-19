#pragma once
#include"node.h"

class list
{
	node* head;
	node* tail;
public:
	list();
	bool isEmpty();
	void insert(char* name, int h, int m, int s);
	char* get_name(int index);//this index will be not out of bound of list size..there will be a check in main
	int get_hour(int index);//this index will be not out of bound of list size..there will be a check in main
	int get_min(int index);//this index will be not out of bound of list size..there will be a check in main
	int get_sec(int index);//this index will be not out of bound of list size..there will be a check in main
	bool compare(char* name);
	void write_on_file();
	int size();
	void removeFromPlaylist(int index);
	void display_while_playing(int index);
	void display();
};
