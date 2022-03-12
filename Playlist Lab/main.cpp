#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Song.h"
#include "Playlist.h"

string GetUserString(const string& prompt);
int GetUserInt(const string& prompt);


int main() {

    vector<Song*> songs; //vector of pointers
    vector<Playlist> playlists; //vector of playlist names

    cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;

    string userMenuChoice = "none";
    bool continueMenuLoop = true;

    while (continueMenuLoop) {

        userMenuChoice = GetUserString("Enter your selection now: ");

        if (userMenuChoice == "add") {

            const string DONE_KEYWORD = "DONE";
            cout << "Enter songs' names and first lines"
                      << " (type \"" << DONE_KEYWORD << "\" when done):" << endl;

            string songName = "none";
            string firstLine = "none";

            songName = GetUserString("Song Name: ");

            while (songName != DONE_KEYWORD) {

                firstLine = GetUserString("Song's first line: ");

                Song* newSong = new Song(songName, firstLine); //allocates memory for song pointers
                songs.push_back(newSong); //adds songs to vector

                songName = GetUserString("Song Name: ");
            }
        }

        else if (userMenuChoice == "list") {

            unsigned int i = 0;

            for(i = 0; i < songs.size(); i++) {
                cout << songs.at(i)->ListSongs() << endl; //calls function from Song and lists songs
            }
            cout << endl;
        }

        else if (userMenuChoice == "addp") {
            Playlist newPlaylist;
            string playlistName;

            cout << "Playlist name: ";
            getline(cin, playlistName);
            newPlaylist.SetName(playlistName);//assigns name to playlist object
            playlists.push_back(newPlaylist);//adds object to playlist vector
            cout << endl;
        }

        else if (userMenuChoice == "addsp") {

            Playlist currPlaylist;
            int playlistIndexNum = 0;
            int songIndexNum = 0;
            unsigned int i = 0;

            for(i = 0; i < playlists.size(); i++) {
                currPlaylist = playlists.at(i);
                cout << i << ": " << currPlaylist.GetPlaylistName() << endl;// outputs playlist names by calling function
            }

            playlistIndexNum = GetUserInt("Pick a playlist index number: ");
            cout << endl;

            for(i = 0; i < songs.size(); i++) {
                cout << i << ": " << songs.at(i)->GetTitle() << endl;//gets titles of songs and outputs list of songs
            }

            songIndexNum = GetUserInt("Pick a song index number: ");

            playlists.at(playlistIndexNum).AddSong(songs.at(songIndexNum)); //access playlist @ index and adds song from song vector @ index
            cout << endl;
        }

        else if (userMenuChoice == "listp") {

            unsigned int i = 0;
            Playlist currPlaylist;

            for(i = 0; i < playlists.size(); i++) {
                currPlaylist = playlists.at(i);
                cout << i << ": " << currPlaylist.GetPlaylistName() << endl; //outputs a list of all the playlists with Getname function
            }
        }

        else if (userMenuChoice == "play") {

            Playlist currPlaylist;
            unsigned int i = 0;
            int playlistIndexNum = 0;

            for(i = 0; i < playlists.size(); i++) {
                currPlaylist = playlists.at(i);
                cout << i << ": " << currPlaylist.GetPlaylistName() << endl;//outputs all playlist names
            }

            playlistIndexNum = GetUserInt("Pick a playlist index number: ");

            cout << "Playing songs from playlist: " << playlists.at(playlistIndexNum).GetPlaylistName() << endl;//gets playlist name
            playlists.at(playlistIndexNum).PlayPlaylist();//access playlist @ playlist index and plays playlist with play function
            cout << endl;
        }

        else if (userMenuChoice == "remp") {

            unsigned int i = 0;
            int playlistIndexNum = 0;
            Playlist currPlaylist;

            for(i = 0; i < playlists.size(); i++) {
                currPlaylist = playlists.at(i);
                cout << i << ": " << currPlaylist.GetPlaylistName() << endl;
            }

            playlistIndexNum = GetUserInt("Pick a playlist index number to remove: ");
            cout << endl;

            for(int i = 0; i < playlists.size(); i++) {
                if (i == playlistIndexNum) {//checks to see if playlist index matches i
                    playlists.erase(playlists.begin() + i);//deletes playlist in vector
                }
            }
        }

        else if (userMenuChoice == "remsp") {

            Playlist currPlaylist;
            int playlistIndexNum = 0;
            int songIndexNum = 0;
            unsigned int i = 0;

            for (i = 0; i < playlists.size(); i++) {
                currPlaylist = playlists.at(i);
                cout << i << ": " << currPlaylist.GetPlaylistName() << endl;
            }

            playlistIndexNum = GetUserInt("Pick a playlist index number: ");
            cout << endl;

            playlists.at(playlistIndexNum).ListSongsInPlaylist();//accesses list songs playlist function

            songIndexNum = GetUserInt("Pick a song index number to remove: ");
            cout << endl;

            playlists.at(playlistIndexNum).RemoveSongPlaylist(songIndexNum);//removes song from playlist by accessing function
            cout << endl;
        }

        else if (userMenuChoice == "remsl") {

            unsigned int i = 0;
            int songIndexNum = 0;
            string songName = "??";

            for (i = 0; i < songs.size(); i++) {
                cout << i << ": " << songs.at(i)->GetTitle() << endl;
            }

            songIndexNum = GetUserInt("Pick a song index number to remove: ");

            songName = songs.at(songIndexNum)->GetTitle(); //sets name of song pointer to a string title to be compared

            for (i = 0; i < playlists.size(); i++) {
                playlists.at(i).RemoveSongLibrary(songName);//access song removal function by passing in above songName function
            }

            delete songs.at(songIndexNum); //Dealocates memory and deletes memory
            songs.erase(songs.begin() + songIndexNum);//deletes memory at song index in vector
        }

        else if (userMenuChoice == "options") {
            cout << "add      Adds a list of songs to the library" << endl
                      << "list     Lists all the songs in the library" << endl
                      << "addp     Adds a new playlist" << endl
                      << "addsp    Adds a song to a playlist" << endl
                      << "listp    Lists all the playlists" << endl
                      << "play     Plays a playlist" << endl
                      << "remp     Removes a playlist" << endl
                      << "remsp    Removes a song from a playlist" << endl
                      << "remsl    Removes a song from the library (and all playlists)" << endl
                      << "options  Prints this options menu" << endl
                      << "quit     Quits the program" << endl << endl;
        }

        else if (userMenuChoice == "quit") {
            cout << "Goodbye!" << endl;
            continueMenuLoop = false;
        }

        else {
            cout << "add      Adds a list of songs to the library" << endl
                      << "list     Lists all the songs in the library" << endl
                      << "addp     Adds a new playlist" << endl
                      << "addsp    Adds a song to a playlist" << endl
                      << "listp    Lists all the playlists" << endl
                      << "play     Plays a playlist" << endl
                      << "remp     Removes a playlist" << endl
                      << "remsp    Removes a song from a playlist" << endl
                      << "remsl    Removes a song from the library (and all playlists)" << endl
                      << "options  Prints this options menu" << endl
                      << "quit     Quits the program" << endl << endl;
        }
    }

    for(int i = 0; i < songs.size(); i++) {
        delete songs.at(i); //Deletes memory and dealocates memory of song index in vector
        songs.erase(songs.begin() + i);//deletes song pointer from vector
        i--;//decreases size to make sure there are no memory leaks
    }

    return 0;
}

string GetUserString(const string& prompt) {
    string userAnswer = "none";

    cout << prompt;
    getline(cin, userAnswer);
    cout << endl;
    return userAnswer;
}
int GetUserInt(const string& prompt) {
    int userAnswer = 0;

    cout << prompt;
    cin >> userAnswer;
    cin.ignore();
    cout << endl;
    return userAnswer;
}