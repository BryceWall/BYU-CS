//
// Created by Bryce on 11/29/2021.
//

#include <iostream>
#include <sstream>
#include "Song.h"

Song::Song() {
    songTitle = "none";
    songFirstLine = "none";
}

Song::Song(string title, string firstLine) {
    songTitle = title;
    songFirstLine = firstLine;
}

string Song::GetTitle() const {
    return songTitle;
}

string Song::GetFirstLine() const {
    return songFirstLine;
}

string Song::ListSongs() {
    string songOutput = "??";
    songOutput = songTitle + ": " + "\"" + songFirstLine + "\"" + ", " + to_string(timesPlayed) + " play(s)."; //sets appended string to a variable to be removed

    return songOutput;
}

void Song::NumTimesPlayed() {
    timesPlayed += 1;
}
