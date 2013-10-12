#include <cstdlib>
#include <windows.h>
#include <fstream>

#include "GBExporter.hpp"

int getNote(const stChanNote &note) {
	if(note.Note == 0) {
		return T_NONE;
	} else if (note.Note <= 12) {
		return ((int)note.Octave-1)*12 + (int)note.Note-1;
	} else {
		return T_SILENCE;
	}
}

DLL_EXPORT bool Export(FamitrackerDocInterface const *doc, const char *filename) {
	const char *names[15]={"NONE","C","Cs","D","Ds","E","F","Fs","G","Gs","A","As","B","SILENCE","SILENCE"};
	std::ofstream os;
	os.open(filename, std::ios::out);
	stChanNote note;
	int lastVol[3] = {15,15,15};

	os << "#ifndef __TESTSONG_H" << std::endl;
	os << "#define __TESTSONG_H" << std::endl << std::endl;

	os << "const UBYTE test_song_data[] = {" << std::endl;

	for(int i = 0; i < doc->GetFrameCount(); ++i) {
		for(int j = 0; j < doc->GetPatternLength(); ++j) {
			for(int k = 0; k < 3; ++k) {
				doc->GetNoteData(i,k,j,&note);
				if(note.Note < 1 || note.Note > 12) {
					os << "0";
				} else if(note.Vol == 16) {
					os << lastVol[k];
				} else {
					os << (int)note.Vol;
				}
				os << ",\t";
				os << getNote(note);
				os << ",\t";
			}
			os << std::endl;
		}
	}

	os << "};" << std::endl;
	os << "#define test_song_length " << doc->GetFrameCount()*doc->GetPatternLength()*6 << std::endl << std::endl;
	os << "#endif" << std::endl;

	os.close();
	return true;
}

DLL_EXPORT const char *GetName(void) {
	return "Game Boy exporter";
}

DLL_EXPORT const char *GetExt(void) {
	return ".h";
}
