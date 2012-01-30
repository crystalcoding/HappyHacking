import Image
import ImageOps
import string
import os

filename = 'i539735.GIF'
img = Image.open(filename)
img_rgba = img.convert("RGBA")
bg = Image.new("RGBA", img_rgba.size)
combine = Image.composite(img_rgba, bg, img_rgba)
combine.save('tmp.jpg')
invert_img_file_name = filename[0: string.find(filename, '.')] + '-invert.jpg'
ImageOps.invert(Image.open('tmp.jpg')).save(invert_img_file_name)
os.remove('tmp.jpg')


