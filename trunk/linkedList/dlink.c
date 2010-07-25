#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h>

struct Date {
	short month, day, year;
};

struct Song {
	char title[64];
	char artist[32];
	char composer[32];
	short duration;		//play times
	struct Date published;	//publish date
};
/*
struct Cell {
	struct Song song;
	struct Cell *pNext;
};
*/
typedef struct Song Song_t;

typedef struct Cell {
	struct Song song;
	struct Cell *pNext;
} Cell_t;


typedef struct {
	Cell_t *pFirst, *pLast;
} SongList_t;


bool appendSong( SongList_t *pList, const Song_t *pSong)
{
	Cell_t *pCell = calloc( 1, sizeof(Cell_t) );	//create a new link list project
	if ( pCell == NULL )
	{
		return false;
	}

	pCell->song = *pSong;
	pCell->pNext = NULL;

	if ( pList->pFirst == NULL )
	{
		pList->pFirst = pList->pLast = pCell;
	}
	else
	{
		pList->pLast->pNext = pCell;
		pList->pLast = pCell;
	}

	return true;
}

void clearSongList( SongList_t *pList)
{
	Cell_t *pCell, *pNextCell;
	for ( pCell = pList->pFirst; pCell != NULL; pCell = pNextCell )
	{
		pNextCell = pCell->pNext;
		free( pCell );
	}
	pList->pFirst = pList->pLast = NULL;
}

SongList_t cloneSongList( const SongList_t *pList)
{
	SongList_t newSL = { NULL, NULL }; //new empty linked list
	Cell_t *pCell = pList->pFirst; // copy from linklist's first
	while ( pCell != NULL && appendSong( &newSL, &pCell->song))
	{
		pCell = pCell->pNext;
	}

	if ( pCell != NULL )			//if we are not com.. the last one
	{
		clearSongList( &newSL );	//drop all project
	}

	return newSL;				//return link list's head
}
