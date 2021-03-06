# ofxTrianglular

Easy to subdivide a complex 2d shape to triangles.<br>

Support ```OSX```(Xcode 6.0) ```Windows```(Visual Studio 2012), and ```Linux```(QtCreator, Ubuntu, Thanks for [icq4ever](https://github.com/icq4ever)).<br>

Based on ```Jonathan Richard Shewchuk```'s [triangle library]( http://www.cs.cmu.edu/~quake/triangle.html)<br>

---

### How to bulid

* Based on [OpenFrameworks](http://openframeworks.cc/), only need [ofxTriangular](https://github.com/BentleyBlanks/ofxTrianglular), no other dependencies<br>


* To bulid example you need to include [ofxUI](https://github.com/rezaali/ofxUI) and [ofxXmlSettings](https://github.com/openframeworks/openFrameworks/tree/master/addons/ofxXmlSettings) in projectGenerator or added manually.


* Replace the defalut project's ```ofApp.cpp``` + ```ofApp.h``` + ```main.cpp```<br>

---

### Screenshots

#### OSX

![image](https://raw.githubusercontent.com/BentleyBlanks/ofxTrianglular/master/pictures/Mac%20(1).png)

#### Windows

![image](https://raw.githubusercontent.com/BentleyBlanks/ofxTrianglular/master/pictures/Windows%20(1).jpg)

#### Linux

![screenshot_Linux](https://cloud.githubusercontent.com/assets/530796/12534737/160ac166-c2a9-11e5-8576-92796b94cf6b.png)

(Thanks for [icq4ever](https://github.com/icq4ever))

---

### Getting Started

Simplest way to init ```ofxTriangular```.

``` c
// set a boundary made by ofPolyline
ofPolyline polyline

triangular.setBoundary(polyline);
```

If your 2d shape include some holes in it.

``` c
// set a hole made by ofPolyline

// one ofxHole connect one point inside it.
ofxHole hole;
vector<ofxHole> holes;

// only if point(x, y) was inside the hole that you want to add.
if(holeline.inside(x, y))
{
    hole.set(holeline, ofPoint(x, y));
    holes.push_back(hole);
}

triangular.setHoles(holes);
```

Subdivide complex 2d shape to triangles.

``` c
// generate the triangle collections

triangles = triangular.triangulate();
```

If you want to render the triangle that ofxTriangular generated.

``` c
// loop all of it if needed
for(int i=0; i<triangles.size(); i++)
{
   triangles[i].draw();
}
```

---

### Shortage

* The Option ```Tesselation``` was enabled, but the effect of it was not obvious.(unless you set the option ```tesselation```  ```0``` compared with ```600```)<br><br>
* Don't support advanced features like ```iteration```, ```constraint```. etc(haven't open the ```API``` yet).<br><br>
* Under some certain circumstances, ```Debug``` is much easier to crash than the ```Release```.<br>

---

#### Extreme Cases

Only in some exreme cases (complex nested boundary) that ofxTriangular runs on Windows was easier to crash than the OSX.

#### OSX

![image](https://raw.githubusercontent.com/BentleyBlanks/ofxTrianglular/master/pictures/Mac%20(2).png)

![image](https://raw.githubusercontent.com/BentleyBlanks/ofxTrianglular/master/pictures/Mac%20(3).png)

#### Windows

![image](https://raw.githubusercontent.com/BentleyBlanks/ofxTrianglular/master/pictures/Windows%20(1).jpg)

![image](https://raw.githubusercontent.com/BentleyBlanks/ofxTrianglular/master/pictures/Windows%20(2).jpg)


---

## Author

``` c
   int 官某某 = Bingo;

   char[] 个人博客 = "http://bentleyblanks.github.io";
```