#include"Track.h"

Track::Track()
{
	track_name = nullptr;
	hour = min = sec = 0;
}

Track::Track(char* name, int h, int m, int s)
{
	hour = h;
	min = m;
	sec = s;
	int size = 0;
	while (name[size] != '\0')
	{
		size++;
	}
	track_name = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		track_name[i] = name[i];
	}
	track_name[size] = '\0';
}

char *Track::get_trackName()
{
	char *temp;
	int size = 0;
	while (track_name[size] != '\0')
	{
		size++;
	}
	temp = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		temp[i] = track_name[i];
	}
	temp[size] = '\0';
	return temp;
}

int Track::get_hour()
{
	return hour;
}

int Track::get_min()
{
	return min;
}

int Track::get_sec()
{
	return sec;
}