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
void readData(double* data_portion, int N, FILE* f_in ){
  
  char* fname = "readData";

  int i, tmp;
  for (i = 0; i < N; i++){
    fread(&tmp, sizeof(int), 1, f_in);
    data_portion[i]=(double)tmp;
  } 

  return;
}

// Return the number of portions and the tail size
void calcPortions(int* portions_info, t_wavhdr* header, int N){

  int bytesPerSample = bitsToBytes(header->bitsPerSample);
  int sampleNumber = header->subchunk2Size/bytesPerSample;
  portions_info[0] = sampleNumber/N; //number of portions without tail
  portions_info[1] = sampleNumber%N; //size of tail

  printf("num of pors = %i, tail = %i", portions_info[0], portions_info[1]);
  
  return;
}

int bitsToBytes(int bits){

  return bits/8;
}
