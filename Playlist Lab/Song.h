//
// Created by Bryce on 11/29/2021.
//

#ifndef MAINLAB8PP_SONG_H
#define MAINLAB8PP_SONG_H

#include <vector>
#include <string>

using namespace std;

class Song {

private:
    string songTitle;
    string songFirstLine;
    int timesPlayed = 0;

public:
    Song();
    Song(string, string);
    string GetTitle() const;
    string GetFirstLine() const;
    string ListSongs();
    void NumTimesPlayed();

};


#endif //MAINLAB8PP_SONG_H
