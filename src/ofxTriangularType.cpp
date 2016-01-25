#include "ofxTriangularType.h"

// triangle
ofxTriangle::ofxTriangle()
{
    // ����
    a.zero();
    b.zero();
    c.zero();
    
    fill = false;
    
    // Ĭ��Ϊ��ɫ
    color.set(0, 0, 0);
}

ofxTriangle::ofxTriangle(ofPoint a, ofPoint b, ofPoint c):a(a), b(b), c(c)
{
    fill = false;
}

// ������������������Ƿ��߽��м��
void ofxTriangle::set(ofPoint a, ofPoint b, ofPoint c)
{
    this->a = a;
    this->b = b;
    this->c = c;
    
    this->fill = false;
}

void ofxTriangle::setFill(bool fill)
{
    this->fill = fill;
}

void ofxTriangle::setColor(ofColor color)
{
    this->color = color;
}

void ofxTriangle::draw()
{
    ofPushStyle();
    
    ofSetColor(color);
    if(fill)
        ofFill();
    else
        ofNoFill();
    
    // �����εĻ���
    ofTriangle(a.x, a.y, b.x, b.y, c.x, c.y);
    
    ofPopStyle();
}


// hole
ofxHole::ofxHole()
{
    pointInsideHole.zero();
}

ofxHole::ofxHole(ofPolyline boundary, ofPoint pointInsideHole):pointInsideHole(pointInsideHole), boundary(boundary)
{
    
}

void ofxHole::set(ofPolyline boundary, ofPoint pointInsideHole)
{
    this->pointInsideHole = pointInsideHole;
    this->boundary = boundary;
}

ofPolyline ofxHole::getBoundary()
{
    return boundary;
}

ofPoint ofxHole::getPointInsideHole()
{
    return pointInsideHole;
}



// segment
ofxSegment::ofxSegment()
{
    start.zero();
    end.zero();
}

ofxSegment::ofxSegment(ofPoint start, ofPoint end): start(start), end(end)
{
    
}

void ofxSegment::set(ofPoint start,  ofPoint end)
{
    this->start = start;
    this->end = end;
}

ofPoint ofxSegment::getStart()
{
    return start;
}
ofPoint ofxSegment::getEnd()
{
    return end;
}

void ofxSegment::draw()
{
    ofLine(start.x, start.y, end.x, end.y);
}
