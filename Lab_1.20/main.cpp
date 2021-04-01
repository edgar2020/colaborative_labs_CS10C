using namespace std;
#include <iostream>
#include "Playlist.h"

char printMenu();


string title = "";
int main()
{
    //Variables
    

    // set up
    cout<<"Enter playlist's title:"<<endl<<endl;
    getline(cin, title);
    Playlist p1 = Playlist(title);
    // p1.setHead(nullptr);
    // PlaylistNode *newSong = new PlaylistNode("0001", "Abc", "artist", 123);
    // p1.setHead(newSong);
    // // p1.GetHead()->InsertAfter(newSong);
    // newSong = new PlaylistNode("0002", "BBB", "B", 100);
    // newSong->InsertAfter(p1.GetTail());
    // newSong = new PlaylistNode("0003", "CCC", "C", 203);
    // newSong->InsertAfter(p1.GetTail());
    // newSong = new PlaylistNode("0004", "DDD", "D", 130);
    // newSong->InsertAfter(p1.GetTail());
    // newSong = new PlaylistNode("0005", "EEE", "E", 623);
    // newSong->InsertAfter(p1.GetTail());
    // newSong = new PlaylistNode("0006", "FFF", "F", 500);
    // newSong->InsertAfter(p1.GetTail());
    char input = printMenu();
    while(input != 'q')
    {
        if(input == 'a')
        {
            string id, name, artist;
            int length;

            cout<<"ADD SONG"<<endl;
            cout<<"Enter song's unique ID:"<<endl;
            cin>>id;
            cin.ignore();
            cout<<"Enter song's name:"<<endl;
            getline(cin, name);
            cout<<"Enter artist's name:"<<endl;
            getline(cin, artist);
            
            cout<<"Enter song's length (in seconds):"<< endl << endl;
            cin>>length;

            // id=123;
            // name = "Allstart";
            // artist = "Smash mouth";
            // length=422;

            PlaylistNode *newSong = new PlaylistNode(id, name, artist, length);
            if(p1.GetHead()==nullptr)
            {
                p1.setHead(newSong);
                p1.setTail(newSong);
            }
            else
            {
                PlaylistNode *temp = p1.GetTail();
                p1.setTail(newSong);
               temp->InsertAfter(newSong);
            //    p1.setTail(newSong);
            }
            // PlaylistNode *newSong = new PlaylistNode(id, name, artist, length);
            // if (p1.GetHead() == nullptr) {
            //     p1.setHead(newSong);
            //     p1.setTail(newSong);
            // }

            // newSong->InsertAfter(p1.GetTail());
                

            //p1->SetNext(newSong)
        }
        else if(input == 'd')
        {
            string deleteID;
            cout<<"REMOVE SONG"<<endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> deleteID;
             
            p1.remove(deleteID);
            // cout << "\"" << songName << "\" removed."<< endl << endl;
            //cout << "\"" << p1.remove(deleteID) << "\" removed" << endl;
        }
        else if(input == 'c')
        {
            cout << "CHANGE POSITION OF SONG" << endl;
            
            
            int oldPosition;
            int newPosition;
            cout << "Enter song's current position:" << endl;
            cin >> oldPosition;

            cout << "Enter new position for song:" << endl;
            cin >> newPosition;

            // p1.insert(newPosition, oldPosition);
            // PlaylistNode *original = nullptr;
            // PlaylistNode *beforeNewPos = nullptr;
            // PlaylistNode *tempCopy = nullptr; 
            PlaylistNode* beforeOld = nullptr;
            PlaylistNode* beforeNew = nullptr;
            PlaylistNode* atOldLocation = nullptr;
            PlaylistNode* prev = nullptr;
            PlaylistNode *original = nullptr;
            PlaylistNode *temp = nullptr;

            int index = 1;
            bool two = false;
            if (oldPosition <= 1) //if song current poistion is first
            {
                original = p1.GetHead();
                cout << "Position less than 1" << endl;
                if (newPosition == 2) { //if the new position is right after first
                    if (original->GetNext()->GetNext() == nullptr) { //if only 2 songs
                        p1.GetTail()->SetNext(original);
                        p1.setHead(p1.GetTail());
                        original->SetNext(nullptr);
                        p1.setTail(original);
                    } else { // if more than 2 songs
                        temp = original->GetNext();
                        original->SetNext(original->GetNext()->GetNext()); 
                        temp->SetNext(original);
                        p1.setHead(temp);
                    }
                    two = true;
                }
                index++;
            }
            if (newPosition <= 1)
            {
                newPosition++;
            }
            else {
                for (PlaylistNode* curr = p1.GetHead(); curr != nullptr; curr = curr->GetNext())
                {
                    if (index == oldPosition) 
                    {
                        beforeOld = prev;
                        cout << "oldPosition SET" << endl;
                    }
                    if (index == newPosition)
                    {
                        beforeNew = prev;
                        atOldLocation = curr->GetNext();
                        cout << "newPosition SET" << endl;
                    }
                    prev = curr;
                    index++;
                }
            }
            if (original == p1.GetHead() && index >= 3 && !two) {
                cout << "position GREATER than 3" << endl;
                if (atOldLocation == p1.GetTail()) {
                    temp = original->GetNext();
                    original->SetNext(nullptr); 
                    atOldLocation->SetNext(original);
                    p1.setHead(temp);  
                } else {
                    temp = original->GetNext();
                    original->SetNext(atOldLocation->GetNext()); 
                    atOldLocation->SetNext(original);
                    //oldNew->SetNext(temp);
                    p1.setHead(temp);
                }             
            }
            
            //cout << "\"" << tempCopy->GetSongName() << "\" removed" << endl;
        }
        else if(input == 's')
        {
            cout<<"OUTPUT SONGS BY SPECIFIC ARTIST"<<endl;
            cout<<"Enter artist's name:"<<endl<<endl;
            string artist;
            cin.ignore();
            getline(cin, artist);
            int num = 1;
            for(PlaylistNode *curr = p1.GetHead(); curr!=nullptr; curr = curr->GetNext())
            {
                if(curr->GetArtistName() == artist)
                {
                    cout << num << '.' << endl;
                    curr->PrintPlaylistNode();
                }
                num++;
            }

        }
        else if(input == 't')
        {
            int sum = 0;
            for(PlaylistNode *curr = p1.GetHead(); curr!=nullptr; curr = curr->GetNext())
            {
                sum+=curr->GetSongLength();
            }
            cout<<"OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)"<<endl;
            cout<<"Total time: "<<sum<<" seconds"<<endl<<endl;
        }
        else if(input == 'o')
        {
            cout<<p1;
        }

        input = printMenu();
    }


    //test cases
    return 0;
}

char printMenu()
{
    char input;
    cout<<title<<" PLAYLIST MENU"<<endl;
    cout<<"a - Add song"<<endl;
    cout<<"d - Remove song"<<endl;
    cout<<"c - Change position of song"<<endl;
    cout<<"s - Output songs by specific artist"<<endl;
    cout<<"t - Output total time of playlist (in seconds)"<<endl;
    cout<<"o - Output full playlist"<<endl;
    cout<<"q - Quit"<<endl<<endl;
    cout<<"Choose an option:"<<endl;
    cin>>input;
    return input;
}

//g++ main.cpp Playlist.cpp -Wall -o a.out