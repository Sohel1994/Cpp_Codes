#include<iostream>
#include<algorithm>
#include<list>
#include<iterator>
using namespace std;
class song
{
    int rate;
    string artist;
    string songName;
    public:
    song() = default;
    song( int rt , string art , string sName):rate{rt},artist{art},songName{sName}
    {

    }
    bool operator<(const song &rhs) const
    {
        return this->songName < rhs.songName;
    }

    bool operator==(const song &rhs) const
    {
        return this->songName==rhs.songName;
    }
     
    friend ostream & operator<<( ostream &os , const song &s);

}; 

ostream & operator<<( ostream &os , const song &s)
{
    os<<s.songName <<" : "<< s.artist<<" : "<< s.rate <<" ";
    return os;
}

void displaymenu()
{
    cout<<"\nPlaylist Option"<<"\n";
    cout << "F - play the first song "<< "\n";
    cout << "N - play the next song "<< "\n";
    cout << "P - play the previous song "<< "\n";
    cout << "A - add the new song at current song"<<"\n";
    cout << "L - list the current play list "<<"\n";
    cout << "==============================================\n";
    cout << "Q - quit from the list " <<"\n";
}

void display_playlist(const list<song> &playlist , const song &it )
{
     cout << "Display playlist "<<"\n";
     cout << "-------------------------\n";
     for( auto &s : playlist)
     {
        cout<< s << "\n";
     }
     
     cout << "-------------------------\n";
     cout<<" current song : " << "\n";
     cout << it <<"\n";


    // list<song> :: iterator i = playlist.begin(); // to make work this remove const from parameter list
    // for(;i!=playlist.end();i++)
    // {
    //      cout<<*i <<"\n";
    // }   
}
void play_current_song( const song &current)
{
    cout<< " \nplaying current song : " <<"\n";
    cout<< current << "\n";
}
int main()
{
    list<song> playlist = {
                             { 5 , "sonu" , "sathiya"},
                             { 4 , "arijith","kyun ki tum hi ho"},
                             { 4 , "javed ali","arjiyaan"},
                             { 5 , "sid sriram" , "kesariya"},
                             { 4 , "araman malik" , "le ja muzhe"},
                             { 3 , "salman khan" , "main hi hun hero tera"}
                          };
    
    list<song>::iterator currentSong = playlist.begin();
    display_playlist( playlist, *currentSong); // must be send dereferce of iterator to display song
    
    char selection {};
    do
    {
       displaymenu();
       cout << " choose the operation to be perform as per menu for playlist" <<"\n";
       cin >> selection;
       selection = ::toupper(selection);
        int rt = 0;
        string sNm, artNm;
       switch (selection)
       {

       case 'F': cout<<" Play the current song "<<"\n";
                 currentSong = playlist.begin();
                 play_current_song(*currentSong);  
                 break;

       case 'N': cout<<" Play the next song "<<"\n";
                 currentSong++;
                 if(currentSong == playlist.end())
                 { 
                    cout<< "wraping the playlist for first song because of last song"<<"\n";
                    currentSong=playlist.begin();
                 }
                 play_current_song(*currentSong);  
                 break;
       case 'P': cout<<" Play the previous song "<<"\n";
                 if(currentSong == playlist.begin())
                 { 
                    cout<< "wraping the playlist for first song because of last song"<<"\n";
                    currentSong=playlist.end();
                 }
                 currentSong--;
                 play_current_song(*currentSong);  
                 break;

       case 'A': cin.clear();
                 cin.ignore(numeric_limits<streamsize>::max(),'\n');
                 cout<<" Add new song to the playlist"<<"\n";
                 cout << " eneter the name of artist \n";
                 getline(cin,artNm);
                 cout<< " enter the name of the song \n";
                 getline(cin,sNm);
                 cout<< " enter the rating of the of the song \n";
                 cin>>rt;
                 playlist.insert(currentSong,song(rt,artNm,sNm)); //adding new song before the current song position.
                 currentSong--; // decremeting iterator to play new song added.
                 play_current_song(*currentSong); 
                 break;

        case 'Q': cout << "quit from the music player \n";
                 break;

        default : cout << " invalid entery for selection" <<"\n";
                  break;
       }
    }while(selection!= 'Q');
    

}