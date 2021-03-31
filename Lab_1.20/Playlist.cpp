#include <iostream>
#include "Playlist.h"
using namespace std;

void PlaylistNode::PrintPlaylistNode()
{
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds) : " << songLength << endl;
}

void PlaylistNode::InsertAfter(Playlist &thePlaylist, PlaylistNode * pre) 
{
    if(thePlaylist.GetHead()==nullptr)//if playlist empty
    {
        // PlaylistNode *insetThis = this;
        // cout << "InsertAfter Called" << endl;
        thePlaylist.setHead(this);
        thePlaylist.setTail(this);
        // this->SetNext(nullptr);
        // this->PrintPlaylistNode();
    }
    else if (thePlaylist.GetTail() == pre)//if playlist has many songs
    {
        thePlaylist.GetTail()->SetNext(this);
        thePlaylist.setTail(this);
    }
    else
    {
        
        PlaylistNode *temp = pre->GetNext();
        pre->SetNext(this);
        this->SetNext(temp);
    }
}
void Playlist::setHead(PlaylistNode* temp)
{
    cout << "HEAD SET" << endl;
    head=temp;
    if (GetHead() == nullptr)
        cout << "HEAD STILL NULL" << endl;
    else
        cout << "HEAD NOT NULL" << endl;
}
void Playlist::setTail(PlaylistNode* temp)
{
    tail=temp;
}

void Playlist::remove(string ID)
{
    string songName = "";

    if(head!=nullptr && head->GetID()==ID)//if head will be deleted
    {
        PlaylistNode *temp = head;
        head = head->GetNext();
        songName = temp->GetSongName();
        delete temp;
        cout << "\"" << songName << "\" removed" << endl;
        return;
    }
    PlaylistNode *pre = head;
    if (pre != nullptr) {
        for(PlaylistNode *curr = pre->GetNext(); curr!=nullptr; curr = curr->GetNext())
        {
            if(curr->GetID() == ID)
            {
                
                songName = curr->GetSongName();
                if(curr!=tail)//if mid value to be deleted
                {
                    pre->SetNext(curr->GetNext());
                }
                else//if tail is final value
                {
                    pre->SetNext(nullptr);               
                }
                delete curr;
                cout << "\"" << songName << "\" removed" << endl;
                return;

                //if tail is to be deleted
                
            }
            pre = curr;
        }
    }
    cout<<"Song by ID  \""+ID+"\" not found"<<endl;
}

void PlaylistNode::SetNext(PlaylistNode *temp)
{
   nextNodePtr = temp;
} 


ostream &operator<<(ostream & os, const Playlist &somePlaylist)
{
    if(somePlaylist.GetHead()!=nullptr)
    {
        os<<somePlaylist.playlistName<<" - OUTPUT FULL PLAYLIST" << endl;
        
        int num = 1;
        for(PlaylistNode *curr = somePlaylist.GetHead(); curr!=nullptr; curr = curr->GetNext())
        {
            os << num << '.' << endl;
            curr->PrintPlaylistNode();
            num++;
        }
        
    }
    else
    {
        os<<"Playlist is empty"<<endl;
    }
    return os;
}
    