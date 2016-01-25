# ofxTrianglular

Easy to subdivide a complex 2d shape to triangles.<br>

Support ```OSX``` and ```Windows```(Xcode 6.0, Visual Studio 2012), ```Linux```(QtCreator, Ubuntu, Thanks for [icq4ever](https://github.com/icq4ever)).<br>

Based on ```Jonathan Richard Shewchuk```'s [triangle library]( http://www.cs.cmu.edu/~quake/triangle.html)<br>

=====

### How to bulid?

* Only need ofxTriangular library,and no need other dependencies<br>


* To bulid example you need to include ofxUI and ofxXmlSettings<br>


* replace the defalut project's ```ofApp.cpp``` + ```ofApp.h``` + ```main.cpp```<br>

=====

### Screenshot

#### OSX

![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Mac (1).png)

#### Windows

![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Windows (1).jpg)

#### Linux

![screenshot_Linux](https://cloud.githubusercontent.com/assets/530796/12534737/160ac166-c2a9-11e5-8576-92796b94cf6b.png)

(Thanks for [icq4ever](https://github.com/icq4ever))

=====

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

=====

### Shortage

* The Option ```Tesselation``` was enabled, but the effect of it was not obvious.(unless you set the option ```tesselation```  ```0``` compared with ```600```)<br>
* Don't support advanced features like ```iteration```, ```constraint```. etc(haven't open the ```API``` yet).<br>
* Under some certain circumstances, ```Debug``` is much easier to crash than the ```Release```.<br>

=====

#### Extreme Cases

Only in some exreme cases (complex nested boundary) that ofxTriangular runs on Windows was easier to crash than the OSX.

#### OSX

![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Mac (2).png)

![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Mac (3).png)

#### Windows

![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Windows (2).jpg)

![image](https://github.com/BentleyBlanks/ofxTrianglular/raw/master/pictures/Windows (3).jpg)



=====

## Author

``` c
   int 官某某 = Bingo;
```