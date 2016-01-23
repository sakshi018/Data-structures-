import scipy
import matplotlib.pyplot as plt
l= scipy.lena()
from scipy import misc
misc.imsave('lena.png', l) # uses the Image module PIL

lena = misc.imread('lena.png')
type(lena)
<type 'numpy.ndarray'>
lena.shape, lena.dtype
((512, 512), dtype('uint8'))

plt.imshow(l, cmap=plt.cm.gray)
<matplotlib.image.AxesImage object at 0x3c7f710>