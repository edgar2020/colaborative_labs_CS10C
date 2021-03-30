#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <cstring>
#include <iostream>

using namespace std;



class PlaylistNode {

private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;

public:
    PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(0) {}
    PlaylistNode(string uniqueID, string songName, string artistName , int songLength, PlaylistNode* nextNodePtr) : 
        uniqueID(uniqueID), songName(songName), artistName(artistName), songLength(songLength), nextNodePtr(nextNodePtr) {}
 
    void InsertAfter();
    void SetNext();
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    string GetSongLength() const;
    PlaylistNode* GetNext() const;
    void PrintPlaylistNode();
    
};

#endif