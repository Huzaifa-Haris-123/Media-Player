#include"list.h"
#include<iostream>
#include<fstream>
using namespace std;
list::list()
{
	head = nullptr;
	tail = nullptr;
}
bool list::isEmpty()
{
	if (head == nullptr && tail == nullptr)
		return true;
	return false;
}
void list::insert(char* name, int h, int m, int s)
{
	node* newLink = new node(name, h, m, s);
	if (isEmpty())
	{
		head = newLink;
		tail = newLink;
		head->next = tail;
		head->prev = tail;
		tail->next = head;
		tail->prev = head;
	}
	else
	{
		newLink->next = head;
		newLink->prev = tail;
		tail->next = newLink;
		tail = newLink;
	}
}
char* list::get_name(int index)//this index will be not out of bound of list size..there will be a check in main
{
	node* current = head;
	int loc = 1;
	while (true)
	{
		if (loc == index)
		{
			return current->Data.get_trackName();
		}
		current = current->next;
		loc++;
		if (current == head)
		{
			break;
		}
	}
}
int list::get_hour(int index)//this index will be not out of bound of list size..there will be a check in main
{
	node* current = head;
	int loc = 1;
	while (true)
	{
		if (loc == index)
		{
			return current->Data.get_hour();
		}
		current = current->next;
		loc++;
		if (current == head)
		{
			break;
		}
	}
}
int list::get_min(int index)//this index will be not out of bound of list size..there will be a check in main
{
	node* current = head;
	int loc = 1;
	while (true)
	{
		if (loc == index)
		{
			return current->Data.get_min();
		}
		current = current->next;
		loc++;
		if (current == head)
		{
			break;
		}
	}
}
int list::get_sec(int index)//this index will be not out of bound of list size..there will be a check in main
{
	node* current = head;
	int loc = 1;
	while (true)
	{
		if (loc == index)
		{
			return current->Data.get_sec();
		}
		current = current->next;
		loc++;
		if (current == head)
		{
			break;
		}
	}
}
bool list::compare(char* name)
{
	int n_size = strlen(name);
	int size = 0;
	if (!isEmpty())
	{
		node* current = head;
		while (true)
		{
			size = strlen(current->Data.get_trackName());
			if (size == n_size)
			{
				for (int i = 0; i < size; i++)
				{
					if (name[i] != current->Data.get_trackName()[i])
					{
						break;
					}
					if (i == size - 1)
					{
						return false; // this track name exist
					}
				}
			}
			current = current->next;
			if (current == head)
			{
				break;
			}

		}
		return true;
	}

	return true;
}
void list::write_on_file()
{
	ofstream fout;
	fout.open("track.txt");
	node* current = head;
	while (current != nullptr)
	{
		fout << current->Data.get_trackName() << "{" << current->Data.get_hour() << ":" << current->Data.get_min() << ":" << current->Data.get_sec() << "}";
		current = current->next;
		if (current == head)
		{
			break;
		}
		fout << endl;
	}
	fout.close();

}
int list::size()
{
	if (isEmpty()) return 0;
	int s = 1;
	node* current = head;
	while (true)
	{
		current = current->next;
		if (current == head)
		{
			break;
		}
		s++;
	}
	return s;
}
void list::removeFromPlaylist(int index)
{
	node* current = head;
	int loc = 1;

	if (loc == index)
	{
		if (head == tail) // Only one node in the list
		{

			delete current;
			head = nullptr;
			tail = nullptr;
		}
		else
		{

			head = head->next;
			head->prev = tail;
			tail->next = head;
			delete current;
		}
	}
	else
	{
		loc++;
		while (true)
		{
			if (loc == index)
			{
				current->prev->next = current->next;
				current->next->prev = current->prev;

				if (current == tail)
				{
					tail = current->prev;
				}

				delete current;
				return;
			}
			current = current->next;
			loc++;

			if (current == head)
			{
				break;
			}
		}
	}
}


void list::display_while_playing(int index)
{
	int location = 0;
	node* current = head;
	while (true)
	{
		location++;
		if (location == index)
		{
			cout << "		    => " << index << ": " << current->Data.get_trackName() << " " << "{" << current->Data.get_hour() << ":" << current->Data.get_min() << ":" << current->Data.get_sec() << "}" << endl;

		}
		else
		{
			cout << "			" << location << ": " << current->Data.get_trackName() << " " << "{" << current->Data.get_hour() << ":" << current->Data.get_min() << ":" << current->Data.get_sec() << "}" << endl;

		}
		current = current->next;
		if (current == head)return;
	}

}
void list::display()
{
	int index = 1;
	node* current = head;
	if (head != nullptr)
	{
		while (true)
		{
			cout << index << ": " << current->Data.get_trackName() << " " << "{" << current->Data.get_hour() << ":" << current->Data.get_min() << ":" << current->Data.get_sec() << "}" << endl;
			current = current->next;
			index++;
			if (current == head)
			{
				return;
			}
		}
	}
}