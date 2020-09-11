# HandWritten DigitCLassifoer

For This Project I created Train data. I made 25 Images of Digits
## Feature Extaction

When dealing with images, if you use a CNN this step is often overlooked: CNNs are made on purpose to handle raw pixel values, so you just throw the image in and it is handled properly.

When using other types of classifiers, it could help add a bit of feature engineering to help the classifier doing its job and achieve high accuracy.

But not this time.

I wanted to be as "light" as possible, so I only took a couple steps during the feature acquisition:

use a grayscale image
downsample to a manageable size
convert it to black/white with a threshold.

##Result
My dataset is composed of 25 training samples in total and the SVM with linear kernel produced 17 support vectors.

On my M5Stick camera board, the overhead for the model is 6.8 Kb of flash and the inference takes 7ms: not that bad!
