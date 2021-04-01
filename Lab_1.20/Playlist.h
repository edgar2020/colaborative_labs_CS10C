#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <cstring>
#include <iostream>

using namespace std;

class Playlist;

class PlaylistNode {

private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;

public:
    /************************
     * Constructors         *
     ************************/
    PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(0) {}
    PlaylistNode(string uniqueID, string songName, string artistName , int songLength) : 
        uniqueID(uniqueID), songName(songName), artistName(artistName), songLength(songLength), nextNodePtr(nullptr) {}

    ~PlaylistNode() {}
 
    /************************
     * Getter/Accessors     *
     ************************/
    string GetID() const {return uniqueID;}
    string GetSongName() const {return songName;}
    string GetArtistName() const {return artistName;}
    int GetSongLength() const {return songLength;}
    PlaylistNode* GetNext() const {return nextNodePtr;}

    /**********************************
     * Setters/Modifiers/Mutators     *
     **********************************/
    void PrintPlaylistNode();
    void InsertAfter(PlaylistNode *);
    void SetNext(PlaylistNode *);
    
};

class Playlist 
{
    private:
        PlaylistNode *head;
        PlaylistNode *tail;
        string playlistName;
    public:
        // AddSong(string, string, string, int);
        PlaylistNode* GetTail() const{return tail;}
        PlaylistNode* GetHead() const{return head;}
        void remove(string);
        void remove(int);
        void insert(int, int);
        void setTail(PlaylistNode*);
        void setHead(PlaylistNode*);
        Playlist(string name) : playlistName(name), head(nullptr), tail(nullptr) {}
        friend ostream & operator<<(ostream &, const Playlist &);
};
 
#endif