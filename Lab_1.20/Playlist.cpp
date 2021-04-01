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

void Playlist::insert(int pos, PlaylistNode* song)
{
    if(pos<=1)//working - replacing head
    {
        // cout<<"messing with head";
        PlaylistNode *temp = song;
        temp->SetNext(head);
        head = temp;
    }
    else
    {
        // cout<<"messing with mid section"<<endl<<endl;
        int index = 2;
        PlaylistNode *pre = head;
        if(head != tail)//dealing with 2 length lists
        {
            for(PlaylistNode *curr = head->GetNext(); curr!=nullptr; curr=curr->GetNext())
            {
                if(pos == index)
                {
                    if(pre==tail)
                    {
                        // cout<<"tail"<<endl<<endl;
                        setTail(song);
                    }
                    // cout<<"msdfsation"<<endl<<endl;
                    pre->InsertAfter(song);
                }
                index++;
                pre=curr;
            }
        }
        else
        {
            song->SetNext(nullptr);
            pre->InsertAfter(song);
            setTail(song);
        }
    }
}

void Playlist::insert(int newPos, int oldPos)
{
    int index = 2;
    int length = 0;
    for (PlaylistNode* curr = head; curr != nullptr; curr = curr->GetNext())
    {
        length++;
    }
    if(newPos <=1)
    {
        newPos = 1;
    }
    else if (newPos >= length)
    {
        newPos = length;
    }
    PlaylistNode* preOldNode = head;
    PlaylistNode* beforeOldNode = nullptr;
    PlaylistNode* copy = nullptr;
    if(oldPos>1)//if node being moved is not head
    {
        // cout<<"oldNode is not head"<<endl;
        for (PlaylistNode* curr = preOldNode->GetNext(); curr != nullptr; curr = curr->GetNext())
        {
            // cout<<endl<<index<<endl;
            if(index == oldPos)
            {
                copy = curr;
                // cout<<"-----------";
                // copy->PrintPlaylistNode();
                preOldNode->SetNext(curr->GetNext());
                insert(newPos, copy);
                cout << "\"" << copy->GetSongName() << "\" moved to position " << newPos <<endl; //
                return;
            }
            index++;
            preOldNode = curr;
        }     
    }
    else//if node moved is head
    { 
        copy = head;
        head = head->GetNext();       
        // cout<<newPos<<endl<<endl<<endl;
        insert(newPos, copy);
        cout << "\"" << copy->GetSongName() << "\" moved to position " << newPos <<endl<<endl; //if I get rid of 1 endl i get the other test case correct
        return;
        

    }

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
    