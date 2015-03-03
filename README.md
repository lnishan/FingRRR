# FingRRR
a light 2D interaction framework structured on OpenCV

### Motive
##### Why the framework?
OpenCV is extremely feature-poor when it comes to UI. Therefore, building a extensible and reliable interaction framework for 2D interfaces (scenes, objects) and animations is what comes to mind when I was trying to build a game of my own (with OpenCV).

##### Concepts (Interaction):
- Mouse simulator: Using a red ball to simulate mouse behavior, and thus allowing
more advanced and intuitive interaction.
- Key factor: Size of red ball. (ie. red ball size gets bigger when closer to screen)
- The interaction is done on a user-decided imaginary surface.


##### For a better reference
- [Refer to this slide](http://1drv.ms/1vW2Ysq)  
Note that this slide is made when FingRRR still uses one thread, but this one shall give you a good grasp of FingRRR.  
For the multithreaded FingRRR, you can refer to this [Slide](http://1drv.ms/1CmK2p1)  
- [Detailed technical report](http://1drv.ms/1EI4FLZ)

### Examples
**Initialization**
```
inputMethod = INPUT_METHOD_MOUSE;
init(1400, 700, false);
```
**Scene Setup**
```
iScene *main = new iScene(0, 0, 1400, 700, 0, 0, 0, 0, &assetsImg[6]);
sceneActive = main;

iToolbar *mainTB = main->createToolbar(0, 0, 486, 60);
iButton *btn1 = mainTB->createButton(140, 56, 255, 0, 0, 0, &assetsImg[0], onBtnHover, onBtnClick, NULL, NULL, NULL, NULL, onBtnOut);
iButton *btn2 = mainTB->createButton(140, 56, 0, 255, 0, 0, &assetsImg[2], onBtnHover, clickMoveTest, NULL, NULL, NULL, NULL, onBtnOut);
iButton *btn3 = mainTB->createButton(140, 56, 0, 0, 255, 0, &assetsImg[4], onBtnHover, onBtnClick, NULL, NULL, NULL, NULL, onBtnOut);
btn1->customData[0] = 0; btn1->customData[1] = 1;
btn2->customData[0] = 2; btn2->customData[1] = 3;
btn3->customData[0] = 4; btn3->customData[1] = 5; 
iButton *btn4 = mainTB->createButton(56, 56, 255, 0, 255, 255, NULL, NULL, changeClrCursorFootprint, NULL, NULL, NULL, NULL, NULL);

test2 = sceneActive->createObject(50, 50, 475, 475, 0, 0, 0, 0, &assetsImg[7], 230, true, true);
test2->onDrag = &onDrag;

test = sceneActive->createObject(200, 200, 100, 100, 0, 0, 255, 100, NULL, 255, true, true);
test->onDrag = &onDrag;
```
**Hook your own event** (runs in a separate thread during program runtime)
```
hookUserEvent(event);
```
**Start framework execution**
```
start();
```
You may also refer to the source code in main.cpp.
