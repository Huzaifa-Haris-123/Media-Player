
class Track
{
	char* track_name;
	int hour, min, sec;
public:
	Track();
	Track(char* name, int h, int m, int s);
	char *get_trackName();
	int get_hour();
	int get_min();
	int get_sec();
};