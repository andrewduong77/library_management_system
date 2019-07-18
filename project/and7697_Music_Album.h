#ifndef AND7697_MUSIC_ALBUM_H_INCLUDED
#define AND7697_MUSIC_ALBUM_H_INCLUDED

#include "and7697_Media.h"

class Music_Album : public Media
{
public:
    Music_Album(int idn, string cn, string t, string g, int r, string a, vector<string> tr) : Media(idn, cn, t, g), release_year {r}, artist {a}, tracks {tr} {set_type("Music_Album");};
    int get_release_year();
    string get_artist();
    string get_tracks() const;
    string tracks_to_string() const;
    string tracks_to_file() const;
    string to_string() const;
    string to_file() const;
    friend ostream& operator<<(ostream& ost, const Music_Album& music_album_two);
private:
    int release_year;
    string artist;
    vector<string> tracks;
};

#endif // AND7697_MUSIC_ALBUM_H_INCLUDED
