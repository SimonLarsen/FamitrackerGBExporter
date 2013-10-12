#include <CustomExporterInterfaces.h>

#define DLL_EXPORT __declspec(dllexport)

enum E_TONE {
	T_C3, T_Cs3, T_D3, T_Ds3, T_E3, T_F3, T_Fs3, T_G3, T_Gs3, T_A3, T_As3, T_B3,
	T_C4, T_Cs4, T_D4, T_Ds4, T_E4, T_F4, T_Fs4, T_G4, T_Gs4, T_A4, T_As4, T_B4,
	T_C5, T_Cs5, T_D5, T_Ds5, T_E5, T_F5, T_Fs5, T_G5, T_Gs5, T_A5, T_As5, T_B5,
	T_C6, T_Cs6, T_D6, T_Ds6, T_E6, T_F6, T_Fs6, T_G6, T_Gs6, T_A6, T_As6, T_B6,
	T_C7, T_Cs7, T_D7, T_Ds7, T_E7, T_F7, T_Fs7, T_G7, T_Gs7, T_A7, T_As7, T_B7,
	T_C8, T_Cs8, T_D8, T_Ds8, T_E8, T_F8, T_Fs8, T_G8, T_Gs8, T_A8, T_As8, T_B8,
	T_SILENCE, T_NONE
};

int getNote(const stChanNote &note);
extern "C" DLL_EXPORT bool Export(FamitrackerDocInterface const *iface, const char *filename);
extern "C" DLL_EXPORT const char *GetName(void);
extern "C" DLL_EXPORT const char *GetExt(void);
