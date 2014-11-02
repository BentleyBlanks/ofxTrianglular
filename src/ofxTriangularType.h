#ifndef OFX_TRIANGULARTYPE_H
#define OFX_TRIANGULARTYPE_H

#include <ofMain.h>

class ofxTriangle
{
public:
    ofxTriangle();
    ofxTriangle(ofPoint a, ofPoint b, ofPoint c);
    
    // ≤ªª·∂‘»˝Ω«–Œ»˝∏ˆµ„ «∑Òπ≤œﬂΩ¯––ºÏ≤È
    void set(ofPoint a, ofPoint b, ofPoint c);
    
    // drawœ‡πÿ
    void setFill(bool fill);
    
    void setColor(ofColor color);
    
    void draw();
    
private:
    ofPoint a, b, c;
    
    ofColor color;
    bool fill;
};


class ofxHole
{
public:
    ofxHole();
    ofxHole(ofPolyline boundary, ofPoint pointInsideHole);
    
    void set(ofPolyline boundary, ofPoint pointInsideHole);
    
    // get
    ofPolyline getBoundary();
    
    ofPoint getPointInsideHole();
private:
    ofPoint pointInsideHole;
    ofPolyline boundary;
};

class ofxSegment
{
public:
    ofxSegment();
    ofxSegment(ofPoint start, ofPoint end);
    
    void set(ofPoint start,  ofPoint end);
    
    ofPoint getStart();
    ofPoint getEnd();
    
    void draw();
    
private:
    // 约束线起始点 和 末点
    ofPoint start, end;
};
#endif
