//-*- coding: utf-8 -*-
//******************************************************************************
// Обозначение:			readWavFuncs.h 				       
// Назначение:			
// Разработчик:     	Сергеева Е.И. 
// Дата последней корректировки: 
//******************************************************************************

#ifndef _DEF_READWAVFUNCS_H_
#define _DEF_READWAVFUNCS_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "def_types.h"
#include "fftw3.h"

void readHeader(t_wavhdr* header, FILE* f_in);

void readData(double* data_portion, int N, FILE* f_in );

void calcPortions(int* portions_info, t_wavhdr* header, int N);

int bitsToBytes(int bitsPerSample);

void fftsq(double* data_portion, double* sq, int sqsize);

void accumulation(double* acc, double* sq, int sqsize);

#endif  
