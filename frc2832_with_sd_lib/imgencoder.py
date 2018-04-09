#!/usr/bin/env python
from PIL import Image
import sys

import os

def code(name):
	print name
	name = name.split('.')
	f = open(name[0] + '.img','wb')
	im = Image.open(name[0] + '.png') #Can be many different formats.
	pix = im.load()
	a = im.size
	for y in range(0,im.size[1]):
		for x in range(0,im.size[0]):
			f.write(chr(pix[x,y][0]))
			f.write(chr(pix[x,y][1]))
			f.write(chr(pix[x,y][2]))
	f.close()


filelist=os.listdir('./')
for fichier in filelist[:]: # filelist[:] makes a copy of filelist.
    if (fichier.endswith(".png")):
	print fichier
        code(fichier)
print(filelist)




