default: GBExporter.dll

GBExporter.o: GBExporter.cpp GBExporter.hpp
	i486-mingw32-g++ -ISource -c GBExporter.cpp

GBExporter.dll: GBExporter.o
	i486-mingw32-g++ -shared -static-libgcc -static-libstdc++ -o GBExporter.dll GBExporter.o
	mv GBExporter.dll ../plugins/
