# Normalized Cross-Correlation

Commonly used in template matching and primitive stereo correspondence. 

## Problem 

Solving the problem of corresponding pixel boils down to finding the region of highest similarity given an input image and template image, to back out the global offsets (x & y) that localize the origin of the template within the input image. 

The problem here is determining a well posed similarity metric that is invariant across an images radiometric parameters (e.g. brightness and contrast). Using more standard metric of squared or absolute errors, it turns out that the radiometric parameters are no invariant and that a change in brightness or contrast will change the value of the cost function leading to false positive/negatives due to mismatches in an images exposure settings. 

## NNC Solution 
The solution that NNC takes is to normalize standard deviations from mean of an image and its kernel so only the deviations from the means are actually tracked instead of the shifts in the mean value themselves as would occur with absolute or squared error cost functions.