# SamuCam

In this project I have started to experiment with real input data. 

## SamuCam, exp. 10, cognitive mental organs: MPU (Mental Processing Unit), COP-based Q-learning, acquiring higher-order knowledge

This experiment shows how the program of ["Game of Life"](https://github.com/nbatfai/SamuBrain) 
has been mechanically applied to learn human faces from videos and photos. The class SamuCam uses OpenCV for face detection. 
The results for this first experiment can be seen in a video at [https://youtu.be/6cRbyKrq45c](https://youtu.be/6cRbyKrq45c)
It can be seen easily that Samu COP-based prediction technique for distinguishing human faces will be problematic 
due to the prediction mechanism has strongly local scope.

## Usage

### vInitialHack

```
git clone https://github.com/nbatfai/SamuCam.git
cd SamuCam/
wget https://github.com/Itseez/opencv/raw/master/data/lbpcascades/lbpcascade_frontalface.xml
git checkout vInitialHack
~/Qt/5.5/gcc_64/bin/qmake SamuLife.pro
make
./SamuKnows 2>out
```

```
tail -f out|grep "HIGHER-ORDER NOTION MONITOR"
```

```
tail -f out|grep SENSITIZATION
```

## Previous other experiments

Samu (Nahshon)
http://arxiv.org/abs/1511.02889,
https://github.com/nbatfai/nahshon

---

SamuLife
https://github.com/nbatfai/SamuLife,
https://youtu.be/b60m__3I-UM

SamuMovie
https://github.com/nbatfai/SamuMovie,
https://youtu.be/XOPORbI1hz4

SamuStroop
https://github.com/nbatfai/SamuStroop,
https://youtu.be/6elIla_bIrw,
https://youtu.be/VujHHeYuzIk

SamuBrain
https://github.com/nbatfai/SamuBrain

SamuCopy
https://github.com/nbatfai/SamuCopy

---

SamuTicker
https://github.com/nbatfai/SamuTicker

SamuVocab
https://github.com/nbatfai/SamuVocab

---

SamuKnows
https://github.com/nbatfai/SamuKnows

---

SamuCam
https://github.com/nbatfai/SamuCam

![samucam1-nandi4](https://cloud.githubusercontent.com/assets/3148120/14001514/91fbb354-f146-11e5-9a0a-5d551bee494a.png)

![samucam1-nandi7](https://cloud.githubusercontent.com/assets/3148120/14001569/e5268d56-f146-11e5-9f6b-f4fbf6c007e2.png)

Robopsychology One
https://github.com/nbatfai/Robopsychology
