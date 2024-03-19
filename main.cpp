/*
Group Members:
Saad Younas Mughal (L1S22BSCS0067)
Huzaifa Haris      (L1S22BSCS0066)

*/

#include<iostream>
#include<fstream>
#include <chrono>
#include <thread> // using these two libraries because the library containing sleep() function does not supported by visual Studio
#include<conio.h> // to use functions like getch()...
#include"list.h"
using namespace std;
void Play_Track(list obj)
{
	int hr = 0, min = 0, sec = 0;
	int index = 1;
	while (true)
	{
		system("cls");
		cout << "**************** Your Playlist is Playing ****************" << endl;
		obj.display_while_playing(index);
		cout << "**********************************************************" << endl;
		cout << "			" << hr << " : " << min << " : " << sec << endl;
		cout << "**********************************************************" << endl;
		cout << "Press N to play next track" << endl;
		cout << "Press P to play previous track" << endl;
		cout << "Press Space Bar to Pause" << endl;
		cout << "Press F to seek 5sec forward" << endl;
		cout << "Press B to seek 5sec backward" << endl;
		cout << "Press M to go back to main menu" << endl;
		sec++;
		if (sec == 60)
		{
			min++;
			sec = 0;
			if (min == 60)
			{
				hr++;
				min = 0;
				if (hr == 12)
				{
					hr = 0;
				}
			}
		}

		this_thread::sleep_for(chrono::seconds(1));
		if (_kbhit())
		{
			cout << "\a"; // to beep on any keypressed on keyboard
			char a = _getch();
			if (a == 'M' || a == 'm')return;
			if (a == 'F' || a == 'f')
			{
				sec = sec + 5;
				if (sec > 60)
				{
					sec = 0;
					min++;
					if (min > 60)
					{
						min = 0;
						hr++;
					}
				}
				if ((hr == obj.get_hour(index) && min == obj.get_min(index) && sec >= obj.get_sec(index)) || (hr == obj.get_hour(index) && min >= obj.get_min(index) && sec == obj.get_sec(index)) || (hr >= obj.get_hour(index) && min == obj.get_min(index) && sec == obj.get_sec(index)))
				{
					hr = sec = min = 0;
					index++;
					if (index == obj.size() + 1)
					{
						index = 1;
					}
				}

			}
			else if (a == 'B' || a == 'b')
			{
				sec = sec - 5;
				if (sec < 0)
				{
					sec += 60;  // Add 60 seconds to wrap around
					min--;
					if (min < 0)
					{
						min += 60;  // Add 60 minutes to wrap around
						hr--;
						if (hr < 0)
						{
							hr = 0;
						}
					}
				}

				if ((hr == obj.get_hour(index) && min == obj.get_min(index) && sec >= obj.get_sec(index)) || (hr == obj.get_hour(index) && min > obj.get_min(index)) || (hr > obj.get_hour(index)))
				{
					hr = sec = min = 0;
					index--;
					if (index == 0)
					{
						index = obj.size();
					}
				}
			}

			else if (a == 'N' || a == 'n')
			{
				hr = sec = min = 0;
				index++;
				if (index == obj.size() + 1)
				{
					index = 1;
				}
			}
			else if (a == 'P' || a == 'p')
			{
				hr = sec = min = 0;
				index--;
				if (index == 0)
				{
					index = obj.size();
				}
			}
			else if (a == ' ')
			{
				cout << "Press Space Bar again to Play track" << endl;
				a = _getch();
				if (a == ' ')
				{
					continue;
				}
				while (a != ' ')
				{
					cout << "Press Space Bar to Play track" << endl;
					a = _getch();
					if (a == ' ')
						break;
				}
			}
		}
		if (hr == obj.get_hour(index) && min == obj.get_min(index) && sec == obj.get_sec(index))
		{
			hr = sec = min = 0;
			index++;
			if (index == obj.size() + 1)
			{
				index = 1;
			}
		}
	}
}
bool search_arr(int* arr, int search, int size, int current_size)
{
	for (int i = 0; i < current_size; i++)
	{
		if (arr[i] == search)
		{
			return true;
		}
	}
	return false;
}
void copy_list(list original, list &shuffle, int* indexes, int size)
{
	for (int i = 0; i < size; i++)
	{
		shuffle.insert(original.get_name(indexes[i]), original.get_hour(indexes[i]), original.get_min(indexes[i]), original.get_sec(indexes[i]));
	}
}
void Shuffle(list obj)
{
	list shuffled_obj;
	int size = obj.size();
	int *shuffle_index = new int[size];
	int current_size = 0;
	int n = 0;
	while (true)
	{
		if (current_size == size)break;
		else
		{
			n = (rand() % size + 1);
			if (!search_arr(shuffle_index, n, size, current_size))
			{
				shuffle_index[current_size] = n;
				cout << shuffle_index[current_size] << endl;
				current_size++;
			}

		}
	}
	copy_list(obj, shuffled_obj, shuffle_index, size);
	int hr = 0, min = 0, sec = 0;
	int index = 1;
	while (true)
	{
		system("cls");
		cout << "*********** Your Shuffled Playlist is Playing ************" << endl;
		shuffled_obj.display_while_playing(index);

		cout << "**********************************************************" << endl;
		cout << "			" << hr << " : " << min << " : " << sec << endl;
		cout << "**********************************************************" << endl;
		cout << "Press N to play next track" << endl;
		cout << "Press P to play previous track" << endl;
		cout << "Press Space Bar to Pause" << endl;
		cout << "Press F to seek 5sec forward" << endl;
		cout << "Press B to seek 5sec backward" << endl;
		cout << "Press M to go back to main menu" << endl;
		sec++;
		if (sec == 60)
		{
			min++;
			sec = 0;
			if (min == 60)
			{
				hr++;
				min = 0;
				if (hr == 12)
				{
					hr = 0;
				}
			}
		}

		this_thread::sleep_for(chrono::seconds(1));
		if (_kbhit())
		{
			cout << "\a"; // to beep on any keypressed on keyboard
			char a = _getch();
			if (a == 'M' || a == 'm')return;
			if (a == 'F' || a == 'f')
			{
				sec = sec + 5;
				if (sec > 60)
				{
					sec = 0;
					min++;
					if (min > 60)
					{
						min = 0;
						hr++;
					}
				}
				if ((hr == shuffled_obj.get_hour(index) && min == shuffled_obj.get_min(index) && sec >= shuffled_obj.get_sec(index)) || (hr == shuffled_obj.get_hour(index) && min >= shuffled_obj.get_min(index) && sec == shuffled_obj.get_sec(index)) || (hr >= shuffled_obj.get_hour(index) && min == shuffled_obj.get_min(index) && sec == shuffled_obj.get_sec(index)))
				{
					hr = sec = min = 0;
					index++;
					if (index == shuffled_obj.size() + 1)
					{
						index = 1;
					}
				}

			}
			else if (a == 'B' || a == 'b')
			{
				sec = sec - 5;
				if (sec < 0)
				{
					sec += 60;  // Add 60 seconds to wrap around
					min--;
					if (min < 0)
					{
						min += 60;  // Add 60 minutes to wrap around
						hr--;
						if (hr < 0)
						{
							hr = 0;
						}
					}
				}

				if ((hr == shuffled_obj.get_hour(index) && min == shuffled_obj.get_min(index) && sec >= shuffled_obj.get_sec(index)) || (hr == shuffled_obj.get_hour(index) && min > shuffled_obj.get_min(index)) || (hr > shuffled_obj.get_hour(index)))
				{
					hr = sec = min = 0;
					index--;
					if (index == 0)
					{
						index = shuffled_obj.size();
					}
				}
			}

			else if (a == 'N' || a == 'n')
			{
				hr = sec = min = 0;
				index++;
				if (index == shuffled_obj.size() + 1)
				{
					index = 1;
				}
			}
			else if (a == 'P' || a == 'p')
			{
				hr = sec = min = 0;
				index--;
				if (index == 0)
				{
					index = shuffled_obj.size();
				}
			}
			else if (a == ' ')
			{
				cout << "Press Space Bar again to Play track" << endl;
				a = _getch();
				if (a == ' ')
				{
					continue;
				}
				while (a != ' ')
				{
					cout << "Press Space Bar to Play track" << endl;
					a = _getch();
					if (a == ' ')
						break;
				}
			}
		}
		if (hr == shuffled_obj.get_hour(index) && min == shuffled_obj.get_min(index) && sec == shuffled_obj.get_sec(index))
		{
			hr = sec = min = 0;
			index++;
			if (index == shuffled_obj.size() + 1)
			{
				index = 1;
			}
		}
	}
}

