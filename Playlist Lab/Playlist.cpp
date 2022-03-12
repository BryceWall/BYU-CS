//
// Created by Bryce on 11/29/2021.
//

#include <iostream>
#include <iomanip>
#include "Playlist.h"

using namespace std;

Playlist::Playlist() {
    playlistName = "none";
}

Playlist::Playlist(string name) {
    playlistName = name;
}

void Playlist::SetName(string name) {
    playlistName = name;
}

string Playlist::GetPlaylistName() const {
    return playlistName;
}

void Playlist::RemoveSongLibrary(string songName) {
    for(int i = 0; i < playlistSongs.size(); i++) {     //accepts variable songName which gets title from song vector
        if(songName == playlistSongs.at(i)->GetTitle()) {   //and compares to the names of songs in playlist vector
            playlistSongs.erase(playlistSongs.begin() + i); //deletes song at index in vector
        }
    }
}

void Playlist::AddSong(Song* songPointer) {
    playlistSongs.push_back(songPointer); //adds song pointer to pointer vector
}

void Playlist::PlayPlaylist() {
    for(int i = 0; i < playlistSongs.size(); i++) {
        playlistSongs.at(i)->NumTimesPlayed(); //plays playlist and calls function for numTimesPlayed which adds +1 to numTimesPlayed
        cout << playlistSongs.at(i)->GetFirstLine() << endl; //outputs song first lines
    }
}

void Playlist::RemoveSongPlaylist(int songIndex) {
    playlistSongs.erase(playlistSongs.begin() + songIndex);//removes song from vector at index

}

void Playlist::ListSongsInPlaylist() const {
    Song* currSong;

    for(int i = 0; i < playlistSongs.size(); i++) {
        currSong = playlistSongs.at(i);
        cout << i << ": " << currSong->GetTitle() << endl;  //outputs song title at index
    }
}

