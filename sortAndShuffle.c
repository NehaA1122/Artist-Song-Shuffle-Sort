#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"
#include <time.h>



/*
* This method sorts the artists alphabetically. It takes as input:
* - sortedArtists: the array of artists that that should be sorted
* - numOfArtists: the total number of artists
*
*/

void sortArtists(char sortedArtists[][80] , int numOfArtists, char* songArrayPtrs[])
{
    char temp[80]={0};
    char* swap;
    int i, j;
    int size = numOfArtists;

    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (strcmp(sortedArtists[i], sortedArtists[j]) > 0)
            {
                strcpy(temp, sortedArtists[i]);
                strcpy(sortedArtists[i], sortedArtists[j]);
                strcpy(sortedArtists[j], temp);

                //sorts pointer array so it lines up with the artists

                swap = songArrayPtrs[i];
                songArrayPtrs[i] = songArrayPtrs[j];
                songArrayPtrs[j] = swap;
            }
        }
    }
}

/*
* This method sorts the songs of a specific artist alphabetically. It takes as input:
* - songsOfAnArtist: the array of the songs of an artist that was provided from the standard input
* - numOfArtists: the number of artists provided from the standard input
*/
void sortSongs(char songsOfAnArtist[][80], int numOfSongs)
{
    char temp[80];
    int i, j;
    int size = numOfSongs;

    for (i = 0; i < size - 1; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (strcmp(songsOfAnArtist[i], songsOfAnArtist[j]) > 0)
            {
                strcpy(temp, songsOfAnArtist[i]);
                strcpy(songsOfAnArtist[i], songsOfAnArtist[j]);
                strcpy(songsOfAnArtist[j], temp);
            }
        }
    }
}

/*
* This method shuffles a set of songs. It takes as input:
* - songsToBeShuffled: the array of the songs that should be shuffled
* - numOfSongs: the number of songs to be shuffled
*/
void shuffleSongs(char songsToBeShuffled[][80], int numOfSongs)
{
    srand(time(NULL));
    int i, j;
    char swap[80];

    for(i=1; i<numOfSongs; i++)
    {
        j=rand()%(i+1);
        if(j != i)
        {
            strcpy(swap, songsToBeShuffled[i]);
            strcpy(songsToBeShuffled[i], songsToBeShuffled[j]);
            strcpy(songsToBeShuffled[j], swap);
        }
    }

}
