# -*- coding: utf-8 -*-
"""
Created on Sun Nov 22 10:47:18 2020

@author: helladmin
""" 

import numpy as np

import matplotlib as mpl
import matplotlib.pyplot as plt

##########################################################
# https://matplotlib.org/gallery.html
# хорошая подборка разных примеров отображения данных
##########################################################

if (__name__ ==  '__main__'):
###

    data = np.loadtxt('output.dat')
    datasize = len(data)
    arr_n = np.arange(datasize)
    x = arr_n * (24000/datasize) ## значения по оси X
    fig1, ax1 = plt.subplots()
    
    ax1.plot(x, data)
    #ax1.set_yscale('linear') ## масштаб по оси Y

    # Подписи
    ax1.set_title('DFT ton_signal N = 512')
    ax1.set_xlabel('Частота')
    ax1.set_ylabel('Амплитуда')
    
    ax1.grid(True) #включить сетку

## Отображаем все рисунки (вызывается один раз)
    plt.show()
else:
    print(__name__, 'is imported')
    
   
