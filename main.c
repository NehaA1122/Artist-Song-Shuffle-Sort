#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"

//program has to take in all 4 artists and all 3 songs per artist
//could not figure out how to enter artists and songs and then break if needed
//sort works fine
//shuffle doesn't have the 5 space buffer - I've just made it run twice

int main(void)
{
  //The array containing artists names
  char artists[4][80]={0};
  //The array containing the sorted artists
  char sortedArtists[4][80]={0};
  //Songs for Artist 1
  char songsArtist1[3][80];
  //Songs for Artist 2
  char songsArtist2[3][80];
  //Songs for Artist 3
  char songsArtist3[3][80];
  //Songs for Artist 4
  char songsArtist4[3][80];

  //the array of pointers to point to each song array
  char (*songArrayPtrs[4])[3][80]={&songsArtist1, &songsArtist2, &songsArtist3, &songsArtist4};

  //The total number of artists (Note it can be less than 4)
  int numOfArtists = 0;

  //The total number of songs for each artist (Note that less than 3 songs can be provided for each artist)
  int numSongsPerArtist[4];

  int i, j;
  int length;
  int songCount;
  int numOfSongs = 0;


/*
 * Use here functions that you should implement to insert artists and songs from the standard input.
 * Note that you also need to track the number of artists and the number of songs for each artist.
 */

    //asks for 4 artists and 3 songs per artist

    //input for artist 1
    printf("Insert an artist/group name:\n");
    fgets(artists[0], 80, stdin);

    //gets rid of newline char - for neat outputting
    length = strlen(artists[0]);
    artists[0][length-1]='\0';

    songCount=1;
    for(i=0;i<3;i++)
    {
        printf("Insert song %d for %s:\n", songCount, artists[0]);
        fgets(songsArtist1[i], 80, stdin);

        //gets rid of newline char
        length = strlen(songsArtist1[i]);
        songsArtist1[i][length-1]='\0';

        songCount++;
    }

    //artist 2
    printf("Insert an artist/group name:\n");
    fgets(artists[1], 80, stdin);
    numOfArtists++;

    //gets rid of newline char
    length = strlen(artists[1]);
    artists[1][length-1]='\0';

    songCount=1;
    for(i=0;i<3;i++)
    {
        printf("Insert song %d for %s:\n", songCount, artists[1]);
        fgets(songsArtist2[i], 80, stdin);

        //gets rid of newline char
        length = strlen(songsArtist2[i]);
        songsArtist2[i][length-1]='\0';

        songCount++;
    }

    //artist 3
    printf("Insert an artist/group name:\n");
    fgets(artists[2], 80, stdin);
    numOfArtists++;

    //gets rid of newline char
    length = strlen(artists[2]);
    artists[2][length-1]='\0';

    songCount=1;
    for(i=0;i<3;i++)
    {
        printf("Insert song %d for %s:\n", songCount, artists[2]);
        fgets(songsArtist3[i], 80, stdin);

        //gets rid of newline char
        length = strlen(songsArtist3[i]);
        songsArtist3[i][length-1]='\0';

        songCount++;
    }

    //artist 4
    printf("Insert an artist/group name:\n");
    fgets(artists[3], 80, stdin);
    numOfArtists++;

    //gets rid of newline char
    length = strlen(artists[3]);
    artists[3][length-1]='\0';

    songCount=1;
    for(i=0;i<3;i++)
    {
        printf("Insert song %d for %s:\n", songCount, artists[3]);
        fgets(songsArtist4[i], 80, stdin);

         //gets rid of newline char
        length = strlen(songsArtist4[i]);
        songsArtist4[i][length-1]='\0';

        songCount++;
    }


 /*
 * Use here the function sortArtists to sort the array of the artists and sortSongs to sort the songs of each artist
 * Print each artist (alphabetically) and for each of them print the list of songs sorted alphabetically
 */

    //copies artists array into sorted artists array
    for(j=0; j<4; j++)
    {
       strcpy(sortedArtists[j], artists[j]);
    }

    //sets variables
    numOfArtists = 4;
    numOfSongs = 3;

    //function call to sort artists and sort songArrayPtrs so songs will match up to artists
    sortArtists(sortedArtists, numOfArtists, songArrayPtrs);

    //function call to sort songs for each songsArtist array
    sortSongs(songsArtist1, numOfSongs);
    sortSongs(songsArtist2, numOfSongs);
    sortSongs(songsArtist3, numOfSongs);
    sortSongs(songsArtist4, numOfSongs);


    printf("The sorted artists and songs are:\n");
    for(i=0; i<4; i++)
    {
        songArrayPtrs[i];
        printf("%s\n", sortedArtists[i]);

        for(j=0; j<3; j++)
        {
            printf("\t - %s\n", (*songArrayPtrs[i])[j]);
        }
    }

 /*
 * Use here the function shuffleSongs to shuffle all the songs
 * Print the list of shuffled songs
 */

    //total number of songs
    int numSongs = 12;

    //array for songs and artists to be combined into one
    char songsArtists[12][80];
    int k = 0;

    //copying artists and songs into one array - songsArtistsG
    for(i=0; i<4; i++)
    {
        if(i==0)
        {
            for(j=0; j<3; j++)
            {
                //copies sortedArtist[0] into array
                strcpy(songsArtists[k], sortedArtists[i]);
                //appends '-' to sortedArtists[0]
                strcat(songsArtists[k], " - ");
                //then appends the song to the end of artists[0] - . Does this three times for each song.
                strcat(songsArtists[k], (*songArrayPtrs[0])[j]);
                //index gets updated for every storing of 'artist - song'
                k++;
            }
        }

        else if(i==1)
        {
            for(j=0; j<3; j++)
            {
                strcpy(songsArtists[k], sortedArtists[i]);
                strcat(songsArtists[k], " - ");
                strcat(songsArtists[k], (*songArrayPtrs[1])[j]);
                k++;
            }
        }

        else if(i==2)
        {
            for(j=0; j<3; j++)
            {
                strcpy(songsArtists[k], sortedArtists[i]);
                strcat(songsArtists[k], " - ");
                strcat(songsArtists[k], (*songArrayPtrs[2])[j]);
                k++;
            }
        }

       else if(i==3)
        {
            for(j=0; j<3; j++)
            {
                strcpy(songsArtists[k], sortedArtists[i]);
                strcat(songsArtists[k], " - ");
                strcat(songsArtists[k], (*songArrayPtrs[3])[j]);
                k++;
            }
        }
    }

    printf("\nShuffled Playlist:\n");

    shuffleSongs(songsArtists, numSongs);
    for(i=0; i<12; i++)
    {
        printf("%s\n", songsArtists[i]);
    }

    shuffleSongs(songsArtists, numSongs);
    for(i=0; i<12; i++)
    {
        printf("%s\n", songsArtists[i]);
    }

  return 0;
}


