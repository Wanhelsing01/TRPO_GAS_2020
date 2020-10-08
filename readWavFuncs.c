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

//читает структуру заголовка файла f_in в структуру header
//и выводит информацию из заголовка на экран.
void readHeader(t_wavhdr* header, FILE* f_in){
  
  char* fname = "readHeader";

  fread(header, sizeof(t_wavhdr), 1, f_in);
  
<<<<<<< HEAD
=======
  //Здесь будет Ваш код
  fread(header, sizeof(t_wavhdr), 1, f_in);
  
>>>>>>> cee4e710a37f95a2dafbd9c35c72b5f8973653d9
  //пример печати параметров wav-файла

  //printf("***** Parametrs of WAV-file [%s] *****\n", fin_name);
	
  printf("chunkID =  %s\n", header->chunkID);
  printf("chunkSize =  %i\n", header->chunkSize);
  printf("format =  %s\n", header->format);
  printf("subchunk1ID =  %s\n", header->subchunk1ID);
  printf("subchunk1Size =  %i\n", header->subchunk1Size);
  printf("audioFormat =  %i\n", header->audioFormat);
  printf("numChannels = %i\n", header->numChannels);
  printf("sampleRate =  %i\n", header->sampleRate);
  printf("blockAlign = %i\n", header->blockAlign);
  printf("bitsPerSample = %i\n", header->bitsPerSample);
	
  printf("subchunk2ID =  %s\n", header->subchunk2ID);
  printf("subchunk2Size =  %i\n", header->subchunk2Size);
	
  printf("*********************************************************\n");

  return;
}


//читает из файла f_in порцию данных размером N в массив data_portion.
void readData(int* data_portion, int N, FILE* f_in ){
  
  char* fname = "readData";

  fread(data_portion, sizeof(int), N, f_in);

  return;
}
