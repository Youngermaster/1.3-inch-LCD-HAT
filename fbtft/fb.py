#!/usr/bin/env python2
from PIL import Image
import numpy as np
 
im = Image.open('pic.jpg')
 
w, h = im.size
print( "w:", w ,"h:", h)
if w != 240 or h != 240:
	raise ValueError('Image must be same dimensions as display \
		({0}x{1}).' .format(240, 240))
				
with open('/dev/fb1', 'wb') as f:
	img = np.asarray(im)
	pix = np.zeros((240,240,2), dtype = np.uint8)
	pix[...,[1]] = np.add(np.bitwise_and(img[...,[0]],0xF8),np.right_shift(img[...,[1]],5))
	pix[...,[0]] = np.add(np.bitwise_and(np.left_shift(img[...,[1]],3),0xE0),np.right_shift(img[...,[2]],3))
	pix = pix.flatten().tobytes()
	f.write(pix)	
