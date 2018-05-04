#include <stdio.h>
#include <stdlib.h>

struct OjnHeader {
	int SongId;
	char Signature[4];
	float EncodingVersion;
	int Genre;
	float Bpm;
	short Level[4];
	int EventCount[3];
	int NoteCount[3];
	int MeasureCount[3];
	int PackageCount[3];
	short EncodingVersionOld;
	short SongIdOld;
	char GenreOld[20];
	int BeatmapSize;
	int FileVersionOld;
	char Title[64];
	char Artist[32];
	char NoteCharter[32];
	char MusicFileName[32];
	int CoverSize;
	int Time[3];
	int NoteDataOffset[3];
	int CoverDataOffset;
};

typedef struct OjnHeader O2JamHeader;

int PrintData(O2JamHeader *header) {
	printf("Song Name    : %s\n", header->Title);
	printf("Song Artist  : %s\n", header->Artist);
	printf("Song Charter : %s\n", header->NoteCharter);
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("You aren't given file name.");
		return 1;
	}
	
	FILE *stream;
	stream = fopen(argv[1], "rb");

	if (stream == NULL) {
		printf("Invaild file name.");
		return 1;
	}

	O2JamHeader header;
	fread(&header, sizeof(O2JamHeader), 1, stream);

	PrintData(&header);

	return 0;
}
