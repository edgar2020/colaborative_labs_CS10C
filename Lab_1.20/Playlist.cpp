#include <iostream>
#include "Playlist.h"
using namespace std;

void PlaylistNode::PrintPlaylistNode()
{
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl << endl ;
}

void PlaylistNode::SetNext(PlaylistNode *temp)
{
   nextNodePtr = temp;
} 

void PlaylistNode::InsertAfter(PlaylistNode * pre) 
{
    PlaylistNode* tmpNext = nullptr;

    if(this->nextNodePtr == nullptr)//if adding to tail
    {
        this->nextNodePtr = pre;
        
        
        // pre->nextNodePtr = nullptr;
    }
    else
    {
        tmpNext = this->nextNodePtr;
        this->nextNodePtr = pre;
        pre->nextNodePtr = tmpNext;
    }
    // if(thePlaylist.GetHead()==nullptr)//if playlist empty
    // {
    //     // PlaylistNode *insetThis = this;
    //     // cout << "InsertAfter Called" << endl;
    //     thePlaylist.setHead(this);
    //     thePlaylist.setTail(this);
    //     // this->SetNext(nullptr);
    //     // this->PrintPlaylistNode();
    // }
    // else if (thePlaylist.GetTail() == pre)//if playlist has many songs
    // {
    //     thePlaylist.GetTail()->SetNext(this);
    //     thePlaylist.setTail(this);
    // }
    // else
    // {
        
    //     PlaylistNode *temp = pre->GetNext();
    //     pre->SetNext(this);
    //     this->SetNext(temp);
    // }
}

void Playlist::insert(int newPos, int oldPos)
{`
    PlaylistNode *newPosition = nullptr;
    PlaylistNode* copy = nullptr;
    if(oldPos == newPos)
    {
        cout<<"Cannot Be the Same"<<endl;
        return;
    }
    int length = 0;
    int index = 1;
    

    for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext())
    {
        length++;
        
    }
    if(length<=1)
        {
            cout<<"NOT ENOUGH SONGS"<<endl;
            return;
        }
    for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext())
    {
        if(index == oldPos)
        {
            copy = curr;
            copy->SetNext(nullptr);
        }
        index++;
    }
    // remove(oldPos);


    if(newPos<=1)//if new position is head
    {
        PlaylistNode *temp = head;

        copy->SetNext(head->GetNext());
        setHead(copy);
        
    }
    // else if(newPos>length)
    // {
    //     newPos = length;
    // }
    // if(oldPos==1)
    // {

    // }
    // for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext())
    // {
    //     if(index == oldPos)
    //     {
    //         oldPosition = curr;
    //     }
    //     index++;
    // }
    // pre->SetNext(oldPosition->GetNext());
    // // else if(oldPos > length)
    // // {
    // //     oldPosition = tail;
    // // }
    // // else
    // // {
    // //     
    // // }
    // index = 1;
    // if(newPos<=1)
    // {
        
    // }
    // else if(oldPos > length)
    // {
    //     oldPosition = tail;
    // }
    // else
    // {
    //     for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext())
    //     {
    //         if(index == oldPos)
    //         {
    //             oldPosition = curr;
    //         }
    //         index++;
    //     }
    // }
    
    
    
}

void Playlist::setHead(PlaylistNode* temp)
{
    // cout << "HEAD SET" << endl;
    head=temp;
    // if (GetHead() == nullptr)
    //     cout << "HEAD STILL NULL" << endl;
    // else
    //     cout << "HEAD NOT NULL" << endl;
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
        cout << "\"" << songName << "\" removed."<< endl << endl;
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
                cout << "\"" << songName << "\" removed."<< endl << endl;
                return;

                //if tail is to be deleted
                
            }
            pre = curr;
        }
    }
    cout<<"Song by ID  \""+ID+"\" not found"<<endl;
}

void Playlist::remove(int position)
{
    int index = 1;
    if(position<=1)
    {
        PlaylistNode *temp = head;
        head = (head->GetNext());
        delete temp;
        return;
    }
    PlaylistNode *pre = head;
    if (pre != nullptr) {
        for(PlaylistNode *curr = pre->GetNext(); curr!=nullptr; curr = curr->GetNext())
        {
            if(index = position-1)
            {
                if(curr!=tail)//if mid value to be deleted
                {
                    pre->SetNext(curr->GetNext());
                }
                else//if tail is final value
                {
                    pre->SetNext(nullptr);               
                }
                delete curr;
                return;

                //if tail is to be deleted
                
            }
            pre = curr;
        }
    }
    
    
}


ostream &operator<<(ostream & os, const Playlist &somePlaylist)
{
    os<<somePlaylist.playlistName<<" - OUTPUT FULL PLAYLIST" << endl;
    if(somePlaylist.GetHead()!=nullptr)
    {
        
        
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
        os<<"Playlist is empty"<<endl<<endl;
    }
    return os;
}
    