int count_track_in_file()
{
	int i = 0;
	ifstream fin;
	char arr[50] = { '\0' };
	fin.open("track.txt");
	while (!fin.eof())
	{
		fin.getline(arr, 50);
		i++;
	}
	return i;
}
bool read_file(list& obj)
{
	ifstream fin;
	fin.open("track.txt");
	if (fin.is_open() == false)
	{

		cout << "File not found" << endl;
		return false;
	}
	else
	{
		char name[50] = { '\0' };
		int h, m, s;
		char waste;
		while (fin.eof() == false)
		{
			name[0] = { '\0' };
			fin.getline(name, 50, '{');
			fin >> h;
			fin >> waste;
			fin >> m;
			fin >> waste;
			fin >> s;
			fin >> waste;
			fin.ignore();
			obj.insert(name, h, m, s);
		}
		fin.close();
	}
	return true;
}

int main()
{
	int choice;
	list playlist;
	list track_file;
	if (!read_file(track_file) || count_track_in_file() == 0)
	{
		cout << "Track file not found at backend or track file is empty so terminating program!!!" << endl;
		return 0;
	}

	while (true)
	{
		cout << "Press 1 to view Track list (file)" << endl;
		cout << "Press 2 to Add tracks from available list to your Playlist" << endl;
		cout << "Press 3 to Play your Playlist" << endl;
		cout << "Press 4 to Play your playlist by shuffling it" << endl;
		cout << "Press 5 to View your Playlist" << endl;
		cout << "Press 6 to remove a track from your playlist" << endl;
		cout << "Press 7 to add a new track in available track list (file)" << endl;
		cout << "Press 0 to exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		while (choice < 0 || choice>7)
		{
			cout << "Please Enter a Choice From 0 To 7: ";
			cin >> choice;
		}
		if (choice == 1)
		{
			track_file.display();
			system("pause");
			system("cls");
		}
		else if (choice == 2)
		{

			int no_of_track = count_track_in_file();
			track_file.display();
			int index = 0;
			cout << "Enter Track no. to add in your Playlist: ";
			cin >> index;
			while (index<0 || index>no_of_track)
			{
				cout << "Enter a valid option!!!" << endl;
				cout << "Enter Track no. to add in your Playlist: ";
				cin >> index;
			}
			char* name = new char[50];
			name[0] = '\0';
			name = track_file.get_name(index);
			if (playlist.compare(name) == true)
			{
				int h = track_file.get_hour(index);
				int m = track_file.get_min(index);
				int s = track_file.get_sec(index);
				playlist.insert(name, h, m, s);
				playlist.display();
			}
			else
			{
				cout << "This track in your playlist already exist" << endl;
			}
			system("pause");
			system("cls");
		}
		else if (choice == 3)
		{
			if (!playlist.isEmpty())
			{
				Play_Track(playlist);
			}
			else {
				cout << "Your Playlist is empty cannot play it" << endl;
			}

			system("pause");
			system("cls");
		}
		else if (choice == 4)
		{
			if (!playlist.isEmpty())
			{
				Shuffle(playlist);
			}
			else {
				cout << "Your Playlist is empty cannot shuffle it" << endl;
			}

			system("pause");
			system("cls");
		}
		else if (choice == 5)
		{
			if (playlist.isEmpty())
			{
				cout << "You don't have any track in your Playlist" << endl;
			}
			else
			{
				cout << "Your Playlist is as follow: " << endl;
				playlist.display();
			}
			system("pause");
			system("cls");
		}
		else if (choice == 6)
		{
			if (playlist.isEmpty())
			{
				cout << "You don't have any track in your Playlist" << endl;
			}
			else
			{
				int index;
				playlist.display();
				int size = playlist.size();
				cout << "Enter Track no. to remove it from your Playlist";
				cin >> index;
				while (index<1 || index>size)
				{
					cout << "Enter a valid option!!!" << endl;
					cout << "Enter Track no. to remove it from your Playlist: ";
					cin >> index;
				}
				playlist.removeFromPlaylist(index);
				system("cls");
				cout << "Your updated Playlist is following:- " << endl;
				if (playlist.isEmpty())
				{
					cout << "Your Playlist is Empty" << endl;
				}
				else
				{
					playlist.display();
				}
			}
			system("pause");
			system("cls");

		}
		else if (choice == 7)
		{
			cin.ignore();
			char name[50] = { '\0' };
			int h, m, s;
			cout << "Enter name of your new track: ";
			cin.getline(name, 50);
			cout << "Enter Hour: ";
			cin >> h;
			while (h < 0)
			{
				cout << "Enter valid hour!!!" << endl;
				cout << "Enter Hour: ";
				cin >> h;
			}
			cout << "Enter Min: ";
			cin >> m;
			while (m < 0 || m>60)
			{
				cout << "Enter valid minutes!!!" << endl;
				cout << "Enter Min: ";
				cin >> m;
			}
			cout << "Enter Sec: ";
			cin >> s;
			while (s < 0 || s>60)
			{
				cout << "Enter valid seconds!!!" << endl;
				cout << "Enter Sec: ";
				cin >> s;
			}
			track_file.insert(name, h, m, s);
			track_file.write_on_file();
		}
		else if (choice == 0)
		{
			cout << "Bye Bye" << endl;
			return 0;
		}
	}
	system("pause");
	return 0;
}