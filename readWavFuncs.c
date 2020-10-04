//-*- coding: utf-8 -*-
//******************************************************************************
// Обозначение:		readWavFuncs.c 				       
// Назначение:			
// Разработчик:     	Сергеева Е.И.
// Дата последней корректировки: 
//******************************************************************************

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "def_types.h"
#include "readWavFuncs.h"

void readHeader(t_wavhdr* header, FILE* f_in){
  
  char* fname = "readHeader";

  
  //Здесь будет Ваш код

  
//пример печати параметров wav-файла
/*
	printf("***** Parametrs of WAV-file [%s] *****\n", fin_name);
	
	printf("chunkID =  %s\n", header.chunkID);
	printf("chunkSize =  %i\n", header.chunkSize);
	printf("format =  %s\n", header.format);
	printf("subchunk1ID =  %s\n", header.subchunk1ID);
	printf("subchunk1Size =  %i\n", header.subchunk1Size);
	printf("audioFormat =  %i\n", header.audioFormat);
	printf("numChannels = %i\n", header.numChannels);
	printf("sampleRate =  %i\n", header.sampleRate);
	printf("blockAlign = %i\n", header.blockAlign);
	printf("bitsPerSample = %i\n", header.bitsPerSample);
	
	printf("subchunk2ID =  %s\n", header.subchunk2ID);
	printf("subchunk2Size =  %i\n", header.subchunk2Size);
	
	printf("*********************************************************\n");
*/
  
  return;
}



void readData(float* data_portion, int N, FILE* f_in ){
  
  char* fname = "readData";

  
  //Здесь будет Ваш код

  
  return;
}
