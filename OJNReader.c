#include <stdio.h>
#include <wchar.h>

struct OjnHeader {
    int SongId;
    char Signature[4];
    float EncodeVersion;
    int Genre;
    float Bpm;
    short Level[4];
    int EventCount[3];
    int NoteCount[3];
    int MeasureCount[3];
    int PackageCount[3];
    short EncodeVersionOld;
    short SongIdOld;
    char GenreOld[20];
    int BeatmapSize;
    int FileVersionOld;
    char Title[64];
    char Artist[32];
    char NoteCharter[32];
    char OjmFileName[32];
    int CoverSize;
    int Time[3];
    int NoteDataOffset[3];
    int CoverDataOffset;
};

int main(int argc, char *argv[])
{
    struct OjnHeader header;

    FILE *file = fopen(argv[1], "rb");

    if (file == NULL)
        return 0;

    fread(&header, sizeof(header), 1, file);

    printf("TITLE : %s\n", header.Title);
    printf("ARTIST : %s\n", header.Artist);
    printf("NOTECHARTER : %s\n", header.NoteCharter);
    printf("NOTECOUNT: E %d, N %d, H %d\n", header.NoteCount[0], header.NoteCount[1], header.NoteCount[2]);
    printf("LEVEL: E %d, N %d, H %d\n", header.Level[0], header.Level[1], header.Level[2]);
    
    return 0;
}
