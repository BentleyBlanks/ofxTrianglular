#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    
    sketchMode = 0;
    bClear = false;
    
//  polyline.addVertex(0, 0);
//	polyline.addVertex(100, 0);
//	polyline.addVertex(100, 400);
//	polyline.addVertex(0, 400);
//
//	holeline.addVertex(20, 100);
//	holeline.addVertex(80, 100);
//	holeline.addVertex(80, 200);
//	holeline.addVertex(20, 200);

//  segments.push_back(ofxSegment(ofPoint(20, 300), ofPoint(80, 350)));
//  segments.push_back(ofxSegment(ofPoint(80, 300), ofPoint(20, 350)));
    
    // 暂不开放
    //triangular.setSegments(segments);
    
    canvas = new ofxUISuperCanvas("canvas");
    
    vector<string> radioName;
    radioName.push_back("Boundary");
    radioName.push_back("Holes");
    radioName.push_back("PointInsideHole");
    
    canvas->addRadio("Radio", radioName);
    canvas->addSpacer();
    canvas->addButton("Clear", false);
    canvas->addButton("Generate", false);
    slider = canvas->addSlider("tesselationSlider", 100, 700, 600);
    
    // 细分默认值
    triangular.setLevelOfTesselation(slider->getValue());
    
    canvas->setPosition(ofGetWidth() - canvas->getRect()->getWidth(), 0);
    
    ofAddListener(canvas->newGUIEvent, this, &ofApp::guiEvent);
}

//--------------------------------------------------------------
void ofApp::update(){
 
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushStyle();
    ofSetColor(20, 20, 200);
    
    if(polyline.size() != 0)
        polyline.draw();
    
    if(holeline.size() != 0)
        holeline.draw();
    
    for(int i=0; i<holes.size(); i++)
    {
        //holes[i].getBoundary().draw();
        ofCircle(holes[i].getPointInsideHole().x, holes[i].getPointInsideHole().y, 2);
    }
    ofPopStyle();
    
    for(int i=0; i<triangles.size(); i++)
    {
        triangles[i].draw();
    }

}


void ofApp::guiEvent(ofxUIEventArgs &e)
{
    string name = e.getName();
    
    cout << "widget name:" << name << endl;
    
    if(name == "Generate")
    {
        triangular.setBoundary(polyline);
        triangular.setHoles(holes);
        
        triangular.setLevelOfTesselation(slider->getValue());
		
        triangles = triangular.triangulate();
        
        for(int i=0; i<triangles.size(); i++)
        {
            triangles[i].setColor(ofColor(200, 20, 20));
            triangles[i].setFill(false);
        }
    }
    else if(name == "Clear")
    {
        bClear = true;

        polyline.clear();
        holeline.clear();
        holes.clear();
        segments.clear();
        triangles.clear();
        
        triangular.clearBoundary();
        triangular.clearHoles();
        triangular.clearSegments();
    }
    else if(name == "Boundary")
    {
        sketchMode = 0;
    }
    else if(name == "Holes")
    {
        sketchMode = 1;
    }
    else if(name == "PointInsideHole")
    {
        sketchMode = 2;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    if(bMouseDown)
    {
        switch (sketchMode)
        {
            case 0:
                polyline.addVertex(ofPoint(x, y));
                break;
                
            case 1:
                holeline.addVertex(ofPoint(x, y));
                break;
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    bMouseDown = true;
    
    if(sketchMode == 2)
    {
        ofxHole hole;
        // 只有点在孔中才会被添加
		if(holeline.size()!=0 && holeline.inside(x, y))
        {
            hole.set(holeline, ofPoint(x, y));
            holes.push_back(hole);
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    bMouseDown = false;
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
