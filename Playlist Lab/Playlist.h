//
// Created by Bryce on 11/29/2021.
//

#ifndef MAINLAB8PP_PLAYLIST_H
#define MAINLAB8PP_PLAYLIST_H

#include <vector>
#include <string>
#include "Song.h"

using namespace std;

class Playlist {
private:
    string playlistName;
    vector<Song*> playlistSongs;

public:
    Playlist();
    Playlist(string);
    void SetName(string);
    string GetPlaylistName() const;
    void RemoveSongLibrary(string);
    void AddSong(Song*);
    void PlayPlaylist();
    void RemoveSongPlaylist(int);
    void ListSongsInPlaylist() const;

};


#endif //MAINLAB8PP_PLAYLIST_H
