using namespace std;
#include <iostream>
#include "Playlist.h"

char printMenu();


string title = "";
int main()
{
    //Variables
    

    // set up
    cout<<"Enter playlist's title: "<<endl;
    getline(cin, title);
    Playlist p1 = Playlist(title);
    PlaylistNode *newSong = new PlaylistNode("0001", "Abc", "artist", 123);
    newSong->InsertAfter(p1, p1.GetTail());
    newSong = new PlaylistNode("0002", "BBB", "B", 100);
    newSong->InsertAfter(p1, p1.GetTail());
    newSong = new PlaylistNode("0003", "CCC", "C", 203);
    newSong->InsertAfter(p1, p1.GetTail());
    newSong = new PlaylistNode("0004", "DDD", "D", 130);
    newSong->InsertAfter(p1, p1.GetTail());
    newSong = new PlaylistNode("0005", "EEE", "E", 623);
    newSong->InsertAfter(p1, p1.GetTail());
    newSong = new PlaylistNode("0006", "FFF", "F", 500);
    newSong->InsertAfter(p1, p1.GetTail());
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
            
            cout<<"Enter song's length:"<<endl;
            cin>>length;

            // id=123;
            // name = "Allstart";
            // artist = "Smash mouth";
            // length=422;

            PlaylistNode *newSong = new PlaylistNode(id, name, artist, length);

            newSong->InsertAfter(p1, p1.GetTail());

            //p1->SetNext(newSong)
        }
        else if(input == 'd')
        {
            string deleteID;
            cout<<"REMOVE SONG"<<endl;
            cout << "Enter song's unique ID: " << endl;
            cin >> deleteID;
             
            p1.remove(deleteID);

            //cout << "\"" << p1.remove(deleteID) << "\" removed" << endl;
        }
        else if(input == 'c')
        {

        }
        else if(input == 's')
        {

        }
        else if(input == 't')
        {

        }
        else if(input == 'o')
        {
            // for(PlaylistNode *curr = p1.GetHead(); curr!=nullptr; curr = curr->nextNodePtr)
            // {

            //     curr.PrintPlaylistNode();
            // }

            cout<<p1;
        }
        else if(input == 'p')
        {

        }

        input = printMenu();
    }


    //test cases
    return 0;
}

char printMenu()
{
    char input;
    cout<<title<<" Playlist Menu: "<<endl;
    cout<<"a - Add song"<<endl;
    cout<<"d - Remove song"<<endl;
    cout<<"c - Change position of song"<<endl;
    cout<<"s - Output songs by specific artist"<<endl;
    cout<<"t - Output total time of playlist (in seconds)"<<endl;
    cout<<"o - Output full playlist"<<endl;
    cout<<"q - Quit"<<endl;
    cout<<"Choose an option:"<<endl;
    cin>>input;
    return input;
}

//g++ main.cpp Playlist.cpp -Wall -o a.out