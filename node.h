#pragma once
#include"Track.h"
struct node
{
	Track Data;
	node* next;
	node* prev;
	node()
	{
		next = nullptr;
		prev = nullptr;
	}
	node(char* name, int h, int m, int s)
	{
		Data = { name, h, m, s };
		next = nullptr;
		prev = nullptr;
	}
};
